# Const in Classes (Part 1)

---

# Introduction

As programs become larger,

protecting objects from unintended modifications becomes increasingly important.

C++ provides the keyword

```cpp
const
```

to indicate that something should **not be modified**.

In classes,

`const` appears in three common places:

- const objects
- const member functions
- const references

Together, these form the idea of

**Const Correctness.**

Writing const-correct code makes programs

- safer,
- easier to understand,
- easier to optimize,
- and less prone to bugs.

---

# What is Const Correctness?

Const Correctness means

> "Declare objects and functions as `const` whenever they are not supposed to modify data."

Instead of allowing everything to be modified,

we explicitly tell the compiler

which objects and functions are read-only.

The compiler then helps us detect mistakes.

---

# Const Objects

Example

```cpp
const Player villain{"Villain", 100, 55};
```

Here,

`villain` is a constant object.

After it has been created,

its state cannot be modified.

For example,

```cpp
villain.set_name("Super Villain");
```

produces a compiler error.

The compiler prevents accidental modification.

---

# What Can a Const Object Do?

A const object may call only

**const member functions.**

Example

```cpp
villain.get_name();
```

works because

```cpp
get_name()
```

does not modify the object.

However,

```cpp
villain.set_name(...)
```

is forbidden because setters change the object's state.

---

# Const Member Functions

Example

```cpp
std::string get_name() const
{
    return name;
}
```

Notice the keyword

```cpp
const
```

after the function declaration.

This does **not** make the return value constant.

Instead,

it promises that

> this member function will not modify the object.

---

# What Does the Compiler Check?

Inside

```cpp
std::string get_name() const
```

the compiler treats the object as read-only.

The following is allowed

```cpp
return name;
```

Reading data is perfectly safe.

However,

this would generate a compiler error

```cpp
name = "New Name";
```

because a const member function cannot modify member variables.

---

# Why Should Getters Be Const?

Getters only read data.

They do not change the object.

Therefore,

they should almost always be declared

```cpp
const
```

Example

```cpp
int get_health() const;

double get_balance() const;

std::string get_name() const;
```

This allows them to be called on

- const objects
- non-const objects

without any restrictions.

---

# Why Can't Setters Be Const?

A setter changes the object.

Example

```cpp
void set_name(const std::string &name_val)
{
    name = name_val;
}
```

This modifies

```cpp
name
```

Therefore,

making this function const

```cpp
void set_name(...) const
```

would produce a compiler error.

The compiler knows the function changes the object.

---

# Visual Representation

```
Player

↓

name

health

xp
```

Getter

```
Read

↓

Allowed
```

Setter

```
Modify

↓

Not Allowed for const objects
```

---

# Common Beginner Mistakes

## Mistake 1

Thinking

```cpp
std::string get_name() const
```

returns a constant string.

It does not.

The `const` applies to the object,

not the return value.

---

## Mistake 2

Forgetting to mark getters as const.

This prevents const objects from calling them.

---

## Mistake 3

Trying to modify member variables inside a const member function.

The compiler correctly rejects this.

---

# Best Practices

✔ Declare every getter as `const`.

✔ Declare member functions `const` whenever they do not modify the object.

✔ Let the compiler enforce const correctness instead of relying on memory.

---

# Summary (Part 1)

- `const` objects cannot be modified after construction.
- A const object may call only const member functions.
- A const member function promises not to modify the object's state.
- Getters should almost always be declared `const`.
- Setters cannot be const because they modify member variables.

> **Key Takeaway:**  
> `const` member functions are a promise to both the compiler and other programmers that calling the function will **not change the object's state**. This idea is one of the foundations of writing safe, predictable, and maintainable Modern C++ code.

# Const in Classes (Part 2)

---

# Passing Objects by Const Reference

Consider the following function

```cpp
void display_player_name(const Player &player)
{
    std::cout << player.get_name() << std::endl;
}
```

This function demonstrates one of the most common techniques in Modern C++.

The object is passed

- by reference,
- and as read-only.

This provides both

- efficiency,
- and safety.

---

# Why Not Pass by Value?

Suppose we write

```cpp
void display_player_name(Player player)
```

Execution

```
Original Object

↓

Copy Constructor

↓

Function Parameter
```

Every function call creates a copy.

For small objects,

this may not matter.

For large objects,

copying can become expensive.

---

# Passing by Reference

Instead,

we write

```cpp
Player &
```

Execution

```
Original Object

↓

Reference

↓

Function
```

No copy is created.

The function directly accesses the original object.

This is much faster.

---

# Why Add const?

A normal reference

```cpp
Player &
```

allows the function to modify the object.

Example

```cpp
player.set_name("Enemy");
```

would be legal.

Sometimes this is exactly what we want.

However,

many functions only need to read information.

Adding

```cpp
const
```

prevents accidental modifications.

---

# Const Reference

```cpp
const Player &
```

means

> "I want to use this object without copying it, and I promise not to modify it."

This is one of the most frequently used parameter types in Modern C++.

---

# Visual Representation

Passing by Value

```
Original

↓

Copy

↓

Function
```

Passing by Reference

```
Original

↓

Function
```

Passing by Const Reference

```
Original

↓

Read Only

↓

Function
```

No copy

No modification

Maximum efficiency

---

# Why Does get_name() Need const?

Inside

```cpp
display_player_name()
```

we write

```cpp
player.get_name();
```

Remember

```cpp
player
```

is

```cpp
const Player&
```

The compiler treats it as a const object.

Therefore,

only const member functions may be called.

This is why

```cpp
std::string get_name() const
```

is necessary.

Without the final

```cpp
const
```

the following line

```cpp
player.get_name();
```

would fail to compile.

---

# Const Correctness

Professional C++ developers follow an important rule

> Everything that can be const should be const.

This is known as

**Const Correctness.**

Benefits

- prevents accidental modifications,
- documents programmer intent,
- improves code readability,
- helps the compiler detect bugs,
- may enable compiler optimizations.

---

# Typical Function Parameters

### Small Types

```cpp
void print(int number);
```

Passing by value is fine.

---

### Large Objects

```cpp
void print(const std::string &text);
```

Avoid unnecessary copies.

---

### Custom Classes

```cpp
void print(const Player &player);
```

The same idea applies.

---

# When Should You Use const?

Use `const`

✔ when a function only reads data.

✔ for getter functions.

✔ for references that should not modify the object.

✔ for variables whose values never change.

Avoid `const`

✘ for setters.

✘ for functions that intentionally modify the object.

---

# Common Beginner Mistakes

## Mistake 1

Passing large objects by value.

This creates unnecessary copies.

Prefer

```cpp
const ClassName&
```

---

## Mistake 2

Forgetting the final

```cpp
const
```

on getter functions.

Const objects will no longer be able to call them.

---

## Mistake 3

Using non-const references for functions that only read data.

This makes the function unnecessarily dangerous.

---

# Best Practices

✔ Pass large objects by `const` reference.

✔ Declare getters as `const`.

✔ Use `const` whenever modification is unnecessary.

✔ Let the compiler protect your objects.

✔ Think of `const` as documentation as well as a safety feature.

---

# Modern C++ Guideline

A useful rule followed by many C++ developers is

> **"Prefer const by default."**

Only remove `const`

when the program genuinely needs to modify data.

This philosophy leads to safer,

clearer,

and easier-to-maintain code.

---

# Final Summary

- Passing objects by `const` reference avoids unnecessary copies.
- `const` references guarantee that the object will not be modified.
- Const member functions can be called on both const and non-const objects.
- Getter functions should almost always be declared `const`.
- Const Correctness is one of the core principles of Modern C++ programming.

---

# Key Takeaways

- **`const` objects cannot be modified.**
- **Const member functions promise not to change the object's state.**
- **Passing by `const ClassName&` avoids copying while protecting the object.**
- **Const Correctness makes programs safer, more readable, and more efficient.**
- **Using `const` consistently is considered a best practice in professional Modern C++ development.**

> **Final Thought:**  
> Const Correctness is not just a language feature—it is a programming discipline. By declaring objects, parameters, and member functions as `const` whenever possible, you communicate your intentions clearly, prevent accidental modifications, and allow the compiler to enforce correctness. This habit is a hallmark of well-written Modern C++ code.