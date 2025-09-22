#include <iostream>
using namespace std;

class Point2D {
public:
    double x, y;
    Point2D(double px = 0, double py = 0) : x(px), y(py) {}
};

class Vector {
    double x, y;
public:
    Vector(const Point2D& a, const Point2D& b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }
    Vector(double px = 0, double py = 0) : x(px), y(py) {}
    Vector operator+(const Vector& v) const {
        return Vector(x + v.x, y + v.y);
    }
    Vector operator*(double r) const {
        return Vector(x * r, y * r);
    }
    bool operator==(const Vector& v) const {
        return (x == v.x && y == v.y);
    }
    void display() const {
        cout << "(" << x << "," << y << ")";
    }
};
