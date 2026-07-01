#include "Snake.hpp"

Snake::Snake()
    : body_(std::deque<Vector2>()),
    direction_({1, 0})
{
    reset();
}

void Snake::move(const Vector2 &new_direction)
{
    if(!(new_direction.x == -direction_.x &&
        new_direction.y == -direction_.y))
    {
        setDirection(new_direction);
    }

    Vector2 new_head_pos = {getHeadPos().x + direction_.x, getHeadPos().y + direction_.y};
    body_.push_front(new_head_pos);
    body_.pop_back();
}

void Snake::wrap(int max_x, int max_y)
{
    for (auto &segment : body_)
    {
        if (segment.x >= max_x) { segment.x = 0; }
        if (segment.y >= max_y) { segment.y = 0; }
        if (segment.x < 0) { segment.x = max_x - 1; }
        if (segment.y < 0) { segment.y = max_y - 1; }
    }
}

bool Snake::isColliding() const
{
    for(size_t i = 1; i < body_.size(); ++i)
    {
        if (
            body_[0].x == body_[i].x &&
            body_[0].y == body_[i].y
        )
        {
            return true;
        }
    }

    return false;
}

bool Snake::occupies(const Vector2 &pos) const
{
    for (Vector2 const& segment : body_)
    {
        if (segment.x == pos.x && segment.y == pos.y)
        {
            return true;
        }
    }

    return false;
}

void Snake::extendBody()
{
    body_.push_back(body_.back());
}

void Snake::reset()
{
    body_.clear();
    direction_ = {1, 0};

    body_.push_back({5,5});
    body_.push_back({5,4});
}
