#include "Mystring.h"
#include <cstring>
#include <iostream>
/*
        **HOW TO BUILD A CONSTRUCTOR**
    
    Normally while we define a dunction we use this formalization:

    return_type function_name(type_of_variable variable)

    when you are defining it in a class:

    return_type Class::function_name()

    But there is two rules that changes the formulation 

    rule I : Constructors do not have any return type
    rule II : Name of the constructor must be same as the name of the class

    Constructor formulation:

    Class::function_name(variable_type variable) => Class_name::Class_name(variable_type variable) 

*/

// No args Constructor
Mystring::Mystring() 
    : str{nullptr} {
        str = new char[1];
        str = '\0';
    }

// Overloaded Constructor
Mystring::Mystring(const char* s) 
    : str{nullptr} {
        if(str == nullptr) {
            str = new char[1];
            str = '\0';
        } else {
            str = new char[std::strlen(s) + 1];
            std::strcpy(str, s);
        }
    }

// Copy Constructor
Mystring::Mystring(const Mystring &source) 
    : str{nullptr} {
        str = new char[std::strlen(source.str) + 1];
        std::strcpy(str, source.str);
    }

// Destructor
Mystring::~Mystring() {
    delete[] str;
}

/*
        HOW TO WRITE COPY ASSIGNMENT IN 5 STEPS

    STEP I 

    Remember the formulation for the constructors (refer ln: 5)

    The difference between them is that assignment is like a breed of both regular function and a constructor
    |
    |-> It has a return type like a regular function : return type = Class object type = Class name 
    |
    |-> Rest is same as the classic constrcutor but the function name is not same with class name
    |
    |-> Function name is called using "operator" keyword

    Assignment Operator formulation: 

    return_type Class::operator_operatorSymbolOverload(variable/object_type variable/object) =>
       V          V       V      V                           V                   V
    Class&       Class::operator=(  const                    Class              object_name)
    
    so most of the items are equivalent to the name of the "Class"

    object_name is choosed as "rhs" in general which stands as a abbrevation for right-hand-side

    STEP II

    if(this == &rhs) 
        return *this;

    With these lines we secure our code from self assignemts.

    This is a must due to how compiler works. It reads lines starting from the right to the left.

    So if you make a self assignment it is going to destroy the wanted value and then try to assign a nullptr value to the pointer

    to understand why it gets to delete, refer STEP III

    STEP III

    delete[] this->pointer_object

    Since we want to assign a new value we must first get rid of the older value and have a fresh empty space that we can store a new value

    So we have to return the old storage back to computer in order to not have any errors and memory leak.

    STEP IV

    pointer_object = new object_type[needed memory + 1]
    std::strcpy(this->object, rhs.object);

    +1 is for the null object that tells compiler to stop reading the memory

    so we allocate new memory exactly as much as we need to copy the new value

    using a copy function or maybe a loop we copy all the values

    STEP V

    return *this

    we must return a reference since the compiler reades from the right to the left

    If we make a chian of assignment like a = b = c then (without reference)
        1. b = c
        2. return b
        3. a = b
*/

// +++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++
// Copy Assignemt (Start)
// +++++++++++++++++++++++++++++++++++++++

Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << "Copy Assignment" << std::endl;
    if(this == &rhs)
        return *this;
    delete[] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);
    return *this;
    
}

// +++++++++++++++++++++++++++++++++++++++
// Copy Assignemt (End)
// +++++++++++++++++++++++++++++++++++++++
// +++++++++++++++++++++++++++++++++++++++


// Length displaying function
int Mystring::get_length() const {return std::strlen(str);}

// String displaying function
const char* Mystring::get_string() const {return str;}

// Fancy display function that shows both the sting and it's length
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}