#include <iostream>

using namespace std;

// ============================================================
// Base Class
// ============================================================
//
// Access levels:
//
// public:
//     Accessible from:
//         - Base class itself
//         - Derived classes
//         - Outside code
//
// protected:
//     Accessible from:
//         - Base class itself
//         - Derived classes
//         - NOT from outside code
//
// private:
//     Accessible from:
//         - Base class itself
//         - NOT directly from derived classes
//         - NOT from outside code
//
// ============================================================

class Base {

public:

    // --------------------------------------------------------
    // PUBLIC MEMBER
    // --------------------------------------------------------
    //
    // 'a' is public.
    //
    // Therefore it can be accessed:
    //
    //     Base object
    //     Derived object
    //     Base member functions
    //     Derived member functions
    //
    int a{0};


    // --------------------------------------------------------
    // PUBLIC MEMBER FUNCTION
    // --------------------------------------------------------
    //
    // A public member function can be called from outside
    // the class.
    //
    // IMPORTANT:
    //
    // This function is inside Base, therefore it can access
    // ALL Base members, including protected and private members.
    //
    void display() {

        std::cout << "a = " << a
                  << ", b = " << b
                  << ", c = " << c
                  << std::endl;
    }


protected:

    // --------------------------------------------------------
    // PROTECTED MEMBER
    // --------------------------------------------------------
    //
    // 'b' is protected.
    //
    // It can be accessed:
    //
    //     Base itself       -> YES
    //     Derived class     -> YES
    //     Outside code     -> NO
    //
    // This is one of the main purposes of 'protected':
    //
    //     "Give derived classes access,
    //      but hide the member from normal outside access."
    //
    int b{0};


private:

    // --------------------------------------------------------
    // PRIVATE MEMBER
    // --------------------------------------------------------
    //
    // 'c' is private.
    //
    // It can be accessed directly only inside Base.
    //
    // Even though Derived inherits from Base,
    // Derived CANNOT directly access c.
    //
    int c{0};
};


// ============================================================
// Derived Class
// ============================================================
//
// Syntax:
//
//     class Derived : public Base
//
// This means:
//
//     Derived IS-A Base
//
// and public/protected inheritance preserves the access
// relationship for inherited members:
//
//     Base public     -> Derived public
//     Base protected  -> Derived protected
//     Base private    -> not directly accessible in Derived
//
// ============================================================

class Derived : public Base {

public:

    // --------------------------------------------------------
    // ACCESSING BASE MEMBERS FROM DERIVED
    // --------------------------------------------------------
    //
    // This function belongs to Derived.
    //
    // Because Derived inherits from Base,
    // it can directly access Base's public and protected
    // members.
    //
    void access_base_members() {

        // ----------------------------------------------------
        // Base::a
        // ----------------------------------------------------
        //
        // a is public in Base.
        //
        // Therefore Derived can access it.
        //
        a = 100;


        // ----------------------------------------------------
        // Base::b
        // ----------------------------------------------------
        //
        // b is protected in Base.
        //
        // Derived CAN access protected members.
        //
        b = 200;


        // ----------------------------------------------------
        // Base::c
        // ----------------------------------------------------
        //
        // c is private in Base.
        //
        // Derived CANNOT access it directly.
        //
        // c = 300;     // ERROR
        //
        // If Derived needs access to c,
        // Base would need to provide a public/protected
        // member function such as a getter or setter.
    }
};


// ============================================================
// MAIN
// ============================================================

int main() {

    // ========================================================
    // 1. Accessing Base members from a Base object
    // ========================================================

    cout << "\n=== Base object =============================\n";

    Base base;


    // --------------------------------------------------------
    // PUBLIC MEMBER
    // --------------------------------------------------------
    //
    // a is public.
    //
    // Therefore outside code can access it.
    //
    base.a = 100;

    cout << "base.a = " << base.a << endl;


    // --------------------------------------------------------
    // PROTECTED MEMBER
    // --------------------------------------------------------
    //
    // b is protected.
    //
    // Outside code CANNOT access it.
    //
    // base.b = 200;       // ERROR
    // cout << base.b;     // ERROR
    //
    // protected means:
    //
    //     "Accessible to the class and its derived classes,
    //      but not directly from outside."


    // --------------------------------------------------------
    // PRIVATE MEMBER
    // --------------------------------------------------------
    //
    // c is private.
    //
    // Outside code cannot access it either.
    //
    // base.c = 300;       // ERROR
    // cout << base.c;     // ERROR


    // --------------------------------------------------------
    // But Base itself can access b and c
    // --------------------------------------------------------
    //
    // display() is a Base member function.
    //
    // Therefore display() can access:
    //
    //     a -> public
    //     b -> protected
    //     c -> private
    //
    base.display();


    // ========================================================
    // 2. Accessing inherited members from a Derived object
    // ========================================================

    cout << "\n=== Derived object ==========================\n";

    Derived d;


    // --------------------------------------------------------
    // PUBLIC Base member
    // --------------------------------------------------------
    //
    // a was public in Base.
    //
    // Because we are using public inheritance:
    //
    //     Base::a -> remains public in Derived
    //
    // Therefore outside code can access it.
    //
    d.a = 100;

    cout << "d.a = " << d.a << endl;


    // --------------------------------------------------------
    // PROTECTED Base member
    // --------------------------------------------------------
    //
    // b is inherited as protected.
    //
    // Therefore Derived itself can access b,
    // but main() cannot.
    //
    // d.b = 200;          // ERROR
    //
    // Notice the important distinction:
    //
    //     Derived::access_base_members()
    //
    // CAN access b.
    //
    //     main()
    //
    // CANNOT access b.
    //


    // --------------------------------------------------------
    // PRIVATE Base member
    // --------------------------------------------------------
    //
    // c is private in Base.
    //
    // Derived cannot access it directly,
    // and main() cannot access it either.
    //
    // d.c = 300;          // ERROR


    // ========================================================
    // 3. Let Derived access its inherited members
    // ========================================================
    //
    // This function is public, so main() can call it.
    //
    // Inside the function:
    //
    //     a -> accessible
    //     b -> accessible
    //     c -> NOT accessible
    //
    d.access_base_members();


    // ========================================================
    // 4. Check the result
    // ========================================================

    cout << "\nAfter Derived accessed Base members:\n";

    cout << "d.a = " << d.a << endl;

    // We cannot write:
    //
    // cout << d.b;
    //
    // because b is protected.
    //
    // We also cannot write:
    //
    // cout << d.c;
    //
    // because c is private.


    cout << "\n=============================================\n";

    return 0;
}