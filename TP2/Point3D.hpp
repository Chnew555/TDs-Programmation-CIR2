#ifndef POINT3D_H
#define POINT3D_H

class Point3D {
private:
    float x, y, z;

public:
    // Constructeurs
    Point3D();
    Point3D(const float& newx, const float& newy, const float& newz);

    // Setters et getters
    void setXYZ(const float& newx, const float& newy, const float& newz);
    void setX(const float& newx);
    void setY(const float& newy);
    void setZ(const float& newz);
    float getX();
    float getY();
    float getZ();

    // Autres méthodes
    void print();
    float distanceTo(const Point3D& otherPoint3D);
};

#endif