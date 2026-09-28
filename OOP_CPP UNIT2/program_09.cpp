#include <iostream>     // Provides std::cout
#include <string>       // Provides std::string
#include <utility>      // Provides std::move()

// Base class
class Person {

protected:
    std::string name;   // Stores name

public:

    // Parameterized constructor
    explicit Person(std::string personName)
        : name(std::move(personName))
    {
        // Initializes name
    }

    // Function to display name
    void showName() const
    {
        std::cout << "Name: " << name << '\n';
    }
};

// Derived class
class Student : public Person {

private:
    int rollNumber;     // Stores roll number

public:

    // Parameterized constructor of derived class
    Student(std::string studentName, int roll)
        : Person(std::move(studentName)),
          rollNumber(roll)
    {
        // First:
        // Person constructor is called

        // Second:
        // rollNumber is initialized
    }

    // Displays complete student information
    void show() const
    {
        showName();

        std::cout << "Roll Number: "
                  << rollNumber << '\n';
    }
};

int main()
{
    // Passes values to Student constructor
    Student student("Rahul", 102);

    // Displays student information
    student.show();

    return 0;
}