#include <iostream>     // Provides std::cout

// Base class
class Animal {

public:

    // Function of base class
    void sound() const
    {
        std::cout << "Animal makes a sound\n";
    }
};

// Derived class
class Dog : public Animal {

public:

    // Function with the same name
    // This hides the base-class function
    void sound() const
    {
        std::cout << "Dog barks\n";
    }
};

int main()
{
    // Creates Dog object
    Dog dog;

    // Calls Dog's version of sound()
    dog.sound();

    return 0;
}