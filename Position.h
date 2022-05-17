#ifndef POSITION
#define POSITION

#include <iostream>

class Position {
private:
    float x, y;
public:
    Position(const float init_x, const float init_y) : x(init_x), y(init_y) {}
    float operator-(const Position that) const;
    Position operator+(Position that);
    Position operator/(float denominator);
    float GetX() const;
    float GetY() const;
    void Read(std::istream& s);
};
#endif
