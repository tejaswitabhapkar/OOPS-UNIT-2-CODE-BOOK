#include <iostream>     // Provides std::cout

// Base class
class Base {

public:

    // Public function of Base
    void show() const
    {
        std::cout << "Base public function\n";
    }
};

// Public inheritance
class PublicDerived : public Base
{
    // show() remains public
};

// Private inheritance
class PrivateDerived : private Base {

public:

    // Public function of PrivateDerived
    void callBaseShow() const
    {
        show();
        // show() becomes private through private inheritance
        // But it can still be called inside PrivateDerived
    }
};

int main()
{
    // Object of PublicDerived
    PublicDerived publicObject;

    // Allowed because show() remains public
    publicObject.show();

    // Object of PrivateDerived
    PrivateDerived privateObject;

    // Calls the wrapper function
    privateObject.callBaseShow();

    // This would produce an error:
    // privateObject.show();
    // show() is private through private inheritance

    return 0;
}