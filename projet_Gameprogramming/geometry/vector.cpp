#include "vector.h"
#include "point.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include <iostream>

Vector2f MakeV2f(float x, float y){
    return Vector2f{ x, y };
}

Vector2f MakeV2f(const Point2f& a, const Point2f& b) {
    return Vector2f{ b.x - a.x, b.y - a.y };
}

Vector2f Add(const Vector2f& a, const Vector2f& b) {
    return Vector2f{ a.x + b.x, a.y + b.y };
}

Vector2f Sub(const Vector2f& a, const Vector2f& b) {
    return Vector2f{ a.x - b.x, a.y - b.y };
}

Vector2f Scale(const Vector2f& v, float scalar) {
    return Vector2f{ v.x * scalar, v.y * scalar };
}

float Dot(const Vector2f& a, const Vector2f& b) {
    return a.x * b.x + a.y * b.y;
}

float Length(const Vector2f& v){
    float taille;
    taille = (v.x * v.x) + (v.y * v.y);
    
    return std::sqrt(taille);
}

Vector2f Normalize(const Vector2f& v) {
    const float len = Length(v);
    if (len <= 1e-6f) return Vector2f{0.0f, 0.0f};
    return Scale(v, 1.0f / len);
}

Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t) {
    return Add(a, Scale(Sub(b, a), t));
}

float Determinant(const Vector2f& a, const Vector2f& b) {
    return a.x * b.y - a.y * b.x;
}

std::string ToString(const Vector2f& v){
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(3);
    oss << "< " << v.x << ", " << v.y << " >";
    return oss.str();
}