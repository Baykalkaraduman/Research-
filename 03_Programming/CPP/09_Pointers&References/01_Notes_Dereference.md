# Dereference Operator (*)

## Introduction

A pointer by itself is not very useful. It only stores a memory address. To access the actual object stored at that address, we use the **Dereference Operator (`*`)**.

The dereference operator is one of the most important operators in C++. It allows us to:

- Read the value stored at a memory address.
- Modify the value stored at that address.
- Work with dynamically allocated memory.
- Access arrays through pointers.
- Manipulate objects efficiently.
- Build complex data structures such as linked lists, trees, graphs, and hash tables.

Understanding dereferencing is the key to understanding how pointers actually work.

---

# Why Do We Need Dereferencing?

Suppose we have an integer variable.

```cpp
int score {100};
```

Memory may look like

```
Address        Value
---------      -----
0x1000         100
```

Now create a pointer.

```cpp
int* score_ptr {&score};
```

Memory becomes

```
score

Address
0x1000

Value
100


score_ptr

Address
0x2000

Value
0x1000
```

Notice something important:

`score_ptr` stores **0x1000**, not **100**.

If we simply write

```cpp
cout << score_ptr;
```

Output

```
0x1000
```

But what if we actually want the **100**?

That's exactly what dereferencing does.

```cpp
cout << *score_ptr;
```

Output

```
100
```

---

# What Does the * Operator Mean?

The symbol `*` has two completely different meanings depending on where it is used.

### During declaration

```cpp
int* ptr;
```

means

> ptr is a pointer to an integer.

---

### During usage

```cpp
*ptr
```

means

> Go to the address stored inside ptr and access the object located there.

These are completely different operations even though they use the same symbol.

---

# Dereference Syntax

General syntax

```cpp
*pointer_name
```

Example

```cpp
int number {50};

int* ptr {&number};

cout << *ptr;
```

Output

```
50
```

---

# Visualizing Dereferencing

```
number

Address
0x1000

Value
50
```

Pointer

```
ptr

Value

0x1000
```

Dereferencing

```
*ptr

↓

Go to

0x1000

↓

Read

50
```

Think of it like following a map.

The pointer tells you **where** to go.

The dereference operator opens the door and retrieves what's inside.

---

# Reading Values Through a Pointer

Example

```cpp
int score {95};

int* score_ptr {&score};

cout << *score_ptr;
```

Output

```
95
```

The pointer itself never changes.

We are simply asking

> "What is stored at the address inside this pointer?"

---

# Modifying Values Through a Pointer

Dereferencing is not only for reading.

It can also modify data.

Example

```cpp
int score {100};

int* score_ptr {&score};

*score_ptr = 250;
```

Memory

Before

```
score

100
```

After

```
score

250
```

Now

```cpp
cout << score;
```

prints

```
250
```

because both the variable and the pointer refer to the same memory location.

---

# Pointer vs Dereferenced Pointer

Suppose

```cpp
int number {42};

int* ptr {&number};
```

Then

```
ptr
```

contains

```
0x5000
```

while

```
*ptr
```

contains

```
42
```

A useful way to remember this is

```
ptr

↓

Address


*ptr

↓

Value
```

---

# Memory Diagram

```
          Memory

+----------------------+
| Address : 0x1000     |
| Value   : 42         |
+----------------------+
          ▲
          │
          │
     +-------------+
     | ptr         |
     | 0x1000      |
     +-------------+

ptr

↓

0x1000

↓

*ptr

↓

42
```

---

# Changing the Object vs Changing the Pointer

This distinction is extremely important.

Suppose

```cpp
int x {10};
int y {20};

int* ptr {&x};
```

Current situation

```
ptr

↓

x

10
```

Now

```cpp
*ptr = 50;
```

Result

```
x = 50

ptr still points to x
```

Nothing changed about the pointer.

Only the object changed.

---

Now instead

```cpp
ptr = &y;
```

Result

```
ptr

↓

y

20
```

Notice

- x is still 50.
- y is still 20.
- Only the pointer moved.

This is one of the most common beginner confusions.

Always ask yourself:

> Did I change the pointer?

or

> Did I change the object?

---

# Dereferencing Strings

Pointers can point to objects, not only primitive types.

Example

```cpp
string name {"Richard"};

string* ptr {&name};

cout << *ptr;
```

Output

```
Richard
```

Now

```cpp
name = "Marie";
```

Output

```
Marie
```

The pointer still points to the same object.

Only the object's contents changed.

---

# Scientific Notes

Dereferencing is used constantly inside scientific software.

Examples include:

- ROOT event trees
- Geant4 detector objects
- Eigen matrices
- OpenCV image buffers
- CUDA device memory
- MPI communication buffers

Even when modern C++ hides raw pointers behind abstractions, dereferencing is still happening internally. Understanding this concept helps when debugging segmentation faults, analyzing memory usage, and reading large scientific codebases.

---

# Best Practices

✔ Always initialize pointers before dereferencing them.

```cpp
int* ptr {nullptr};
```

✔ Dereference only valid pointers.

✔ Use meaningful pointer names.

```cpp
matrix_ptr
event_ptr
particle_ptr
```

✔ Remember the distinction between:

- the pointer
- the object

✔ Draw memory diagrams when learning.

They eliminate most pointer confusion.

---

# Common Mistakes (Part 1)

### Forgetting that `ptr` is an address

Wrong idea

```
ptr = value
```

Reality

```
ptr = address
```

---

### Confusing `ptr` with `*ptr`

```
ptr

↓

address

*ptr

↓

value
```

---

### Thinking changing `*ptr` changes the pointer

Wrong

```
*ptr = 100;
```

This changes the object.

It does **not** move the pointer.

---

### Thinking assigning a new address changes the object

```cpp
ptr = &another_variable;
```

This changes only the pointer.

The original object remains unchanged.

---

---

# Dereferencing Objects

Pointers are not limited to primitive data types such as integers or doubles.

They can also point to complex C++ objects.

Example

```cpp
string scientist {"Richard Feynman"};

string* scientist_ptr {&scientist};

cout << *scientist_ptr << endl;
```

Output

```
Richard Feynman
```

If the object changes,

```cpp
scientist = "Marie Curie";
```

then

```cpp
cout << *scientist_ptr;
```

prints

```
Marie Curie
```

The pointer never changed.

It simply points to the same object whose contents changed.

---

# Dereferencing Vectors

Pointers can also reference STL containers.

Example

```cpp
vector<string> names
{
    "Larry",
    "Moe",
    "Curly"
};

vector<string>* vector_ptr {&names};
```

To access a member function we first dereference the pointer.

```cpp
(*vector_ptr).size()
```

or

```cpp
(*vector_ptr).at(0)
```

Example

```cpp
cout << (*vector_ptr).at(0);
```

Output

```
Larry
```

---

# Accessing Members Through a Pointer

When a pointer points to an object, member functions are accessed like this

```cpp
(*pointer).member
```

Example

```cpp
(*vector_ptr).push_back("Shemp");
```

This modifies the original vector.

Memory

```
vector_ptr

↓

names vector

↓

push_back()

↓

Original vector changes
```

---

# The Arrow Operator (->)

Later in C++ you will learn the Arrow Operator.

Instead of

```cpp
(*vector_ptr).size();
```

we usually write

```cpp
vector_ptr->size();
```

These two expressions are completely equivalent.

```
(*pointer).member

==

pointer->member
```

The arrow operator is simply cleaner syntax.

---

# Range-Based For with Dereferenced Containers

Since dereferencing returns the original object, we can directly iterate over it.

Example

```cpp
for (const auto& name : *vector_ptr)
    cout << name << endl;
```

This loops through the original vector.

No copies are created.

---

# Reading vs Writing Through a Pointer

Reading

```cpp
cout << *ptr;
```

Writing

```cpp
*ptr = 500;
```

Both operations access the same object.

The only difference is whether we read from memory or write to memory.

---

# Multiple Pointers to the Same Object

Several pointers may point to the same variable.

Example

```cpp
int score {100};

int* p1 {&score};
int* p2 {&score};
```

Memory

```
score

100

▲     ▲
│     │

p1    p2
```

Changing

```cpp
*p1 = 300;
```

immediately affects

```cpp
*p2
```

because both pointers reference the same object.

---

# nullptr and Dereferencing

This is one of the most important safety rules.

Never dereference a nullptr.

Wrong

```cpp
int* ptr {nullptr};

cout << *ptr;
```

This causes **Undefined Behavior** and usually crashes the program.

Always verify a pointer before dereferencing.

```cpp
if (ptr != nullptr)
    cout << *ptr;
```

or

```cpp
if (ptr)
    cout << *ptr;
```

---

# Memory Visualization

Suppose

```cpp
int value {25};

int* ptr {&value};
```

Memory

```
Variable

value

Address
0x1000

Value
25


Pointer

ptr

Address
0x2000

Value
0x1000
```

Dereferencing

```
*ptr

↓

Go to

0x1000

↓

Read

25
```

Changing

```cpp
*ptr = 80;
```

Memory becomes

```
value

80
```

The pointer itself never changes.

---

# Scientific Notes

Dereferencing is used everywhere in scientific software.

Examples include

- ROOT Event objects
- Geant4 detector geometry
- OpenCV image matrices
- Eigen matrices
- CUDA GPU memory
- MPI communication buffers

Most large scientific libraries internally manipulate objects through pointers.

Understanding dereferencing makes reading professional research code significantly easier.

---

# Performance Notes

Dereferencing itself is extremely fast.

The compiler usually converts

```cpp
*ptr
```

into a direct memory access instruction.

The operation is generally O(1).

Modern compilers optimize pointer dereferencing aggressively.

---

# Modern C++ Notes

Although raw pointers are still fundamental, Modern C++ often prefers

- std::unique_ptr
- std::shared_ptr
- std::weak_ptr

These smart pointers still rely on dereferencing.

Example

```cpp
smart_ptr->member
```

internally behaves exactly like

```cpp
(*smart_ptr).member
```

The concept never changes.

---

# Common Mistakes

## Dereferencing nullptr

Wrong

```cpp
int* ptr {nullptr};

*ptr = 5;
```

Undefined Behavior.

---

## Forgetting Parentheses

Wrong

```cpp
*vector_ptr.size();
```

Compiler Error.

Correct

```cpp
(*vector_ptr).size();
```

The dereference must happen before accessing the member.

---

## Confusing Address with Value

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

## Assuming Dereferencing Creates a Copy

Wrong assumption

```
*ptr

↓

copy
```

Reality

```
*ptr

↓

original object
```

Dereferencing accesses the actual object in memory.

---

## Moving the Pointer vs Changing the Object

```cpp
ptr = &another;
```

changes

```
Pointer
```

while

```cpp
*ptr = value;
```

changes

```
Object
```

Never confuse these two operations.

---

# Summary

After completing this topic, you should understand:

- What dereferencing means.
- The difference between a pointer and the object it points to.
- Reading values through pointers.
- Writing values through pointers.
- Dereferencing objects.
- Dereferencing vectors.
- `(*pointer).member`
- `pointer->member`
- Pointer safety.
- Modern C++ usage.

---

# Exercises

## Exercise 1

Create an integer variable.

Create a pointer.

Print

- address
- value
- dereferenced value

---

## Exercise 2

Modify an integer only through its pointer.

Verify that the original variable changes.

---

## Exercise 3

Create two pointers pointing to the same integer.

Modify the integer using one pointer.

Print the value using the second pointer.

---

## Exercise 4

Create a vector.

Create a pointer to the vector.

Use

```cpp
(*pointer).push_back(...)
```

to add three new elements.

Print the vector.

---

## Exercise 5

Rewrite

```cpp
(*pointer).size()
```

using the Arrow Operator.

Explain why both expressions are identical.

---

# Interview Questions

**Q:** What is the difference between `ptr` and `*ptr`?

**A:** `ptr` stores a memory address, while `*ptr` accesses the object stored at that address.

---

**Q:** Does `*ptr = value;` change the pointer?

**A:** No. It changes the object the pointer points to.

---

**Q:** What happens if you dereference `nullptr`?

**A:** Undefined Behavior, usually resulting in a program crash.

---

**Q:** Why do we write `(*pointer).member`?

**A:** Because the pointer must first be dereferenced to obtain the object before accessing one of its members.

---

# Key Takeaways

- A pointer stores an address; dereferencing accesses the value at that address.
- `*ptr` operates on the original object, not on a copy.
- Changing `*ptr` modifies the object itself.
- Reassigning a pointer changes where it points, not the object it previously referenced.
- Always ensure a pointer is valid before dereferencing it.
- `(*pointer).member` and `pointer->member` are equivalent, with the arrow operator serving as cleaner syntax.
- Mastering dereferencing is essential before learning pointer arithmetic, dynamic memory allocation, references, linked lists, trees, smart pointers, and many advanced C++ topics.