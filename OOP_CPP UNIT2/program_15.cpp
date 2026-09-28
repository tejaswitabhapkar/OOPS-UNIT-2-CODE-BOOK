#include <iostream>     // Provides std::cout
#include <string>       // Provides std::string
#include <utility>      // Provides std::move()

// Base class
class Vehicle {

protected:

    std::string number;     // Vehicle registration number
    double rentPerDay;     // Rental cost per day

public:

    // Constructor
    Vehicle(std::string vehicleNumber, double rent)
        : number(std::move(vehicleNumber)),
          rentPerDay(rent)
    {
    }

    // Virtual destructor
    virtual ~Vehicle() = default;

    // Function to calculate rental cost
    virtual double calculateRent(int days) const
    {
        return rentPerDay * days;
        // Daily rent × number of days
    }

    // Function to display vehicle information
    virtual void display() const
    {
        std::cout << "Vehicle Number: "
                  << number << '\n';

        std::cout << "Rent Per Day: "
                  << rentPerDay << '\n';
    }
};

// Car class inherits from Vehicle
class Car : public Vehicle {

public:

    // Constructor
    Car(std::string vehicleNumber, double rent)
        : Vehicle(std::move(vehicleNumber), rent)
    {
    }

    // Overrides display()
    void display() const override
    {
        std::cout << "Vehicle Type: Car\n";

        // Calls base-class display()
        Vehicle::display();
    }
};

// Bike class inherits from Vehicle
class Bike : public Vehicle {

public:

    // Constructor
    Bike(std::string vehicleNumber, double rent)
        : Vehicle(std::move(vehicleNumber), rent)
    {
    }

    // Overrides display()
    void display() const override
    {
        std::cout << "Vehicle Type: Bike\n";

        // Calls base-class display()
        Vehicle::display();
    }
};

int main()
{
    // Creates Car object
    Car car("MH12AB1234", 1500);

    // Creates Bike object
    Bike bike("MH12CD5678", 500);

    // Displays car details
    car.display();

    // Calculates car rent for 3 days
    std::cout << "Car Rent for 3 Days: "
              << car.calculateRent(3)
              << '\n';

    // Displays bike details
    bike.display();

    // Calculates bike rent for 3 days
    std::cout << "Bike Rent for 3 Days: "
              << bike.calculateRent(3)
              << '\n';

    return 0;
}