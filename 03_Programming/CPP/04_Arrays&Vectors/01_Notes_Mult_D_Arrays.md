# Multi-Dimensional Arrays in C++

---

# Objective

In this lesson, we extend the concept of arrays by introducing **multi-dimensional arrays**.

A two-dimensional array can be thought of as a table, spreadsheet, image, or matrix.

This type of data structure is extremely common in scientific computing, simulations, detector physics, and image processing.

---

# What is a Two-Dimensional Array?

A two-dimensional array is an array whose elements are themselves arrays.

Instead of storing data in a single line,

```
10 20 30 40
```

we organize the data into rows and columns.

Example:

```
1   2   3   4

2   4   1   3

12 17 22 40
```

---

# Declaration

General syntax:

```cpp
data_type array_name[rows][columns];
```

Example:

```cpp
int matrix[3][4];
```

This creates

- 3 rows
- 4 columns

for a total of

```
3 × 4 = 12
```

integer elements.

---

# Initialization

```cpp
int matrix[3][4]
{
    {1,2,3,4},
    {2,4,1,3},
    {12,17,22,40}
};
```

Each inner pair of braces represents one row.

---

# Visual Representation

```
            Columns

        0   1   2   3

      +----------------+

Row 0 | 1   2   3   4 |

Row 1 | 2   4   1   3 |

Row 2 |12  17  22  40 |

      +----------------+
```

---

# Accessing Elements

The syntax is

```cpp
matrix[row][column]
```

Example

```cpp
matrix[1][2]
```

returns

```
1
```

because

```
Row 1

2 4 1 3

      ↑

Column 2
```

---

# Modifying Elements

Changing an element is identical to one-dimensional arrays.

```cpp
matrix[2][3] = 12;
```

Only that single element changes.

---

# Memory Layout

Although a matrix looks like a table, it is still stored **contiguously in memory**.

Conceptually:

```
1

2

3

4

2

4

1

3

12

17

22

40
```

The compiler simply remembers where each row begins.

---

# Advantages

- Organizes tabular data naturally.
- Very fast indexing.
- Excellent cache performance.
- Simple syntax.
- Frequently used in numerical algorithms.

---

# Limitations

- Fixed size.
- All elements must have the same type.
- Cannot dynamically grow.
- No automatic bounds checking.

---

# Applications in Physics

Two-dimensional arrays appear frequently in physics and engineering.

Examples include:

- Detector hit maps
- Pixel detectors
- CCD cameras
- Heat maps
- Magnetic field grids
- Electric potential tables
- Finite difference simulations
- Numerical methods
- Image processing

---

# Scientific Example

Imagine a detector composed of pixels.

```
125  98  76

104 112  93

132 118 101
```

Each value represents the signal measured by one detector cell.

A two-dimensional array is a natural way to represent this information.

---

# Best Practices

✔ Keep row and column meanings clear.

✔ Use meaningful variable names.

✔ Avoid hard-coded indices whenever possible.

✔ Prefer loops when processing entire matrices.

---

# Common Mistakes

❌ Mixing row and column indices.

❌ Accessing invalid indices.

❌ Assuming indexing starts at 1.

---

# Connections

This lesson prepares you for

- Nested loops
- Matrix operations
- Image processing
- Numerical simulations
- Scientific computing
- ROOT histograms
- Geant4 detector geometries

---

# Summary

After completing this lesson, you should understand:

- What a two-dimensional array is
- How matrices are declared
- Initialization syntax
- Row and column indexing
- Element modification
- Memory organization
- Scientific applications