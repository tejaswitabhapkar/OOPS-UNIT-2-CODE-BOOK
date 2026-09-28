#include <iostream>     // Provides std::cout

// First base class
class Parent1 {

public:

    // Function named show()
    void show() const
    {
        std::cout << "Parent1 show()\n";
    }
};

// Second base class
class Parent2 {

public:

    // Another function with the SAME name
    void show() const
    {
        std::cout << "Parent2 show()\n";
    }
};

// Child inherits from both Parent1 and Parent2
class Child : public Parent1, public Parent2 {

public:

    // Function to demonstrate ambiguity resolution
    void demonstrate() const
    {
        // Parent1::show()
        // :: is the scope resolution operator
        // It specifically selects show() from Parent1
        Parent1::show();

        // Parent2::show()
        // Specifically selects show() from Parent2
        Parent2::show();
    }
};

int main()
{
    // Creates Child object
    Child child;

    // Calls demonstrate()
    child.demonstrate();

    return 0;
}