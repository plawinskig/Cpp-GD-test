#pragma once

#include <vector>
#include "raylib.h"

class Snake
{
public:
    Snake();

    Vector2 operator[](int i) const { return body_[i]; }

    auto begin() { return body_.begin(); }
    auto end()   { return body_.end(); }

    auto begin() const { return body_.cbegin(); }
    auto end() const   { return body_.cend(); }

    size_t getSize() const { return body_.size(); }
    Vector2 getDirection() const { return direction_; }
    Vector2 getHeadPos() const { return body_[0]; }

    void setDirection(const Vector2 &direction) { direction_ = direction; }

    bool isColliding() const;
    bool occupies(const Vector2 &pos) const;

    void move(const Vector2 &new_direction);
    void wrap(int max_x, int max_y);
    void extendBody();
    void reset();

private:
    std::vector<Vector2> body_;
    Vector2 direction_;
};
