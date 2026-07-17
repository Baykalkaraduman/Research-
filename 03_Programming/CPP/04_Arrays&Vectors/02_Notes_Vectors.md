# std::vector

---

## Introduction

`std::vector` is one of the most important containers in Modern C++.

It belongs to the **Standard Template Library (STL)** and provides a dynamic array implementation.

Unlike traditional C-style arrays, vectors automatically manage memory and can change their size during program execution.

Because of their flexibility and safety, vectors are one of the most widely used data structures in scientific computing, software engineering, and game development.

---

# Why do we need vectors?

Imagine storing exam scores.

With arrays:

```cpp
int scores[5];
```

The size is fixed forever.

If you later need to store a sixth score, you must create another array and manually copy everything.

Vectors solve this problem.

```cpp
std::vector<int> scores;
```

Now new elements can simply be appended.

```cpp
scores.push_back(95);
```

No memory management is required from the programmer.

---

# Arrays vs Vectors

| Arrays | Vectors |
|---------|----------|
| Fixed size | Dynamic size |
| Faster in some situations | Slightly slower |
| Manual memory management | Automatic memory management |
| Less flexible | Highly flexible |
| Built into the language | Part of the STL |
| No built-in size information | Knows its own size |

Arrays are useful when the number of elements is known beforehand.

Vectors should be preferred whenever the amount of data may change.

---

# Creating Vectors

Empty vector

```cpp
std::vector<int> numbers;
```

Five elements initialized to zero

```cpp
std::vector<int> numbers(5);
```

Five elements initialized to 100

```cpp
std::vector<int> numbers(5,100);
```

Initialization list

```cpp
std::vector<int> numbers {10,20,30,40};
```

---

# Accessing Elements

There are two common methods.

## Using []

```cpp
numbers[2];
```

Advantages

- Very fast

Disadvantages

- No bounds checking
- Invalid indices cause undefined behavior

---

## Using `.at()`

```cpp
numbers.at(2);
```

Advantages

- Bounds checking
- Throws an exception if the index is invalid
- Safer during development

Disadvantages

- Slightly slower than `[]`

For debugging and learning, `.at()` is generally recommended.

---

# Common Member Functions

## size()

Returns the current number of elements.

```cpp
numbers.size();
```

Example

```
10
20
30
40
```

Size = 4

---

## push_back()

Adds a new element to the end of the vector.

```cpp
numbers.push_back(50);
```

Result

```
10
20
30
40
50
```

---

## front()

Returns the first element.

```cpp
numbers.front();
```

Example

```
First element = 10
```

---

## back()

Returns the last element.

```cpp
numbers.back();
```

Example

```
Last element = 50
```

---

## empty()

Checks whether the vector contains any elements.

```cpp
if(numbers.empty())
```

Returns

- true
- false

This function is extremely useful before calling `front()` or `back()`.

---

# Nested Vectors

A vector may contain other vectors.

```cpp
std::vector<std::vector<int>> matrix;
```

Example

```cpp
std::vector<std::vector<int>> matrix
{
    {1,2,3},
    {4,5,6},
    {7,8,9}
};
```

Access

```cpp
matrix.at(1).at(2);
```

Output

```
6
```

Nested vectors are similar to two-dimensional arrays but are much more flexible.

---

# Memory Model

Many beginners think a nested vector is stored exactly like a two-dimensional array.

This is **not true**.

Two-dimensional array

```
+---------------------------+
|1|2|3|4|5|6|7|8|9|
+---------------------------+
```

One continuous memory block.

---

Nested vector

```
vector
 │
 ├── vector<int>
 │
 ├── vector<int>
 │
 └── vector<int>
```

Each row is an independent vector.

Advantages

- Rows may have different lengths.
- Rows may be resized independently.
- Easier insertion and deletion.

---

# How does push_back() work?

When the current storage becomes full,

the vector

1. allocates a larger memory block,
2. copies every element,
3. destroys the old memory,
4. continues execution.

This entire process happens automatically.

The programmer never needs to allocate or free memory manually.

---

# Best Practices

✔ Prefer vectors over arrays whenever the size is unknown.

✔ Use `.at()` while learning.

✔ Use `front()` and `back()` for readability.

✔ Prefer `push_back()` instead of manually managing memory.

✔ Use vectors in modern C++ projects.

---

# Common Mistakes

## Accessing an invalid index

```cpp
numbers[100];
```

Undefined behavior.

---

## Calling front() on an empty vector

```cpp
numbers.front();
```

Undefined behavior.

Always check

```cpp
if(!numbers.empty())
```

---

## Forgetting that vectors resize automatically

Do not manually allocate memory for vectors.

The container already manages memory internally.

---

# Scientific Computing Notes

Vectors are used extensively in modern scientific software.

Examples include

- ROOT
- Geant4
- Eigen
- Boost
- HepMC
- OpenCV
- Tensor libraries

Particle physics analyses often store

- detector hits
- particle collections
- event information
- reconstructed objects

inside vectors.

If you work in High Energy Physics, vectors will become one of your most frequently used C++ containers.

---

# Summary

After completing this chapter you should know

- what a vector is,
- why vectors are preferred over arrays,
- how to create vectors,
- how to access elements,
- how to append new elements,
- how nested vectors work,
- how vectors manage memory,
- why vectors are essential in scientific computing.

---

# Exercises

## Exercise 1

Create a vector containing five integers.

Display all of them.

---

## Exercise 2

Ask the user for three numbers.

Store them inside a vector.

Display the vector.

---

## Exercise 3

Create a vector of doubles representing temperatures.

Display the first and last temperature using

- `front()`
- `back()`

---

## Exercise 4

Create a nested vector representing a 3×3 matrix.

Print every element.

---

## Exercise 5 (Challenge)

Create a program that

- reads five exam scores,
- stores them in a vector,
- prints the highest,
- prints the lowest,
- prints the average.

(We will improve this program later using loops.)