# Floating Point Numbers

---

# Objective

Learn how computers store decimal numbers and understand the differences between float, double and long double.

---

# Why Floating Point?

Integers cannot represent decimal numbers.

Examples

```
3.14

2.71828

9.81

6.626×10⁻³⁴
```

For these numbers we use floating-point data types.

---

# Data Types

## float

Approximately

```
7 decimal digits
```

Memory

```
4 Bytes
```

---

## double

Approximately

```
15 decimal digits
```

Memory

```
8 Bytes
```

Most scientific software uses double.

---

## long double

Higher precision.

Memory depends on the compiler and operating system.

Usually

```
16 Bytes
```

or

```
80-bit Extended Precision
```

---

# Scientific Notation

```cpp
6.62607015e-34
```

means

```
6.62607015 × 10⁻³⁴
```

This notation is widely used in physics.

---

# Precision

Different types store different numbers of digits.

```
float

3.1415927

double

3.141592653589793

long double

3.141592653589793238...
```

Higher precision requires more memory.

---

# Best Practices

Use

```
double
```

unless memory is extremely limited.

Most scientific libraries use

```
double
```

by default.

---

# Common Mistakes

Using

```cpp
float
```

when high precision is required.

Comparing floating point numbers with

```cpp
==
```

instead of using a tolerance.

We will learn why later.

---

# Physics Applications

Examples

```
Particle energy

Momentum

Mass

Detector position

Time of flight

Cross section

Planck constant

Speed of light
```

Almost every calculation in particle physics uses floating point numbers.

---

# Exercises

1. Create variables using

- float
- double
- long double

2. Store π.

3. Store the speed of light.

4. Store the Planck constant.

5. Multiply two doubles.

6. Compare precision.

---

# Summary

You learned

- float
- double
- long double
- Scientific notation
- Precision
- Scientific computing