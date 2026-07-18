# Default Arguments

---

# Introduction

When writing functions, we sometimes want certain parameters to have a **default value**.

If the caller does not provide a value for that parameter, the compiler automatically uses the predefined default value.

Default arguments make functions easier to call and reduce the need to create multiple overloaded versions of the same function.

Example

```cpp
double calculate_cost(double price = 100.0);
```

Now the function can be called either as

```cpp
calculate_cost();
```

or

```cpp
calculate_cost(250.0);
```

The first call uses the default value, while the second replaces it with the supplied argument.

---

# Why Do We Need Default Arguments?

Imagine a shipping cost calculator.

Without default arguments, every function call must specify every parameter.

```cpp
calculate_cost(120.0, 0.06, 3.50);
```

Even if the tax rate and shipping cost almost never change.

Using default arguments,

```cpp
calculate_cost(120.0);
```

becomes enough.

The compiler automatically fills in the missing arguments.

This makes function calls cleaner and easier to read.

---

# Syntax

General syntax

```cpp
return_type function_name(type parameter = default_value);
```

Example

```cpp
double calculate_cost(double price = 100.0);
```

Multiple default arguments

```cpp
double calculate_cost(double price = 100.0,
                      double tax = 0.06,
                      double shipping = 3.50);
```

---

# How the Compiler Uses Default Arguments

Suppose the prototype is

```cpp
double calculate_cost(double price = 100.0,
                      double tax = 0.06,
                      double shipping = 3.50);
```

Calling

```cpp
calculate_cost();
```

is interpreted approximately as

```cpp
calculate_cost(100.0, 0.06, 3.50);
```

Calling

```cpp
calculate_cost(200.0);
```

becomes

```cpp
calculate_cost(200.0, 0.06, 3.50);
```

Calling

```cpp
calculate_cost(200.0, 0.08);
```

becomes

```cpp
calculate_cost(200.0, 0.08, 3.50);
```

The compiler inserts the missing arguments before compilation.

---

# The Right-to-Left Rule

This is the most important rule for default arguments.

Once a parameter has a default value,

**every parameter to its right must also have a default value.**

Correct

```cpp
void func(int a,
          int b = 5,
          int c = 10);
```

Incorrect

```cpp
void func(int a = 5,
          int b,
          int c = 10);
```

The compiler cannot determine what value should be used for `b`.

---

# Default Arguments Are Usually Written in the Prototype

Recommended

```cpp
double calculate_cost(double price = 100.0,
                      double tax = 0.06,
                      double shipping = 3.50);
```

Function definition

```cpp
double calculate_cost(double price,
                      double tax,
                      double shipping)
{
    ...
}
```

This keeps the declaration and definition separate and avoids duplicate default values.

---

# Function Calls

Suppose we have

```cpp
double calculate_cost(double price = 110,
                      double tax = 0.06,
                      double shipping = 3.50);
```

Possible calls

```cpp
calculate_cost();
```

```cpp
calculate_cost(200);
```

```cpp
calculate_cost(200, 0.08);
```

```cpp
calculate_cost(200, 0.08, 5);
```

All of these are valid.

---

# Default Arguments with Strings

Default arguments work with any data type.

Example

```cpp
void greet(string name,
           string prefix = "Mr.",
           string suffix = "");
```

Calls

```cpp
greet("Alice");
```

```cpp
greet("Alice", "Dr.");
```

```cpp
greet("Alice", "Professor", "Ph.D");
```

Each call supplies a different number of arguments.

---

# Default Arguments vs Function Overloading

Without default arguments, programmers often write several overloaded functions.

Example

```cpp
calculate_cost();
calculate_cost(double);
calculate_cost(double,double);
calculate_cost(double,double,double);
```

With default arguments,

one function is usually enough.

```cpp
double calculate_cost(double price = 110,
                      double tax = 0.06,
                      double shipping = 3.50);
```

Default arguments reduce code duplication.

---

# Compiler Behavior

Default arguments are **not stored inside the function**.

Instead,

the compiler inserts the missing values at the function call.

Conceptually,

```cpp
calculate_cost(200);
```

becomes

```cpp
calculate_cost(200, 0.06, 3.50);
```

before the program is compiled.

---

# Advantages

- Cleaner function calls
- Less repetitive code
- Easier maintenance
- Fewer overloaded functions
- More readable interfaces

---

# Scientific Computing Notes

Default arguments appear frequently in scientific software.

Examples include

- numerical integration tolerances
- detector thresholds
- simulation parameters
- optimization algorithms
- plotting functions
- ROOT utilities
- Geant4 helper functions

Many scientific libraries choose sensible defaults while still allowing the user to override them when needed.

---

# Best Practices

✔ Put default arguments in the function prototype.

✔ Keep default values meaningful.

✔ Use defaults only when a value is truly optional.

✔ Place optional parameters at the end of the parameter list.

✔ Document what each default value represents.

---

# Common Mistakes

## Giving Default Values Twice

Incorrect

```cpp
double func(double x = 5);

double func(double x = 5)
{
}
```

Correct

```cpp
double func(double x = 5);

double func(double x)
{
}
```

---

## Violating the Right-to-Left Rule

Incorrect

```cpp
void func(int a = 5,
          int b,
          int c = 10);
```

Correct

```cpp
void func(int a,
          int b = 5,
          int c = 10);
```

---

## Forgetting Which Values Are Default

```cpp
calculate_cost(200);
```

Some beginners assume every parameter is supplied manually.

Remember that the compiler automatically inserts the missing arguments.

---

## Using Too Many Default Arguments

Giving every parameter a default value can make function calls confusing.

Only use default arguments when they genuinely improve usability.

---

# Summary

After completing this chapter you should understand

- what default arguments are,
- why they are useful,
- how to declare them,
- the right-to-left rule,
- why they are usually written in function prototypes,
- how the compiler inserts missing arguments,
- how they reduce the need for function overloading.

---

# Exercises

## Exercise 1

Create a function

```cpp
void print_line(char symbol = '*',
                int count = 20);
```

Print the given symbol `count` times.

Call it using

- no arguments,
- one argument,
- two arguments.

---

## Exercise 2

Create a function

```cpp
double rectangle_area(double width = 1,
                      double height = 1);
```

Calculate the rectangle's area.

Test all possible valid function calls.

---

## Exercise 3

Write a greeting function

```cpp
void greet(string name,
           string prefix = "Mr.",
           string suffix = "");
```

Call it several times using different combinations of arguments.

---

## Exercise 4

Write a temperature conversion function

```cpp
double convert(double temperature,
               bool to_fahrenheit = true);
```

If `to_fahrenheit` is `true`, convert Celsius to Fahrenheit.

Otherwise, convert Fahrenheit to Celsius.

---

## Exercise 5 (Challenge)

Create a shipping cost calculator with four parameters:

```cpp
double shipping_cost(double weight,
                     double tax = 0.08,
                     double insurance = 5.0,
                     double handling = 2.5);
```

Test every valid combination of function calls and explain which default arguments the compiler inserts automatically.