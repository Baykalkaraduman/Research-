# Public and Private Access Specifiers

---

# Introduction

One of the most important principles of Object-Oriented Programming is **encapsulation**.

Encapsulation means protecting an object's data from direct access and allowing controlled interaction through member functions.

C++ provides **access specifiers** to achieve this.

The two most common access specifiers are

- public
- private

Understanding these keywords is essential because nearly every C++ class in ROOT, Geant4, Qt and the STL uses them.

---

# Why Do We Need Access Specifiers?

Imagine a Player object.

```
Player

↓

Name

Health

XP
```

Should any part of the program be allowed to change the player's health?

Example

```cpp
player.health = -500;
```

This clearly makes no sense.

To prevent invalid modifications, classes hide their internal data.

This concept is called **Data Hiding**.

---

# private Members

Members declared below

```cpp
private:
```

can only be accessed inside the class itself.

Example

```cpp
class Player
{
private:

    string name;
    int health;
    int xp;
};
```

The following code is illegal.

```cpp
Player player;

player.health = 100;
```

The compiler produces an error because `health` is private.

---

# public Members

Members declared below

```cpp
public:
```

are accessible from anywhere.

Example

```cpp
class Player
{
public:

    void talk(string text);
};
```

Now

```cpp
Player player;

player.talk("Hello!");
```

works correctly.

---

# Visual Representation

```
Player

───────────────

private

↓

name

health

xp

───────────────

public

↓

talk()

is_dead()
```

Only the public section is visible from outside the class.

---

# Accessing Private Data

Suppose we have

```cpp
Player emir;
```

Trying

```cpp
emir.name = "Emir";
```

produces a compiler error.

Likewise,

```cpp
emir.health = 100;

emir.xp = 40;
```

are also illegal.

The object owns these variables, but outside code cannot touch them directly.

---

# Accessing Public Functions

Although the data is hidden, public functions remain accessible.

Example

```cpp
emir.talk("Hi there!");
```

The function executes successfully because

```
talk()

↓

public
```

---

# Why Does talk() Still Work?

Notice that

```cpp
name
```

is private.

Yet

```cpp
talk()
```

prints it.

Why?

Because member functions belong to the class.

A class always has access to its own private members.

```
Player

↓

talk()

↓

Private Variables
```

This is one of the fundamental ideas behind encapsulation.

---

# Default Values

Private variables may still have default values.

Example

```cpp
string name {"Player"};
```

Even though outside code cannot modify `name`, the object initializes it automatically.

Therefore,

```cpp
emir.talk("Hi!");
```

prints

```
Player says: "Hi!"
```

instead of an empty name.

---

# Encapsulation

Encapsulation means

- hiding internal data
- exposing only what is necessary

Instead of allowing

```cpp
player.health = -500;
```

we later create functions like

```cpp
set_health();

get_health();
```

These functions can check whether the new value is valid before modifying the object.

This protects the integrity of the object.

---

# Real Physics Examples

ROOT

```cpp
TH1F histogram;
```

You cannot directly modify every internal variable of `TH1F`.

Instead, ROOT provides public member functions.

Example

```cpp
histogram.Fill(5.2);

histogram.Draw();
```

Geant4 works exactly the same way.

Objects expose public interfaces while hiding their implementation.

---

# Common Beginner Mistakes

## Mistake 1

Thinking private means "the variable does not exist."

Wrong.

It exists.

It is simply hidden from outside code.

---

## Mistake 2

Trying

```cpp
player.health = 100;
```

when `health` is private.

The compiler will reject it.

---

## Mistake 3

Thinking public functions cannot access private variables.

Wrong.

Member functions always have access to their own class's private members.

---

## Mistake 4

Making every variable public.

This completely defeats encapsulation and should generally be avoided.

---

# Best Practices

✔ Keep data private.

✔ Expose behavior through public functions.

✔ Let objects protect their own state.

✔ Avoid exposing internal implementation details.

✔ Think of an object as a "black box."

```
Outside World

↓

Public Interface

↓

Private Data
```

---

# Summary

- `private` members cannot be accessed outside the class.
- `public` members are accessible everywhere.
- Member functions may freely access private variables.
- Encapsulation protects objects from invalid modifications.
- Data hiding is one of the core principles of Object-Oriented Programming.
- Nearly every modern C++ library relies heavily on public and private access specifiers.

> **Key Takeaway:**  
> Good C++ design hides an object's data (`private`) and exposes only the operations that users need (`public`). This makes programs safer, easier to maintain, and much closer to real-world modeling.