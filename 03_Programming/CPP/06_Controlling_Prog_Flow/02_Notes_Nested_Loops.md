# Nested Loops

---

# Introduction

A **nested loop** is simply a loop that exists inside another loop.

```cpp
for (...)
{
    for (...)
    {

    }
}
```

The outer loop controls how many times the inner loop will execute.

Nested loops are extremely common in C++ and appear frequently when working with

- matrices
- multidimensional arrays
- nested vectors
- tables
- pattern generation
- image processing
- scientific simulations

---

# Why do we need Nested Loops?

Suppose you want to print a multiplication table.

```
1 x 1
1 x 2
1 x 3

2 x 1
2 x 2
2 x 3
```

One loop controls the rows.

The second loop controls the columns.

Without nested loops this would require a huge amount of repetitive code.

---

# General Syntax

```cpp
for(initialization)
{
    for(initialization)
    {

    }
}
```

The inner loop completes **all** of its iterations before the outer loop advances.

---

# How Nested Loops Work

Example

```cpp
for(int row = 1; row <= 3; row++)
{
    for(int column = 1; column <= 3; column++)
    {
        cout << row << "," << column << endl;
    }
}
```

Output

```
1,1
1,2
1,3
2,1
2,2
2,3
3,1
3,2
3,3
```

Notice that the inner loop starts over every time the outer loop advances.

---

# Multiplication Table Example

Your program prints

```cpp
1 x 2 = 2
1 x 3 = 3
...
```

using

```cpp
for(int num1 {1}; num1 <= 10; num1++)
{
    for(int num2 {2}; num2 <= 10; num2++)
    {
        cout << num1 << " x " << num2
             << " = "
             << num1 * num2
             << endl;
    }

    cout << "======================" << endl;
}
```

The outer loop chooses the current multiplication row.

The inner loop calculates every multiplication inside that row.

---

# Nested Loops with Vectors

Nested loops become much more useful when working with containers.

Example

```cpp
vector<vector<int>> matrix
{
    {1,2,3},
    {4,5,6},
    {7,8,9}
};
```

Printing every element

```cpp
for(size_t row = 0; row < matrix.size(); row++)
{
    for(size_t column = 0; column < matrix[row].size(); column++)
    {
        cout << matrix[row][column] << " ";
    }

    cout << endl;
}
```

This idea is used constantly in scientific software.

---

# Range-Based For Loops

Your histogram program introduces another modern C++ feature.

```cpp
for(auto value : data)
{
    cout << value << endl;
}
```

Instead of writing

```cpp
for(size_t i = 0; i < data.size(); i++)
```

the compiler automatically visits every element.

Advantages

- cleaner code
- fewer indexing mistakes
- easier to read
- recommended in Modern C++

---

# Histogram Example

Your second example is an excellent practical application.

The program

1. asks the user how many values will be entered,
2. stores those values inside a vector,
3. prints a simple histogram.

Example

Input

```
3

4
8
12
```

Output

```
----
--------/
----------/--
```

Every dash represents one unit.

Every fifth dash is replaced by

```
-/
```

making the histogram easier to read.

This is a simple example of data visualization.

---

# Time Complexity

Suppose

Outer loop executes

```
n
```

times

and the inner loop executes

```
m
```

times.

The total work is

```
n × m
```

This is called

```
O(nm)
```

If both loops iterate over the same size

```
n
```

then

```
O(n²)
```

Nested loops can become computationally expensive for very large datasets.

---

# Scientific Computing Notes

Nested loops appear everywhere in scientific programming.

Examples include

- matrix multiplication
- detector geometry
- finite element methods
- particle tracking
- image processing
- Monte Carlo simulations
- lattice calculations
- heat transfer simulations

ROOT and Geant4 analyses frequently iterate through collections of particles using nested loops.

---

# Best Practices

✔ Keep nested loops as short as possible.

✔ Use meaningful variable names.

```cpp
row
column
particle
hit
event
```

instead of

```cpp
i
j
k
```

whenever possible.

✔ Use range-based for loops when indexing is unnecessary.

✔ Avoid deeply nested loops when possible.

---

# Common Mistakes

## Forgetting to reset the inner loop

Fortunately, `for` loops automatically reset the loop variable every iteration.

---

## Infinite loops

Incorrect loop conditions may prevent the inner loop from terminating.

---

## Confusing outer and inner loop variables

Avoid using similar names.

Instead of

```cpp
i
j
```

prefer

```cpp
row
column
```

---

## Unnecessary nesting

Sometimes a single loop is sufficient.

Do not automatically use nested loops if they are not required.

---

# Summary

After completing this chapter you should understand

- what nested loops are,
- how the outer and inner loops interact,
- how multiplication tables are generated,
- how nested loops work with vectors,
- how range-based for loops simplify iteration,
- why nested loops are essential in scientific computing.

---

# Exercises

## Exercise 1

Print a multiplication table from

```
1 × 1

to

10 × 10
```

---

## Exercise 2

Create a rectangle using stars.

Example

```
*****
*****
*****
*****
```

---

## Exercise 3

Create a right triangle.

```
*
**
***
****
*****
```

---

## Exercise 4

Create a 3×3 vector.

Print every element using nested loops.

---

## Exercise 5 (Challenge)

Ask the user for the dimensions of a matrix.

Store the values inside a nested vector.

Print the matrix exactly as entered.

(You will revisit this example later when learning functions and algorithms.)