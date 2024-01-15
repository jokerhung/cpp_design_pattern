// Apdater.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

typedef int Coordinate;
typedef int Dimension;

class Rectangele {
public:
    virtual void draw() = 0;
};

class LegacyRectangle {
public:
    LegacyRectangle(Coordinate x1, Coordinate x2, Coordinate y1, Coordinate y2) {
        _x1 = x1;
        _y1 = y1;
        _x2 = x2;
        _y2 = y2;

        std::cout << "LegacyRectangle:  create.  (" << _x1 << "," << _y1 << ") => ("
            << _x2 << "," << _y2 << ")" << std::endl;
    }

    void oldDraw() {
        std::cout << "LegacyRectangle:  oldDraw.  (" << _x1 << "," << _y1 << ") => ("
            << _x2 << "," << _y2 << ")" << std::endl;
    }
private:
    Coordinate _x1;
    Coordinate _y1;
    Coordinate _x2;
    Coordinate _y2;
};

class RectangeApdater : public Rectangele, private LegacyRectangle {
public:
    RectangeApdater(Coordinate x, Coordinate y, Dimension w, Dimension h) :LegacyRectangle(x, y, x + w, y + h) {
        std::cout << "RectangleAdapter: create.  (" << x << "," << y <<
            "), width = " << w << ", height = " << h << std::endl;
    }

    virtual void draw() {
        std::cout << "RectangleAdapter: draw." << std::endl;
        oldDraw();
    }
};

int main()
{
    Rectangele* r = new RectangeApdater(120, 200, 60, 40);
    r->draw();

    delete r;
}
