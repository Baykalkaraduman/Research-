# Function Overloading

---

# Introduction

One of the most useful features of C++ is **Function Overloading**.

Function overloading allows multiple functions to have the **same name**, as long as their **parameter lists are different**.

The compiler determines which function should be called based on the arguments provided.

Example

```cpp
print(10);
```

```cpp
print(3.14);
```

```cpp
print("Hello");
```

Although every function is named `print`, each call invokes a different function.

---

# Why Do We Need Function Overloading?

Imagine writing several printing functions.

Without overloading, we might write

```cpp
print_integer();
```

```cpp
print_double();
```

```cpp
print_string();
```

```cpp
print_vector();
```

This quickly becomes repetitive.

With function overloading

```cpp
print(10);

print(3.14);

print("Hello");
```

the compiler automatically selects the correct version.

---

# General Syntax

```cpp
return_type function_name(parameter_list);
```

Examples

```cpp
void print(int);
```

```cpp
void print(double);
```

```cpp
void print(string);
```

```cpp
void print(vector<string>);
```

Notice that

- the function name is identical,
- only the parameter list changes.

---

# How Overloading Works

Suppose we have

```cpp
void print(int);
```

```cpp
void print(double);
```

Calling

```cpp
print(5);
```

selects

```cpp
void print(int);
```

Calling

```cpp
print(5.2);
```

selects

```cpp
void print(double);
```

The compiler performs this selection during compilation.

---

# What Makes Two Functions Different?

Functions may differ by

- number of parameters

```cpp
print(string);
```

```cpp
print(string,string);
```

or

- parameter types

```cpp
print(int);
```

```cpp
print(double);
```

or both.

---

# Return Type Does NOT Matter

This is illegal

```cpp
int print(int);
```

```cpp
double print(int);
```

The compiler cannot distinguish them because the parameter list is identical.

Only the return type changed.

---

# Automatic Type Conversion

The compiler may automatically convert arguments.

Example

```cpp
print('A');
```

There is no

```cpp
print(char);
```

so the compiler promotes

```cpp
char
```

to

```cpp
int
```

and calls

```cpp
print(int);
```

---

Another example

```cpp
print(3.5F);
```

There is no

```cpp
print(float);
```

The compiler promotes

```cpp
float
```

to

```cpp
double
```

and calls

```cpp
print(double);
```

---

# Implicit String Conversion

Suppose we have

```cpp
void print(string);
```

Calling

```cpp
print("Hello");
```

works because

```cpp
const char*
```

is automatically converted into

```cpp
std::string
```

---

# Overloading with Different Numbers of Parameters

Example

```cpp
void print(string);
```

```cpp
void print(string,string);
```

Calls

```cpp
print("Alice");
```

and

```cpp
print("Alice","Bob");
```

invoke different overloads.

---

# Overloading with Containers

Entire containers may also be overloaded.

Example

```cpp
void print(vector<string>);
```

Now

```cpp
vector<string> names;
```

can be printed with

```cpp
print(names);
```

---

# Compiler Resolution

When multiple overloads exist,

the compiler tries to find

1. an exact match,
2. a promotion,
3. a standard conversion,
4. a user-defined conversion.

If several overloads match equally well,

the call becomes **ambiguous**, producing a compilation error.

---

# Overloading vs Default Arguments

These two features interact.

Example

```cpp
void print(int);
```

```cpp
void print(int,int=0);
```

Now

```cpp
print(5);
```

matches **both** functions.

The compiler cannot choose.

This results in an **ambiguous function call**.

For this reason, avoid mixing overloads and default arguments carelessly.

---

# Scientific Computing Notes

Function overloading is heavily used in scientific libraries.

Examples include

- ROOT
- Geant4
- Eigen
- Boost
- OpenCV
- STL

Many mathematical functions accept

- integers,
- floating-point numbers,
- vectors,
- matrices,

all using the same function name.

---

# Best Practices

✔ Give overloaded functions the same logical purpose.

✔ Change only the parameter list.

✔ Prefer `const` references for large objects.

✔ Keep overloads simple and intuitive.

✔ Avoid ambiguous overloads.

---

# Common Mistakes

## Changing Only the Return Type

Incorrect

```cpp
int print(int);
double print(int);
```

---

## Creating Ambiguous Calls

Incorrect

```cpp
void func(int);
```

```cpp
void func(double);
```

```cpp
func('A');
```

Although this may compile depending on promotions, more complex overload sets can easily become ambiguous.

---

## Mixing Default Arguments Incorrectly

Incorrect

```cpp
void print(int);
```

```cpp
void print(int,int=0);
```

Calling

```cpp
print(5);
```

produces a compiler error.

---

## Using Overloading for Unrelated Operations

Bad design

```cpp
calculate(int);
```

```cpp
calculate(string);
```

if the two functions perform completely unrelated tasks.

Overloaded functions should represent the same conceptual operation.

---

# Summary

After completing this chapter you should understand

- what function overloading is,
- how the compiler selects an overload,
- implicit type conversions,
- overload resolution,
- why the return type alone cannot overload a function,
- how default arguments may create ambiguity,
- where overloading is used in professional C++ software.

---

# Exercises

## Exercise 1

Create three overloaded functions named

```cpp
square()
```

that accept

- `int`
- `double`
- `long`

---

## Exercise 2

Create overloaded

```cpp
maximum()
```

functions for

- integers,
- doubles,
- characters.

---

## Exercise 3

Create overloaded

```cpp
print()
```

functions for

- `int`
- `double`
- `string`
- `vector<int>`

---

## Exercise 4

Write two overloaded functions

```cpp
area(double radius);
```

and

```cpp
area(double width,double height);
```

One computes the area of a circle and the other computes the area of a rectangle.

---

## Exercise 5 (Challenge)

Design a small mathematical library containing overloaded functions for

```cpp
abs()
```

that work with

- `int`
- `float`
- `double`

Test which overload the compiler chooses for different numeric literals.