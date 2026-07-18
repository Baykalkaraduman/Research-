# Memory Behavior

One of the most important things to understand is what actually happens when an array is passed to a function.

Suppose we have

```cpp
int numbers[] {10,20,30,40,50};
```

Memory

```
Index:      0    1    2    3    4
Value:     10   20   30   40   50
Address: 1000 1004 1008 1012 1016
```

When calling

```cpp
print_array(numbers,5);
```

the function parameter

```cpp
const int arr[]
```

does **not** become another array.

Instead,

```
arr
```

contains the address of the first element.

```
numbers
      │
      ▼
+----+----+----+----+----+
|10  |20  |30  |40  |50  |
+----+----+----+----+----+
 ^
 |
arr
```

Both names refer to the same memory.

---

# Why Size Must Be Passed

Arrays lose their size information when passed to functions.

This works

```cpp
int values[] {1,2,3,4,5};

print_array(values,5);
```

Inside the function

```cpp
sizeof(values)
```

is **NOT**

```
5 × sizeof(int)
```

Instead it becomes

```
sizeof(pointer)
```

because arrays decay into pointers.

Therefore

```cpp
void print_array(const int arr[], size_t size)
```

requires

```
size
```

as a separate parameter.

---

# Arrays Decay Into Pointers

The compiler converts

```cpp
int arr[]
```

into

```cpp
int *arr
```

Therefore these declarations are identical.

```cpp
void print_array(int arr[], size_t size);
```

and

```cpp
void print_array(int *arr, size_t size);
```

Both receive a pointer.

The square brackets are only syntactic sugar.

---

# Read-Only Functions

Functions that only display data should receive

```cpp
const int arr[]
```

Example

```cpp
void display(const int arr[], size_t size);
```

Advantages

- Prevents accidental modification
- Easier to understand
- Safer code
- Compiler catches mistakes

---

# Modifying Functions

Functions that intentionally modify data should omit `const`.

Example

```cpp
void fill(int arr[], size_t size, int value)
{
    for(size_t i{}; i<size; ++i)
        arr[i]=value;
}
```

Now every element changes.

---

# Arrays Are Efficient

Passing arrays is very fast.

Imagine an array with

```
1,000,000 integers
```

Passing by value would require copying all million integers.

Instead C++ passes only one pointer.

Memory copied

```
8 bytes
```

instead of

```
4,000,000 bytes
```

This is one reason arrays are efficient.

---

# Scientific Computing

Passing arrays is everywhere in scientific software.

Examples

- Detector hit positions
- Particle energies
- Sensor measurements
- Monte Carlo events
- Experimental datasets
- Waveforms
- Images
- Matrices

ROOT analyses frequently contain functions like

```cpp
calculateEnergy(double energies[], size_t size);
```

or

```cpp
fillHistogram(double values[], size_t n);
```

---

# Modern C++ Alternatives

Raw arrays are still useful,

but modern C++ usually prefers

```cpp
std::array
```

for fixed-size arrays

or

```cpp
std::vector
```

for dynamic arrays.

Advantages

- Stores its own size
- Safer
- Easier to use
- Works well with STL algorithms

Example

```cpp
void print(const vector<int>& values)
```

No separate size parameter is required.

---

# Best Practices

✔ Use `const` whenever data should not change.

✔ Pass the array size separately.

✔ Use `size_t` for indices.

✔ Keep printing and modifying functions separate.

✔ Prefer `std::vector` or `std::array` in modern C++.

✔ Give descriptive parameter names.

Example

```cpp
const double temperatures[]
```

instead of

```cpp
const double arr[]
```

---

# Common Mistakes

## Forgetting const

Bad

```cpp
void print(int arr[])
```

Better

```cpp
void print(const int arr[])
```

---

## Forgetting the Size Parameter

Wrong

```cpp
void print(int arr[])
```

Correct

```cpp
void print(int arr[], size_t size)
```

---

## Using sizeof()

Wrong

```cpp
sizeof(arr)
```

inside the function.

It returns pointer size,

not array size.

---

## Out-of-Bounds Access

Wrong

```cpp
arr[size]
```

The last valid index is

```cpp
size - 1
```

---

## Assuming a Copy Was Made

Many beginners expect

```cpp
set_array(arr,...)
```

to modify only a copy.

It does not.

The original array changes because both refer to the same memory.

---

# Summary

After completing this chapter you should understand

- How arrays are passed to functions
- Why arrays decay into pointers
- Why array size must be passed separately
- Why `const` protects arrays
- The difference between read-only and modifying functions
- Why passing arrays is efficient
- Modern alternatives (`std::array` and `std::vector`)
- Common mistakes when working with arrays

---

# Exercises

## Exercise 1

Write a function

```cpp
void print_array(const int arr[], size_t size);
```

that prints every element.

---

## Exercise 2

Write

```cpp
void double_values(int arr[], size_t size);
```

that doubles every element.

Input

```
1 2 3 4
```

Output

```
2 4 6 8
```

---

## Exercise 3

Write

```cpp
int largest(const int arr[], size_t size);
```

that returns the largest element.

---

## Exercise 4

Write

```cpp
double average(const int arr[], size_t size);
```

that computes the arithmetic mean.

---

## Exercise 5

Write

```cpp
bool contains(const int arr[], size_t size, int value);
```

that returns whether a value exists inside the array.

---

## Exercise 6 (Challenge)

Write

```cpp
void reverse(int arr[], size_t size);
```

that reverses the array **in place** without creating another array.

Example

Input

```
1 2 3 4 5
```

Output

```
5 4 3 2 1
```

---

# Final Notes

Passing arrays to functions is one of the oldest mechanisms in C++, inherited from C.

Although modern C++ often favors `std::vector` and `std::array`, understanding raw array passing is essential because:

- many legacy codebases still use raw arrays,
- low-level embedded systems rely on them,
- scientific libraries frequently expose pointer-based APIs,
- they form the conceptual foundation for understanding pointers, references, and memory management.

Mastering this topic will make the transition to pointers, references, dynamic memory, and the Standard Template Library (STL) much easier.
---

# Scientific Notes

Passing arrays to functions is extremely common in scientific and engineering software.

Examples include:

- Sensor measurements
- Detector hits
- Monte Carlo events
- Particle energies
- Experimental observations
- Time-series measurements
- Numerical simulation results

Instead of copying thousands or millions of values, scientific software almost always passes arrays by address (or in modern C++, by reference).

Libraries such as

- ROOT
- Geant4
- Eigen
- OpenCV
- OpenGL

all rely heavily on passing large collections to functions efficiently.

Understanding how arrays behave when passed to functions is therefore essential for high-performance C++ programming.

---

# Arrays Decay into Pointers

One of the most important C++ concepts is that arrays **decay into pointers** when passed to functions.

Example

```cpp
int numbers[5];
```

Calling

```cpp
print_array(numbers, 5);
```

actually passes

```cpp
&numbers[0]
```

the address of the first element.

Inside the function

```cpp
arr
```

is **not** an array anymore.

It is effectively

```cpp
int* arr
```

This is why changes inside the function affect the original array.

---

# Why Size Must Be Passed Separately

Since arrays decay into pointers,

the compiler no longer knows how many elements exist.

This is why

```cpp
sizeof(arr)
```

inside the function does **not** return

```
number_of_elements × sizeof(element)
```

Instead it returns

```
sizeof(pointer)
```

Therefore every array-processing function should also receive its size.

Correct

```cpp
void print_array(const int arr[], size_t size);
```

Incorrect

```cpp
void print_array(int arr[]);
```

---

# Read-Only vs Modifiable Arrays

There are two common categories of array parameters.

### Read-only

```cpp
void print_array(const int arr[], size_t size);
```

Purpose

- display
- calculate statistics
- search
- compute averages
- compute minimum/maximum

The array must never change.

---

### Modifiable

```cpp
void set_array(int arr[], size_t size, int value);
```

Purpose

- initialize
- modify
- normalize
- sort
- fill
- transform

The function intentionally changes the original array.

---

# Why const is Important

Suppose your printing function accidentally contains

```cpp
arr[0] = 999;
```

Now every future use of the array is incorrect.

This bug can be difficult to find.

Adding

```cpp
const
```

prevents the compiler from allowing such mistakes.

This is one of the simplest and most powerful safety features in C++.

---

# Memory Behavior

Consider

```cpp
int scores[]{90,95,100};
```

Memory

```
scores

+----+----+-----+
|90  |95  |100  |
+----+----+-----+
 ^
 |
 address passed
```

Function call

```cpp
set_array(scores,3,0);
```

Inside the function

```
arr

|
v

+----+----+-----+
|90  |95  |100  |
+----+----+-----+
```

Both variables point to exactly the same memory.

There is only one array.

---

# Performance Considerations

Imagine

```cpp
int detector_hits[1000000];
```

Passing by value would require copying

```
1,000,000 integers
```

every function call.

That would be extremely slow.

Passing the address requires copying only

```
one pointer
```

which is usually only

```
8 bytes
```

on modern 64-bit systems.

This is why arrays are always passed efficiently.

---

# Arrays vs std::vector

Traditional arrays

```cpp
int arr[10];
```

Advantages

- Fast
- Very low overhead
- Compatible with C libraries

Disadvantages

- Fixed size
- Manual size management
- Easy to misuse

---

Modern C++

```cpp
vector<int> numbers;
```

Advantages

- Stores its own size
- Dynamic resizing
- Safer
- Rich member functions
- Preferred in modern C++

Whenever possible,

prefer

```cpp
std::vector
```

instead of raw arrays.

---

# Best Practices

✔ Use

```cpp
const
```

whenever the function should not modify the array.

✔ Always pass the array size.

✔ Use

```cpp
size_t
```

for array indices.

✔ Give functions descriptive names.

```cpp
print_array()

fill_array()

sort_array()

find_max()

compute_average()
```

✔ Prefer

```cpp
std::vector
```

for new C++ projects.

✔ Keep functions responsible for one task only.

---

# Common Mistakes

## Forgetting const

Bad

```cpp
void print(int arr[], size_t size)
```

Better

```cpp
void print(const int arr[], size_t size)
```

---

## Forgetting the size parameter

Bad

```cpp
void print(int arr[])
```

The function cannot determine the array length.

---

## Using sizeof()

Wrong

```cpp
sizeof(arr)
```

inside the function.

Remember:

Inside a function,

```cpp
arr
```

is a pointer.

---

## Accessing beyond the array

Wrong

```cpp
arr[size]
```

Last valid element

```cpp
arr[size - 1]
```

---

## Modifying arrays accidentally

Never change an array inside a function that is only supposed to display it.

Use

```cpp
const
```

to let the compiler enforce this rule.

---

# Summary

After completing this chapter you should understand

- Why arrays decay into pointers
- Why functions must receive the array size
- Passing arrays efficiently
- Using const for read-only arrays
- Modifying arrays through function parameters
- Memory sharing between caller and function
- Why vectors are preferred in modern C++

---

# Exercises

## Exercise 1

Write

```cpp
print_array()
```

that prints every element of an integer array.

---

## Exercise 2

Write

```cpp
fill_array()
```

that assigns a given value to every element.

---

## Exercise 3

Write

```cpp
sum_array()
```

that returns the sum of all elements.

---

## Exercise 4

Write

```cpp
find_max()
```

that returns the largest element.

---

## Exercise 5

Write

```cpp
compute_average()
```

that returns the average value of the array.

---

## Exercise 6 (Challenge)

Create a function

```cpp
normalize_array()
```

that divides every element by the largest value so that every number lies between

```
0
```

and

```
1
```

---

## Exercise 7 (Challenge)

Write a program that stores the exam grades of 100 students in an array.

Create separate functions to

- print the grades
- compute the average
- find the highest grade
- find the lowest grade
- count how many students passed

using function parameters instead of global variables.