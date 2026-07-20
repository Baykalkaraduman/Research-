# Simple Pointers

## Introduction

A **pointer** is a variable whose purpose is to store the **memory address** of another object. Unlike ordinary variables that store actual values, pointers store locations in memory.

Pointers are one of the most powerful features of C++. They allow direct interaction with memory, making C++ suitable for systems programming, operating systems, embedded systems, game engines, scientific computing, and high-performance applications.

Understanding pointers is essential before learning:

- References
- Dynamic Memory Allocation
- Arrays
- C-style Strings
- Linked Lists
- Trees
- Smart Pointers
- STL Iterators

---

# Why Do We Need Pointers?

Normally, variables store values.

```cpp
int age {25};
```

Memory might look like:

```
Address        Value
---------      -----
0x1000          25
```

A pointer stores the address instead.

```cpp
int* ptr {&age};
```

```
Variable      Stores
--------      ----------------
ptr           0x1000
```

Now the pointer knows where `age` lives in memory.

---

# Memory Visualization

```
          Memory

+----------------------+
| Address : 0x1000     |
| Value   : 25         |
+----------------------+
          ▲
          │
          │
      +-----------+
      |   ptr     |
      | 0x1000    |
      +-----------+
```

Notice:

- `age` stores **25**
- `ptr` stores **0x1000**

The pointer **does not** store the integer itself.

---

# Pointer Declaration Syntax

General syntax:

```cpp
type* pointer_name;
```

Examples:

```cpp
int* ptr;
double* temperature_ptr;
char* character_ptr;
string* name_ptr;
vector<int>* vector_ptr;
```

Modern C++ initialization:

```cpp
int* ptr {nullptr};
```

This is the safest way.

---

# Address-of Operator (&)

The address-of operator returns the memory address of a variable.

```cpp
int number {50};

cout << &number;
```

Possible output:

```
0x61FF08
```

The exact address changes every execution because the operating system determines memory allocation.

---

# Creating a Pointer

```cpp
int score {95};

int* score_ptr {nullptr};

score_ptr = &score;
```

Memory representation:

```
score

Address      Value
--------     -----
0x5000        95

score_ptr

Value
------
0x5000
```

The pointer stores the address, not the value.

---

# nullptr

Modern C++ introduced **nullptr**.

```cpp
int* ptr {nullptr};
```

Meaning:

> This pointer currently points to nothing.

Never leave pointers uninitialized.

Bad:

```cpp
int* ptr;
```

Good:

```cpp
int* ptr {nullptr};
```

---

# Pointer Sizes

One surprising fact is that every pointer usually has exactly the same size.

Example:

```cpp
int* p1;
double* p2;
string* p3;
vector<int>* p4;
```

Typical 64-bit output:

```
sizeof(p1) = 8 bytes
sizeof(p2) = 8 bytes
sizeof(p3) = 8 bytes
sizeof(p4) = 8 bytes
```

Why?

Pointers never store the object itself.

They only store a memory address.

A memory address always has the same size on the same architecture.

---

# Type Safety

Pointers are type-safe.

Correct:

```cpp
int number {10};

int* ptr {&number};
```

Wrong:

```cpp
double value {3.14};

int* ptr {&value};
```

Compiler Error.

The compiler prevents assigning addresses of incompatible types because different data types have different memory layouts.

---

# Pointer Variable vs Pointed Object

Many beginners confuse these two concepts.

```cpp
int score {100};

int* ptr {&score};
```

```
score = 100

ptr = address of score
```

Pointer Variable

```
Variable
---------
ptr
```

Pointed Object

```
score
```

These are two completely different objects.

---

# How Memory Works

Suppose we have:

```cpp
int age {25};

int* age_ptr {&age};
```

Memory may look like:

```
Variable      Address      Stored Value
----------------------------------------
age           0x1000       25

age_ptr       0x2000       0x1000
```

Notice carefully:

- `age` stores **25**
- `age_ptr` stores **0x1000**

The pointer is just another variable whose value happens to be an address.

---

# Best Practices

✔ Always initialize pointers.

```cpp
int* ptr {nullptr};
```

✔ Use meaningful names.

```cpp
student_ptr
matrix_ptr
temperature_ptr
```

✔ Keep pointer types consistent.

✔ Prefer Modern C++ initialization.

```cpp
int* ptr {nullptr};
```

instead of

```cpp
int *ptr;
```

✔ Initialize immediately after declaration whenever possible.

---

# Common Mistakes

## 1. Leaving pointers uninitialized

Wrong:

```cpp
int* ptr;

cout << ptr;
```

The pointer contains an unknown (garbage) address.

---

## 2. Forgetting nullptr

Wrong:

```cpp
int* ptr;
```

Correct:

```cpp
int* ptr {nullptr};
```

---

## 3. Mixing pointer types

Wrong:

```cpp
double d {3.14};

int* ptr {&d};
```

Compiler error.

---

## 4. Thinking a pointer stores data

Wrong idea:

```
ptr = 25
```

Reality:

```
ptr = 0x61FF08
```

Pointers store addresses.

---

## 5. Confusing the pointer with the variable

```
score
```

is NOT

```
score_ptr
```

One stores the value.

The other stores its address.

---

# Scientific Notes

Pointers are fundamental in scientific computing.

Libraries such as:

- ROOT
- Geant4
- Eigen
- OpenCV
- CUDA
- MPI

all make extensive use of pointers internally.

Although Modern C++ often hides raw pointers behind smart pointers and STL containers, understanding raw pointers is essential for:

- Reading scientific source code
- Debugging segmentation faults
- Optimizing performance
- Understanding memory management

---

# Performance Notes

Pointers are extremely lightweight.

Typical size on modern systems:

```
32-bit OS → 4 Bytes

64-bit OS → 8 Bytes
```

Copying a pointer copies only an address, making pointer copies much cheaper than copying large objects.

---

# Modern C++ Notes

Modern C++ encourages safer pointer usage.

Instead of:

```cpp
NULL
```

use:

```cpp
nullptr
```

Modern C++ also provides smart pointers:

- `std::unique_ptr`
- `std::shared_ptr`
- `std::weak_ptr`

These automatically manage memory and help prevent memory leaks.

However, understanding raw pointers is essential because smart pointers are built upon the same core concepts.

---

# Summary

After completing this topic, you should understand:

- What a pointer is.
- Why pointers exist.
- The difference between values and addresses.
- The Address-of Operator (`&`).
- Pointer declaration syntax.
- `nullptr`.
- Pointer sizes.
- Type safety.
- Memory visualization.
- Modern pointer initialization.

---

# Exercises

## Exercise 1

Create an integer variable.

Create a pointer pointing to it.

Print:

- value
- address
- pointer value

---

## Exercise 2

Create pointers for:

- int
- double
- string
- vector<int>

Print the size of every pointer.

---

## Exercise 3

Initialize every pointer using `nullptr`.

Explain why this is safer than leaving them uninitialized.

---

## Exercise 4

Create three variables:

```cpp
int
double
char
```

Attempt to assign their addresses to mismatched pointer types.

Observe and explain the compiler errors.

---

## Exercise 5

Draw the memory layout for:

```cpp
int score {95};

int* ptr {&score};
```

Include:

- Variable
- Address
- Stored value
- Pointer value

---

## Key Takeaways

- A pointer is a variable that stores a memory address.
- The `&` operator returns the address of a variable.
- Pointer types must match the object's type.
- Always initialize pointers with `nullptr`.
- All pointers generally have the same size on the same architecture.
- Pointers do **not** store data; they store addresses.
- Understanding raw pointers is the foundation for advanced C++ topics such as dynamic memory, smart pointers, STL iterators, and many scientific computing libraries.