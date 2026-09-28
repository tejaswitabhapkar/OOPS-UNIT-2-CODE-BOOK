#include <iostream>     // Provides std::cout
#include <string>       // Provides std::string
#include <utility>      // Provides std::move()

// First-level base class
class Person {

protected:
    std::string name;   // Stores person's name

public:

    // Constructor
    explicit Person(std::string personName)
        : name(std::move(personName))
    {
    }

    // Displays person's name
    void showPerson() const
    {
        std::cout << "Name: " << name << '\n';
    }
};

// Employee inherits from Person
class Employee : public Person {

protected:
    int employeeId;     // Stores employee ID

public:

    // Employee constructor
    Employee(std::string employeeName, int id)
        : Person(std::move(employeeName)),
          employeeId(id)
    {
        // Calls Person constructor
        // Initializes employeeId
    }

    // Displays employee ID
    void showEmployee() const
    {
        std::cout << "Employee ID: " << employeeId << '\n';
    }
};

// Manager inherits from Employee
class Manager : public Employee {

private:
    int teamSize;       // Stores team size

public:

    // Manager constructor
    Manager(std::string managerName, int id, int size)
        : Employee(std::move(managerName), id),
          teamSize(size)
    {
        // Calls Employee constructor
        // Initializes teamSize
    }

    // Displays manager details
    void showManager() const
    {
        showPerson();       // Function inherited from Person
        showEmployee();     // Function inherited from Employee

        std::cout << "Team Size: " << teamSize << '\n';
    }
};

int main()
{
    // Creates Manager object
    Manager manager("Ravi", 501, 8);

    // Displays all manager information
    manager.showManager();

    return 0;
}