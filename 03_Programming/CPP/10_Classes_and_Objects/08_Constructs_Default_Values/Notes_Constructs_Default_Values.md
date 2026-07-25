# Constructors with Default Values (Part 1)

---

# Introduction

So far, we have learned several ways to create constructors.

For example

```cpp
Player();

Player(std::string);

Player(std::string, int);

Player(std::string, int, int);
```

Each constructor handles a different combination of arguments.

Although this works well, writing many constructors often leads to duplicated code.

Modern C++ provides another solution:

**Default Arguments**

Default arguments allow a single constructor to replace several overloaded constructors.

---

# What are Default Arguments?

A default argument is a value automatically used when no value is provided by the programmer.

General syntax

```cpp
Player(std::string name = "None",
       int health = 0,
       int xp = 0);
```

If an argument is omitted,

its default value is used automatically.

---

# Why Use Default Arguments?

Without default arguments

```cpp
Player();

Player(std::string);

Player(std::string,int);

Player(std::string,int,int);
```

With default arguments

```cpp
Player(std::string name = "None",
       int health = 0,
       int xp = 0);
```

One constructor now handles every case.

This reduces code duplication and simplifies the class interface.

---

# Example

Constructor declaration

```cpp
Player(std::string name = "None",
       int health = 0,
       int xp = 0);
```

Constructor implementation

```cpp
Player::Player(std::string name,
               int health,
               int xp)

: name{name},
  health{health},
  xp{xp}
{

}
```

Notice that default values appear **only in the declaration**, not in the implementation.

---

# Different Ways to Create Objects

Because of default arguments, all of the following are valid.

Default object

```cpp
Player empty;
```

Equivalent to

```cpp
Player empty{"None",0,0};
```

---

Only name

```cpp
Player emir{"Emir"};
```

Equivalent to

```cpp
Player emir{"Emir",0,0};
```

---

Name and health

```cpp
Player hero{"Hero",100};
```

Equivalent to

```cpp
Player hero{"Hero",100,0};
```

---

Full constructor

```cpp
Player villain{"Villain",200,15};
```

Equivalent to

```cpp
Player villain{"Villain",200,15};
```

No values needed to be supplied automatically.

---

# How the Compiler Uses Default Arguments

Suppose we write

```cpp
Player hero{"Hero"};
```

The compiler transforms it into

```cpp
Player hero{"Hero",0,0};
```

Likewise,

```cpp
Player empty;
```

becomes

```cpp
Player empty{"None",0,0};
```

The compiler inserts the missing arguments automatically.

---

# Rules for Default Arguments

Default arguments always start from the **rightmost parameter**.

Correct

```cpp
Player(std::string name = "None",
       int health = 0,
       int xp = 0);
```

Also valid

```cpp
Player(std::string name,
       int health = 0,
       int xp = 0);
```

Invalid

```cpp
Player(std::string name = "None",
       int health,
       int xp = 0);
```

Once a parameter receives a default value,

every parameter to its right must also have a default value.

---

# Constructor Initialization Lists Still Apply

Default arguments only determine **which values are passed**.

Initialization Lists still determine **how members are initialized**.

Example

```cpp
Player::Player(std::string name,
               int health,
               int xp)

: name{name},
  health{health},
  xp{xp}
{

}
```

These are two different concepts that work together.

---

# Common Beginner Mistakes

## Mistake 1

Writing default arguments in both the declaration and the implementation.

Only the declaration should contain default values.

---

## Mistake 2

Believing default arguments replace Initialization Lists.

They do not.

Default arguments supply values.

Initialization Lists initialize members.

---

## Mistake 3

Thinking omitted arguments become random values.

They always receive the specified default values.

---

# Best Practices

✔ Place default values only in the function declaration.

✔ Use meaningful default values.

✔ Combine default arguments with Constructor Initialization Lists.

✔ Use default arguments to reduce unnecessary constructor overloads.

---

# Summary (Part 1)

- Default arguments allow omitted parameters to receive predefined values automatically.
- One constructor can replace several overloaded constructors.
- Missing arguments are supplied by the compiler.
- Default values are written only in the constructor declaration.
- Constructor Initialization Lists are still used to initialize class members.
- Default arguments simplify class design while reducing duplicated code.

> **Key Takeaway:**  
> Default constructor arguments make object creation more flexible by allowing a single constructor to support multiple argument combinations. They reduce unnecessary constructor overloads while keeping the class interface simple and easy to use.

# Constructors with Default Values (Part 2)

---

# Default Arguments vs Constructor Overloading

Default arguments and constructor overloading often solve the same problem.

Example using overloads

```cpp
Player();

Player(std::string);

Player(std::string,int);

Player(std::string,int,int);
```

The same behavior can often be achieved with

```cpp
Player(std::string name = "None",
       int health = 0,
       int xp = 0);
```

Instead of maintaining four constructors,

only one constructor is required.

---

# Advantages

## Less Code

One constructor replaces multiple overloads.

This reduces the amount of code that must be maintained.

---

## Easier Maintenance

Suppose we add a new member.

```cpp
int level;
```

Without default arguments,

every overloaded constructor must be modified.

With default arguments,

only one constructor needs to be updated.

---

## Cleaner Interface

Users of the class immediately know that only one constructor exists.

Different argument combinations are handled automatically.

---

## Better Readability

Creating objects becomes simple.

```cpp
Player hero;

Player villain{"Villain"};

Player boss{"Boss",200};

Player king{"King",300,50};
```

Every line calls the same constructor.

Only the supplied arguments change.

---

# Limitations

Default arguments are useful,

but they cannot replace every overloaded constructor.

Sometimes constructors perform completely different work.

Example

```cpp
Player(std::ifstream &file);

Player(NetworkConnection &server);
```

These constructors initialize the object in different ways.

Using default arguments here would make little sense.

Different constructors should remain separate.

---

# Ambiguity

Improper use of default arguments may confuse overload resolution.

Example

```cpp
Player();

Player(std::string name = "None");
```

Calling

```cpp
Player hero;
```

creates ambiguity.

The compiler cannot determine which constructor should be called.

For this reason,

careful API design is important.

---

# Default Arguments and Delegating Constructors

Sometimes both techniques are possible.

Example using delegation

```cpp
Player();

Player(std::string);

Player(std::string,int,int);
```

Example using default arguments

```cpp
Player(std::string name = "None",
       int health = 0,
       int xp = 0);
```

Both approaches reduce duplicated code.

Which one is better depends on the complexity of the class.

---

# When Should You Use Default Arguments?

Default arguments are ideal when

✔ every constructor performs the same initialization

✔ only a few values change

✔ constructors differ only by optional parameters

---

Avoid default arguments when

✘ constructors perform different tasks

✘ initialization logic changes significantly

✘ overloads represent different meanings

---

# Professional Usage

Many C++ libraries use default arguments.

Examples include

- C++ Standard Library
- Qt
- SFML
- SDL
- OpenGL helper libraries

However,

large frameworks such as ROOT or Geant4 often combine

- constructor overloading,
- delegating constructors,
- initialization lists,

depending on what produces the clearest interface.

---

# Common Beginner Mistakes

## Mistake 1

Placing default values in both the declaration and the implementation.

Default values belong only in the declaration.

---

## Mistake 2

Giving default values to parameters in the middle.

Incorrect

```cpp
Player(std::string name = "None",
       int health,
       int xp = 0);
```

Default parameters must appear from right to left.

---

## Mistake 3

Using default arguments when constructors perform different jobs.

In these situations,

separate constructors are clearer.

---

## Mistake 4

Thinking default arguments always replace constructor overloading.

Sometimes overloaded constructors provide a much cleaner design.

---

# Best Practices

✔ Use default arguments when constructors differ only by optional values.

✔ Keep default values meaningful.

✔ Combine default arguments with Constructor Initialization Lists.

✔ Avoid creating ambiguous constructor overloads.

✔ Prefer readability over reducing the number of constructors.

---

# Looking Ahead

The next major topic is object copying.

Soon you will study

- Copy Constructors
- Shallow Copy
- Deep Copy
- Copy Assignment

These topics build directly on constructor behavior.

Understanding default constructors, initialization lists, delegating constructors, and default arguments provides the foundation for learning how C++ creates and copies objects safely.

---

# Summary

- Default arguments allow one constructor to support multiple argument combinations.
- They reduce unnecessary constructor overloads.
- Missing arguments are supplied automatically by the compiler.
- Default arguments work best when constructors differ only by optional values.
- Constructors with different responsibilities should usually remain separate.
- Modern C++ uses default arguments to simplify APIs while preserving readability.
- Constructor design is about clarity as much as flexibility.

> **Key Takeaway:**  
> Default constructor arguments are a powerful feature for simplifying class interfaces. They are most effective when constructors share the same initialization logic but differ only in optional values. Used carefully, they reduce boilerplate code while making classes easier to use and maintain.