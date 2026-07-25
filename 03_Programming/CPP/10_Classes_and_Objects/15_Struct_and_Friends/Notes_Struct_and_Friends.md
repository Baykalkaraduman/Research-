# Struct and Friends

---

# Introduction

This note introduces two small but useful C++ language features:

- struct
- friend

Although they are not used as frequently as constructors, inheritance, or polymorphism, they appear in many libraries and legacy codebases.

---

# Struct

A `struct` is almost identical to a `class`.

The primary difference is the default access level.

```cpp
struct Example
{
    int value;
};
```

Everything is **public** by default.

---

For classes

```cpp
class Example
{
    int value;
};
```

Everything is **private** by default.

---

# Struct vs Class

| struct | class |
|---------|--------|
| Default access is public | Default access is private |
| Often used for simple data | Often used for encapsulated objects |

---

Example

```cpp
struct Point
{
    double x;
    double y;
};
```

Usage

```cpp
Point p;

p.x = 10;
p.y = 20;
```

No setters or getters are required because everything is public.

---

# When Should You Use struct?

Use a struct when the object is simply storing data.

Examples

- Point
- Color
- Vector3
- Particle information
- Configuration data

---

Use a class when

- data should be hidden,
- validation is needed,
- encapsulation is important.

---

# Friend

Normally,

private members cannot be accessed outside the class.

Example

```cpp
class Player
{
private:

    std::string name;
};
```

The following is illegal

```cpp
player.name
```

because `name` is private.

---

# Friend Function

Sometimes,

a non-member function needs access to private data.

Example

```cpp
friend void display_player(const Player&);
```

Now

```cpp
display_player(player);
```

can access

```cpp
player.name
```

even though it is private.

---

# Friend Class

An entire class may also become a friend.

Example

```cpp
friend class PlayerPrinter;
```

Now every member function inside

```cpp
PlayerPrinter
```

may access Player's private members.

---

# Why Use Friend?

Friendship is useful when two classes cooperate closely.

Examples

- Matrix libraries
- Operator overloading
- Serialization
- Debugging utilities
- Printing objects

---

# Important Rule

Friendship is

- **not inherited**
- **not symmetric**
- **not transitive**

If

```
A is friend of B
```

it does **not** mean

```
B is friend of A.
```

---

# Advantages

✔ Allows controlled access to private data.

✔ Simplifies operator overloading.

✔ Useful for helper classes.

---

# Disadvantages

✘ Breaks encapsulation.

✘ Can make code harder to maintain if overused.

---

# Best Practices

✔ Use `struct` for plain data objects.

✔ Use `class` for encapsulated objects.

✔ Use `friend` only when necessary.

✔ Avoid making many classes friends of each other.

---

# Summary

- `struct` and `class` are almost identical.
- The default access level is the main difference.
- Friend functions may access private members.
- Friend classes may access all private members.
- Friendship should be used sparingly to preserve encapsulation.

---

# Key Takeaways

- **struct = public by default**
- **class = private by default**
- **friend grants special access to private members**
- **Friendship should be used only when there is a clear design reason**