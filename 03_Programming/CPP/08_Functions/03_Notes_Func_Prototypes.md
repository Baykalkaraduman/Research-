# Function Prototypes

---

# Introduction

As programs grow larger, writing every function before `main()` becomes difficult.

Imagine a project with hundreds of functions.

Finding the correct order quickly becomes impossible.

Function Prototypes solve this problem.

A prototype tells the compiler:

- the function's name,
- its return type,
- its parameter types.

The compiler now knows that the function exists, even if its implementation appears later.

---

# What is a Function Prototype?

A function prototype is simply a declaration.

It tells the compiler:

> "Trust me. This function will be defined later."

It does **not** contain the function body.

Example

```cpp
double calculate_area(double radius);
```

Later in the file

```cpp
double calculate_area(double radius)
{
    return PI * radius * radius;
}
```

---

# Why Do We Need Prototypes?

Without a prototype:

```cpp
int main()
{
    hello();        // ERROR
}

void hello()
{
    cout << "Hello";
}
```

The compiler reads from top to bottom.

When it reaches

```cpp
hello();
```

it has never seen that function before.

Compilation fails.

---

Adding a prototype fixes the problem.

```cpp
void hello();

int main()
{
    hello();
}

void hello()
{
    cout << "Hello";
}
```

Now the compiler already knows the function exists.

---

# Function Prototype Syntax

General form

```cpp
return_type function_name(parameter_list);
```

Examples

```cpp
void greet();

int add(int a, int b);

double area(double radius);

bool is_even(int number);

char get_grade(double average);
```

Notice the semicolon.

A prototype always ends with

```cpp
;
```

because it is only a declaration.

---

# Prototype vs Definition

Prototype

```cpp
double square(double x);
```

Definition

```cpp
double square(double x)
{
    return x * x;
}
```

Difference

Prototype

- Ends with `;`
- No function body
- Only tells the compiler

Definition

- Contains `{ }`
- Performs the actual work
- Exists only once

---

# Typical Program Layout

Professional C++ files usually follow this order.

```cpp
#include <iostream>

using namespace std;

const double PI {3.14159};

// Function Prototypes

double area(double radius);

double volume(double radius, double height);

void menu();

int main()
{
    menu();
}

// Function Definitions

double area(double radius)
{
    return PI * radius * radius;
}

double volume(double radius,double height)
{
    return area(radius) * height;
}

void menu()
{
    ...
}
```

This layout is used in almost every professional C++ project.

---

# Prototype Rules

Every prototype must exactly match its definition.

Prototype

```cpp
double add(double,double);
```

Definition

```cpp
double add(double x,double y)
{
    return x+y;
}
```

Valid.

---

Return type must match.

Wrong

```cpp
int area(double radius);

double area(double radius)
{
}
```

Compiler error.

---

Parameter types must match.

Wrong

```cpp
double add(int,int);

double add(double,double)
{
}
```

Compiler error.

---

Parameter names are optional.

All of these are valid.

```cpp
double area(double radius);

double area(double);

double area(double r);
```

The compiler only cares about the types.

---

# Function Call Flow

Example

```cpp
main()

↓

area_circle()

↓

calc_area_circle()

↓

return

↓

area_circle()

↓

return

↓

main()
```

Execution always jumps into the called function.

When it finishes,

execution returns exactly where it was called.

---

# Advantages of Function Prototypes

✔ Functions may be defined in any order.

✔ `main()` stays near the top.

✔ Code becomes easier to read.

✔ Easier debugging.

✔ Large projects become manageable.

✔ Multiple source files become possible.

---

# Header Files

Most standard library functions are actually prototypes.

Example

```cpp
#include <cmath>
```

Inside `<cmath>` there are prototypes like

```cpp
double sqrt(double);

double pow(double,double);

double sin(double);
```

Their implementations are stored inside the standard library.

This is exactly the same idea you use in your own programs.

---

# Scientific Computing Notes

Large scientific software relies heavily on prototypes.

Examples

- CERN ROOT
- Geant4
- Eigen
- OpenCV
- TensorFlow C++
- Boost

These projects contain millions of lines of code.

Without prototypes (and header files), they would be impossible to organize.

---

# Best Practices

✔ Place all prototypes before `main()`.

✔ Keep `main()` near the beginning of the file.

✔ Give parameters meaningful names.

```cpp
double area(double radius);
```

instead of

```cpp
double area(double x);
```

✔ Match every prototype exactly with its definition.

✔ Prefer header files (`.h` / `.hpp`) in larger projects instead of keeping prototypes in `.cpp`.

---

# Common Mistakes

## Forgetting the semicolon

Wrong

```cpp
double area(double radius)
```

Correct

```cpp
double area(double radius);
```

---

## Calling a function before the compiler knows it

Wrong

```cpp
int main()
{
    hello();
}

void hello()
{
}
```

Correct

```cpp
void hello();

int main()
{
    hello();
}
```

---

## Different return types

Wrong

```cpp
int square(double);

double square(double)
{
}
```

The prototype and definition must match exactly.

---

## Different parameter types

Wrong

```cpp
double add(int,int);

double add(double,double)
{
}
```

Again,

both declarations must be identical.

---

## Writing multiple definitions

Wrong

```cpp
double area(double)
{
}

double area(double)
{
}
```

A function may have only one definition.

---

# Formula (Prototype Syntax)

General formula

```cpp
return_type function_name(parameter_types);
```

Examples

```cpp
void display();

int add(int,int);

double area(double);

bool valid(int);

char grade(double);
```

Definition formula

```cpp
return_type function_name(parameter_list)
{
    // body
}
```

---

# Summary

After completing this chapter you should understand

- what a function prototype is,
- why prototypes are necessary,
- how the compiler reads source files,
- the difference between declarations and definitions,
- how function calls work,
- where prototypes should be placed,
- why prototypes are essential in large C++ projects.

---

# Exercises

## Exercise 1

Create a prototype for

```cpp
double circumference(double radius);
```

Then define it after `main()`.

---

## Exercise 2

Write prototypes for

- square()
- cube()
- average()

Implement them below `main()`.

---

## Exercise 3

Create a program that calculates

- rectangle area
- triangle area
- circle area

using prototypes.

---

## Exercise 4

Move every function definition below `main()`.

Verify that the program still compiles using prototypes.

---

## Exercise 5 (Challenge)

Create a geometry calculator.

Functions

- square area
- rectangle area
- circle area
- cylinder volume

Place only the prototypes before `main()`.

Put every function definition after `main()`.

Call them from a menu-driven interface.