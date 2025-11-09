#include "point.h"
#include "vector.h"
#include <cmath>
#include <sstream>
#include <iomanip>
#include <iostream>

const float PI = 3.14159265358979323846f;

Point2f MakeP2f(float x, float y){
    Point2f p{ x, y };

    return p;
}

Point2f Translate(const Point2f& p, float dx, float dy){
    return Point2f{ p.x + dx, p.y + dy };
}

Point2f Translate(const Point2f& p, const Vector2f& v){
    return Point2f{ p.x + v.x, p.y + v.y };
}

Point2f Scale(const Point2f& p, float sx, float sy){
    return Point2f{ p.x * sx, p.y * sy};
}

Point2f Scale(const Point2f& p, const Vector2f& s){
    return Point2f{ p.x * s.x, p.y * s.y };
}

Point2f Rotate(const Point2f& p, float angleDegree) {
    const float rad = angleDegree * PI / 180.0f;
    const float c = std::cos(rad);
    const float s = std::sin(rad);
    return Point2f{ p.x * c - p.y * s, p.x * s + p.y * c };
}

std::string ToString(const Point2f& p){
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(3);
    oss << "Point2f(" << p.x << ", " << p.y << ")";
    return oss.str();
}