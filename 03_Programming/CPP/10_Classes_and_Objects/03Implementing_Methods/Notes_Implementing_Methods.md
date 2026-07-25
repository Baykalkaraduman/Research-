# Implementing Member Methods

---

# Introduction

As programs grow larger, writing an entire class inside a single source file quickly becomes difficult to manage.

Professional C++ software separates a class into multiple files.

Instead of writing everything inside one `.cpp` file, a class is usually divided into

```
ClassName.h

↓

Class Declaration
```

```
ClassName.cpp

↓

Member Function Definitions
```

```
main.cpp

↓

Program Logic
```

This organization makes projects cleaner, easier to read, easier to debug, and much easier to maintain.

Nearly every professional C++ project follows this structure.

Examples include

- ROOT
- Geant4
- CLHEP
- Eigen
- Qt
- CMSSW

---

# Why Split a Class Into Multiple Files?

Imagine a project containing 100 classes.

If every class were written inside one file

```
main.cpp

↓

5000+ lines
```

finding bugs would become extremely difficult.

Instead, each class has its own files.

Example

```
Player.h

Player.cpp
```

```
Account.h

Account.cpp
```

```
Detector.h

Detector.cpp
```

This makes each file responsible for only one class.

---

# Typical C++ Project Structure

A small project usually looks like

```
Project

│

├── main.cpp

├── Account.h

├── Account.cpp
```

A larger project might look like

```
Project

│

├── main.cpp

├── Account.h

├── Account.cpp

├── Player.h

├── Player.cpp

├── Weapon.h

├── Weapon.cpp

├── Enemy.h

├── Enemy.cpp
```

This is exactly how large software projects are organized.

---

# The Header File (.h)

The header file contains the **class declaration**.

Example

```cpp
class Account
{
private:

    std::string name;
    double balance;

public:

    void set_name(std::string);

    std::string get_name();

    bool deposit(double);

    bool withdraw(double);
};
```

Notice that no actual code is written for the functions.

Only the declarations exist.

The header answers the question

> **What can this class do?**

---

# Class Declaration

A declaration tells the compiler

- the function exists
- its name
- its return type
- its parameters

Example

```cpp
bool deposit(double amount);
```

The compiler now knows this function exists, even though it has not yet seen its implementation.

---

# Inline Member Functions

Some small functions are written directly inside the class.

Example

```cpp
void set_balance(double bal)
{
    balance = bal;
}
```

These are called **inline member functions**.

They are usually

- short
- simple
- frequently called

Examples

```
getters

setters

small utility functions
```

Large functions should generally be implemented inside the `.cpp` file.

---

# The Source File (.cpp)

The implementation file contains the actual code.

Example

```cpp
bool Account::deposit(double amount)
{
    balance += amount;
    return true;
}
```

This file answers the question

> **How does the class perform its work?**

The compiler already knows the function exists because it saw the declaration inside the header.

Now it learns what the function actually does.

---

# The Main Program

The purpose of

```
main.cpp
```

is simply to use the class.

Example

```cpp
Account account;

account.deposit(200);
```

Notice that `main.cpp` does not need to know how `deposit()` works internally.

It simply uses the public interface.

This is one of the biggest advantages of Object-Oriented Programming.

---

# Responsibilities of Each File

## Account.h

Contains

- Class declaration
- Attributes
- Function declarations
- Inline functions

---

## Account.cpp

Contains

- Member function definitions
- Algorithms
- Business logic

---

## main.cpp

Contains

- Object creation
- User interaction
- Function calls
- Program flow

Keeping these responsibilities separate makes the code much easier to understand.

---

# Declaration vs Definition

These two concepts are often confused.

## Declaration

Tells the compiler

> "This function exists."

Example

```cpp
bool withdraw(double amount);
```

No implementation is provided.

---

## Definition

Provides the actual implementation.

Example

```cpp
bool Account::withdraw(double amount)
{
    if(balance >= amount)
    {
        balance -= amount;
        return true;
    }

    return false;
}
```

Now the compiler knows exactly how the function behaves.

---

# Advantages of Separating Files

✔ Better organization

✔ Easier maintenance

✔ Faster debugging

✔ Easier collaboration

✔ Cleaner code

✔ Matches professional C++ standards

✔ Allows very large software projects to remain manageable

---

# Common Beginner Mistakes

## Mistake 1

Putting every class into one file.

This quickly becomes unmanageable.

---

## Mistake 2

Writing large functions directly inside the class.

Keep only very small functions inline.

---

## Mistake 3

Confusing declaration with definition.

Remember

Declaration

↓

Function exists

Definition

↓

Function implementation

---

# Summary (Part 1)

- Professional C++ projects separate classes into multiple files.
- The header (`.h`) contains declarations.
- The source file (`.cpp`) contains implementations.
- `main.cpp` only uses the class.
- Separating responsibilities makes programs easier to maintain.
- Declaration tells the compiler **what exists**.
- Definition tells the compiler **how it works**.

# Implementing Member Methods (Part 2)

---

# Including Header Files

Before using a class, the compiler must know that the class exists.

This is accomplished using the `#include` directive.

Example

```cpp
#include "Account.h"
```

Unlike standard libraries,

```cpp
#include <iostream>
```

our own classes are usually included with quotation marks.

```
Standard Library

↓

< >

```

```
User Defined Header

↓

" "

```

The compiler literally copies the contents of `Account.h` into the current source file before compilation.

---

# The Scope Resolution Operator (::)

When member functions are implemented outside the class, they must be connected back to their class.

Example

```cpp
void Account::set_name(std::string n)
{
    name = n;
}
```

The operator

```cpp
::
```

is called the **Scope Resolution Operator**.

It tells the compiler

> "This function belongs to the `Account` class."

Without it

```cpp
void set_name(...)
```

would simply be an ordinary global function.

---

# Header Guards

Notice the following code inside the header file.

```cpp
#ifndef ACCOUNT_H
#define ACCOUNT_H

...

#endif
```

These are called **Header Guards**.

Their purpose is to prevent the same header file from being included multiple times.

Without Header Guards

```
Account.h

↓

Included twice

↓

Class defined twice

↓

Compiler Error
```

With Header Guards

```
Account.h

↓

Already included?

↓

YES

↓

Ignore second inclusion
```

The compiler only processes the header once.

---

# #pragma once

Another way to prevent multiple inclusion is

```cpp
#pragma once
```

Both methods serve the same purpose.

```
#ifndef

↓

Portable

↓

Works Everywhere
```

```
#pragma once

↓

Simpler

↓

Modern Compilers
```

Most professional codebases choose **one** method, not both.

---

# Compilation Process

Many beginners believe the compiler reads only `main.cpp`.

Actually, the compilation process is much more structured.

```
main.cpp

↓

#include "Account.h"

↓

Compiler learns the Account class

↓

Account.cpp

↓

Compiler finds implementations

↓

Executable Program
```

Each source file is compiled separately.

Later, the linker combines them into one executable.

---

# Compilation Stages

A simplified compilation pipeline is

```
Source Files

↓

Preprocessor

↓

Compiler

↓

Object Files

↓

Linker

↓

Executable
```

### 1. Preprocessor

Processes

- `#include`
- `#define`
- Header Guards

---

### 2. Compiler

Translates C++ code into object code.

```
.cpp

↓

.o
```

---

### 3. Linker

Combines every object file.

```
main.o

+

Account.o

↓

Executable
```

Without the linker, the compiler could not connect function calls across different files.

---

# Why Separate Compilation?

Imagine a project with

```
100 Classes
```

If only one file changes,

```
Account.cpp
```

only that file needs recompilation.

Without separate compilation,

the compiler would need to rebuild the entire project every time.

Large projects would take hours instead of seconds.

---

# Real Physics Libraries

ROOT

```
TH1.h

↓

TH1.cxx
```

---

Geant4

```
G4Track.hh

↓

G4Track.cc
```

---

Qt

```
QWidget.h

↓

QWidget.cpp
```

---

Eigen

Uses mostly header-only templates.

Even there,

the code is carefully organized into many files.

---

# Advantages of This Structure

✔ Cleaner organization

✔ Easier debugging

✔ Faster compilation

✔ Better collaboration

✔ Easier maintenance

✔ Reusable classes

✔ Professional project layout

---

# Common Beginner Mistakes

## Mistake 1

Forgetting

```cpp
#include "Account.h"
```

The compiler does not know what `Account` is.

---

## Mistake 2

Writing

```cpp
void set_name(...)
```

instead of

```cpp
void Account::set_name(...)
```

Without `Account::`, the function is no longer a member of the class.

---

## Mistake 3

Removing Header Guards.

This often produces

```
Redefinition of class
```

errors.

---

## Mistake 4

Putting implementations inside the header unnecessarily.

Large functions belong in

```
.cpp
```

not

```
.h
```

---

## Mistake 5

Using both

```cpp
#ifndef
```

and

```cpp
#pragma once
```

in every project.

Usually one method is sufficient.

---

# Best Practices

✔ One class per header.

✔ One implementation file per class.

✔ Keep `main.cpp` focused on program flow.

✔ Use Header Guards.

✔ Implement large functions in `.cpp`.

✔ Keep headers lightweight.

✔ Include only what you need.

✔ Organize projects into small, reusable modules.

---

# Visual Summary

```
            Project

               │

      ┌────────┴────────┐

      │                 │

 Account.h         Account.cpp

      │                 │

      └────────┬────────┘

               │

          main.cpp

               │

         Program Runs
```

---

# Professional Workflow

When creating a new class, the usual workflow is

```
Create Header

↓

Declare Class

↓

Declare Member Functions

↓

Create Source File

↓

Implement Member Functions

↓

Include Header in main()

↓

Create Objects

↓

Use the Class
```

This workflow is followed in almost every professional C++ project.

---

# Summary

- `.h` files contain declarations.
- `.cpp` files contain implementations.
- `main.cpp` creates and uses objects.
- `#include` makes class declarations visible.
- The **Scope Resolution Operator (`::`)** connects a function to its class.
- Header Guards prevent duplicate inclusion.
- The compiler compiles each source file separately, and the linker combines them into a single executable.
- Splitting classes into multiple files is the standard organization used in professional C++ software, including scientific frameworks such as ROOT, Geant4, Qt, and CMSSW.

> **Key Takeaway:**  
> Separating a class into **header (`.h`)**, **implementation (`.cpp`)**, and **application (`main.cpp`)** files is one of the defining characteristics of professional C++ development. This structure improves readability, enables modular design, speeds up compilation, and scales naturally to the large scientific software projects used in High Energy Physics.