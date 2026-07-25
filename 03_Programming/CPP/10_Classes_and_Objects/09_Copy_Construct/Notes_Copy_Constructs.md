# Copy Constructors (Part 1)

---

# Introduction

Until now, we have learned how objects are created using constructors.

However, objects are not only created from scratch.

Very often, a new object is created **from another existing object**.

Example

```cpp
Player emir{"Emir"};

Player hero{emir};
```

Here, `hero` is initialized using the contents of `emir`.

This process is called **copy construction**.

To perform this operation safely, C++ provides a special member function called the **Copy Constructor**.

---

# What is a Copy Constructor?

A Copy Constructor is a special constructor whose purpose is to initialize a new object using another object of the same class.

General syntax

```cpp
Player(const Player &source);
```

The parameter is

- another object of the same class,
- passed by reference,
- and marked as const.

---

# When is the Copy Constructor Called?

The compiler automatically calls the Copy Constructor whenever a new object is initialized from another object.

Example

```cpp
Player emir{"Emir"};

Player hero{emir};
```

Execution

```
emir already exists

↓

hero is created

↓

Copy Constructor is called

↓

hero receives copies of emir's members
```

---

# Copy Construction vs Assignment

These two statements look similar but are completely different.

Copy Construction

```cpp
Player hero{emir};
```

Object **does not exist yet**.

The Copy Constructor is called.

---

Copy Assignment

```cpp
Player hero;

hero = emir;
```

Object already exists.

The Copy Assignment Operator is used instead.

This distinction is extremely important.

---

# Implementing a Copy Constructor

Example

```cpp
Player::Player(const Player &source)

: Player{
    source.name,
    source.health,
    source.xp
}
{

}
```

Instead of copying every member manually,

the constructor delegates to the main constructor.

This is a modern and clean implementation.

---

# Delegating Copy Constructor

Older C++ code often looks like this

```cpp
Player::Player(const Player &source)

: name{source.name},
  health{source.health},
  xp{source.xp}
{

}
```

Modern C++ often prefers

```cpp
Player::Player(const Player &source)

: Player{
    source.name,
    source.health,
    source.xp
}
{

}
```

Advantages

- less duplicated code
- one initialization point
- easier maintenance
- cleaner design

---

# Why is the Parameter a Reference?

Notice the declaration

```cpp
Player(const Player &source);
```

Why not

```cpp
Player(Player source);
```

Because passing by value would require making another copy.

Creating that copy would call the Copy Constructor again.

That constructor would again need another copy.

Which would again call the Copy Constructor.

The result would be

```
Copy

↓

Copy

↓

Copy

↓

Copy

↓

Infinite recursion

↓

Stack Overflow
```

Passing by reference avoids this problem completely.

---

# Why is the Parameter const?

The source object is only read.

It should never be modified during copying.

Using

```cpp
const Player &
```

guarantees that the original object remains unchanged.

It also allows copying from const objects.

This is considered best practice throughout Modern C++.

---

# Visual Representation

Suppose

```cpp
Player emir{"Emir"};

Player hero{emir};
```

Memory concept

```
Original Object

+----------------+
| Name   = Emir  |
| Health = 0     |
| XP     = 0     |
+----------------+

        │

        │ Copy Constructor

        ▼

New Object

+----------------+
| Name   = Emir  |
| Health = 0     |
| XP     = 0     |
+----------------+
```

Two different objects now exist.

They simply contain the same values.

---

# Common Beginner Mistakes

## Mistake 1

Confusing copy construction with assignment.

```cpp
Player hero{emir};
```

is **not**

```cpp
hero = emir;
```

---

## Mistake 2

Passing the source object by value.

Always use

```cpp
const Player &
```

---

## Mistake 3

Thinking the Copy Constructor duplicates memory addresses.

At this stage,

it copies the object's data members.

Later, when dynamic memory is introduced, this becomes much more complicated.

That is exactly why we study Shallow Copy and Deep Copy next.

---

# Summary (Part 1)

- A Copy Constructor initializes a new object from an existing object.
- It is automatically called when an object is created from another object.
- The parameter should always be `const ClassName&`.
- Passing by reference prevents infinite recursion.
- Using `const` guarantees that the source object will not be modified.
- Modern C++ often combines Copy Constructors with Delegating Constructors for cleaner code.

> **Key Takeaway:**  
> A Copy Constructor creates a brand-new object using the values of an existing object. Although the two objects contain the same data, they remain completely separate objects in memory. Understanding this behavior is essential before learning about shallow copies, deep copies, and modern resource management.

# Copy Constructors (Part 2)

---

# Compiler-Generated Copy Constructor

If a class does not define its own Copy Constructor,

the C++ compiler automatically generates one.

Example

```cpp
class Player
{
private:

    std::string name;
    int health;
    int xp;
};
```

No Copy Constructor exists.

The compiler silently creates one.

Its behavior is roughly equivalent to

```cpp
Player(const Player &source)

: name{source.name},
  health{source.health},
  xp{source.xp}
{

}
```

This is called the **Compiler-Generated Copy Constructor**.

---

# Memberwise Copy

The compiler-generated Copy Constructor performs a

**Memberwise Copy**.

Each data member is copied one by one.

Example

Original object

```
Name   = Emir

Health = 100

XP     = 42
```

↓

Copied object

```
Name   = Emir

Health = 100

XP     = 42
```

Every member receives the same value.

For simple data types,

this works perfectly.

---

# When Does the Copy Constructor Run?

There are several situations where the compiler automatically invokes it.

---

## 1. Copy Initialization

```cpp
Player hero{emir};
```

or

```cpp
Player hero = emir;
```

Both call the Copy Constructor.

---

## 2. Passing an Object by Value

Example

```cpp
void display(Player player)
{

}
```

Calling

```cpp
display(emir);
```

creates a copy of `emir`.

Execution

```
emir

↓

Copy Constructor

↓

player

↓

Function Body
```

After the function finishes,

the copied object is destroyed.

---

## 3. Returning by Value

Example

```cpp
Player create_player()
{
    Player hero{"Hero"};

    return hero;
}
```

Traditionally,

returning an object by value required copying it.

Modern C++ often avoids this copy through compiler optimizations (discussed later).

---

## 4. Temporary Objects

Sometimes temporary objects are created automatically.

Example

```cpp
Player hero{Player{"Emir"}};
```

Depending on compiler optimizations,

the Copy Constructor may or may not execute.

---

# Why Pass by Reference Instead?

Compare

Pass by Value

```cpp
void display(Player player);
```

↓

Creates a copy.

---

Pass by Reference

```cpp
void display(const Player &player);
```

↓

No copy.

↓

Faster.

↓

Less memory usage.

For large classes,

passing by reference is almost always preferred.

---

# Copy Constructor and Destructor

Every copied object is a completely independent object.

Example

```cpp
Player emir{"Emir"};

Player hero{emir};
```

Memory

```
Original Object

↓

Copy Constructor

↓

New Object
```

Later

```
Destructor(hero)

↓

Destructor(emir)
```

Each object has its own lifetime.

Each object is destroyed separately.

---

# Copy Constructor Does NOT Mean Shared Object

Beginners sometimes think

```cpp
Player hero{emir};
```

creates another name for the same object.

It does not.

Instead

```
Object A

↓

Copy

↓

Object B
```

Both objects contain identical values,

but they occupy different memory locations.

Changing one object does not affect the other.

Example

```cpp
Player hero{emir};

hero.set_name("Hero");
```

Result

```
hero.name = Hero

emir.name = Emir
```

The original object remains unchanged.

---

# When Is the Compiler Version Enough?

The compiler-generated Copy Constructor works correctly when the class contains only

- integers
- floating-point numbers
- bool
- std::string
- STL containers
- other classes that correctly support copying

These types already know how to copy themselves safely.

---

# Looking Ahead

Everything changes once a class owns dynamic memory.

Example

```cpp
class Player
{
private:

    int *health;
};
```

Now,

copying the pointer copies only the address.

Two objects end up pointing to the same memory.

This problem is called

**Shallow Copy**.

The solution is

**Deep Copy**.

That is why understanding ordinary Copy Constructors is essential before moving on.

---

# Common Beginner Mistakes

## Mistake 1

Thinking every function call copies an object.

Only **pass-by-value** creates a copy.

Passing by reference does not.

---

## Mistake 2

Assuming copied objects share memory.

They do not (unless pointers are involved).

---

## Mistake 3

Writing unnecessary Copy Constructors.

If your class owns no dynamic resources,

the compiler-generated Copy Constructor is often sufficient.

---

# Best Practices

✔ Pass large objects using `const ClassName&`.

✔ Understand when copying occurs automatically.

✔ Use the compiler-generated Copy Constructor whenever possible.

✔ Write a custom Copy Constructor only when your class manages resources.

---

# Summary (Part 2)

- The compiler automatically generates a Copy Constructor if one is not provided.
- The generated constructor performs a memberwise copy.
- Copy Constructors are called during copy initialization, pass-by-value, and (conceptually) return-by-value.
- Passing objects by reference avoids unnecessary copies.
- Copied objects are separate objects with independent lifetimes.
- Classes containing only standard C++ types usually do not require a custom Copy Constructor.

> **Key Takeaway:**  
> The compiler-generated Copy Constructor is sufficient for most ordinary classes because it performs a memberwise copy. Problems begin only when a class owns resources such as dynamically allocated memory. That limitation leads directly to the concepts of **Shallow Copy** and **Deep Copy**, which are the next major topics in modern C++.

# Copy Constructors (Part 3)

---

# The Real Purpose of Copy Constructors

At first glance,

a Copy Constructor seems simple.

It copies one object's data into another object.

However,

its real purpose is much more important.

A Copy Constructor defines **how an object should be duplicated**.

For small objects,

this process is straightforward.

For classes managing resources,

copying becomes one of the most critical operations in C++.

---

# Copying Objects vs Copying Resources

Consider this class.

```cpp
class Player
{
private:

    std::string name;
    int health;
    int xp;
};
```

Every member already knows how to copy itself.

Copying is easy.

---

Now imagine

```cpp
class Player
{
private:

    int *health;
};
```

The object no longer owns an integer.

Instead,

it owns a pointer to dynamically allocated memory.

Now copying becomes dangerous.

The compiler will only copy the pointer itself.

Both objects will point to the same memory location.

This is the beginning of the **Shallow Copy** problem.

---

# Visual Comparison

Safe Copy

```
Object A

Name = Emir

Health = 100

XP = 25

↓

Copy Constructor

↓

Object B

Name = Emir

Health = 100

XP = 25
```

Everything is duplicated safely.

---

Unsafe Copy (Dynamic Memory)

```
Object A

health ─────┐
            │
            ▼
         Heap Memory

↓

Copy

↓

Object B

health ─────┘
```

Now both objects own exactly the same memory.

Neither object knows the other exists.

This eventually causes serious bugs.

---

# Why Learning Copy Constructors Matters

Soon you will study

- Shallow Copy
- Deep Copy
- Move Constructor
- Move Assignment
- Smart Pointers

Every one of these topics is built on one simple question:

> **"What should happen when an object is copied?"**

The Copy Constructor provides the answer.

---

# Compiler Optimizations

Modern C++ compilers are very intelligent.

Sometimes they completely remove copies.

Example

```cpp
Player create_player()
{
    return Player{"Hero"};
}
```

Although this appears to create a copy,

the compiler often constructs the object directly in its final destination.

This optimization is called

**Copy Elision**

or

**Return Value Optimization (RVO / NRVO).**

Because of this,

the Copy Constructor may not actually execute,

even though logically a copy exists.

---

# Copy Constructor vs Copy Assignment

Many beginners confuse these.

Remember

Copy Constructor

```cpp
Player hero{emir};
```

A brand-new object is created.

---

Copy Assignment

```cpp
Player hero;

hero = emir;
```

The object already exists.

Its contents are replaced.

These are two completely different operations.

Each has its own special function in C++.

---

# Relation to the Rule of Three

Whenever a class manages dynamic memory,

implementing only one special member function is usually not enough.

Historically,

C++ introduced the **Rule of Three**.

If your class defines one of these

- Destructor
- Copy Constructor
- Copy Assignment Operator

it will probably need all three.

This is because all three deal with resource ownership.

Later,

Modern C++ expanded this idea into the

**Rule of Five**.

---

# Common Beginner Mistakes

## Mistake 1

Thinking copying is always inexpensive.

Some objects contain thousands of elements.

Copying them may be very expensive.

---

## Mistake 2

Passing every object by value.

Large objects should usually be passed as

```cpp
const ClassName&
```

unless copying is actually required.

---

## Mistake 3

Assuming the compiler-generated Copy Constructor always works.

It works perfectly for ordinary data members.

It is **not** sufficient for classes owning raw pointers.

---

## Mistake 4

Believing copied objects share state.

Normally they do not.

Only shared resources (typically pointers) can create this behavior.

---

# Best Practices

✔ Prefer compiler-generated Copy Constructors for simple classes.

✔ Write a custom Copy Constructor only when managing resources.

✔ Pass objects by const reference whenever possible.

✔ Understand the difference between copying values and copying ownership.

✔ Keep constructors responsible for creating valid independent objects.

---

# Preparing for the Next Topic

The next lesson introduces one of the most famous bugs in C++.

**Shallow Copy**

You will see why the compiler-generated Copy Constructor becomes dangerous when a class owns dynamically allocated memory.

After that,

you will learn **Deep Copy**, which solves this problem by creating completely independent resources for every object.

These two topics are among the most important concepts in Modern C++.

---

# Final Summary

- A Copy Constructor defines how a new object is created from an existing one.
- The compiler can automatically generate a memberwise Copy Constructor.
- For ordinary classes, this is usually sufficient.
- Classes that own dynamic memory require special care.
- Copy Constructors, Destructors, and Copy Assignment Operators together manage object ownership.
- Understanding Copy Constructors is the foundation for learning Shallow Copy, Deep Copy, Move Semantics, and Smart Pointers.

---

# Key Takeaways

- A Copy Constructor creates **a new object** from an existing object.
- The copied object has its own lifetime and identity.
- Memberwise copying works well for standard library types.
- Raw pointers introduce ownership problems that require custom copying strategies.
- Copy Constructors are one of the core mechanisms that make object-oriented programming possible in C++.
- Mastering this topic is essential before studying memory management and modern resource handling.

> **Final Thought:**  
> Copy Constructors are not simply about duplicating data—they define **how ownership and state are transferred when a new object is created**. This idea lies at the heart of modern C++ resource management. Understanding it thoroughly will make concepts such as Shallow Copy, Deep Copy, Move Semantics, RAII, and Smart Pointers much easier to learn.