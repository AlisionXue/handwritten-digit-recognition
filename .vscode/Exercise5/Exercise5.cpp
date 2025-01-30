#include "Point.h"
#include <iostream>
#include <cmath> // For sqrt() and pow()

using namespace std;
class point;

Point midpoint(Point p1, Point p2) {
    Point mid((p1.getX() + p2.getX()) / 2, (p1.getY() + p2.getY()) / 2);
    return mid;
}

double distance(Point p1, Point p2) {
    int dx = p2.getX() - p1.getX();
    int dy = p2.getY() - p1.getY();
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int x1, y1, x2, y2;
    cout << "Enter x and y coordinates for point p: ";
    cin >> x1 >> y1;
    cout << "Enter x and y coordinates for point q: ";
    cin >> x2 >> y2;

    Point p(x1, y1);
    Point q(x2, y2);

    p.print();
    q.print();

    Point midP = midpoint(p, q);
    cout << "The midpoint of ";
    p.print();
    cout << " and ";
    q.print();
    cout << " is ";
    midP.print();

    cout << "Distance: " << distance(p, q) << endl;
    return 0;
}
