#ifndef MYSTRING_H
#define MYSTRING_H

#pragma once

class Mystring
{

//================================================
// Attributes // Data Members
//================================================

private:

    char* str;

//================================================
// Member Functions
//================================================

public:

    //--------------------------------------------
    // Constructors
    //--------------------------------------------

    // *** Default Construtor ***
    Mystring();

    // *** Overloading Constructor ***
    Mystring(const char* s);

    // *** Copy Constructor ***
    Mystring(const Mystring &source);

    // *** Destructor ***
    ~Mystring();

    //--------------------------------------------
    // Assignments
    //--------------------------------------------

        // +++++++++++++++++++++++++++++++++++++++
        // +++++++++++++++++++++++++++++++++++++++
        // Copy Assignemt (Start)
        // +++++++++++++++++++++++++++++++++++++++
        // +++++++++++++++++++++++++++++++++++++++

        Mystring &operator=(const Mystring &rhs);

        // +++++++++++++++++++++++++++++++++++++++
        // +++++++++++++++++++++++++++++++++++++++
        // Copy Assignemt (End)
        // +++++++++++++++++++++++++++++++++++++++
        // +++++++++++++++++++++++++++++++++++++++


    //--------------------------------------------
    // Function Declerations
    //--------------------------------------------

    // *** getters ***
    int get_length() const;
    const char* get_string() const;

    // *** display function (Fancy getter) ***
    void display() const;

};

#endif