# Increment and Decrement Operators

---

# Introduction

Increment (`++`) and decrement (`--`) are unary operators that increase or decrease the value of a variable by one.

Although they appear simple, understanding the difference between **prefix** and **postfix** forms is essential for writing correct and efficient C++ programs.

These operators are used extensively in loops, iterators, array indexing, and scientific software.

---

# Increment Operator (++)

The increment operator increases a variable by one.

```cpp
counter++;
```

is equivalent to

```cpp
counter = counter + 1;
```

Example

```cpp
int counter {10};

counter++;
```

Result

```
11
```

---

# Decrement Operator (--)

The decrement operator decreases a variable by one.

```cpp
counter--;
```

is equivalent to

```cpp
counter = counter - 1;
```

---

# Prefix vs Postfix

There are two ways to use these operators.

## Prefix

```cpp
++counter
```

The variable is incremented **before** its value is used.

Example

```cpp
int counter {10};

int result = ++counter;
```

Output

```
counter = 11
result = 11
```

---

## Postfix

```cpp
counter++
```

The current value is used first.

Only after the expression finishes does the variable increase.

Example

```cpp
int counter {10};

int result = counter++;
```

Output

```
counter = 11
result = 10
```

---

# Prefix vs Postfix Timeline

Prefix

```
Increment

↓

Use new value
```

Postfix

```
Use current value

↓

Increment afterwards
```

---

# Using Increment Inside Expressions

Example

```cpp
int result = ++counter + 10;
```

If

```
counter = 10
```

Result

```
counter = 11
result = 21
```

---

Example

```cpp
int result = counter++ + 10;
```

Result

```
counter = 11
result = 20
```

---

# Decrement Examples

Prefix

```cpp
--counter;
```

Postfix

```cpp
counter--;
```

They behave exactly like increment operators, but subtract one instead.

---

# Best Practices

✔ Prefer prefix when you do not need the old value.

✔ Avoid writing expressions like

```cpp
i++++
```

or

```cpp
++i++
```

They are confusing and often invalid.

✔ Never modify the same variable multiple times inside one expression.

Bad example

```cpp
int x = i++ + ++i;
```

This leads to undefined behavior and should never be written.

---

# Scientific Computing Notes

Increment operators appear constantly in scientific software.

Examples include

- loop counters
- array traversal
- detector hit processing
- event loops
- particle collections
- STL iterators
- ROOT analyses
- Geant4 simulations

Modern C++ style generally prefers **prefix increment** (`++i`) when iterating with iterators because it may avoid unnecessary temporary objects.

---

# Summary

After completing this chapter you should understand

- increment operators
- decrement operators
- prefix increment
- postfix increment
- prefix decrement
- postfix decrement
- when prefix and postfix behave differently
- best programming practices

---

# Exercises

## Exercise 1

Create an integer initialized to 25.

Increment it five times.

Display the result.

---

## Exercise 2

Create a counter.

Compare

```cpp
++counter
```

and

```cpp
counter++
```

using a second variable.

---

## Exercise 3

Repeat the same experiment using decrement operators.

---

## Exercise 4

Predict the output before running the following code.

```cpp
int x {5};

std::cout << x++ << std::endl;
std::cout << x << std::endl;
```

Verify your prediction.

---

## Exercise 5 (Challenge)

Without compiling the program, determine the output of

```cpp
int a {10};

int b = ++a;

int c = a++;

std::cout << a << " "
          << b << " "
          << c;
```

Explain every step.