#include <iostream>     // Provides std::cout
#include <string>       // Provides std::string
#include <utility>      // Provides std::move()

// Base class
class Vehicle {

protected:
    std::string registrationNumber;
    // Stores vehicle registration number

public:

    // Constructor
    explicit Vehicle(std::string registration)
        : registrationNumber(std::move(registration))
    {
    }

    // Common function inherited by Car and Bike
    void start() const
    {
        std::cout << "Vehicle "
                  << registrationNumber
                  << " started\n";
    }
};

// Car inherits from Vehicle
class Car : public Vehicle {

public:

    // Car constructor
    explicit Car(std::string registration)
        : Vehicle(std::move(registration))
    {
    }

    // Car-specific function
    void openBoot() const
    {
        std::cout << "Car boot opened\n";
    }
};

// Bike inherits from Vehicle
class Bike : public Vehicle {

public:

    // Bike constructor
    explicit Bike(std::string registration)
        : Vehicle(std::move(registration))
    {
    }

    // Bike-specific function
    void helmetReminder() const
    {
        std::cout << "Please wear a helmet\n";
    }
};

int main()
{
    // Creates Car object
    Car car("MH12AB1234");

    // Creates Bike object
    Bike bike("MH12CD5678");

    // Calls inherited function
    car.start();

    // Calls Car-specific function
    car.openBoot();

    // Calls inherited function
    bike.start();

    // Calls Bike-specific function
    bike.helmetReminder();

    return 0;
}