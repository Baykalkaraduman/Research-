# Delegating Constructors (Part 1)

---

# Introduction

As classes become larger, they often require multiple constructors.

Example

```cpp
Player();

Player(std::string);

Player(std::string, int, int);
```

Without careful design, each constructor may repeat the same initialization code.

Repeated code is difficult to maintain and increases the chance of bugs.

To solve this problem, Modern C++ introduced **Delegating Constructors** in C++11.

A Delegating Constructor allows one constructor to call another constructor of the same class.

---

# What is a Delegating Constructor?

A Delegating Constructor is a constructor whose only task is to call another constructor in the same class.

Instead of initializing every member itself,

it delegates the work to another constructor.

General syntax

```cpp
Player()

: Player{"None", 0, 0}
{

}
```

The constructor above does **not** initialize any data members directly.

Instead,

it forwards the work to another constructor.

---

# Why Use Delegating Constructors?

Imagine a class with three constructors.

Without delegation

```cpp
Player()
{
    name = "None";
    health = 0;
    xp = 0;
}

Player(std::string name)
{
    this->name = name;
    health = 0;
    xp = 0;
}

Player(std::string name,
       int health,
       int xp)
{
    this->name = name;
    this->health = health;
    this->xp = xp;
}
```

Notice that

```
health = 0;

xp = 0;
```

appear multiple times.

This repetition is called

**Code Duplication**.

Duplicated code is difficult to maintain.

If one constructor changes,

every duplicated constructor must also be updated.

---

# Delegation Eliminates Duplication

Using Delegating Constructors

```cpp
Player()

: Player{"None", 0, 0}
{

}

Player(std::string name)

: Player{name, 0, 0}
{

}
```

Now only one constructor performs the real initialization.

```cpp
Player(std::string name,
       int health,
       int xp)

: name{name},
  health{health},
  xp{xp}
{

}
```

Every other constructor simply forwards the work.

---

# Constructor Delegation Flow

Suppose we create

```cpp
Player hero;
```

Execution

```
Default Constructor

↓

Delegates

↓

Three-Argument Constructor

↓

Initialize Members

↓

Return

↓

Default Constructor Body

↓

Object Ready
```

Notice that the object is initialized only once.

---

Now consider

```cpp
Player emir{"Emir"};
```

Execution

```
One-Argument Constructor

↓

Delegates

↓

Three-Argument Constructor

↓

Initialize Members

↓

Return

↓

One-Argument Constructor Body

↓

Object Ready
```

Again,

only one constructor performs member initialization.

---

# The Main Constructor

In many classes,

one constructor becomes the **main constructor**.

Its responsibility is

✔ initialize every member

✔ guarantee a valid object

✔ contain the complete initialization logic

Every other constructor simply forwards to it.

This keeps the class simple and consistent.

---

# Delegation vs Function Calls

Delegating Constructors do **not** behave like ordinary function calls.

This is valid

```cpp
Player()

: Player{"None", 0, 0}
{

}
```

This is **not** valid

```cpp
Player()
{
    Player("None",0,0);
}
```

The second example creates a temporary object.

It does **not** initialize the current object.

Only constructor delegation initializes the object being created.

---

# Common Beginner Mistakes

## Mistake 1

Repeating initialization code in every constructor.

Prefer one main constructor.

---

## Mistake 2

Thinking delegation creates another object.

It does not.

It forwards construction of the same object.

---

## Mistake 3

Trying to call another constructor inside the constructor body.

Delegation only works through the Initialization List.

---

# Best Practices

✔ Choose one constructor as the primary constructor.

✔ Perform all member initialization there.

✔ Let smaller constructors delegate to it.

✔ Avoid duplicated initialization code.

✔ Keep constructors short and easy to maintain.

---

# Summary (Part 1)

- Delegating Constructors were introduced in C++11.
- They allow one constructor to call another constructor in the same class.
- Their primary purpose is eliminating duplicated initialization code.
- Usually one constructor performs all initialization, while the others delegate to it.
- Delegation makes classes easier to maintain, easier to extend, and less error-prone.

> **Key Takeaway:**  
> Delegating Constructors improve code quality by centralizing object initialization in a single constructor. Instead of repeating initialization logic across multiple constructors, Modern C++ encourages one primary constructor and several lightweight delegating constructors.

# Delegating Constructors (Part 2)

---

# Constructor Delegation Rules

Delegating Constructors follow a few important rules.

---

## Rule 1

A delegating constructor may delegate to **only one constructor**.

Valid

```cpp
Player()

: Player{"None",0,0}
{

}
```

Invalid

```cpp
Player()

: Player{"None"},
  Player{"Hero",100,10}
{

}
```

Only one delegation is allowed.

---

## Rule 2

Delegation must appear inside the Initialization List.

Correct

```cpp
Player()

: Player{"None",0,0}
{

}
```

Incorrect

```cpp
Player()
{
    Player("None",0,0);
}
```

The second example creates a temporary object.

It does **not** initialize the current object.

---

## Rule 3

Only one constructor performs real initialization.

Suppose

```cpp
Player hero;
```

Execution

```
Default Constructor

↓

Delegates

↓

Three-Argument Constructor

↓

Initialize Members

↓

Return

↓

Default Constructor Body

↓

Object Ready
```

Notice that the members are initialized exactly once.

---

# Constructor Chaining

Delegating Constructors create a chain.

Example

```cpp
Player()

↓

Player(string)

↓

Player(string,int,int)
```

The last constructor performs all initialization.

Then execution returns upward.

```
Three-Argument Constructor

↓

One-Argument Constructor

↓

Default Constructor
```

This behavior is often called **Constructor Chaining**.

---

# Delegation and Initialization Lists

Delegating Constructors and Constructor Initialization Lists work together.

Example

```cpp
Player()

: Player{"None",0,0}
{

}
```

↓

delegates to

```cpp
Player(string,int,int)

: name{name},
  health{health},
  xp{xp}
{

}
```

Delegation chooses **which constructor** performs initialization.

Initialization Lists determine **how the members are initialized**.

These are two different concepts that work together.

---

# Advantages of Delegating Constructors

## Less Code

Initialization appears only once.

---

## Easier Maintenance

Suppose a new member is added.

```cpp
int level;
```

Without delegation,

every constructor must be updated.

With delegation,

only the primary constructor changes.

---

## Lower Bug Risk

Repeated initialization code often becomes inconsistent.

Delegation guarantees every object is initialized using exactly the same logic.

---

## Better Readability

Each constructor has a clear responsibility.

Small constructors

↓

Forward

↓

Primary constructor

↓

Initialization

The intent becomes obvious.

---

# Real-World Usage

Delegating Constructors are used throughout Modern C++.

Examples include

- C++ Standard Library
- Qt Framework
- LLVM
- Unreal Engine
- ROOT
- Geant4

Large software projects rely on delegation to reduce duplicated code and improve maintainability.

---

# Delegation vs Inheritance

Beginners sometimes confuse these ideas.

Delegating Constructors

```
One constructor

↓

Another constructor

↓

Same class
```

Inheritance

```
Derived Class

↓

Base Class
```

Delegation occurs entirely inside one class.

Inheritance involves different classes.

---

# Common Beginner Mistakes

## Mistake 1

Believing delegation creates another object.

It does not.

The same object is being constructed.

---

## Mistake 2

Using delegation for every constructor.

Sometimes constructors genuinely perform different initialization and should not delegate.

---

## Mistake 3

Repeating initialization after delegation.

Example

```cpp
Player()

: Player{"None",0,0}
{
    health = 100;
}
```

Although valid,

it often defeats the purpose of centralizing initialization.

---

## Mistake 4

Thinking delegation improves performance.

Its primary purpose is

- reducing duplicated code,
- improving readability,
- simplifying maintenance.

Performance improvements are usually secondary.

---

# Best Practices

✔ Choose one constructor as the primary constructor.

✔ Perform all member initialization there.

✔ Let simpler constructors delegate to it.

✔ Combine Delegating Constructors with Constructor Initialization Lists.

✔ Avoid duplicating initialization logic.

✔ Keep constructors small and focused.

---

# Looking Ahead

The next topics build directly on constructor behavior.

Soon you will learn

- Copy Constructors
- Move Constructors
- Shallow vs Deep Copy
- Copy Assignment Operator
- Move Assignment Operator

All of these rely on understanding how constructors initialize objects.

Delegating Constructors provide the foundation for writing clean and maintainable constructors before moving on to object copying and resource management.

---

# Summary

- A Delegating Constructor forwards construction to another constructor in the same class.
- Delegation is performed through the Constructor Initialization List.
- Only one constructor should contain the complete initialization logic.
- Constructor Chaining allows constructors to reuse each other safely.
- Delegation and Initialization Lists serve different purposes but work together.
- Delegating Constructors reduce duplicated code and improve maintainability.
- Modern C++ projects use Delegating Constructors extensively as part of clean object-oriented design.

> **Key Takeaway:**  
> Delegating Constructors are a design tool rather than a performance optimization. By centralizing initialization in one primary constructor, they make classes easier to read, easier to maintain, and less prone to bugs—a practice widely adopted in professional Modern C++ codebases.