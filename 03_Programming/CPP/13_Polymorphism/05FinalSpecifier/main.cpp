/**
 * ============================================================================
 * FILE: polymorphism_final_references.cpp
 * DESCRIPTION: 
 * Demonstrates dynamic polymorphism using pointers and references in C++.
 * It also highlights the 'final' specifier, which prevents further overriding
 * of virtual functions in downstream derived classes.
 * ============================================================================
 */

#include <iostream>

// Using standard namespace (Note: generally avoided in large projects to prevent name clashes)
using namespace std;

/**
 * ============================================================================
 * CLASS: Base
 * Represents the root of the polymorphic hierarchy.
 * ============================================================================
 */
class Base {
public:
    // Virtual function enables late binding. 
    // The 'const' qualifier ensures this method does not modify object state.
    virtual void say_hello() const {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
    
    // Note: In a strict real-world scenario, a virtual destructor should be 
    // added here to prevent memory leaks when deleting derived objects.
};

/**
 * ============================================================================
 * CLASS: Derived
 * Inherits from Base and provides a specialized implementation of say_hello().
 * ============================================================================
 */
class Derived: public Base {
public:
    // 'override' ensures compile-time signature matching with Base::say_hello().
    // 'final' tells the compiler that no class deriving from 'Derived' can 
    // override this specific function anymore. It provides architectural safety 
    // and enables devirtualization optimizations.
    virtual void say_hello() const override final {       
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
};

/**
 * ============================================================================
 * CLASS: Another (Commented Out for Compilation)
 * Demonstrates the compile-time error caused by the 'final' specifier.
 * ============================================================================
 */
/*          
// Gives Error Because it tries to override a final method from the parent class
class Another: public Derived {
public:
    // ERROR: cannot override 'final' function 'say_hello' from 'Derived'
    virtual void say_hello()  const override  {       
        std::cout << "Hello - I'm a Another class object" << std::endl;
    }
};
*/

/**
 * ============================================================================
 * FUNCTION: greetings
 * Demonstrates polymorphic behavior using C++ References instead of Pointers.
 * Taking 'Base' by reference (&) ensures no object slicing occurs and dynamic 
 * binding is perfectly preserved.
 * ============================================================================
 */
void greetings(const Base &obj) {
    std::cout << "Greetings: " ;
    // Late binding executes here based on the ACTUAL object type passed in.
    obj.say_hello();
}

// Redundant namespace declaration (kept exactly as in the original code)
using namespace std;

int main() {
    
    // =========================================================
    // 1. STATIC BINDING (Direct Object Instantiation)
    // =========================================================
    Base b;
    b.say_hello();                      // Compiles and runs as Base::say_hello()
    
    Derived d;                          
    d.say_hello();                      // Compiles and runs as Derived::say_hello()
    
    // =========================================================
    // 2. POINTERS AND POLYMORPHISM
    // =========================================================
    
    // Base pointer pointing to an actual Base object in memory
    Base *p1 = new Base();      
    p1->say_hello();                    // Resolves to Base::say_hello()
    
    // Derived pointer pointing to an actual Derived object in memory
    Derived *p2 = new Derived();    
    p2->say_hello();                    // Resolves to Derived::say_hello()
    
    // =========================================================
    // 3. DYNAMIC BINDING (Late Binding via V-Table)
    // =========================================================
    // Base pointer pointing to a Derived object.
    // User Note: //  Base::say_hello()   ?????   IMPORTANT !!!
    // Clarification: Because say_hello() is 'virtual', C++ ignores the pointer 
    // type (Base*) and looks at the ACTUAL object type in memory (Derived).
    // Therefore, this will dynamically bind to Derived::say_hello().
    Base *p3 = new Derived();   
    p3->say_hello();                    // Resolves to Derived::say_hello()
    
    std::cout <<  "\n========================" << std::endl;
    
    // =========================================================
    // 4. POLYMORPHISM VIA REFERENCES
    // =========================================================
    // Passing concrete objects and dereferenced pointers into a function 
    // expecting a Base class reference (const Base &obj).
    
    greetings(b);       // Outputs Base
    greetings(d);       // Outputs Derived
    
    greetings(*p1);     // Dereferences p1 -> Outputs Base
    greetings(*p2);     // Dereferences p2 -> Outputs Derived
    
    // Dereferences p3. The reference correctly identifies the underlying
    // object as 'Derived' and dynamically binds to Derived::say_hello().
    greetings(*p3);     // Outputs Derived
    
    // Note: To prevent memory leaks, delete p1, delete p2, and delete p3 
    // should ideally be called here before exiting main.

    return 0;
}