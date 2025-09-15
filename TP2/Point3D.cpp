#include "Point3D.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <random>
using namespace std;

// Constructeur par défaut (valeurs aléatoires)
Point3D::Point3D() {
    // Initialisation du générateur de nombres aléatoires
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<float> dis(0.0f, 100.0f);

    x = dis(gen);
    y = dis(gen);
    z = dis(gen);
}

// Constructeur avec paramètres
Point3D::Point3D(const float& newx, const float& newy, const float& newz) {
    x = newx;
    y = newy;
    z = newz;
}

// Setters
void Point3D::setXYZ(const float& newx, const float& newy, const float& newz) {
    x = newx;
    y = newy;
    z = newz;
}

void Point3D::setX(const float& newx) {
    x = newx;
}

void Point3D::setY(const float& newy) {
    y = newy;
}

void Point3D::setZ(const float& newz) {
    z = newz;
}

// Getters
float Point3D::getX() {
    return x;
}

float Point3D::getY() {
    return y;
}

float Point3D::getZ() {
    return z;
}

// Affichage des coordonnées
void Point3D::print() {
    cout << "Point3D(" << x << ", " << y << ", " << z << ")" << endl;
}

// Calcul de la distance entre deux points 3D
float Point3D::distanceTo(const Point3D& otherPoint3D) {
    float dx = x - otherPoint3D.x;
    float dy = y - otherPoint3D.y;
    float dz = z - otherPoint3D.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}