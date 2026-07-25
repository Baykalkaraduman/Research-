# Constructor Initialization Lists (Part 1)

---

# Introduction

Constructors are responsible for creating valid objects.

So far, we have initialized member variables inside the constructor body.

Example

```cpp
Player::Player()
{
    name = "None";
    health = 0;
    xp = 0;
}
```

Although this works, it is **not the preferred way** in Modern C++.

Instead, C++ provides **Constructor Initialization Lists**, which initialize data members directly before the constructor body executes.

Initialization Lists are

- more efficient,
- cleaner,
- required for certain member types,
- used throughout professional C++ projects.

---

# What is a Constructor Initialization List?

A Constructor Initialization List initializes member variables immediately when the object is being created.

General syntax

```cpp
ClassName::ClassName()

: member1{value1},
  member2{value2},
  member3{value3}
{

}
```

Notice that the initialization list appears

- after the constructor declaration,
- before the opening brace.

---

# Initialization vs Assignment

This is the most important concept of this topic.

Many beginners believe these two pieces of code do exactly the same thing.

They do **not**.

---

## Assignment

```cpp
Player::Player()
{
    name = "None";
    health = 0;
    xp = 0;
}
```

Execution

```
Construct name

↓

Construct health

↓

Construct xp

↓

Assign "None"

↓

Assign 0

↓

Assign 0
```

Every member is created first.

Only afterward are new values assigned.

---

## Initialization

```cpp
Player::Player()

: name{"None"},
  health{0},
  xp{0}
{

}
```

Execution

```
Initialize name

↓

Initialize health

↓

Initialize xp

↓

Object Ready
```

Each member receives its value immediately during construction.

No unnecessary assignments occur.

---

# Why is Initialization Better?

Initialization avoids extra work.

Assignment

```
Create Object

↓

Default Construct Members

↓

Assign New Values
```

Initialization

```
Create Object

↓

Construct Members Directly
```

The second approach performs fewer operations and is therefore more efficient.

---

# Constructor Body vs Initialization List

The constructor body executes **after** every member has already been initialized.

Order of execution

```
Allocate Object Memory

↓

Initialize Data Members

↓

Execute Constructor Body
```

This explains why Initialization Lists are fundamentally different from assignments inside the constructor body.

---

# Example

Instead of

```cpp
Player::Player(std::string name_val)
{
    name = name_val;
    health = 0;
    xp = 0;
}
```

Modern C++ prefers

```cpp
Player::Player(std::string name_val)

: name{name_val},
  health{0},
  xp{0}
{

}
```

The object is fully initialized before entering the constructor body.

---

# Constructor Overloading with Initialization Lists

Initialization Lists work with every constructor.

Example

Default Constructor

```cpp
Player()

: name{"None"},
  health{0},
  xp{0}
{

}
```

---

One-Argument Constructor

```cpp
Player(std::string name)

: name{name},
  health{0},
  xp{0}
{

}
```

---

Three-Argument Constructor

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

Every constructor initializes its members directly.

---

# Member Initialization Order

One extremely important rule is often misunderstood.

Members are initialized in the order they are **declared inside the class**, **not** in the order they appear in the initialization list.

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

Initialization

```cpp
: xp{5},
  name{"Hero"},
  health{100}
```

Actual execution order

```
name

↓

health

↓

xp
```

The declaration order always determines initialization order.

For clarity and good style, always write the initialization list in the same order as the member declarations.

---

# Why This Rule Exists

The compiler guarantees a predictable initialization order.

Changing the order in the initialization list does **not** change the construction order.

Ignoring this rule may generate compiler warnings and can introduce subtle bugs.

---

# Common Beginner Mistakes

## Mistake 1

Thinking assignment and initialization are identical.

They are different operations.

---

## Mistake 2

Writing initialization lists in a different order than member declarations.

Always match the declaration order.

---

## Mistake 3

Using assignments inside constructors when direct initialization is possible.

Prefer Initialization Lists whenever appropriate.

---

# Best Practices

✔ Prefer Constructor Initialization Lists over assignments.

✔ Keep the initialization list in the same order as member declarations.

✔ Initialize every data member directly whenever possible.

✔ Remember that the constructor body executes only after all members have been initialized.

---

# Summary (Part 1)

- Constructor Initialization Lists initialize members directly during object construction.
- Initialization is different from assignment.
- Initialization avoids unnecessary work and is more efficient.
- The constructor body executes after all members have already been initialized.
- Every constructor can use an Initialization List.
- Members are always initialized according to their declaration order, not the order written in the initialization list.

> **Key Takeaway:**  
> Constructor Initialization Lists construct objects correctly from the very beginning of their lifetime. They are the preferred initialization method in Modern C++ because they are cleaner, more efficient, and required for many advanced language features.

# Constructor Initialization Lists (Part 2)

---

# Performance Advantages

Initialization Lists are not only cleaner but also more efficient.

Consider

```cpp
Player::Player()
{
    name = "Hero";
}
```

Execution

```
Default Construct std::string

↓

Assign "Hero"
```

The string object is constructed first.

Then another operation assigns a new value.

---

Using an Initialization List

```cpp
Player::Player()

: name{"Hero"}
{

}
```

Execution

```
Construct std::string with "Hero"
```

Only one operation occurs.

No unnecessary assignment is performed.

This is especially important for large or complex objects.

---

# When Initialization Lists are Required

Sometimes Initialization Lists are not simply recommended.

They are mandatory.

---

## Const Data Members

Example

```cpp
class Player
{
private:

    const int id;

public:

    Player(int value)

    : id{value}
    {

    }
};
```

Writing

```cpp
id = value;
```

inside the constructor body is impossible.

A constant must receive its value immediately when it is created.

---

## Reference Data Members

References cannot exist without referring to an object.

Example

```cpp
class Example
{
private:

    int &ref;

public:

    Example(int &r)

    : ref{r}
    {

    }
};
```

References must always be initialized.

They cannot be assigned later.

---

# Objects as Data Members

Suppose a class contains another class.

```cpp
class Weapon
{

};

class Player
{
private:

    Weapon sword;
};
```

The `Weapon` object is constructed before entering the constructor body.

Initialization Lists allow the contained object to be constructed correctly from the beginning.

---

# Constructor Body Cannot Reconstruct Members

Once a member has been created,

the constructor body cannot reconstruct it.

It can only modify it.

Initialization Lists are therefore the only way to control how members are constructed.

---

# Initialization Order Reminder

Remember

Members are initialized according to their declaration order.

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

Even if we write

```cpp
: xp{5},
  name{"Hero"},
  health{100}
```

the compiler still performs

```
name

↓

health

↓

xp
```

Always match your Initialization List to the declaration order.

This improves readability and avoids compiler warnings.

---

# Why Professional Projects Prefer Initialization Lists

Nearly every modern C++ project uses Initialization Lists.

Examples include

- C++ Standard Library
- ROOT
- Geant4
- Qt
- Unreal Engine
- LLVM

Reading professional code will almost always reveal constructors written in this style.

---

# Relationship with RAII

Initialization Lists naturally support the RAII principle.

Resources should be acquired during construction.

Example

```
Constructor

↓

Initialization List

↓

Object Ready

↓

Destructor

↓

Resources Released
```

Constructing objects correctly from the beginning makes resource management safer and more predictable.

---

# Looking Ahead

Soon you will encounter classes containing

```cpp
const

references

objects

smart pointers
```

Initialization Lists will no longer be optional.

They will be required.

Understanding them now will make future topics much easier.

---

# Common Beginner Mistakes

## Mistake 1

Thinking Initialization Lists are only a stylistic preference.

They are often required.

---

## Mistake 2

Initializing members inside the constructor body instead of using an Initialization List.

Prefer direct initialization whenever possible.

---

## Mistake 3

Ignoring member declaration order.

Always initialize members in the same order they are declared.

---

## Mistake 4

Believing Initialization Lists execute after the constructor body.

The opposite is true.

Initialization Lists execute before entering the constructor body.

---

# Best Practices

✔ Prefer Constructor Initialization Lists in every constructor.

✔ Match the initialization order to the member declaration order.

✔ Use Initialization Lists for every `const` member.

✔ Use Initialization Lists for every reference member.

✔ Initialize contained objects directly.

✔ Keep the constructor body focused on logic that cannot be handled during initialization.

---

# Summary

- Constructor Initialization Lists initialize members directly during object construction.
- They eliminate unnecessary assignments and improve efficiency.
- They are required for `const` members and reference members.
- Objects that are members of other classes should also be initialized using Initialization Lists.
- Members are always initialized according to their declaration order.
- Initialization Lists are the standard style used in professional C++ development.
- Mastering Initialization Lists is essential before learning Copy Constructors, Move Constructors, Inheritance, and Smart Pointers.

> **Key Takeaway:**  
> Constructor Initialization Lists are the preferred and often mandatory way to initialize objects in Modern C++. They provide cleaner syntax, better performance, and form the foundation for many advanced C++ features used in large scientific frameworks such as ROOT, Geant4, and CMSSW.