#include <iostream>     // Provides std::cout
#include <string>       // Provides std::string
#include <utility>      // Provides std::move()

// Base class
class Employee {

protected:

    std::string name;   // Stores employee name

public:

    // Constructor
    explicit Employee(std::string employeeName)
        : name(std::move(employeeName))
    {
    }

    // Virtual destructor
    virtual ~Employee() = default;

    // Pure virtual function
    virtual double calculatePay() const = 0;

    // Pure virtual function
    // Every derived class must implement calculatePay()
};

// SalariedEmployee inherits from Employee
class SalariedEmployee : public Employee {

private:

    double monthlySalary;   // Stores monthly salary

public:

    // Constructor
    SalariedEmployee(std::string employeeName,
                     double salary)
        : Employee(std::move(employeeName)),
          monthlySalary(salary)
    {
    }

    // Implements calculatePay()
    double calculatePay() const override
    {
        // For a salaried employee,
        // monthly salary is the pay
        return monthlySalary;
    }

    // Displays salary information
    void display() const
    {
        std::cout << "Employee: "
                  << name << '\n';

        std::cout << "Monthly Salary: "
                  << calculatePay()
                  << '\n';
    }
};

// HourlyEmployee inherits from Employee
class HourlyEmployee : public Employee {

private:

    double hourlyRate;     // Pay per hour
    int hoursWorked;       // Number of hours worked

public:

    // Constructor
    HourlyEmployee(std::string employeeName,
                   double rate,
                   int hours)
        : Employee(std::move(employeeName)),
          hourlyRate(rate),
          hoursWorked(hours)
    {
    }

    // Implements calculatePay()
    double calculatePay() const override
    {
        // Hourly pay = hourly rate × hours worked
        return hourlyRate * hoursWorked;
    }

    // Displays salary information
    void display() const
    {
        std::cout << "Employee: "
                  << name << '\n';

        std::cout << "Hourly Pay: "
                  << calculatePay()
                  << '\n';
    }
};

int main()
{
    // Creates salaried employee
    SalariedEmployee salaried(
        "Priya",
        50000
    );

    // Creates hourly employee
    HourlyEmployee hourly(
        "Arjun",
        300,
        160
    );

    // Displays salaried employee details
    salaried.display();

    // Displays hourly employee details
    hourly.display();

    return 0;
}