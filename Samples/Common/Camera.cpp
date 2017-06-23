//
// Camera

#include "Camera.h"

namespace VKCookbook {

  Matrix4x4 Camera::GetMatrix() const {
    if( Dirty ) {
      ViewMatrix = {
        RightVector[0],
        UpVector[0],
        -ForwardVector[0],
        0.0f,

        RightVector[1],
        UpVector[1],
        -ForwardVector[1],
        0.0f,

        RightVector[2],
        UpVector[2],
        -ForwardVector[2],
        0.0f,

        Dot( Position, RightVector ),
        Dot( Position, UpVector ),
        Dot( Position, ForwardVector ),
        1.0f
      };
      Dirty = false;
    }
    return ViewMatrix;
  }

  Vector3 Camera::GetPosition() const {
    return Position;
  }

  Vector3 Camera::GetRightVector() const {
    return RightVector;
  }

  Vector3 Camera::GetUpVector() const {
    return UpVector;
  }

  Vector3 Camera::GetForwardVector() const {
    return ForwardVector;
  }

  Camera::Camera() :
    Camera( { 0.0f, 0.0f, 0.0f }, { 1.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f, -1.0f } ) {
  }

  Camera::Camera( Vector3 const & position,
                  Vector3 const & right_vector,
                  Vector3 const & up_vector,
                  Vector3 const & forward_vector ) :
    ViewMatrix( {} ),
    Position( position ),
    RightVector( right_vector ),
    UpVector( up_vector ),
    ForwardVector( forward_vector ),
    Dirty( true ) {
  }

  Camera::Camera( Camera const & camera ) {
    *this = camera;
  }

  Camera::~Camera() {
  }

  Camera& Camera::operator= ( Camera const & camera ) {
    if( this != &camera ) {
      ViewMatrix = camera.ViewMatrix;
      Position = camera.Position;
      RightVector = camera.RightVector;
      UpVector = camera.UpVector;
      ForwardVector = camera.ForwardVector;
      Dirty = camera.Dirty;
    }
    return *this;
  }

} // namespace VulkanCookbook