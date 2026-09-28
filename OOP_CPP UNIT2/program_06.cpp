#include <iostream>     // Provides std::cout

// First base class
class Academic {

protected:
    int academicMarks;  // Stores academic marks

public:

    // Constructor
    explicit Academic(int marks)
        : academicMarks(marks)
    {
    }

    // Displays academic marks
    void showAcademic() const
    {
        std::cout << "Academic Marks: "
                  << academicMarks << '\n';
    }
};

// Second base class
class Sports {

protected:
    int sportsMarks;    // Stores sports marks

public:

    // Constructor
    explicit Sports(int marks)
        : sportsMarks(marks)
    {
    }

    // Displays sports marks
    void showSports() const
    {
        std::cout << "Sports Marks: "
                  << sportsMarks << '\n';
    }
};

// Student inherits from TWO classes
class Student : public Academic, public Sports {

public:

    // Student constructor
    Student(int academic, int sports)
        : Academic(academic),
          Sports(sports)
    {
        // Initializes Academic base
        // Initializes Sports base
    }

    // Calculates and displays total marks
    void showTotal() const
    {
        std::cout << "Total Marks: "
                  << academicMarks + sportsMarks
                  << '\n';
    }
};

int main()
{
    // Creates Student object
    Student student(80, 15);

    // Displays academic marks
    student.showAcademic();

    // Displays sports marks
    student.showSports();

    // Displays total marks
    student.showTotal();

    return 0;
}