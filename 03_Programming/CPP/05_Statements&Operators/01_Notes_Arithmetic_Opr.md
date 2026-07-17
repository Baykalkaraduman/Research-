# Arithmetic Operators

---

# Introduction

Arithmetic operators are among the most fundamental building blocks of every programming language.

They allow a program to perform mathematical calculations such as addition, subtraction, multiplication, division, and finding remainders.

Although these operators appear simple, they are used constantly in real-world software, engineering applications, scientific computing, and physics simulations.

Every numerical computation in C++ ultimately relies on arithmetic operators.

---

# What is an Operator?

An **operator** is a symbol that tells the compiler to perform a specific operation on one or more operands.

Example:

```cpp
int result = 5 + 3;
```

In this example

- `5` and `3` are **operands**
- `+` is the **operator**
- `8` is the result of the operation

---

# Basic Arithmetic Operators

| Operator | Meaning | Example |
|----------|---------|---------|
| `+` | Addition | `5 + 3` |
| `-` | Subtraction | `8 - 2` |
| `*` | Multiplication | `4 * 6` |
| `/` | Division | `20 / 5` |
| `%` | Modulus (Remainder) | `17 % 5` |

These five operators are the foundation of numerical programming in C++.

---

# Addition (+)

The addition operator combines two values.

```cpp
int result = 20 + 15;
```

Output

```
35
```

Addition can also be used with floating-point numbers.

```cpp
double x = 3.14 + 2.71;
```

---

# Subtraction (-)

The subtraction operator removes one value from another.

```cpp
int result = 20 - 8;
```

Output

```
12
```

---

# Multiplication (*)

The multiplication operator calculates the product of two values.

```cpp
int result = 12 * 4;
```

Output

```
48
```

---

# Division (/)

The division operator divides one value by another.

```cpp
20 / 5
```

Result

```
4
```

However, division behaves differently depending on the data types involved.

---

# Integer Division

If both operands are integers,

```cpp
5 / 2
```

the result is

```
2
```

not

```
2.5
```

The decimal part is simply discarded.

This is called **integer division**.

Example

```cpp
std::cout << 100 / 200;
```

Output

```
0
```

Even though mathematically

```
100 / 200 = 0.5
```

the result becomes zero because both operands are integers.

---

# Floating-Point Division

If at least one operand is a floating-point number,

```cpp
5.0 / 2
```

or

```cpp
5 / 2.0
```

the result becomes

```
2.5
```

Examples

```cpp
5 / 10
```

Output

```
0
```

```cpp
5.0 / 10.0
```

Output

```
0.5
```

Always remember:

> Integer ÷ Integer = Integer

> Double ÷ Anything = Double

---

# Modulus Operator (%)

The modulus operator returns the remainder after integer division.

Example

```cpp
17 % 5
```

Result

```
2
```

because

```
17 = 5 × 3 + 2
```

Another example

```cpp
200 % 3
```

Result

```
2
```

The modulus operator only works with integer types.

---

# Assignment with Arithmetic Operators

Instead of directly printing a calculation,

```cpp
std::cout << num1 + num2;
```

it is usually better to store the result first.

```cpp
int result = num1 + num2;
```

Advantages

- easier to read
- easier to debug
- reusable later in the program

This is considered good programming practice.

---

# Constants

Programs often contain values that should never change.

Example

```cpp
const double USD_PER_EUR {1.19};
```

Using `const`

- improves readability
- prevents accidental modifications
- makes programs safer

Constants are heavily used in scientific programming.

Examples include

- speed of light
- Planck constant
- detector dimensions
- calibration parameters

---

# Operator Precedence

C++ follows mathematical precedence rules.

Example

```cpp
2 + 3 * 4
```

Result

```
14
```

because multiplication has higher precedence.

Using parentheses makes expressions clearer.

```cpp
(2 + 3) * 4
```

Result

```
20
```

When expressions become complex, always prefer explicit parentheses.

---

# Common Mistakes

## Integer Division

```cpp
double x = 5 / 2;
```

Result

```
2
```

because the division happens before assignment.

Correct version

```cpp
double x = 5.0 / 2;
```

---

## Using % with doubles

Incorrect

```cpp
5.5 % 2
```

This does not compile.

The modulus operator only accepts integer operands.

---

## Dividing by Zero

```cpp
10 / 0
```

This causes undefined behavior.

Always ensure the denominator is not zero before performing division.

---

# Best Practices

✔ Store calculations in variables whenever possible.

✔ Use descriptive variable names.

✔ Prefer constants over magic numbers.

✔ Use parentheses to improve readability.

✔ Think about the data type before performing division.

---

# Scientific Computing Notes

Arithmetic operators appear everywhere in scientific software.

Examples include

- calculating particle momentum
- detector efficiencies
- probability calculations
- matrix operations
- numerical integration
- Monte Carlo simulations
- ROOT data analysis
- Geant4 detector simulations

Understanding arithmetic operators thoroughly is essential before moving on to more advanced numerical algorithms.

---

# Summary

After completing this chapter you should understand

- what operators are,
- how arithmetic operators work,
- the difference between integer and floating-point division,
- how the modulus operator works,
- why constants are useful,
- how operator precedence affects expressions,
- common mistakes beginners make,
- why arithmetic operators are fundamental in scientific programming.

---

# Exercises

## Exercise 1

Create two integer variables.

Perform every arithmetic operation and display the results.

---

## Exercise 2

Ask the user for two numbers.

Display

- sum
- difference
- product
- quotient
- remainder

---

## Exercise 3

Experiment with integer division.

Try

```cpp
7 / 2
```

```cpp
7.0 / 2
```

```cpp
7 / 2.0
```

Explain why the outputs differ.

---

## Exercise 4

Create a simple currency converter.

Convert Euros to U.S. Dollars using a constant exchange rate.

---

## Exercise 5 (Challenge)

Create a program that asks the user for a radius.

Calculate

- diameter
- circumference
- area

using

```cpp
const double PI {3.141592653589793};
```

Display every result with appropriate labels.