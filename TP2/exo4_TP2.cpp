#include "Point3D.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Initialisation pour l'affichage des floats
    cout << fixed << setprecision(2);

    cout << "=== TEST DE LA CLASSE Point3D ===" << endl << endl;

    // Test du constructeur par défaut (valeurs aléatoires)
    cout << "1. Constructeur par defaut :" << endl;
    Point3D p1;
    p1.print();
    cout << endl;

    // Test du constructeur avec paramètres
    cout << "2. Constructeur avec parametres :" << endl;
    Point3D p2(1.0f, 2.0f, 3.0f);
    p2.print();
    cout << endl;

    // Test des setters et getters
    cout << "3. Test des setters et getters :" << endl;
    Point3D p3;
    p3.setXYZ(10.5f, 20.3f, 30.7f);
    cout << "Apres setXYZ(10.5, 20.3, 30.7): ";
    p3.print();

    p3.setX(5.0f);
    p3.setY(15.0f);
    p3.setZ(25.0f);
    cout << "Apres setX(5.0), setY(15.0), setZ(25.0): ";
    p3.print();

    cout << "getX() = " << p3.getX() << endl;
    cout << "getY() = " << p3.getY() << endl;
    cout << "getZ() = " << p3.getZ() << endl;
    cout << endl;

    // Test de la distance entre points
    cout << "4. Calcul de distance entre points :" << endl;
    Point3D pointA(0.0f, 0.0f, 0.0f);
    Point3D pointB(1.0f, 1.0f, 1.0f);
    Point3D pointC(3.0f, 4.0f, 0.0f);

    cout << "Point A: ";
    pointA.print();
    cout << "Point B: ";
    pointB.print();
    cout << "Distance A-B: " << pointA.distanceTo(pointB) << endl;

    cout << "Point C: ";
    pointC.print();
    cout << "Distance A-C: " << pointA.distanceTo(pointC) << endl;
    cout << "Distance B-C: " << pointB.distanceTo(pointC) << endl;
    cout << endl;

    // Test avec plusieurs points aléatoires
    cout << "5. Test avec points aleatoires :" << endl;
    Point3D points[3];

    for (int i = 0; i < 3; i++) {
        cout << "Point " << i + 1 << ": ";
        points[i].print();
    }

    // Calcul des distances entre points aléatoires
    cout << "Distances entre points aleatoires:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            cout << "Distance entre point " << i + 1 << " et point " << j + 1 << ": "
                << points[i].distanceTo(points[j]) << endl;
        }
    }

    return 0;
}