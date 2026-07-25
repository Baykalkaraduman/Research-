# Dynamic Memory Allocation (Heap Memory)

---

# Introduction

So far in C++, every variable we created has been stored automatically by the compiler.

For example,

```cpp
int score {100};
double temperature {36.7};
string name {"Emir"};
```

All of these variables are created automatically when execution reaches their declarations and destroyed automatically when they leave their scope.

This automatic memory management is sufficient for many programs.

However, real-world software often needs memory whose size or lifetime is unknown until the program is already running.

Examples include:

- Reading an unknown number of values from a file.
- Loading a large image into memory.
- Creating game objects during gameplay.
- Allocating matrices for scientific simulations.
- Managing millions of detector events in High-Energy Physics.

For situations like these, C++ provides **Dynamic Memory Allocation**.

---

# What is Dynamic Memory?

Dynamic memory is memory requested manually while the program is running.

Instead of letting the compiler decide where variables live, the programmer explicitly asks the operating system for additional memory.

This memory comes from the **Heap**.

Unlike local variables, heap memory:

- is not automatically destroyed,
- remains allocated until we release it,
- gives the programmer complete control over its lifetime.

---

# Memory Layout of a C++ Program

A simplified memory layout is shown below.

```
+----------------------------------+
|            Code Segment          |
|  Compiled program instructions   |
+----------------------------------+

|        Global / Static Data      |
| Global variables                 |
| Static variables                 |
+----------------------------------+

|              Heap               |
| Dynamic memory (new)            |
|                                 |
|  grows upward ↑                 |
+----------------------------------+

|                                 |
|       Free Memory               |
|                                 |
+----------------------------------+

|              Stack              |
| Local variables                 |
| Function calls                  |
| Parameters                      |
|                                 |
| grows downward ↓                |
+----------------------------------+
```

The Stack and Heap grow toward one another.

If both become too large, available memory is exhausted.

---

# Stack Memory

Local variables are placed on the Stack.

Example

```cpp
int age {22};
double pi {3.14159};
```

The compiler automatically

- allocates memory,
- initializes variables,
- destroys them when they leave scope.

You never call `delete` for stack variables.

Example

```cpp
void foo()
{
    int x {10};
}
```

When `foo()` finishes,

```
x
```

disappears automatically.

---

# Heap Memory

Heap memory behaves differently.

The compiler does **not** manage it automatically.

Instead, the programmer requests memory manually.

Example

```cpp
int* ptr {new int};
```

The compiler allocates an integer somewhere inside the heap.

Memory now looks like

```
Stack

ptr
↓

Heap

+------+
| ???? |
+------+
```

The pointer stores the address of the allocated memory.

---

# Why Use Dynamic Memory?

Dynamic allocation is useful whenever the amount of required memory is unknown beforehand.

Examples include

- User-defined array sizes
- Dynamic matrices
- Linked lists
- Trees
- Graphs
- Queues
- Stacks
- Physics event buffers
- Image processing
- Database systems

Without dynamic memory, many modern applications would be impossible.

---

# The new Operator

The `new` operator allocates memory from the heap.

General syntax

```cpp
pointer = new datatype;
```

Example

```cpp
int* ptr {new int};
```

Memory

```
Stack

ptr

↓

Heap

+------+
| int  |
+------+
```

Notice that the allocated integer initially contains an undefined value unless explicitly initialized.

---

# Initializing Dynamic Memory

Instead of

```cpp
int* ptr {new int};
```

prefer

```cpp
int* ptr {new int {100}};
```

Now the allocated integer already contains

```
100
```

This is both safer and clearer.

The same applies to other types.

```cpp
double* temp {new double {37.5}};
```

---

# Dereferencing Dynamic Memory

Since `new` returns an address, we use dereferencing to access the object.

Example

```cpp
int* ptr {new int {50}};

cout << *ptr;
```

Output

```
50
```

Changing the object

```cpp
*ptr = 250;
```

Now

```
Heap

250
```

The pointer still points to exactly the same memory location.

---

# Visualizing Dynamic Allocation

Suppose

```cpp
int* score_ptr {new int {100}};
```

Memory

```
Stack

score_ptr

↓

Heap

Address
0x51A0

Value
100
```

Dereferencing

```
*score_ptr

↓

100
```

---

# Heap Variables Behave Like Normal Variables

Although allocated differently, heap variables behave just like ordinary variables.

Example

```cpp
int* age {new int {20}};

*age += 5;
```

The stored value becomes

```
25
```

You can

- read,
- modify,
- compare,
- perform arithmetic,

exactly as you would with ordinary variables.

The only difference is that access occurs through a pointer.

---

# Dynamic Memory Lifetime

A local variable

```cpp
int x {10};
```

exists only until the surrounding block ends.

Dynamic memory

```cpp
int* ptr {new int {10}};
```

continues to exist until

```cpp
delete ptr;
```

is executed.

Even if the function ends, heap memory remains allocated unless explicitly released.

This is why dynamic memory must be managed carefully.

---

# Best Practices

✔ Initialize pointers with `nullptr`.

```cpp
int* ptr {nullptr};
```

---

✔ Initialize heap objects immediately.

```cpp
new int {100}
```

instead of

```cpp
new int
```

---

✔ Keep ownership clear.

One pointer should clearly own dynamically allocated memory.

---

✔ Draw memory diagrams while learning.

They help visualize the relationship between

- Stack
- Heap
- Pointer
- Object

---

# Common Mistakes (Part 1)

## Forgetting that `new` returns an address

Wrong idea

```cpp
new int
```

returns

```
integer
```

Reality

```
new int

↓

address of integer
```

---

## Forgetting Dereferencing

Wrong

```cpp
cout << ptr;
```

prints

```
0x61FF08
```

Correct

```cpp
cout << *ptr;
```

prints

```
100
```

---

## Thinking Heap Variables Are Automatic

Wrong assumption

```
Heap variables disappear automatically.
```

Reality

Heap memory remains allocated until

```cpp
delete
```

is called.

---

## Using Uninitialized Dynamic Objects

Less safe

```cpp
new int;
```

Safer

```cpp
new int {0};
```

Always initialize dynamically allocated memory whenever possible.

---

## Key Takeaways (Part 1)

- Dynamic memory is allocated from the **Heap**.
- `new` requests memory during program execution.
- `new` returns a memory **address**, not the object itself.
- A pointer stores the returned address.
- Dereferencing (`*`) accesses the allocated object.
- Heap memory remains allocated until explicitly released.
- Dynamic allocation is essential when memory requirements are unknown at compile time.
- Always initialize both pointers and dynamically allocated objects for safer, more predictable code.

---

# Dynamic Memory Allocation (Heap Memory)

---

# Releasing Memory with `delete`

When we allocate memory using `new`, the operating system reserves a portion of the Heap for our program.

However, the operating system **does not automatically know when we are finished using that memory**.

Therefore, we must explicitly return it.

The `delete` operator releases dynamically allocated memory back to the Heap.

General syntax

```cpp
delete pointer;
```

Example

```cpp
int* ptr {new int {100}};

delete ptr;
```

After `delete`, the reserved memory becomes available for future allocations.

---

# Why Is `delete` Necessary?

Suppose we repeatedly allocate memory.

```cpp
while (true)
{
    new int;
}
```

Every iteration requests more Heap memory.

Since nothing is released,

the Heap eventually becomes full.

This situation is called a **Memory Leak**.

Eventually, the operating system may terminate the program due to insufficient memory.

---

# Memory Before and After delete

Before

```
Stack

ptr

↓

Heap

+------+
| 100  |
+------+
```

After

```cpp
delete ptr;
```

```
Stack

ptr

↓

Memory released
```

The memory is no longer owned by your program.

---

# Dangling Pointers

After calling

```cpp
delete ptr;
```

the pointer still stores the old address.

Example

```cpp
int* ptr {new int {100}};

delete ptr;

cout << ptr;
```

The address may still be printed.

However,

that memory no longer belongs to your program.

This is called a **Dangling Pointer**.

---

# Preventing Dangling Pointers

Immediately after deleting memory,

assign the pointer to `nullptr`.

```cpp
delete ptr;

ptr = nullptr;
```

Now

```
ptr

↓

nullptr
```

This prevents accidental access to invalid memory.

---

# What is nullptr?

`nullptr` represents

> "This pointer points to nothing."

Example

```cpp
int* ptr {nullptr};
```

Benefits

- Safe initialization
- Easier debugging
- Prevents accidental dereferencing
- Makes ownership obvious

Always prefer

```cpp
nullptr
```

instead of

```cpp
0

NULL
```

---

# Dynamic Arrays

We can also allocate arrays dynamically.

General syntax

```cpp
datatype* pointer = new datatype[size];
```

Example

```cpp
int* numbers {new int[5]};
```

Memory

```
Heap

+----+
| 0  |
+----+
| 0  |
+----+
| 0  |
+----+
| 0  |
+----+
| 0  |
+----+
```

The pointer stores the address of the first element.

Access works exactly like ordinary arrays.

```cpp
numbers[0]

numbers[1]

numbers[2]
```

---

# Initializing Dynamic Arrays

Example

```cpp
size_t size {5};

double* temperatures {new double[size]};
```

Input

```cpp
for(size_t i{0}; i<size; ++i)
    cin >> temperatures[i];
```

Output

```cpp
for(size_t i{0}; i<size; ++i)
    cout << temperatures[i];
```

Dynamic arrays behave almost identically to stack arrays.

---

# delete[] for Arrays

Arrays require a different delete operator.

Correct

```cpp
delete[] temperatures;
```

Wrong

```cpp
delete temperatures;
```

Using the wrong delete operator results in **Undefined Behavior**.

Rule

```
new

↓

delete

---------------------

new[]

↓

delete[]
```

Always match them correctly.

---

# Memory Leak

A memory leak occurs whenever allocated memory becomes unreachable.

Example

```cpp
int* ptr {new int {100}};

ptr = nullptr;
```

What happened?

```
Heap

100
```

still exists,

but no pointer knows its address anymore.

The memory can never be deleted.

It remains reserved until the program terminates.

---

# Wild Pointer

A Wild Pointer is an uninitialized pointer.

Example

```cpp
int* ptr;
```

Its value is unknown.

Dereferencing it

```cpp
*ptr = 50;
```

causes Undefined Behavior.

Always initialize pointers.

```cpp
int* ptr {nullptr};
```

---

# Dynamic Memory vs Stack Memory

| Stack | Heap |
|--------|------|
| Automatic | Manual |
| Fast | Slightly slower |
| Compiler managed | Programmer managed |
| Small | Very large |
| Automatically destroyed | Must call `delete` |
| Local lifetime | User-controlled lifetime |

---

# Memory Management Rules

Whenever you see

```cpp
new
```

ask yourself

> Where will I call `delete`?

Whenever you see

```cpp
new[]
```

ask yourself

> Where will I call `delete[]`?

Never write one without planning the other.

---

# Scientific Applications

Dynamic memory is everywhere in scientific programming.

Examples include

- Event buffers in ROOT
- Detector geometry in Geant4
- Large matrices
- Monte Carlo simulations
- Particle collections
- Image processing
- Finite Element Analysis
- Computational Fluid Dynamics
- Machine Learning datasets

Large scientific applications would be impossible using only stack memory.

---

# Modern C++ Notes

Modern C++ discourages direct use of `new` and `delete`.

Instead, it recommends

- `std::unique_ptr`
- `std::shared_ptr`
- `std::weak_ptr`

These are called **Smart Pointers**.

They automatically release memory when no longer needed.

However,

understanding raw pointers is essential because smart pointers are built on the same concepts.

---

# Common Mistakes

## Forgetting delete

Wrong

```cpp
int* ptr {new int};
```

Program ends without

```cpp
delete ptr;
```

Memory leak.

---

## Mixing delete and delete[]

Wrong

```cpp
int* arr {new int[10]};

delete arr;
```

Correct

```cpp
delete[] arr;
```

---

## Dereferencing After delete

Wrong

```cpp
delete ptr;

cout << *ptr;
```

Undefined Behavior.

---

## Losing the Pointer

Wrong

```cpp
ptr = new int;

ptr = nullptr;
```

Memory leaked forever.

---

## Forgetting nullptr

Safer

```cpp
delete ptr;

ptr = nullptr;
```

This prevents many bugs.

---

# Exercises

## Exercise 1

Allocate one integer dynamically.

Store

```
250
```

Print it.

Release the memory.

---

## Exercise 2

Ask the user for an array size.

Allocate the array dynamically.

Fill it.

Print it.

Delete it.

---

## Exercise 3

Create five dynamic doubles.

Compute their average.

Release memory.

---

## Exercise 4

Intentionally create a memory leak.

Explain why it happens.

Then fix it.

---

## Exercise 5

Draw a memory diagram showing

- Stack
- Heap
- Pointer
- Object

before and after calling `delete`.

---

# Interview Questions

**Q:** What does `new` return?

**A:** The memory address of the newly allocated object.

---

**Q:** Why do we need `delete`?

**A:** To release dynamically allocated Heap memory and avoid memory leaks.

---

**Q:** What is a dangling pointer?

**A:** A pointer that still holds the address of memory that has already been released.

---

**Q:** What is a memory leak?

**A:** Dynamically allocated memory that is no longer reachable because its address has been lost.

---

**Q:** Why should pointers be assigned `nullptr` after `delete`?

**A:** To avoid accidentally accessing invalid memory and to clearly indicate that the pointer no longer owns any object.

---

**Q:** What is the difference between `delete` and `delete[]`?

**A:** `delete` releases memory allocated with `new`, while `delete[]` releases memory allocated with `new[]`.

---

# Key Takeaways

- Dynamic memory is allocated with `new` and released with `delete`.
- Arrays allocated with `new[]` must always be released using `delete[]`.
- Forgetting to release Heap memory leads to memory leaks.
- Accessing memory after `delete` results in dangling pointers and undefined behavior.
- Always initialize pointers with `nullptr` and reset them to `nullptr` after deleting.
- Heap memory provides flexible storage whose size and lifetime are determined at runtime.
- Understanding raw dynamic memory is essential before learning Smart Pointers, RAII, STL allocators, and advanced C++ resource management.