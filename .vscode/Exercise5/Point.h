#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
private:
    int x, y;

public:
    // Default constructor with default values for x and y
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // Getter for x-coordinate
    int getX() const {
        return x;
    }

    // Getter for y-coordinate
    int getY() const {
        return y;
    }

    // Function to print the point coordinates in the format "(x, y)"
    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

#endif // POINT_H

