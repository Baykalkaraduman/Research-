/**
 * ============================================================================
 * FILE: override_specifier_example.cpp
 * DESCRIPTION: Demonstrates the crucial role of the 'override' specifier in C++11.
 * It prevents silent bugs that occur when a derived class function accidentally 
 * hides, rather than overrides, a base class virtual function due to slight 
 * signature mismatches (such as missing the 'const' qualifier).
 * ============================================================================
 */

#include <iostream>

/**
 * ============================================================================
 * CLASS: Base
 * The base class defining a virtual interface.
 * ============================================================================
 */
class Base {
public:
    // The 'const' qualifier here is part of the function signature.
    // It guarantees that calling this function will not modify the object's state.
    virtual void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
    
    // Virtual destructor ensuring safe memory cleanup for derived objects.
    virtual ~Base() {}
};

/**
 * ============================================================================
 * CLASS: Derived
 * Inherits from Base and attempts to override the say_hello() function.
 * ============================================================================
 */
class Derived: public Base {
public:
    // The 'override' keyword is a compiler directive. It explicitly tells the 
    // compiler: "I intend to override a virtual function from my Base class."
    // 
    // YOUR NOTE: "// Notice I forgot the const"
    // If you remove 'const' but keep 'override', the compiler will throw an ERROR. 
    // It will say: "say_hello() marked 'override' but does not override any member functions."
    // 
    // Without 'override', forgetting 'const' would compile silently, creating a 
    // NEW function instead of overriding the base one, breaking polymorphism.
    // Since 'const' is present here along with 'override', this is perfectly safe and correct.
    virtual void say_hello() const override {             
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
    
    virtual ~Derived() {}
};

int main() {
    
    // 1. Static binding (essentially). Pointer type and object type are the same.
    Base *p1 = new Base();      // Calls Base::say_hello()
    p1->say_hello();
    
    // 2. Static binding. Pointer type and object type are the same.
    Derived *p2 = new Derived();    // Calls Derived::say_hello()
    p2->say_hello();
    
    /**
     * 3. Dynamic Binding (Polymorphism)
     * YOUR NOTE: "//  Base::say_hello()   ?????   I wanted Derived::say_hello()"
     * 
     * Explanation of your note: 
     * If you had actually forgotten the 'const' in the Derived class (without using 'override'),
     * this pointer 'p3' would have called Base::say_hello() because the signatures wouldn't match.
     * The compiler would not link them dynamically.
     * 
     * However, in this current code, because you HAVE 'const' and 'override', 
     * the signature matches perfectly. Therefore, dynamic binding succeeds, 
     * and this WILL correctly print: "Hello - I'm a Derived class object".
     */
    Base *p3 = new Derived();   
    p3->say_hello();
    
    // Memory cleanup (Best practice, even in small examples)
    delete p1;
    delete p2;
    delete p3;
   
    return 0;
}