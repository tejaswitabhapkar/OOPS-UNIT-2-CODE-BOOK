 #include <iostream>     // Provides input/output functions such as std::cout
#include <string>       // Provides the std::string data type
#include <utility>      // Provides std::move()

// Person is the BASE CLASS
class Person {

protected:
    std::string name;   // Stores the person's name
                        // protected means derived classes can access it

public:

    // Constructor of Person
    explicit Person(std::string personName)
        : name(std::move(personName))
    {
        // personName is passed to the constructor
        // std::move(personName) transfers the string value
        // name is initialized with that value
    }

    // Function to display the name
    void displayName() const
    {
        std::cout << "Name: " << name << '\n';
        // std::cout  -> displays output
        // "Name: "    -> text displayed
        // << name     -> displays the value of name
        // '\n'        -> moves to the next line
    }
};

// Student is the DERIVED CLASS
// public Person means Student inherits publicly from Person
class Student : public Person {

private:
    int rollNumber;     // Stores student's roll number
                        // private means only Student can directly access it

public:

    // Constructor of Student
    Student(std::string studentName, int roll)
        : Person(std::move(studentName)), rollNumber(roll)
    {
        // Person(std::move(studentName))
        // calls the constructor of the base class Person

        // rollNumber(roll)
        // initializes rollNumber with roll
    }

    // Function to display student information
    void displayStudent() const
    {
        displayName();
        // Calls the displayName() function inherited from Person

        std::cout << "Roll Number: " << rollNumber << '\n';
        // Displays the student's roll number
    }
};

// Program execution starts from main()
int main()
{
    // Creates a Student object
    // "Amit" is passed as studentName
    // 101 is passed as roll
    Student student("Amit", 101);

    // Calls the displayStudent() function
    student.displayStudent();

    // Indicates successful completion of the program
    return 0;
}