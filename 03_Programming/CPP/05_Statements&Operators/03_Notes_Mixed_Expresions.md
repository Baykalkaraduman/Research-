# Mixed Expressions and Type Conversion

---

# Introduction

Real-world programs rarely perform calculations using only one data type.

A single mathematical expression may contain

- integers
- floating-point numbers
- characters
- variables of different types

When different types appear in the same expression, C++ automatically performs **type conversions**.

Understanding these conversions is essential for writing correct numerical software.

---

# What is a Mixed Expression?

A mixed expression is an expression containing operands of different data types.

Example

```cpp
10 + 3.5
```

One operand is an integer.

The other is a double.

Before performing the addition, C++ converts the integer into a double.

The result becomes

```
13.5
```

---

# Integer Division

If both operands are integers,

```cpp
7 / 2
```

Result

```
3
```

The decimal part is discarded.

---

# Floating-Point Division

If at least one operand is a floating-point number,

```cpp
7.0 / 2
```

or

```cpp
7 / 2.0
```

Result

```
3.5
```

---

# Implicit Type Conversion

Sometimes C++ converts data automatically.

Example

```cpp
int x {5};

double y = x;
```

The integer is automatically promoted to a double.

This process is called **implicit conversion**.

---

# Explicit Type Conversion

Sometimes we want to perform the conversion ourselves.

Example

```cpp
static_cast<double>(x)
```

This is called an **explicit conversion**.

---

# C-Style Cast

Older C++ code often uses

```cpp
(double)x
```

Although valid, this style is discouraged.

Modern C++ recommends using

```cpp
static_cast<double>(x)
```

because it is safer and easier to read.

---

# static_cast

General syntax

```cpp
static_cast<NewType>(expression)
```

Example

```cpp
double average =
    static_cast<double>(total) / count;
```

This converts only the value being cast.

The original variable remains unchanged.

---

# Why use static_cast?

Advantages

- safer
- clearer
- checked by the compiler
- modern C++ style

Whenever possible, prefer `static_cast` over old C-style casts.

---

# Best Practices

✔ Use `static_cast` for explicit conversions.

✔ Never rely on implicit conversions unless they are obvious.

✔ Be careful with integer division.

✔ Remember that only one operand needs to be a floating-point value to obtain floating-point division.

---

# Common Mistakes

## Expecting integer division to keep decimals

```cpp
double average = total / count;
```

Incorrect if both variables are integers.

---

Correct

```cpp
double average =
static_cast<double>(total) / count;
```

---

## Using C-style casts

Avoid

```cpp
(double)total
```

Prefer

```cpp
static_cast<double>(total)
```

---

# Scientific Computing Notes

Type conversion is one of the most frequently used concepts in scientific programming.

Examples include

- detector efficiencies
- normalized histograms
- particle energies
- Monte Carlo weights
- numerical integration
- statistical calculations

Modern scientific C++ code almost always uses `static_cast`.

---

# Summary

After completing this chapter you should understand

- mixed expressions
- implicit conversion
- explicit conversion
- integer division
- floating-point division
- C-style casts
- static_cast
- why Modern C++ prefers static_cast

---

# Exercises

## Exercise 1

Compute the average of five integers.

First using integer division.

Then using `static_cast`.

Compare the results.

---

## Exercise 2

Experiment with

```cpp
5 / 2
5.0 / 2
5 / 2.0
```

Explain every output.

---

## Exercise 3

Write a temperature converter.

Convert Celsius into Fahrenheit.

Use `static_cast` whenever appropriate.

---

## Exercise 4

Read two integers.

Display

- integer quotient
- floating-point quotient

Compare the results.

---

## Exercise 5 (Challenge)

Ask the user to enter

- total distance
- total time

Calculate the average speed as a floating-point number using `static_cast`.