# Arrays in C++

---

# Objective

In this lesson, we introduce one of the most fundamental data structures in C++: **arrays**.

Arrays allow us to store multiple values of the same data type inside a single variable.

They are one of the building blocks of programming and are used extensively in scientific computing, data analysis, and high-energy physics.

---

# What is an Array?

An array is a collection of elements of the **same data type** stored in **contiguous memory locations**.

Instead of creating many variables,

```cpp
int score1;
int score2;
int score3;
int score4;
int score5;
```

we can simply write

```cpp
int scores[5];
```

The compiler allocates memory for five integers.

---

# Array Declaration

```cpp
int scores[5];
```

creates an array with five integer elements.

---

# Array Initialization

Arrays may be initialized during declaration.

```cpp
int scores[] {90, 85, 76, 100, 92};
```

The compiler automatically determines the size.

---

# Indexing

Arrays use **zero-based indexing**.

```
Element

90   85   76   100   92

Index

0    1    2    3     4
```

Accessing

```cpp
scores[0]
```

returns

```
90
```

---

# Modifying Elements

Individual elements can be changed.

```cpp
scores[0] = 95;
```

Only that element changes.

---

# Initialization Types

## Uninitialized

```cpp
int numbers[5];
```

Contains garbage values.

---

## Zero Initialization

```cpp
int numbers[5] {};
```

All elements become

```
0
```

---

## Partial Initialization

```cpp
int numbers[5] {100};
```

Produces

```
100
0
0
0
0
```

---

# Memory Representation

```
scores

↓

+-----+-----+-----+-----+-----+

| 90  | 85  | 76  |100  | 92  |

+-----+-----+-----+-----+-----+

  0     1     2     3     4
```

All elements are stored sequentially.

---

# Advantages

- Simple
- Fast
- Contiguous memory
- Excellent cache performance
- Very efficient for numerical computing

---

# Limitations

- Fixed size
- Cannot grow dynamically
- No bounds checking with `[]`

---

# Arrays in Physics

Arrays appear everywhere in scientific software.

Examples include:

- Detector channels
- Temperature measurements
- Event counters
- Histogram bins
- Sensor readings
- Experimental measurements

Although modern C++ often uses `std::vector`, understanding arrays is essential because many scientific libraries and legacy codes still rely on them.

---

# Best Practices

✔ Initialize arrays whenever possible.

✔ Avoid accessing indices outside the valid range.

✔ Use meaningful variable names.

✔ Prefer `std::vector` when the size is not known in advance.

---

# Common Mistakes

❌ Reading uninitialized arrays.

❌ Writing outside array boundaries.

❌ Assuming indexing starts at 1.

---

# Connections

This topic is the foundation for:

- Loops
- Functions
- Pointers
- Dynamic Memory
- STL Containers
- ROOT
- Geant4
- Coffea

---

# Summary

After completing this lesson you should understand:

- What an array is
- How arrays are stored in memory
- Array declaration
- Initialization methods
- Indexing
- Modifying elements
- Memory layout
- Common mistakes