 #include <iostream>     // Provides std::cout
#include <string>       // Provides std::string
#include <utility>      // Provides std::move()

// Common base class
class Person {

protected:
    std::string name;   // Stores person's name

public:

    // Constructor
    explicit Person(std::string personName)
        : name(std::move(personName))
    {
    }

    // Displays name
    void showName() const
    {
        std::cout << "Name: " << name << '\n';
    }
};

// Student virtually inherits Person
class Student : virtual public Person {

public:

    // Constructor
    explicit Student(std::string studentName)
        : Person(std::move(studentName))
    {
    }
};

// Employee virtually inherits Person
class Employee : virtual public Person {

public:

    // Constructor
    explicit Employee(std::string employeeName)
        : Person(std::move(employeeName))
    {
    }
};

// Manager inherits from Student and Employee
class Manager : public Student, public Employee {

public:

    // Manager must initialize the virtual base Person
    explicit Manager(std::string managerName)
        : Person(managerName),
          Student(managerName),
          Employee(managerName)
    {
    }

    // Displays manager information
    void show() const
    {
        // Only one Person object exists
        showName();
    }
};

int main()
{
    // Creates Manager object
    Manager manager("Kiran");

    // Displays name
    manager.show();

    return 0;
}