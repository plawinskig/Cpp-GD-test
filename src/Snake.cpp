#include "Snake.hpp"

Snake::Snake()
{
    reset();
}

void Snake::move(Vector2 &new_direction)
{
    for (int i = body_.size() - 1; i > 0; --i)
    {
        body_[i] = body_[i - 1];
    }

    if(new_direction.x == -direction_.x &&
        new_direction.y == -direction_.y)
    {
        new_direction = direction_;
    }

    setDirection(new_direction);

    body_[0].x += direction_.x;
    body_[0].y += direction_.y;
}

void Snake::reset()
{
    body_ = std::vector<Vector2>();
    direction_ = {1, 0};

    body_.push_back({5,5});
    body_.push_back({5,4});
}
