# Recursive Functions

---

# Introduction

A recursive function is a function that calls itself in order to solve a problem.

Instead of solving the entire problem at once, recursion repeatedly breaks a problem into smaller versions of the same problem until a simple case can be solved directly.

Many important algorithms in computer science rely on recursion.

Examples include

- Factorial
- Fibonacci numbers
- Tree traversal
- Binary Search
- Quick Sort
- Merge Sort
- Depth-First Search (DFS)
- Backtracking algorithms

Understanding recursion is essential for advanced C++ programming.

---

# What is Recursion?

A recursive function has two essential parts.

1. Base Case
2. Recursive Case

The **base case** stops the recursion.

The **recursive case** reduces the problem into a smaller version and calls the function again.

General structure

```cpp
return_type function(parameters)
{
    if(base_case)
        return answer;

    return function(smaller_problem);
}
```

Without a base case, recursion never stops.

---

# How Recursion Works

Suppose we compute

```cpp
factorial(4)
```

The function creates a sequence of calls

```
factorial(4)

↓

factorial(3)

↓

factorial(2)

↓

factorial(1)

↓

factorial(0)
```

Only when the base case is reached does the program begin returning.

```
factorial(0)

returns 1

↓

factorial(1)

returns 1

↓

factorial(2)

returns 2

↓

factorial(3)

returns 6

↓

factorial(4)

returns 24
```

This process is called **stack unwinding**.

---

# The Call Stack

Every function call creates a new stack frame.

Each frame stores

- Parameters
- Local variables
- Return address
- Temporary values

Example

```
main()

↓

factorial(4)

↓

factorial(3)

↓

factorial(2)

↓

factorial(1)

↓

factorial(0)
```

After the base case,

the stack is emptied one function at a time.

Understanding the call stack is the key to understanding recursion.

---

# Factorial Example

Mathematical definition

```
0! = 1

n! = n × (n−1)!
```

Recursive implementation

```cpp
unsigned long long factorial(unsigned long long n)
{
    if (n == 0)
        return 1;

    return n * factorial(n - 1);
}
```

Each recursive call reduces the problem size by one.

Eventually,

```
n = 0
```

and recursion stops naturally.

---

# Fibonacci Sequence

Another classic recursive problem is the Fibonacci sequence.

The sequence begins as

```
0, 1, 1, 2, 3, 5, 8, 13, 21, ...
```

Each number is the sum of the previous two numbers.

Mathematically,

```
F(0) = 0

F(1) = 1

F(n) = F(n−1) + F(n−2)
```

Recursive implementation

```cpp
unsigned long long fibonacci(unsigned long long n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

Unlike factorial, Fibonacci generates **two recursive calls** at every level.

This causes the number of function calls to grow extremely quickly.

---

# Visualizing Fibonacci

Calculating

```cpp
fibonacci(5)
```

creates the following recursion tree.

```
                 fib(5)
               /        \
          fib(4)        fib(3)
         /      \      /      \
     fib(3)   fib(2) fib(2)  fib(1)
     /    \    /   \   /   \
 fib(2) fib(1)fib(1)fib(0)fib(1)fib(0)
 /   \
1     0
```

Notice that

```
fib(3)

fib(2)

fib(1)
```

are calculated many times.

This repeated work makes the naive recursive Fibonacci algorithm inefficient.

---

# Recursion vs Iteration

Many recursive algorithms can also be written using loops.

Recursive factorial

```cpp
return n * factorial(n - 1);
```

Iterative factorial

```cpp
unsigned long long factorial(unsigned long long n)
{
    unsigned long long result {1};

    for(unsigned long long i {1}; i <= n; ++i)
        result *= i;

    return result;
}
```

Both produce the same answer.

Iteration usually uses less memory because it does not create additional stack frames.

---

# Advantages of Recursion

✔ Elegant solutions

✔ Very short implementations

✔ Closely matches mathematical definitions

✔ Ideal for trees and graphs

✔ Natural for divide-and-conquer algorithms

Examples

- Merge Sort
- Quick Sort
- DFS
- Binary Search
- Tree Traversal

---

# Disadvantages of Recursion

Every recursive call creates another stack frame.

Too many recursive calls may cause

```
Stack Overflow
```

Recursive solutions are also sometimes slower than iterative solutions because of function call overhead.

Naive Fibonacci recursion is especially inefficient because it repeatedly solves the same subproblems.

---

# Tail Recursion

A recursive function is **tail recursive** if the recursive call is the last operation performed.

Example

```cpp
void countdown(int n)
{
    if(n == 0)
        return;

    cout << n << endl;

    countdown(n - 1);
}
```

Some compilers can optimize tail recursion into ordinary loops.

However, this optimization is not guaranteed in C++.

---

# Scientific Computing

Recursion appears frequently in scientific programming.

Examples include

- Tree structures
- Particle decay chains
- Monte Carlo search
- Recursive numerical integration
- Adaptive mesh refinement
- Fractal generation
- Recursive file-system traversal
- Expression parsing
- Binary search algorithms

Although iterative solutions are often faster, recursion frequently produces cleaner and more maintainable scientific code.

---

# Best Practices

✔ Always define a clear base case.

✔ Make sure every recursive call moves closer to the base case.

✔ Keep recursive functions as simple as possible.

✔ Avoid unnecessary recursive calls.

✔ Prefer iteration for very simple repetitive tasks.

✔ Use recursion when the problem is naturally recursive.

---

# Common Mistakes

## Forgetting the Base Case

Incorrect

```cpp
int f(int n)
{
    return f(n - 1);
}
```

This causes infinite recursion and eventually a stack overflow.

Correct

```cpp
int f(int n)
{
    if(n == 0)
        return 0;

    return f(n - 1);
}
```

---

## Not Making Progress Toward the Base Case

Incorrect

```cpp
return factorial(n);
```

The argument never changes.

The recursion never ends.

Correct

```cpp
return factorial(n - 1);
```

---

## Recursive Explosion

Naive Fibonacci repeatedly computes the same values.

Example

```
fib(5)

↓

fib(4)

↓

fib(3)

↓

fib(2)
```

Many of these calls are duplicated.

For large values,

this becomes extremely slow.

Dynamic Programming or Memoization is often used to solve this problem.

---

## Stack Overflow

Very deep recursion eventually exceeds the program's stack memory.

Example

```cpp
factorial(1000000)
```

Most systems cannot support recursion this deep.

---

# Summary

After completing this chapter you should understand

- What recursion is
- Base case and recursive case
- How recursive calls use the call stack
- Recursive factorial
- Recursive Fibonacci
- Stack unwinding
- Recursion trees
- Tail recursion
- Advantages and disadvantages of recursion
- Common recursion mistakes
- Where recursion is used in scientific computing

---

# Exercises

## Exercise 1

Write a recursive function that computes

```
n!
```

for any positive integer.

---

## Exercise 2

Write a recursive function that prints

```
10 9 8 ... 1
```

without using loops.

---

## Exercise 3

Write a recursive function that computes the sum

```
1 + 2 + 3 + ... + n
```

---

## Exercise 4

Write both recursive and iterative versions of Fibonacci.

Compare their execution times for

```
n = 40
```

Which implementation is faster?

---

## Exercise 5 (Challenge)

Write a recursive function that determines whether a string is a palindrome.

Examples

```
level

racecar

madam
```

The function should return

```cpp
true
```

only if the string reads the same forwards and backwards.
---

# Understanding the Call Stack

Every time a function is called, the operating system allocates a new **stack frame** in memory.

Each stack frame stores

- Function parameters
- Local variables
- The return address
- Temporary values created during execution

Whenever a recursive function calls itself, another stack frame is pushed onto the call stack.

Example

```cpp
factorial(3);
```

Execution order

```
main()

↓

factorial(3)

↓

factorial(2)

↓

factorial(1)

↓

factorial(0)
```

At this point the stack is full of unfinished function calls.

Only after reaching the base case does the program begin returning.

```
factorial(0)
returns 1

↓

factorial(1)
returns 1

↓

factorial(2)
returns 2

↓

factorial(3)
returns 6
```

This process is called **stack unwinding**.

---

# Memory Visualization

Suppose we execute

```cpp
factorial(4);
```

The call stack grows like this

```
-----------------
factorial(4)
-----------------
factorial(3)
-----------------
factorial(2)
-----------------
factorial(1)
-----------------
factorial(0)
-----------------
main()
-----------------
```

After reaching the base case, the stack shrinks one frame at a time until only `main()` remains.

---

# Why Fibonacci is Slow

Consider

```cpp
fibonacci(5)
```

The recursion tree becomes

```
                 fib(5)
               /        \
          fib(4)        fib(3)
         /      \      /      \
     fib(3)   fib(2) fib(2)  fib(1)
     /    \    /   \   /   \
 fib(2) fib(1)fib(1)fib(0)fib(1)fib(0)
```

Notice that

```
fib(3)

fib(2)

fib(1)
```

are computed multiple times.

The algorithm repeatedly solves the same subproblems.

This unnecessary work causes an exponential increase in execution time.

---

# Time Complexity

Recursive algorithms do not all have the same efficiency.

Recursive Factorial

```
T(n) = T(n−1)
```

Time Complexity

```
O(n)
```

Space Complexity

```
O(n)
```

because each recursive call creates one stack frame.

---

Recursive Fibonacci

```
T(n)=T(n−1)+T(n−2)
```

Time Complexity

```
O(2ⁿ)
```

Space Complexity

```
O(n)
```

The exponential running time is caused by repeated calculations.

---

# Recursion Tree Analysis

For

```cpp
fibonacci(6)
```

the tree contains many duplicate computations.

```
fib(6)

├── fib(5)

│   ├── fib(4)

│   └── fib(3)

└── fib(4)

    ├── fib(3)

    └── fib(2)
```

Observe that

```
fib(4)

fib(3)
```

appear multiple times.

The larger the input,

the more duplicated work occurs.

---

# Memoization

One solution is **Memoization**.

Instead of computing the same value repeatedly,

store the result the first time it is calculated.

```
fib(20)

↓

Store Result

↓

Need fib(20) again?

↓

Return stored value
```

Memoization reduces Fibonacci's running time dramatically.

Time Complexity becomes

```
O(n)
```

instead of

```
O(2ⁿ)
```

Dynamic Programming is built upon this idea.

---

# Tail Recursion

A recursive function is called **tail recursive** when the recursive call is the final operation.

Example

```cpp
void countdown(int n)
{
    if(n == 0)
        return;

    cout << n << endl;

    countdown(n - 1);
}
```

Since nothing happens after the recursive call,

some compilers may optimize the recursion into a loop.

This optimization is called

```
Tail Call Optimization (TCO)
```

However,

the C++ standard does **not** require compilers to perform this optimization.

---

# Recursion vs Iteration

Many recursive algorithms can also be implemented using loops.

Recursive factorial

```cpp
return n * factorial(n - 1);
```

Iterative factorial

```cpp
unsigned long long result {1};

for(unsigned long long i {1}; i <= n; ++i)
    result *= i;
```

Comparison

| Recursive | Iterative |
|------------|-----------|
| Easier to understand | Usually faster |
| Elegant | Uses less memory |
| Uses call stack | No recursive calls |
| Can overflow stack | No stack overflow risk |

There is no universal rule.

Choose the implementation that best fits the problem.

---

# Scientific Notes

Recursion is heavily used in scientific computing.

Examples include

- Binary Search
- Merge Sort
- Quick Sort
- Tree Traversal
- Graph Traversal (DFS)
- Adaptive Mesh Refinement
- Recursive Numerical Integration
- Recursive File System Traversal
- Particle Decay Trees
- Fractal Generation
- Expression Parsing
- Compiler Design

Frameworks such as

- ROOT
- Geant4
- LLVM
- Eigen
- Boost

contain recursive algorithms internally.

Although recursion is elegant, scientific software often replaces expensive recursive algorithms with iterative or dynamic programming solutions when performance becomes critical.
---

# Best Practices

✔ Always define a clear **base case**.

Without a base case, recursion will never terminate.

```cpp
if (n == 0)
    return 1;
```

---

✔ Make sure every recursive call moves toward the base case.

Each recursive call should reduce the size or complexity of the problem.

Good example

```cpp
factorial(n - 1);
```

Bad example

```cpp
factorial(n + 1);
```

The second example moves farther away from the base case and will never terminate.

---

✔ Keep recursive functions small and focused.

A recursive function should solve **one problem** only.

Avoid mixing multiple unrelated tasks inside the same recursive function.

---

✔ Prefer recursion only when it naturally models the problem.

Examples include

- Trees
- Graphs
- Divide and conquer algorithms
- Mathematical recurrence relations
- Recursive file systems

Simple counting or repetitive tasks are usually better implemented with loops.

---

✔ Be aware of stack usage.

Every recursive call creates a new stack frame.

Very deep recursion may cause

```
Stack Overflow
```

For extremely large inputs, consider an iterative solution instead.

---

✔ Avoid repeated calculations.

Recursive Fibonacci is elegant but inefficient.

Whenever overlapping subproblems exist, consider using

- Memoization
- Dynamic Programming

---

✔ Give recursive functions descriptive names.

Examples

```cpp
factorial()

fibonacci()

binarySearch()

mergeSort()

quickSort()

treeTraversal()
```

Clear names improve readability.

---

✔ Test small inputs first.

Before trying

```cpp
factorial(100)
```

verify that

```cpp
factorial(0)

factorial(1)

factorial(2)

factorial(5)
```

produce the expected results.

---

# Common Mistakes

## Forgetting the Base Case

Incorrect

```cpp
unsigned long long factorial(unsigned long long n)
{
    return n * factorial(n - 1);
}
```

This function never stops calling itself.

Eventually the program crashes due to stack overflow.

Correct

```cpp
if(n == 0)
    return 1;
```

---

## Recursive Call Does Not Progress

Incorrect

```cpp
factorial(n);
```

The argument never changes.

The recursion never reaches the base case.

Correct

```cpp
factorial(n - 1);
```

---

## Infinite Recursion

A recursive function that never reaches its stopping condition eventually exhausts the call stack.

Typical symptoms include

- Program crash
- Stack overflow
- Segmentation fault

---

## Ignoring Performance

Recursive Fibonacci

```cpp
fibonacci(45);
```

requires millions of recursive calls.

A loop or memoized solution is dramatically faster.

Always consider the algorithm's complexity.

---

## Using Recursion for Simple Loops

Instead of

```cpp
countdown(1000000);
```

an ordinary

```cpp
for
```

or

```cpp
while
```

loop is often simpler, faster, and safer.

---

## Confusing Recursive Calls with Loops

Recursion creates **new function calls**.

Loops repeat inside the **same function call**.

Although both perform repetition, they work in fundamentally different ways.

---

# Summary

After completing this chapter you should understand

- What recursion is
- How recursive functions call themselves
- The purpose of a base case
- Recursive case vs base case
- How the call stack works
- Stack unwinding
- Recursive implementation of factorial
- Recursive implementation of Fibonacci
- Why recursive Fibonacci is inefficient
- Time and space complexity of recursive algorithms
- Memoization and Dynamic Programming concepts
- Tail recursion
- Recursion versus iteration
- When recursion is appropriate
- Common recursion mistakes
- Best practices for writing recursive functions

---

# Exercises

## Exercise 1

Write a recursive function that calculates

```
n!
```

for a user-entered integer.

---

## Exercise 2

Write a recursive function that calculates

```
2ⁿ
```

for any non-negative integer.

---

## Exercise 3

Write a recursive function that sums all integers from

```
1

to

n
```

Example

```
sum(5)

=

15
```

---

## Exercise 4

Write a recursive function that counts the number of digits in an integer.

Example

```
54321

↓

5 digits
```

---

## Exercise 5

Write a recursive function that reverses a string.

Example

```
Programming

↓

gnimmargorP
```

---

## Exercise 6

Write a recursive function that determines whether a string is a palindrome.

Examples

```
level

↓

true
```

```
physics

↓

false
```

---

## Exercise 7

Implement Fibonacci using **memoization**.

Compare its execution speed with the naive recursive version.

---

## Exercise 8 (Challenge)

Write a recursive Binary Search function.

The function should search a sorted array and return

- the index of the element if found,
- `-1` otherwise.

---

## Exercise 9 (Challenge)

Write a recursive function that prints every file and folder inside a directory (conceptually or using the C++17 `<filesystem>` library).

---

## Exercise 10 (Challenge)

Research one real-world scientific algorithm that uses recursion (for example Merge Sort, Quick Sort, Tree Traversal, Depth-First Search, or Adaptive Mesh Refinement).

Prepare a short explanation covering

- Why recursion is appropriate
- Its time complexity
- Its space complexity
- Possible iterative alternatives