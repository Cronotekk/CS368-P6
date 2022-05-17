#include <iostream>
#include <cmath>
#include "Position.h"

using namespace std;

float Position::operator-(const Position that) const {
    float diff_x = this->x - that.x;
    float diff_y = this->y - that.y;
    return sqrt(diff_x * diff_x + diff_y * diff_y);
}

void Position::Read(istream& s) {
    cin >> x >> y;
}

Position Position::operator+(Position that) {
	float x = this->x + that.x;
	float y = this->y + that.y;
	Position pos(x, y);
	return pos;
}

Position Position::operator/(float denominator) {
	float x = this->x / denominator;
	float y = this->y / denominator;
	Position pos(x, y);
	return pos;
}

float Position::GetX() const {
	return this->x;
}

float Position::GetY() const {
	return this->y;
}
