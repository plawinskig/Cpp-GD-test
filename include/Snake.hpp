#pragma once

#include <vector>
#include "raylib.h"

class Snake
{
public:
    Snake();

    Vector2 operator[](int i) { return body_[i]; }

    size_t getSize() { return body_.size(); }
    Vector2 getDirection() { return direction_; }

    void setDirection(Vector2 &direction) { direction_ = direction; }

    void move(Vector2 &new_direction);
    void reset();

private:
    std::vector<Vector2> body_;
    Vector2 direction_;
};
