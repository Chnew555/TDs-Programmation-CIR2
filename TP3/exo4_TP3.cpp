#include <vector>
#include <cmath>

class Polygon {
    vector<Point2D> points;
public:
    Polygon(const vector<Point2D>& pts) : points(pts) {}

    double area() const {
        double sum = 0;
        int n = points.size();
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n; 
            sum += points[i].x * points[j].y - points[j].x * points[i].y;
        }
        return fabs(sum) / 2.0;
    }
};
int main() {
    // Triangle (points (0,0), (1,0), (0,1)) => aire = 0.5
    vector<Point2D> tri = { Point2D(0,0), Point2D(1,0), Point2D(0,1) };
    Polygon triangle(tri);
    cout << "Aire du triangle = " << triangle.area() << endl;

    // Carré (points (0,0), (2,0), (2,2), (0,2)) => aire = 4
    vector<Point2D> sq = { Point2D(0,0), Point2D(2,0), Point2D(2,2), Point2D(0,2) };
    Polygon carre(sq);
    cout << "Aire du carre = " << carre.area() << endl;

    // Rectangle (points (0,0), (3,0), (3,2), (0,2)) => aire = 6
    vector<Point2D> rect = { Point2D(0,0), Point2D(3,0), Point2D(3,2), Point2D(0,2) };
    Polygon rectangle(rect);
    cout << "Aire du rectangle = " << rectangle.area() << endl;
    return 0;
}
