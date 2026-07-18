# Function Definition

---

# Introduction

Functions are one of the most fundamental building blocks of every programming language.

Instead of writing the same code multiple times, we can place that code inside a function and call it whenever we need it.

Functions make programs

- shorter,
- easier to read,
- easier to debug,
- easier to maintain,
- easier to reuse.

Modern C++ programs may contain hundreds or even thousands of functions.

---

# What is a Function?

A function is simply a named block of code that performs a specific task.

Instead of writing

```cpp
cout << "Hello";
```

ten different times,

we write

```cpp
print_message();
```

and let the function perform the work.

Think of a function as a small machine.

```
Input
   │
   ▼
Function
   │
   ▼
Output
```

Some functions receive information.

Some functions return information.

Some do both.

---

# General Syntax

```cpp
return_type function_name(parameter_list)
{
    statements;
}
```

Example

```cpp
double square(double x)
{
    return x * x;
}
```

Everything has a purpose.

---

# Return Type

The first word specifies what the function returns.

```cpp
int
double
char
bool
string
```

Example

```cpp
double area(...)
```

means

"This function returns a double."

---

## Returning Nothing

Sometimes a function only performs an action.

Example

```cpp
void greeting()
{
    cout << "Hello";
}
```

The keyword

```cpp
void
```

means

"This function returns nothing."

---

# Function Name

The function name should clearly describe what the function does.

Good examples

```cpp
calculate_area()

print_menu()

find_maximum()

read_file()
```

Poor examples

```cpp
abc()

func1()

test()
```

A descriptive name makes code much easier to understand.

---

# Parameters

Parameters are variables declared inside the parentheses.

```cpp
double square(double number)
```

Here

```cpp
number
```

is the parameter.

It exists only while the function is running.

---

# Arguments

Arguments are the actual values passed to the function.

Example

```cpp
square(5.0);
```

Parameter

```
number
```

Argument

```
5.0
```

Many beginners confuse these two terms.

Remember

- Parameter → inside the function definition.
- Argument → inside the function call.

---

# Multiple Parameters

Functions may receive several values.

```cpp
double volume(double radius,
              double height)
```

Function call

```cpp
volume(3.5,10.0);
```

Arguments are matched by position.

```
radius ← 3.5

height ← 10.0
```

---

# Function Body

Everything inside

```cpp
{
}
```

belongs to the function.

Example

```cpp
double square(double x)
{
    double result {x*x};

    return result;
}
```

Local variables only exist inside this block.

They disappear automatically after the function finishes.

---

# Return Statement

The

```cpp
return
```

statement immediately ends the function.

Example

```cpp
return result;
```

Execution returns to wherever the function was called.

```
main()

↓

square()

↓

return

↓

main()
```

---

# Calling a Function

Defining a function does not execute it.

It only tells the compiler that the function exists.

Execution begins only when we call it.

Example

```cpp
area_circle();
```

Every call executes the entire function body.

```
area_circle();

area_circle();

area_circle();
```

runs the function three separate times.

---

# Function Declaration vs Definition

These two concepts are often confused.

Declaration

```cpp
double area(double radius);
```

Only informs the compiler.

Definition

```cpp
double area(double radius)
{
    return pi*radius*radius;
}
```

Actually contains the implementation.

---

# Why must functions be defined before main()?

The compiler reads a source file from top to bottom.

Imagine this code

```cpp
int main()
{
    area();
}
```

When the compiler reaches

```cpp
area();
```

it asks

> "What is area?"

If it has not seen the function yet,

it reports an error.

Therefore,

either

the function must appear before

```cpp
main()
```

or

a function declaration must be provided.

---

# Function Execution Flow

Suppose we have

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

Notice that execution always comes back to the exact line after the function call.

This is one of the most important ideas in programming.

Functions do not permanently leave the program.

They temporarily transfer execution.

---

# Local Variables

Variables declared inside a function are called local variables.

Example

```cpp
void area_circle()
{
    double radius;
}
```

This

```cpp
radius
```

exists only inside

```cpp
area_circle()
```

Trying to use it elsewhere causes an error.

```
main()

↓

radius ❌
```

The compiler cannot find it.

---

# Global Variables and Constants

Variables declared outside every function are called global variables.

Example

```cpp
const double pi {3.14159};
```

Every function can access

```cpp
pi
```

because it lives outside all functions.

```
main()

↓

area()

↓

volume()

↓

pi
```

All of them can read it.

Using

```cpp
const
```

makes it safe because no function can accidentally modify it.

Global constants are common.

Global variables should be used carefully.

---

# Why is radius passed as a parameter?

Notice

```cpp
double calc_area_circle(double radius)
```

instead of

```cpp
double calc_area_circle()
```

Why?

Because every circle has a different radius.

Functions should receive the data they need instead of relying on hidden variables.

This makes functions reusable.

```cpp
calc_area_circle(2);

calc_area_circle(5);

calc_area_circle(12);
```

The same function works for every circle.

---

# Reusing Functions

Notice

```cpp
calc_volume_cylinder()
```

uses

```cpp
calc_area_circle()
```

internally.

```cpp
return calc_area_circle(radius) * height;
```

This is excellent programming practice.

Instead of rewriting

```
πr²
```

again,

we reuse an existing function.

Advantages

- less code
- fewer bugs
- easier maintenance

Professional software constantly builds larger functions from smaller ones.
# Function Scope and Lifetime

---

## Local Variables

Variables declared inside a function belong **only to that function**.

Example

```cpp
void print_number() {
    int number {10};
}
```

The variable `number` exists only while `print_number()` is executing.

Outside the function, it no longer exists.

This is called **local scope**.

---

## Global Variables

Variables declared outside every function are called **global variables**.

Example

```cpp
const double PI {3.141592653589793};
```

Global variables can be accessed by every function in the program.

```cpp
double area(double r) {
    return PI * r * r;
}
```

---

### Advantages

- Shared by all functions
- No need to pass as parameters

### Disadvantages

- Can make programs harder to understand
- Large projects avoid unnecessary global variables
- Global variables increase coupling between functions

Modern C++ recommends minimizing global variables.

Instead, pass information through parameters whenever possible.

---

# Parameters

Functions often need information.

Parameters provide that information.

Example

```cpp
double square(double x) {
    return x * x;
}
```

`x` is called a **parameter**.

When calling

```cpp
square(5);
```

the value `5` becomes the parameter.

---

# Arguments vs Parameters

Many beginners confuse these terms.

Parameter

```cpp
double square(double x)
```

`x` is the parameter.

Argument

```cpp
square(5);
```

`5` is the argument.

Simple rule

- Parameter → inside the function definition
- Argument → inside the function call

---

# Return Values

A function may return a value.

Example

```cpp
double cube(double x) {
    return x * x * x;
}
```

The caller receives the returned value.

```cpp
double value = cube(4);
```

Result

```
64
```

---

## Returning Nothing

Some functions simply perform an action.

Example

```cpp
void print_line() {
    cout << "---------------";
}
```

Since nothing is returned,

the return type is

```cpp
void
```

---

# Function Call Stack

Every function call creates a new stack frame.

Simple example

```text
main()

↓

area_circle()

↓

calc_area_circle()
```

Execution always returns in reverse order.

```text
calc_area_circle()

↓

area_circle()

↓

main()
```

Understanding the call stack becomes very important when debugging programs.

---

# Function Reuse

One function may call another.

Example

```cpp
double area(double r) {
    return PI * r * r;
}

double volume(double r,double h) {
    return area(r) * h;
}
```

Advantages

- Less duplicated code
- Easier maintenance
- Smaller functions
- Better readability

This is one of the most important ideas in software engineering.

---

# Function Design Principles

A good function should

- perform one task,
- have a descriptive name,
- avoid unnecessary global variables,
- be easy to test,
- be reusable.

Example

Good

```cpp
calculate_average()
```

Poor

```cpp
function1()
```

---

# Function Naming

Choose names that describe exactly what the function does.

Good examples

```cpp
calculate_area()

calculate_volume()

print_menu()

is_prime()

compute_average()
```

Avoid names like

```cpp
abc()

test()

do_it()

temp()
```

Good names make code almost self-documenting.

---

# Common Mistakes

## Forgetting the return type

Incorrect

```cpp
calculate_area(double r)
```

Correct

```cpp
double calculate_area(double r)
```

---

## Forgetting return

Incorrect

```cpp
double square(double x)
{
    x * x;
}
```

Correct

```cpp
double square(double x)
{
    return x * x;
}
```

---

## Using variables outside their scope

Incorrect

```cpp
void test()
{
    int x {5};
}

cout << x;
```

`x` only exists inside the function.

---

## Duplicating code

Instead of

```cpp
area = PI*r*r;

...

volume = PI*r*r*h;
```

create

```cpp
calculate_area()

calculate_volume()
```

This greatly improves maintainability.

---

# Scientific Computing Notes

Functions are essential in scientific programming.

Libraries like

- ROOT
- Geant4
- Eigen
- CERN software
- OpenCV

contain thousands of reusable functions.

For example

```cpp
double momentum(...)

double invariant_mass(...)

double detector_efficiency(...)
```

Breaking complex physics calculations into small reusable functions makes code

- easier to debug,
- easier to optimize,
- easier to validate,
- easier to share with collaborators.

Professional scientific software heavily relies on modular function design.

---

# Best Practices

✔ Give functions descriptive names.

✔ One function should perform one task.

✔ Avoid duplicated code.

✔ Prefer passing parameters instead of using global variables.

✔ Use `const` global constants when appropriate.

✔ Keep functions short and readable.

✔ Reuse functions whenever possible.

---

# Summary

After completing this chapter you should understand

- what a function is,
- function definition,
- function declaration,
- function calls,
- parameters,
- arguments,
- return values,
- `void` functions,
- local variables,
- global variables,
- function scope,
- function call stack,
- code reuse,
- why functions are fundamental in modern C++.

---

# Exercises

## Exercise 1

Create a function

```cpp
double square(double x)
```

that returns the square of a number.

---

## Exercise 2

Write a function

```cpp
double rectangle_area(double width,double height)
```

and display the result.

---

## Exercise 3

Write a function

```cpp
bool is_even(int number)
```

that returns whether a number is even.

---

## Exercise 4

Create a function

```cpp
double average(double a,double b,double c)
```

and use it from `main()`.

---

## Exercise 5 (Challenge)

Create a small geometry calculator.

Implement separate functions for

- Circle Area
- Circle Circumference
- Cylinder Volume
- Sphere Volume

Call every function from `main()` and display the results.

Try to avoid duplicated calculations by making functions call one another whenever appropriate.