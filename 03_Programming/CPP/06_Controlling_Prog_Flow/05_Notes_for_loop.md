# For Loops

---

# Introduction

A **for loop** is one of the three primary looping constructs in C++.

It is used when the programmer knows, or can estimate, how many times a block of code should execute.

Unlike a `while` loop, which is generally used when the number of iterations is unknown, a `for` loop combines **initialization**, **condition checking**, and **updating** into a single compact statement.

For loops are one of the most frequently used control structures in scientific computing because they efficiently process large collections of data.

---

# General Syntax

```cpp
for (initialization; condition; update)
{
    // loop body
}
```

Example

```cpp
for (int i{0}; i < 5; ++i)
{
    std::cout << i << std::endl;
}
```

---

# How a For Loop Works

Every iteration follows exactly the same sequence.

```
Initialization
      │
      ▼
Check Condition
      │
 ┌────┴────┐
 │         │
True      False
 │         │
 ▼         ▼
Execute    Exit Loop
Body
 │
 ▼
Update
 │
 └─────────────► Check Condition Again
```

The initialization runs **only once**.

The condition is evaluated before every iteration.

The update expression executes after each iteration.

---

# Components of a For Loop

## Initialization

Runs only once.

```cpp
int i {0};
```

Usually initializes the loop counter.

---

## Condition

Determines whether another iteration should occur.

```cpp
i < 10
```

The loop continues while this expression evaluates to `true`.

---

## Update

Changes the loop variable.

Common examples

```cpp
++i
```

```cpp
i++
```

```cpp
i += 2
```

```cpp
--i
```

---

# Counting Loops

Increasing

```cpp
for(int i{0}; i<=10; ++i)
```

Output

```
0
1
2
...
10
```

---

Decreasing

```cpp
for(int i{10}; i>0; --i)
```

Output

```
10
9
8
...
1
```

---

# Multiple Control Variables

A for loop may initialize and update multiple variables simultaneously.

```cpp
for(int i{1}, j{5}; i<=5; ++i, ++j)
```

Example output

```
1 + 5 = 6
2 + 6 = 8
3 + 7 = 10
```

This technique is occasionally useful but should not be overused, as it can reduce readability.

---

# Iterating Through Vectors

One of the most common applications of a `for` loop is processing containers.

```cpp
vector<int> numbers {10,20,30,40};
```

```cpp
for(size_t i{0}; i<numbers.size(); ++i)
{
    cout << numbers[i];
}
```

Notice that the loop uses `<` instead of `<=`.

Vector indices range from

```
0
```

to

```
size()-1
```

---

# Why Use size_t?

You may notice

```cpp
size_t i
```

instead of

```cpp
int i
```

`vector::size()` returns an unsigned integer (`size_t`).

Using the same type avoids compiler warnings and is considered Modern C++ style.

---

# Common Applications

For loops can be used to

- process arrays
- process vectors
- calculate sums
- search for values
- generate tables
- simulate repeated experiments
- iterate over files
- process detector events

---

# Summing Elements

Example

```cpp
int sum{0};

for(size_t i{0}; i<numbers.size(); ++i)
{
    sum += numbers[i];
}
```

Output

```
150
```

This pattern appears constantly in numerical programming.

---

# Finding the Largest Element

Example

```cpp
int largest = numbers[0];

for(size_t i{1}; i<numbers.size(); ++i)
{
    if(numbers[i] > largest)
        largest = numbers[i];
}
```

Output

```
Largest element = 50
```

This algorithm forms the basis of many optimization techniques.

---

# Scope of the Loop Variable

Variables declared inside the loop exist **only** inside the loop.

```cpp
for(int i{0}; i<5; ++i)
{
}
```

The following is illegal.

```cpp
cout << i;
```

because `i` no longer exists.

---

# Empty Loops

Sometimes a loop intentionally performs no work.

```cpp
for(int i{0}; i<1000; ++i)
{
}
```

Although uncommon, empty loops are occasionally used for benchmarking or timing experiments.

---

# Range-Based For Loop (Modern C++)

Modern C++ introduced a cleaner way to iterate over containers.

```cpp
for(auto value : numbers)
{
    cout << value << endl;
}
```

Advantages

- shorter code
- easier to read
- avoids indexing mistakes
- preferred when the index itself is not needed

Whenever you only need the elements, a range-based `for` loop is generally the best choice.

---

# Scientific Computing Notes

For loops are everywhere in scientific software.

Examples include

- Processing millions of detector events
- Reading ROOT TTrees
- Iterating over particle collections
- Numerical integration
- Monte Carlo simulations
- Matrix calculations
- Histogram filling
- Data analysis

A High Energy Physics analysis may execute billions of loop iterations while processing experimental data.

Learning to write efficient loops is therefore an essential programming skill.

---

# Best Practices

✔ Use meaningful loop variable names when appropriate.

✔ Prefer `++i` for iterator-style loops.

✔ Use `size_t` when indexing STL containers.

✔ Use range-based `for` loops whenever the index is unnecessary.

✔ Keep loop bodies short and readable.

✔ Use braces `{}` even for single-line loops to avoid accidental bugs.

---

# Common Mistakes

## Using `<=` Instead of `<`

Incorrect

```cpp
for(size_t i{0}; i<=numbers.size(); ++i)
```

This accesses one element beyond the vector.

Correct

```cpp
for(size_t i{0}; i<numbers.size(); ++i)
```

---

## Infinite Loops

Incorrect

```cpp
for(int i{0}; i<10;)
```

The update expression is missing.

---

## Modifying the Loop Counter Accidentally

Avoid changing the loop variable inside the body.

```cpp
i += 5;
```

unless absolutely necessary.

---

## Declaring Variables Outside the Loop Unnecessarily

Prefer

```cpp
for(int i{0}; ...)
```

instead of

```cpp
int i;

for(i=0; ...)
```

This limits the variable's scope.

---

# Summary

After completing this chapter you should understand

- the structure of a `for` loop
- initialization, condition, and update
- counting upward and downward
- multiple loop variables
- iterating over vectors
- summing values
- finding maximum values
- scope rules
- range-based `for` loops
- why `for` loops are fundamental in scientific computing

---

# Exercises

## Exercise 1

Print the numbers from 1 to 100.

---

## Exercise 2

Print only the even numbers between 1 and 50.

---

## Exercise 3

Read five integers into a vector.

Print their sum.

---

## Exercise 4

Read ten integers.

Print the largest value.

---

## Exercise 5

Print the multiplication table from 1 to 10 using nested `for` loops.

---

## Exercise 6 (Modern C++)

Create a vector containing ten integers.

Print every element using a **range-based for loop**.

---

## Exercise 7 (Challenge)

Ask the user how many numbers they want to enter.

Store them in a vector.

Then calculate

- the sum
- the average
- the largest value
- the smallest value

using `for` loops.