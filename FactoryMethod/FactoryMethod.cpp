// FactoryMethod.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

enum ShapeType {SQUARE, CIRCLE};

class Shape {
public:
    virtual float getArea(int x) = 0;
};

class Square : public Shape {
public:
    float getArea(int x) override {
        return (x * x);
    }
};

class Circle : public Shape {
public:
    float getArea(int x) override {
        return (x * x * 3.14);
    }
};

class ShapeFactory {
public:
    Shape* createShape(ShapeType type) {
        if (type == SQUARE) {
            return new Square();
        } else if (type == CIRCLE) {
            return new Circle();
        }
        else {
            return NULL;
        }
    }
};

int main()
{
    ShapeFactory shapeFactory;
    Shape* shapeCircle = shapeFactory.createShape(CIRCLE);
    std::cout << "Get circle area : " << shapeCircle->getArea(10) << "\n";

    Shape* shapeSquare = shapeFactory.createShape(SQUARE);
    std::cout << "Get square area : " << shapeSquare->getArea(10) << "\n";

    delete shapeCircle;
    delete shapeSquare;
}
