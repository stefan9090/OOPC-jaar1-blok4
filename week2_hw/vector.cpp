#include "vector.hpp"

vector::vector(int x, int y):
    x(x),
    y(y)
{}

vector vector::operator+(const vector rhs) const {
    return vector(x + rhs.x, y + rhs.y);
}
vector vector::operator+(){
    return vector(x, y);
}

vector & vector::operator+=(const vector & rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}
    
vector vector::operator*(const vector rhs) const {
    return vector(x * rhs.x, y * rhs.y);
}

vector vector::operator*(const int rhs)const {
    return vector(x * rhs, y * rhs);
}
    
vector & vector::operator*=(const vector & rhs) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}

bool vector::operator==(const vector & rhs)const{
    return (x == rhs.x) && (y == rhs.y);
}
    
std::ostream & operator<<(std::ostream & os, const vector & rhs){
    return os << '[' << rhs.x <<',' << rhs.y <<']';
}


