//
// Camera

#include "OrbitingCamera.h"
#include "All_Lib.h"

namespace VKCookbook {

  Vector3 OrbitingCamera::GetTarget() const {
    return Target;
  }

  float OrbitingCamera::GetDistance() const {
    return Distance;
  }

  float OrbitingCamera::GetHorizontalAngle() const {
    return HorizontalAngle;
  }

  float OrbitingCamera::GetVerticalAngle() const {
    return VerticalAngle;
  }

  void OrbitingCamera::ChangeDistance( float distance_delta ) {
    Distance -= distance_delta;
    if( Distance < 0.0f ) {
      Distance = 0.0f;
    }
    Position = Target - Distance * ForwardVector;
    Dirty = true;
  }

  void OrbitingCamera::RotateHorizontally( float angle_delta ) {
    Matrix4x4 const rotation = PrepareRotationMatrix( angle_delta, { 0.0f, -1.0f, 0.0f } );

    // Comment by Anastazja:
    //
    // Mama i tata, i brat, i znow brat, i babcia, i dziadek, i wujek, i babcia prabacia, i ciocia.
    // Napisalam to ja z tata.

    HorizontalAngle += angle_delta;
    ForwardVector = ForwardVector * rotation;
    UpVector = UpVector * rotation;
    RightVector = RightVector * rotation;
    Position = Target - Distance * ForwardVector;
    Dirty = true;
  }

  void OrbitingCamera::RotateVertically( float angle_delta ) {
    float const old_angle = VerticalAngle;
    float tmp_delta = angle_delta;

    VerticalAngle += angle_delta;
    if( VerticalAngle > 90.0f ) {
      VerticalAngle = 90.0f;
      tmp_delta = 90.0f - old_angle;
    } else if( VerticalAngle < -90.0f ) {
      VerticalAngle = -90.0f;
      tmp_delta = -90.0f - old_angle;
    }

    Matrix4x4 const rotation = PrepareRotationMatrix( tmp_delta, RightVector );

    ForwardVector = ForwardVector * rotation;
    UpVector = UpVector * rotation;
    Position = Target - Distance * ForwardVector;
    Dirty = true;
  }

  OrbitingCamera::OrbitingCamera() :
    OrbitingCamera( { 0.0f, 0.0f, 0.0f }, 1.0f, 0.0f, 0.0f ) {
  }

  OrbitingCamera::OrbitingCamera( Vector3 const & target,
                                  float           distance,
                                  float           horizontal_angle,
                                  float           vertical_angle ) :
    Camera( target - distance * Vector3{ 0.0f, 0.0f, -1.0f }, { 1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, -1.0f } ),
    Target( target ),
    Distance( distance ),
    HorizontalAngle( 0.0f ),
    VerticalAngle( 0.0f ) {
    RotateHorizontally( horizontal_angle );
    RotateVertically( vertical_angle );
  }

  OrbitingCamera::OrbitingCamera( OrbitingCamera const & camera ) {
    *this = camera;
  }

  OrbitingCamera::~OrbitingCamera() {
  }

  OrbitingCamera& OrbitingCamera::operator=( OrbitingCamera const & camera ) {
    if( this != &camera ) {
      Camera::operator=( camera );
      Target = camera.Target;
      Distance = camera.Distance;
      HorizontalAngle = camera.HorizontalAngle;
      VerticalAngle = camera.VerticalAngle;
    }
    return *this;
  }

} // namespace VulkanCookbook