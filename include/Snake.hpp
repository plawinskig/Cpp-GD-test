#pragma once

#include <vector>
#include "raylib.h"

class Snake
{
public:
    Snake();

    Vector2 operator[](int i) { return body_[i]; }

    auto begin() { return body_.begin(); }
    auto end()   { return body_.end(); }

    auto begin() const { return body_.cbegin(); }
    auto end() const   { return body_.cend(); }

    size_t getSize() { return body_.size(); }
    Vector2 getDirection() { return direction_; }

    void setDirection(Vector2 &direction) { direction_ = direction; }

    void move(Vector2 &new_direction);
    bool isColliding();
    void extendBody();
    void reset();

private:
    std::vector<Vector2> body_;
    Vector2 direction_;
};
