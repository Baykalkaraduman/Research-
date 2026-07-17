# The sizeof Operator

---

# Objective

Learn how to determine the memory occupied by variables and data types.

---

# Why is Memory Important?

Every variable occupies memory.

Choosing the correct data type is important because

- Memory is limited.
- Larger data types consume more RAM.
- Scientific software often stores millions or even billions of values.

---

# The sizeof Operator

The `sizeof` operator returns the number of bytes occupied by a type or variable.

Example

```cpp
sizeof(int)
```

returns

```
4
```

on most modern systems.

You can also write

```cpp
int age {23};

sizeof(age)
```

Both are valid.

---

# Common Data Type Sizes

| Type | Typical Size |
|------|-------------:|
| char | 1 byte |
| short | 2 bytes |
| int | 4 bytes |
| long | 8 bytes (Linux x64) |
| long long | 8 bytes |
| float | 4 bytes |
| double | 8 bytes |
| long double | 16 bytes (compiler dependent) |

> **Note:** These values depend on the compiler and architecture. Always verify them with `sizeof` instead of assuming fixed sizes.

---

# What is a Byte?

```
1 Byte = 8 Bits
```

One bit stores only

```
0

or

1
```

Example

```
char

↓

1 Byte

↓

8 Bits
```

---

# Integer Limits

The `<climits>` library provides predefined constants describing the limits of integer types.

Examples

```cpp
INT_MAX

INT_MIN

LONG_MAX

LLONG_MAX
```

These values help prevent overflow.

---

# Overflow

Every integer type has a maximum value.

Example

```
INT_MAX

↓

2147483647
```

Adding one

```
2147483648
```

cannot be represented in a 32-bit signed integer.

Overflow occurs.

---

# Best Practices

✔ Use `sizeof()` instead of memorizing data type sizes.

✔ Use `<climits>` when checking integer ranges.

✔ Prefer `double` for scientific calculations.

✔ Choose the smallest suitable type only when memory usage is critical.

---

# Physics Applications

Memory matters in High Energy Physics.

Examples

- Detector hit collections
- Event data
- Monte Carlo simulations
- ROOT Trees
- Geant4 simulations
- Machine Learning datasets

A ROOT file may contain hundreds of millions of events.

Saving just **4 bytes per event** can reduce storage by hundreds of megabytes or even gigabytes.

---

# Exercises

1. Print the size of `bool`.

2. Print the size of `std::string`.

3. Create variables of different types and print their sizes.

4. Calculate how much memory one million `double` values require.

5. Calculate how much memory one billion `bool` values require (assume one byte per `bool`).

6. Print the maximum value of `unsigned int`.

---

# Connections

This topic will be used later in

- Arrays
- Pointers
- Dynamic Memory
- Structures
- Classes
- STL Containers
- ROOT
- Geant4
- Detector Simulation

---

# Summary

In this lesson you learned

- `sizeof`
- Memory layout
- Bytes and bits
- `<climits>`
- Integer limits
- Overflow
- Why memory management matters in scientific programming