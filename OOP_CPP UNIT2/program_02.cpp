#include <iostream>     // Provides std::cout
#include <string>       // Provides std::string
#include <utility>      // Provides std::move()

// Base class
class Employee {

protected:
    std::string name;   // Protected member
                        // Accessible inside Employee and Developer

public:

    // Employee constructor
    explicit Employee(std::string employeeName)
        : name(std::move(employeeName))
    {
        // Initializes name with employeeName
    }
};

// Derived class
class Developer : public Employee {

private:
    std::string language;    // Stores programming language

public:

    // Developer constructor
    Developer(std::string employeeName,
              std::string programmingLanguage)
        : Employee(std::move(employeeName)),
          language(std::move(programmingLanguage))
    {
        // Calls Employee constructor
        // Initializes language
    }

    // Function to display details
    void display() const
    {
        // name is inherited from Employee
        // It can be accessed because name is protected
        std::cout << "Developer: " << name << '\n';

        // Displays programming language
        std::cout << "Language: " << language << '\n';
    }
};

// Main function
int main()
{
    // Creates Developer object
    Developer developer("Neha", "C++");

    // Calls display()
    developer.display();

    return 0;    // Successful program termination
}