#pragma once 

#include "vector2d.h"
#include "video.h"
// TODO: format
// util class for transforming cartesian coordinates to screen coordinates
class Camera {
public:
  Camera(Window& window) : origin(window.getWidth(), window.getHeight()) {}

  // get the world position of the camera
  [[nodiscard]] Vector2Df getPosition() { return offset; }

  // transform world to screen coordinates
  [[nodiscard]] Vector2Df transformToDisplayCoords(Vector2Df position) const {
    position.x = origin.x + position.x - offset.x;
    position.y = origin.y - position.y + offset.y;
    return position;
  }

  // transform screen to world coordinates
  [[nodiscard]] Vector2Df transformToWorldCoords(Vector2Df position) const {
    position.x = position.x - origin.x + offset.x;
    position.y = origin.y - position.y - offset.y;
    return position;
  }

  // set position
  void setOffset(const Vector2Df &position) { offset = position; }

private:
  Vector2Df origin;
  Vector2Df offset{0.0f, 0.0f};
};