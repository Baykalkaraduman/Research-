# C++ `<cmath>` Library

---

# Introduction

The `<cmath>` library provides a collection of mathematical functions used in scientific computing, engineering, computer graphics, simulations, and numerical analysis.

Instead of implementing mathematical algorithms manually, C++ provides optimized and well-tested implementations inside the Standard Library.

To use these functions, include

```cpp
#include <cmath>
```

---

# Why Use `<cmath>`?

Imagine computing the square root of a number.

Without `<cmath>`

- You would have to implement an algorithm yourself.
- It would be slower.
- It would be more error-prone.

Using the Standard Library

```cpp
double x {25};

std::cout << sqrt(x);
```

Output

```
5
```

Simple, efficient, and portable.

---

# Square Root

Function

```cpp
sqrt(x)
```

Returns

```
√x
```

Example

```cpp
double x {81};

std::cout << sqrt(x);
```

Output

```
9
```

---

# Cube Root

Function

```cpp
cbrt(x)
```

Example

```cpp
double x {27};

std::cout << cbrt(x);
```

Output

```
3
```

---

# Powers

Function

```cpp
pow(base, exponent)
```

Example

```cpp
pow(2,5)
```

Output

```
32
```

Another example

```cpp
pow(9,0.5)
```

Output

```
3
```

---

# Absolute Value

There are two commonly used functions.

For integers

```cpp
abs()
```

For floating-point numbers

```cpp
fabs()
```

Example

```cpp
abs(-15)
```

Output

```
15
```

Example

```cpp
fabs(-3.75)
```

Output

```
3.75
```

---

# Trigonometric Functions

The Standard Library provides

```cpp
sin()

cos()

tan()
```

Example

```cpp
double angle {1.57};

std::cout << sin(angle);
```

Important

These functions expect **radians**, not degrees.

---

# Degrees to Radians

Formula

```cpp
radians = degrees * π / 180
```

Example

```cpp
const double PI {3.141592653589793};

double radians = degrees * PI / 180.0;
```

---

# Rounding Functions

## ceil()

Rounds upward.

Example

```cpp
ceil(3.2)
```

Output

```
4
```

---

## floor()

Rounds downward.

Example

```cpp
floor(3.8)
```

Output

```
3
```

---

## round()

Rounds to the nearest integer.

Example

```cpp
round(3.6)
```

Output

```
4
```

Example

```cpp
round(3.2)
```

Output

```
3
```

---

## trunc()

Removes the fractional part.

Example

```cpp
trunc(3.99)
```

Output

```
3
```

Example

```cpp
trunc(-3.99)
```

Output

```
-3
```

---

# Exponential Function

Function

```cpp
exp(x)
```

Returns

```
eˣ
```

Example

```cpp
exp(1)
```

Output

```
2.71828...
```

---

# Natural Logarithm

Function

```cpp
log(x)
```

Returns

```
ln(x)
```

Example

```cpp
log(2.7182818)
```

Output

```
1
```

Important

The input must satisfy

```cpp
x > 0
```

---

# Base-10 Logarithm

Function

```cpp
log10(x)
```

Example

```cpp
log10(1000)
```

Output

```
3
```

---

# Distance Formula

Function

```cpp
hypot(x,y)
```

Computes

```
√(x²+y²)
```

Example

```cpp
hypot(3,4)
```

Output

```
5
```

This function is preferred over manually writing

```cpp
sqrt(x*x+y*y)
```

because it is more numerically stable.

---

# Floating-Point Modulus

Function

```cpp
fmod(a,b)
```

Example

```cpp
fmod(7.5,2.0)
```

Output

```
1.5
```

Unlike

```cpp
%
```

this function works with floating-point numbers.

---

# Formatting Output

Scientific programs usually display decimal values with fixed precision.

Include

```cpp
#include <iomanip>
```

Example

```cpp
std::cout << fixed << setprecision(4);
```

Output

```
3.1416
```

---

# Common Mathematical Functions

| Function | Description |
|-----------|-------------|
| `sqrt()` | Square root |
| `cbrt()` | Cube root |
| `pow()` | Power |
| `abs()` | Absolute value (integers) |
| `fabs()` | Absolute value (floating-point) |
| `sin()` | Sine |
| `cos()` | Cosine |
| `tan()` | Tangent |
| `ceil()` | Round upward |
| `floor()` | Round downward |
| `round()` | Round to nearest integer |
| `trunc()` | Remove decimal part |
| `exp()` | eˣ |
| `log()` | Natural logarithm |
| `log10()` | Base-10 logarithm |
| `hypot()` | Distance formula |
| `fmod()` | Floating-point remainder |

---

# Scientific Computing Notes

The `<cmath>` library is one of the most frequently used libraries in scientific programming.

Examples include

- Physics simulations
- Astronomy
- Computational chemistry
- Machine learning
- Robotics
- Computer graphics
- Game engines
- Signal processing
- ROOT
- Geant4
- Numerical methods

Many scientific algorithms are impossible to implement efficiently without mathematical functions.

---

# Best Practices

✔ Always include

```cpp
#include <cmath>
```

when using mathematical functions.

✔ Prefer Standard Library functions instead of implementing your own.

✔ Remember that trigonometric functions use **radians**.

✔ Check that logarithm arguments are positive.

✔ Use `hypot()` instead of manually computing distances.

✔ Format floating-point output using

```cpp
fixed
```

and

```cpp
setprecision()
```

for readable results.

---

# Common Mistakes

## Using degrees instead of radians

Incorrect

```cpp
sin(90)
```

Correct

```cpp
sin(90 * PI / 180)
```

---

## Taking the logarithm of zero or a negative number

Incorrect

```cpp
log(-5)
```

This results in a domain error.

---

## Using `%` with doubles

Incorrect

```cpp
7.5 % 2.0
```

Correct

```cpp
fmod(7.5,2.0)
```

---

## Forgetting `<cmath>`

Without

```cpp
#include <cmath>
```

most mathematical functions are unavailable.

---

# Summary

After completing this chapter you should understand

- Why `<cmath>` exists
- Square roots
- Cube roots
- Powers
- Absolute values
- Trigonometric functions
- Degree-radian conversion
- Rounding functions
- Exponential functions
- Logarithms
- Distance calculations
- Floating-point modulus
- Scientific applications of `<cmath>`

---

# Exercises

## Exercise 1

Ask the user for a number.

Display

- square root
- cube root
- square

---

## Exercise 2

Ask the user for an angle in degrees.

Convert it to radians.

Display

- sine
- cosine
- tangent

---

## Exercise 3

Ask the user for two points

```
(x,y)
```

Calculate the distance from the origin using `hypot()`.

---

## Exercise 4

Ask the user for a positive number.

Display

- `ln(x)`
- `log10(x)`
- `exp(x)`

---

## Exercise 5 (Challenge)

Create a scientific calculator that allows the user to choose between

- square root
- powers
- trigonometric functions
- logarithms
- rounding functions

using a menu system.