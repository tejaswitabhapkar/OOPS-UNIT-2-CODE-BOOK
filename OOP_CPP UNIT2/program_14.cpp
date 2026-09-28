#include <iostream>     // Provides std::cout
#include <string>       // Provides std::string
#include <utility>      // Provides std::move()

// Outer class
class University {

private:

    std::string name;   // Stores university name

public:

    // Constructor of University
    explicit University(std::string universityName)
        : name(std::move(universityName))
    {
    }

    // Nested class
    class Department {

    private:

        std::string departmentName;
        // Stores department name

    public:

        // Constructor of Department
        explicit Department(std::string deptName)
            : departmentName(std::move(deptName))
        {
        }

        // Displays department
        void show() const
        {
            std::cout << "Department: "
                      << departmentName
                      << '\n';
        }
    };

    // Function to display university name
    void show() const
    {
        std::cout << "University: "
                  << name
                  << '\n';
    }
};

int main()
{
    // Creates University object
    University university("ABC University");

    // Displays university name
    university.show();

    // Creates object of nested class
    University::Department department("Computer Science");

    // Displays department
    department.show();

    return 0;
}