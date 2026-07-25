# Deep Copy (Part 1)

---

# Introduction

In the previous lesson, we learned about **Shallow Copy**.

A shallow copy duplicates only the pointer, causing multiple objects to share the same heap memory.

This leads to serious problems such as

- dangling pointers,
- double deletion,
- undefined behavior,
- and program crashes.

The solution to these problems is called **Deep Copy**.

---

# What is a Deep Copy?

A Deep Copy creates a completely independent copy of an object.

Instead of copying only the pointer,

it

1. allocates new memory,
2. copies the stored value,
3. gives the new object ownership of its own resource.

Each object owns its own heap allocation.

---

# Shallow Copy vs Deep Copy

## Shallow Copy

```
Object A

data ----┐
         │
         ▼
      Heap Memory
         ▲
         │
data ----┘

Object B
```

Only the pointer is copied.

Both objects own the same resource.

---

## Deep Copy

```
Object A

data

↓

Heap

100


Object B

data

↓

Heap

100
```

The value is copied,

but the memory is different.

Each object owns its own heap allocation.

---

# The Example Class

```cpp
class Deep
{
private:

    int *data;

public:

    Deep(int value);

    Deep(const Deep &source);

    ~Deep();
};
```

Notice that this class still owns dynamic memory.

The difference lies entirely in the Copy Constructor.

---

# Constructor

```cpp
Deep::Deep(int value)
{
    data = new int;

    *data = value;
}
```

Step by step

1. Allocate memory on the heap.

2. Store the heap address.

3. Save the integer value.

Memory

```
Object

↓

Pointer

↓

Heap

100
```

The object owns exactly one heap allocation.

---

# Deep Copy Constructor

```cpp
Deep::Deep(const Deep &source)

: Deep{*source.data}
{

}
```

This constructor delegates to the main constructor.

Instead of copying the pointer,

it copies the **value** stored in the source object.

The delegated constructor then allocates brand-new memory.

As a result,

the copied object owns its own resource.

---

# What Actually Happens?

Suppose

```cpp
Deep obj1{100};

Deep obj2{obj1};
```

Execution

```
obj1

↓

Heap Allocation

↓

100

↓

Copy Constructor

↓

Allocate NEW Heap

↓

Copy value

↓

obj2
```

Notice carefully.

The integer value is copied,

not the heap address.

---

# Visual Representation

Before copying

```
obj1

↓

Heap

100
```

After Deep Copy

```
obj1

↓

Heap A

100


obj2

↓

Heap B

100
```

Heap A and Heap B are completely different memory locations.

The two objects are now fully independent.

---

# Why Is This Safe?

Each object owns its own memory.

Therefore

```
Destructor(obj1)

↓

Deletes Heap A
```

Later

```
Destructor(obj2)

↓

Deletes Heap B
```

Every allocation has exactly one owner.

Every allocation is deleted exactly once.

No dangling pointers.

No double deletion.

No crash.

---

# Common Beginner Mistakes

## Mistake 1

Thinking Deep Copy simply copies the pointer.

It does not.

It allocates completely new memory.

---

## Mistake 2

Thinking Deep Copy is slower for no reason.

Allocating memory takes extra work,

but it guarantees safe ownership.

---

## Mistake 3

Believing Deep Copy is optional for classes with raw pointers.

Whenever a class owns dynamically allocated memory,

Deep Copy is usually required.

---

# Summary (Part 1)

- Deep Copy allocates new memory for every copied object.
- The stored value is copied, not the pointer.
- Each object owns its own independent resource.
- Every object deletes only its own memory.
- Deep Copy eliminates the problems caused by Shallow Copy.

> **Key Takeaway:**  
> A Deep Copy duplicates both the **data** and the **ownership** of dynamically allocated resources. Every copied object receives its own independent memory, preventing dangling pointers, double deletion, and the resource ownership problems that occur with Shallow Copy.

# Deep Copy (Part 2)

---

# Step-by-Step Execution

Let's examine the program exactly as the compiler executes it.

---

# Step 1 — Creating obj1

```cpp
Deep obj1{100};
```

Constructor

```cpp
Deep::Deep(int value)
{
    data = new int;

    *data = value;
}
```

Execution

```
Allocate Heap

↓

Store integer

↓

Save address inside data
```

Memory

```
Stack

obj1

data

↓

Heap A

100
```

Everything is correct.

obj1 owns Heap A.

---

# Step 2 — Passing by Value

```cpp
display_deep(obj1);
```

Function

```cpp
void display_deep(Deep object)
```

Notice carefully.

The parameter is passed **by value**.

Therefore,

the Copy Constructor is automatically called.

Execution

```
obj1

↓

Copy Constructor

↓

Temporary Object
```

Unlike Shallow Copy,

this temporary object does **not** reuse Heap A.

Instead,

it allocates completely new memory.

---

# Step 3 — Deep Copy Constructor

```cpp
Deep::Deep(const Deep &source)

: Deep{*source.data}
{

}
```

This constructor delegates to

```cpp
Deep(int value)
```

The delegated constructor

1. allocates new heap memory,

2. copies the integer value,

3. stores the new address.

Memory now becomes

```
obj1

↓

Heap A

100



Temporary Object

↓

Heap B

100
```

Notice

```
Heap A

≠

Heap B
```

Only the value

```
100
```

has been copied.

The memory is completely different.

---

# Step 4 — Leaving the Function

When

```cpp
display_deep()
```

finishes,

the temporary object is destroyed.

Destructor

```cpp
delete data;
```

Execution

```
Temporary Object

↓

Delete Heap B
```

Memory

```
obj1

↓

Heap A

100
```

Heap A still exists.

obj1 remains completely valid.

Nothing has been damaged.

---

# Step 5 — Explicit Copy

Later,

the program executes

```cpp
Deep obj2{obj1};
```

Again,

the Copy Constructor runs.

Execution

```
obj1

↓

Heap A

100

↓

Copy Constructor

↓

Allocate Heap C

↓

Copy value

↓

obj2
```

Memory

```
obj1

↓

Heap A

100



obj2

↓

Heap C

100
```

Now

three different heap allocations have existed during execution

```
Heap A

Heap B

Heap C
```

Each belonged to exactly one object.

---

# Step 6 — Modifying obj2

```cpp
obj2.set_data_value(1000);
```

Memory

```
obj1

↓

Heap A

100



obj2

↓

Heap C

1000
```

obj1 is unchanged.

Only obj2 changes.

This is the biggest advantage of Deep Copy.

---

# Destructor Execution

Program ends.

Execution

```
Destructor(obj2)

↓

Delete Heap C

↓

Destructor(obj1)

↓

Delete Heap A
```

Every heap allocation is deleted exactly once.

No shared ownership exists.

No dangling pointers exist.

No crash occurs.

---

# Comparing Deep Copy with Shallow Copy

Shallow Copy

```
Two Objects

↓

One Heap

↓

Double Delete

↓

Crash
```

Deep Copy

```
Two Objects

↓

Two Heaps

↓

Independent Ownership

↓

Safe Destruction
```

The difference is only a few lines of code,

but the behavior is completely different.

---

# Delegating Constructor Advantage

Instead of writing

```cpp
data = new int;

*data = *source.data;
```

the Copy Constructor delegates to

```cpp
Deep{*source.data}
```

Advantages

- avoids duplicated code
- guarantees identical initialization
- easier maintenance
- safer implementation

Whenever possible,

delegating constructors are preferred in Modern C++.

---

# Common Beginner Mistakes

## Mistake 1

Thinking Deep Copy creates another pointer.

It actually creates another heap allocation.

---

## Mistake 2

Believing pass-by-value is dangerous.

It is only dangerous if the Copy Constructor is incorrect.

A proper Deep Copy makes pass-by-value perfectly safe.

---

## Mistake 3

Assuming every copied object shares memory.

Deep Copy guarantees independent ownership.

---

# Best Practices

✔ Allocate new memory during copying.

✔ Copy the stored value, not the pointer.

✔ Ensure every allocation has exactly one owner.

✔ Reuse constructors through delegation whenever possible.

✔ Verify that modifying one object does not affect another.

---

# Summary (Part 2)

- Passing by value invokes the Copy Constructor.
- The Deep Copy Constructor allocates new heap memory.
- The copied object owns a completely independent resource.
- Temporary objects safely delete only their own memory.
- Changing one object does not affect the other.
- Deep Copy completely eliminates the ownership problems caused by Shallow Copy.

> **Key Takeaway:**  
> A proper Deep Copy ensures that every object owns its own dynamically allocated memory. Even when objects are passed by value or copied explicitly, each instance manages its own resources independently, allowing destructors to safely release memory without causing dangling pointers or double deletion.

# Deep Copy (Part 3)

---

# Why Does Deep Copy Matter?

At first,

Deep Copy may seem like extra work.

Why allocate new memory when we could simply copy the pointer?

The answer is

**Resource Ownership.**

Every dynamically allocated resource must have one clear owner.

Deep Copy guarantees this ownership by creating an independent copy of the resource.

---

# Ownership

Imagine two people sharing the same house key.

```
Person A

↓

House Key

↑

Person B
```

If one person throws the key away,

the other person can no longer enter the house.

This is exactly what happens during a Shallow Copy.

---

Deep Copy gives each owner a different key.

```
Person A

↓

Key A

↓

House


Person B

↓

Key B

↓

House Copy
```

Each owner is completely independent.

---

# Resource Ownership in C++

With Deep Copy

```
obj1

↓

Heap A



obj2

↓

Heap B
```

Every object owns exactly one resource.

Each resource is deleted exactly once.

Ownership is clear.

Memory management becomes safe.

---

# Cost of Deep Copy

Deep Copy is much safer,

but it is also more expensive.

Every copy requires

- allocating new memory,
- copying the stored values,
- later releasing that memory.

For small objects,

this cost is insignificant.

For very large objects,

copying may become expensive.

This is one reason why Modern C++ introduced

**Move Semantics.**

---

# Deep Copy and Performance

Suppose an object stores

```
1 integer
```

Deep Copy is almost free.

Now suppose the object stores

```
10 million integers
```

Creating another full copy requires

- another heap allocation,
- another 10 million integers,
- another destructor.

Sometimes copying is unnecessary.

Modern C++ solves this with

Move Constructors.

---

# Deep Copy and the Rule of Three

Whenever a class owns dynamically allocated memory,

three member functions usually become necessary.

```
Destructor

↓

Copy Constructor

↓

Copy Assignment Operator
```

This principle is known as the

**Rule of Three.**

If one of these functions must be customized,

the other two usually must be customized as well.

---

# Modern C++ Evolution

Later,

C++11 introduced

- Move Constructor
- Move Assignment Operator

Together with the previous three,

they form the

**Rule of Five.**

Even later,

Modern C++ encourages avoiding manual memory management whenever possible.

The preferred solution is

**Smart Pointers.**

---

# Smart Pointers

Instead of writing

```cpp
new

delete
```

Modern C++ often uses

```cpp
std::unique_ptr

std::shared_ptr

std::weak_ptr
```

These automatically manage resource ownership.

Most modern C++ projects rarely use raw pointers for ownership.

---

# RAII (Resource Acquisition Is Initialization)

One of the most important ideas in Modern C++ is

**RAII**.

Resources are acquired during object construction,

and automatically released during destruction.

Deep Copy fits naturally into this philosophy,

because every object manages its own lifetime and resources.

---

# Deep Copy vs Shallow Copy

| Shallow Copy | Deep Copy |
|--------------|-----------|
| Copies the pointer | Allocates new memory |
| Shared ownership | Independent ownership |
| One heap allocation | Separate heap allocations |
| Dangling pointers | Safe memory management |
| Double deletion | Each object deletes only its own resource |
| Undefined behavior | Predictable behavior |
| Program may crash | Program remains safe |

---

# Common Beginner Mistakes

## Mistake 1

Using raw pointers without thinking about ownership.

Ownership should always be clear.

---

## Mistake 2

Writing a custom Destructor but forgetting the Copy Constructor.

This almost always causes resource management problems.

---

## Mistake 3

Assuming Deep Copy is always the best solution.

Sometimes moving an object is much faster than copying it.

---

## Mistake 4

Believing Smart Pointers make Deep Copy unnecessary.

Smart Pointers solve ownership,

but understanding Deep Copy is still essential for understanding how object copying works.

---

# Best Practices

✔ Prefer automatic resource management whenever possible.

✔ Use Deep Copy whenever a class owns dynamically allocated memory.

✔ Follow the Rule of Three (or Rule of Five) for resource-owning classes.

✔ Avoid unnecessary copies of large objects.

✔ Pass objects by `const ClassName&` unless copying is required.

✔ Prefer Smart Pointers instead of raw owning pointers in Modern C++.

---

# What Comes Next?

Now that you understand

- Copy Constructor
- Shallow Copy
- Deep Copy

you are ready to study

1. Copy Assignment Operator
2. Move Constructor
3. Move Assignment Operator
4. Rule of Five
5. Smart Pointers

These topics build directly on the ideas introduced here.

---

# Final Summary

- Deep Copy allocates new memory for every copied object.
- Each object owns an independent resource.
- Independent ownership prevents dangling pointers and double deletion.
- Deep Copy is the traditional solution for classes that manage raw pointers.
- Resource-owning classes usually follow the Rule of Three or Rule of Five.
- Modern C++ encourages using RAII and Smart Pointers to automate resource management.

---

# Key Takeaways

- **Shallow Copy copies the pointer.**
- **Deep Copy copies the data into newly allocated memory.**
- Every dynamically allocated resource should have exactly one owner.
- Deep Copy makes object copying safe by eliminating shared ownership.
- Understanding Deep Copy is essential before learning Move Semantics, RAII, and Smart Pointers.
- Deep Copy is one of the foundational concepts of Modern C++ object-oriented programming and memory management.

> **Final Thought:**  
> Deep Copy is not just about preventing crashes—it is about **defining clear ownership of resources**. Once every object owns its own memory, destructors can safely release resources, copies become predictable, and programs remain robust. This concept forms the bridge between traditional C++ memory management and the modern techniques you'll encounter next, including **Move Semantics**, **RAII**, and **Smart Pointers**.