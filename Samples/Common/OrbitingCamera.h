//
// Camera

#ifndef ORBITING_CAMERA
#define ORBITING_CAMERA

#include "Camera.h"

namespace VKCookbook {

  class OrbitingCamera : public Camera {
  public:
    virtual Vector3     GetTarget() const final;
    virtual float       GetDistance() const final;
    virtual float       GetHorizontalAngle() const final;
    virtual float       GetVerticalAngle() const final;

    void                ChangeDistance( float distance_delta );
    void                RotateHorizontally( float angle_delta );
    void                RotateVertically( float angle_delta );

              OrbitingCamera();
              OrbitingCamera( Vector3 const & target,
                              float           distance,
                              float           horizontal_angle = 0.0f,
                              float           vertical_angle = 0.0f );
              OrbitingCamera( OrbitingCamera const & other );
    virtual  ~OrbitingCamera();

    OrbitingCamera& operator=( OrbitingCamera const &i_OrbitingCamera );

  private:
    Vector3             Target;
    float               Distance;
    float               HorizontalAngle;
    float               VerticalAngle;
  };

} // namespace VulkanCookbook

#endif // ORBITING_CAMERA