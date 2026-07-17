# Enumerations (enum)

---

# Introduction

An **enumeration** (`enum`) is a user-defined type that represents a fixed collection of named integer constants.

Instead of writing

```cpp
int direction = 0;
```

we can write

```cpp
enum Direction
{
    left,
    right,
    front,
    back
};
```

This makes code much easier to understand.

---

# Why use Enumerations?

Suppose you write

```cpp
int direction = 2;
```

What does `2` mean?

Nobody knows without looking elsewhere.

Now compare it with

```cpp
Direction direction = front;
```

The meaning is immediately obvious.

Enums improve

- readability
- maintainability
- self-documentation

---

# Declaring an Enumeration

```cpp
enum Direction
{
    left,
    right,
    front,
    back
};
```

Each name is called an **enumerator**.

---

# Creating Enum Variables

```cpp
Direction heading {left};
```

Only values from the enumeration should be assigned.

---

# Default Integer Values

Every enumerator has an integer value.

By default

```cpp
left   = 0
right  = 1
front  = 2
back   = 3
```

Example

```cpp
cout << left;
```

Output

```
0
```

---

# Custom Values

You can assign your own integer values.

```cpp
enum Status
{
    success = 200,
    warning = 300,
    error = 500
};
```

Output

```
error = 500
```

---

# Using Enums with switch

The most common use of enums is together with `switch`.

```cpp
switch(direction)
{
case left:
    ...
    break;

case right:
    ...
    break;
}
```

This is much more readable than using raw integers.

---

# Comparing Enumerations

Enums can be compared.

```cpp
if(direction == left)
```

Result

```
true
```

---

# enum vs enum class

Modern C++ introduced

```cpp
enum class
```

Example

```cpp
enum class Color
{
    Red,
    Green,
    Blue
};
```

Usage

```cpp
Color paint {Color::Green};
```

Notice

```cpp
Color::Green
```

instead of

```cpp
Green
```

Advantages

- Strong type safety
- No name collisions
- Recommended in Modern C++

---

# Memory

Enums are stored internally as integers.

Typically

```
4 bytes
```

although the compiler may optimize this.

---

# Scientific Computing

Enums appear frequently in scientific software.

Examples

- Detector status
- Particle type
- Trigger state
- Event category
- Error codes
- Simulation modes
- Data quality flags

ROOT and Geant4 use enumerations extensively to represent predefined options and states.

---

# Best Practices

✔ Prefer descriptive enum names.

✔ Use enums instead of unexplained integer constants.

✔ Prefer `enum class` in modern C++.

✔ Combine enums with `switch` statements.

✔ Use enums whenever only a fixed set of values is allowed.

---

# Common Mistakes

## Using Magic Numbers

Instead of

```cpp
int state = 3;
```

prefer

```cpp
State current = Finished;
```

---

## Forgetting break

```cpp
case left:
```

must usually end with

```cpp
break;
```

Otherwise execution continues into the next case.

---

## Mixing Different Enums

Avoid assigning unrelated enumerations to one another.

`enum class` prevents many of these mistakes automatically.

---

# Summary

After completing this chapter you should understand

- What an enumeration is
- Why enums improve readability
- Default integer values
- Custom enumerator values
- How enums work with switch
- The difference between `enum` and `enum class`
- Why modern C++ prefers `enum class`

---

# Exercises

## Exercise 1

Create an enumeration called

```cpp
Season
```

containing

- Spring
- Summer
- Autumn
- Winter

Print the selected season.

---

## Exercise 2

Create an enumeration called

```cpp
Difficulty
```

with

- Easy
- Medium
- Hard

Use a switch statement to display a message for each difficulty.

---

## Exercise 3

Assign custom integer values to

```cpp
HttpStatus
```

such as

- OK = 200
- NotFound = 404
- ServerError = 500

Print each value.

---

## Exercise 4

Rewrite a program that currently uses integer constants so that it uses an enumeration instead.

---

## Exercise 5 (Challenge)

Create an `enum class`

```cpp
ParticleType
```

containing

- Electron
- Proton
- Neutron
- Photon

Use a switch statement to print a short description of each particle.