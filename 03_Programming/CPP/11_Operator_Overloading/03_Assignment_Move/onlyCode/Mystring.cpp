#include <iostream>
#include <cstring>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring()
    : str{nullptr} {
        str = new char[1];
        *str = '\0';
    }

// Overloaded Constrcutor
Mystring::Mystring(const char* s) 
    : str{nullptr} {
        if(s == nullptr) {
            str = new char[1];
            *str = '\0';
        } else {
            str = new char[std::strlen(s) +1];
            std::strcpy(str, s);
        }
    }

// Copy Constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[std::strlen(source.str) +1];
        std::strcpy(str, source.str);
        std::cout << "Copy Constructor worked\n";
    }

// Move Constructor
Mystring::Mystring(Mystring &&source)
    : str{source.str} {
        source.str = nullptr;
        std::cout << "Move Constructor worked\n";
    }

// Destructor
Mystring::~Mystring() {
    if(str == nullptr) {
        std::cout << "Calling for Destructor for Mystring : nullptr\n";
    } else {
        std::cout << "Calling for Destructor for Mystring : " << str << std::endl;
    }
    delete [] str;
}

// Copy Assignment
Mystring& Mystring::operator=(const Mystring& rhs) {
    std::cout << "Copy Assignment used" << std::endl;

    if(this == &rhs)
        return *this;
    delete [] str;
    str = new char[strlen(rhs.str) +1];
    std::strcpy(str, rhs.str);
    return *this;
}

// +++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++
// Move Assignment (Start)
// +++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++

// ========================================================================
// ANATOMY OF THE SIGNATURE (The Top Line):
// Mystring& Mystring::operator=(Mystring &&rhs)
//
// 1. [Mystring&]  : Return Type. Returns a reference to the updated object 
//                   itself to allow chained assignments (e.g., a = b = c).
// 2. [Mystring::] : Class Scope. Tells the compiler that this function 
//                   belongs to the Mystring class.
// 3. [operator=]  : Function Name. The special C++ name for overloading 
//                   the assignment operator (equals sign).
// 4. [&&rhs]      : Parameter. The double ampersand (&&) means "R-value 
//                   reference". It catches temporary, unnamed objects that 
//                   are about to be destroyed (like a = "Hello";).
// ========================================================================

Mystring& Mystring::operator=(Mystring &&rhs) {
    std::cout << "Move Assignment used" << std::endl;

    // STEP 1: Self-assignment check
    // In case someone accidentally writes a = std::move(a);
    if(this == &rhs) {
        return *this;
    }
        
    // STEP 2: Clean up the old data
    // Before stealing the new data, we throw away our own old data.
    // Otherwise, our old data will be left hanging in RAM (Memory Leak).
    delete[] this->str;
    
    // STEP 3: The heist! (Taking over the pointer)                                  // Komşular yetişin hırsız var
    // We DO NOT use new or strcpy! We directly copy the memory address 
    // pointed to by the temporary object on the right (rhs) to our own pointer.
    this->str = rhs.str;
    
    // STEP 4: Disarming the temporary object (Nullifying the pointer)
    // Since rhs is a temporary object, its Destructor will run when this line ends.
    // If we don't set its pointer to nullptr, the Destructor will delete the data 
    // we just stole! We set it to null so the Destructor has "nothing left to delete".
    rhs.str = nullptr;
    
    // STEP 5: Return *this for chained assignments (e.g., a = b = "Test")
    return *this;
}

// +++++++++++++++++++++++++++++++++++++++
// Move Assignment (End)
// +++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

 // getters
 int Mystring::get_length() const { return strlen(str); }
 const char *Mystring::get_str() const { return str; }
