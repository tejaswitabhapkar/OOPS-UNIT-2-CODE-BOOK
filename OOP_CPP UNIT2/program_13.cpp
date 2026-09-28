#include <iostream>     // Provides std::cout

// Forward declaration of Auditor
class Auditor;

// Account class
class Account {

private:

    double balance;     // Private data member

public:

    // Constructor
    explicit Account(double initialBalance)
        : balance(initialBalance)
    {
    }

    // Auditor is declared as a friend
    friend class Auditor;
};

// Auditor is a friend of Account
class Auditor {

public:

    // Function to inspect Account
    void inspect(const Account& account) const
    {
        // Auditor can access private member balance
        // because Auditor is a friend class
        std::cout << "Balance: "
                  << account.balance
                  << '\n';
    }
};

int main()
{
    // Creates Account object
    Account account(5000.0);

    // Creates Auditor object
    Auditor auditor;

    // Auditor accesses Account's private data
    auditor.inspect(account);

    return 0;
}