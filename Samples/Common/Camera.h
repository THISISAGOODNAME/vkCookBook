//
// Camera

#ifndef CAMERA
#define CAMERA

#include "Tools.h"

namespace VKCookbook {

  class Camera {
  public:
    virtual Matrix4x4   GetMatrix() const final;
    virtual Vector3     GetPosition() const final;
    virtual Vector3     GetRightVector() const final;
    virtual Vector3     GetUpVector() const final;
    virtual Vector3     GetForwardVector() const final;

  protected:
              Camera();
              Camera( Vector3 const & position,
                      Vector3 const & right_vector,
                      Vector3 const & up_vector,
                      Vector3 const & forward_vector );
              Camera( Camera const & camera );
    virtual  ~Camera() = 0;

    Camera& operator=( Camera const & camera );

    mutable Matrix4x4   ViewMatrix;
    Vector3             Position;
    Vector3             RightVector;
    Vector3             UpVector;
    Vector3             ForwardVector;
    mutable bool        Dirty;
  };

} // namespace VulkanCookbook

#endif // CAMERA