#include <iostream>     // Provides std::cout

// Abstract base class
class Shape {

public:

    // Pure virtual function
    virtual double area() const = 0;

    // virtual means derived classes can provide their own implementation
    // = 0 makes this function pure virtual

    // Virtual destructor
    virtual ~Shape() = default;
};

// Circle derives from Shape
class Circle : public Shape {

private:
    double radius;      // Stores radius

public:

    // Constructor
    explicit Circle(double r)
        : radius(r)
    {
    }

    // Provides implementation of pure virtual function
    double area() const override
    {
        return 3.14159 * radius * radius;
    }
};

int main()
{
    // Creates Circle object
    Circle circle(5.0);

    // Calls Circle's area()
    std::cout << "Area: "
              << circle.area()
              << '\n';

    return 0;
}