#include <iostream>     // Provides std::cout

// Base class
class Base {

public:

    // Base constructor
    Base()
    {
        std::cout << "Base constructor\n";
    }

    // Base destructor
    ~Base()
    {
        std::cout << "Base destructor\n";
    }
};

// Derived class
class Derived : public Base {

public:

    // Derived constructor
    Derived()
    {
        std::cout << "Derived constructor\n";
    }

    // Derived destructor
    ~Derived()
    {
        std::cout << "Derived destructor\n";
    }
};

int main()
{
    {
        // Creates Derived object
        Derived object;

        // Base constructor executes first
        // Derived constructor executes second
    }

    // Object goes out of scope here

    // Derived destructor executes first
    // Base destructor executes second

    return 0;
}