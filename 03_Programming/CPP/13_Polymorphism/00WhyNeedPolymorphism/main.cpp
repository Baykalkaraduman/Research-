//==============================================================
// Why Do We Need Polymorphism?
//
// This example demonstrates the problem that polymorphism
// is designed to solve.
//
// We have:
//      Base
//        |
//        └── Derived
//
// Both classes have a function called say_hello().
//
// The important question is:
//
// What happens when a Derived object is accessed through
// a Base reference or Base pointer?
//
// Without virtual functions, C++ uses STATIC binding.
// That means the function is selected based on the
// TYPE OF THE REFERENCE OR POINTER.
//
// Later, polymorphism will allow us to use DYNAMIC binding
// with virtual functions.
//==============================================================

#include <iostream>
#include <memory>


//==============================================================
// Base Class
//==============================================================

class Base {
public:

    // This function belongs to Base.

    // IMPORTANT:
    //
    // It is NOT virtual yet.
    //
    // Therefore, if we access a Derived object through a
    // Base reference or Base pointer, the Base version
    // will be selected.
    void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
};


//==============================================================
// Derived Class
//==============================================================

class Derived : public Base {
public:

    // Derived provides its own version of say_hello().
    //
    // At first glance, it may look like this function
    // "replaces" Base::say_hello().
    //
    // However, without virtual functions, this is NOT
    // runtime polymorphism.
    //
    // The two functions simply have the same name and
    // compatible signatures.

    void say_hello() const {
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
};


//==============================================================
// Function Receiving a Base Reference
//==============================================================

void greetings(const Base &obj) {

    std::cout << "Greetings: ";

    // IMPORTANT:
    //
    // obj has type:
    //
    //     const Base&
    //
    // Even if the object passed to this function is actually
    // a Derived object, say_hello() is selected using the
    // Base type because say_hello() is NOT virtual.
    //
    // Therefore:
    //
    //     greetings(d);
    //
    // will call:
    //
    //     Base::say_hello()
    //
    // instead of:
    //
    //     Derived::say_hello()

    obj.say_hello();
}


//==============================================================
// Main
//==============================================================

int main() {

    //==========================================================
    // Direct Base Object
    //==========================================================

    Base b;

    // The compiler knows exactly what b is:
    //
    //     Base
    //
    // Therefore Base::say_hello() is called.

    b.say_hello();


    //==========================================================
    // Direct Derived Object
    //==========================================================

    Derived d;

    // The compiler knows exactly what d is:
    //
    //     Derived
    //
    // Therefore Derived::say_hello() is called.

    d.say_hello();


    //==========================================================
    // Passing Base Object to greetings()
    //==========================================================

    greetings(b);

    // b is a Base object.
    //
    // greetings() expects:
    //
    //     const Base&
    //
    // So Base::say_hello() is called.
    //
    // Output:
    //
    // Greetings: Hello - I'm a Base class object


    //==========================================================
    // Passing Derived Object to greetings()
    //==========================================================

    greetings(d);

    // THIS IS THE IMPORTANT PART.
    //
    // d is actually a Derived object.
    //
    // However, greetings() receives it as:
    //
    //     const Base&
    //
    // Because say_hello() is NOT virtual, C++ uses
    // STATIC BINDING.
    //
    // Therefore Base::say_hello() is called.
    //
    // We might expect:
    //
    //     Greetings: Hello - I'm a Derived class object
    //
    // but we actually get:
    //
    //     Greetings: Hello - I'm a Base class object
    //
    // This is the problem that polymorphism solves.


    //==========================================================
    // Base Pointer Pointing to Derived Object
    //==========================================================

    Base *ptr = new Derived();

    // This is one of the most important ideas in inheritance:
    //
    // A Base pointer can point to a Derived object.
    //
    // The object in memory is:
    //
    //     Derived
    //
    // but the pointer type is:
    //
    //     Base*
    //
    // This allows us to treat different derived objects
    // through a common Base interface.
    //
    // This is one of the foundations of polymorphism.

    ptr->say_hello();

    // BUT:
    //
    // say_hello() is not virtual.
    //
    // Therefore C++ looks at the pointer type:
    //
    //     Base*
    //
    // and calls:
    //
    //     Base::say_hello()
    //
    // instead of:
    //
    //     Derived::say_hello()
    //
    // Again, this is STATIC BINDING.


    //==========================================================
    // Smart Pointer + Inheritance
    //==========================================================

    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();

    // This is the modern C++ version of:
    //
    //     Base *ptr = new Derived();
    //
    // We create a Derived object but store it inside
    // a unique_ptr<Base>.
    //
    // unique_ptr automatically manages the lifetime
    // of the dynamically allocated object.
    //
    // This means we do NOT need:
    //
    //     delete ptr1;
    //
    // because unique_ptr will take care of it.


    // Again, however, say_hello() is NOT virtual.
    //
    // Therefore the Base implementation is selected.

    ptr1->say_hello();


    //==========================================================
    // Manual Memory Management
    //==========================================================

    // ptr was created using:
    //
    //     new Derived()
    //
    // Therefore we must manually release it.

    delete ptr;

    // ptr1 does NOT need delete.
    //
    // unique_ptr automatically destroys its managed object
    // when ptr1 goes out of scope.


    //==========================================================
    // The Problem
    //==========================================================

    /*
    
    We currently have:

        Base
            |
            └── Derived

    Both classes define:

        say_hello()


    We can do:

        Derived d;
        d.say_hello();

    and correctly get:

        Derived version


    BUT:

        Base *ptr = new Derived();

        ptr->say_hello();

    gives us:

        Base version


    even though the actual object is Derived.


    The same problem happens here:

        greetings(d);


    because greetings() receives:

        const Base&


    Without polymorphism:

        Base reference
              |
              ↓
        Base::say_hello()


    What we actually want is:

        Base reference
              |
              ↓
        "What object are you REALLY referring to?"
              |
              ↓
        Derived::say_hello()


    This is called DYNAMIC BINDING.


    ===========================================================
    POLYMORPHISM WILL SOLVE THIS
    ===========================================================

    In the next step, we will change Base::say_hello() to:

        virtual void say_hello() const;


    and Derived to:

        void say_hello() const override;


    Then:

        Base *ptr = new Derived();

        ptr->say_hello();


    will call:

        Derived::say_hello()


    even though ptr has type:

        Base*


    Similarly:

        greetings(d);


    will call:

        Derived::say_hello()


    This is runtime polymorphism.

    ===========================================================
    */

    return 0;
}