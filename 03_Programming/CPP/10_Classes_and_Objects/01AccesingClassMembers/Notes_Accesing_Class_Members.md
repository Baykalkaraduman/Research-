# Accessing Class Objects

---

# Introduction

After learning how to declare a class and create objects, the next step is learning **how to access the members of a class**.

A class usually contains two kinds of members:

- Attributes (Data Members)
- Methods (Member Functions)

To use these members, C++ provides two access operators:

- Dot Operator (`.`)
- Arrow Operator (`->`)

Understanding these operators is essential because they are used constantly in Object-Oriented Programming and scientific C++ libraries such as ROOT and Geant4.

---

# The public Access Specifier

Inside a class, members are private by default.

Example

```cpp
class Player
{
    string name;
};
```

The variable `name` is private.

It cannot be accessed outside the class.

To allow outside access, we use the **public** access specifier.

```cpp
class Player
{
public:

    string name;
    int health;
    int xp;

    void talk(string text);
};
```

Everything written below

```cpp
public:
```

can be accessed from outside the class.

---

# Accessing Object Members

Suppose we create an object.

```cpp
Player emir;
```

We access its members using the **dot operator**.

```cpp
emir.name = "Emir";

emir.health = 100;

emir.xp = 41;
```

The general formula is

```
Object.Member
```

Example

```
Player Object

↓

emir

↓

.

↓

health
```

---

# Calling Member Functions

Member functions are called exactly the same way.

Example

```cpp
emir.talk("Hi there!");
```

General formula

```
Object.Function(arguments)
```

Example

```
emir

↓

talk()

↓

Function Executes
```

---

# Accessing Objects Through Pointers

Objects can also be created dynamically.

```cpp
Player *enemy {new Player};
```

Memory

```
Stack

↓

enemy

↓

Heap

↓

Player Object
```

Since `enemy` is a pointer, we cannot use the dot operator directly.

Instead, we have two options.

---

# Traditional Notation

```cpp
(*enemy).health = 100;
```

Explanation

```
enemy

↓

Pointer

↓

*

↓

Actual Object

↓

.

↓

health
```

Step-by-step

1. Dereference the pointer.

2. Obtain the object.

3. Access the member.

Because the dereference operator has lower precedence than the dot operator, parentheses are required.

Correct

```cpp
(*enemy).health
```

Incorrect

```cpp
*enemy.health
```

The compiler interprets the incorrect version as

```
*(enemy.health)
```

which is invalid because `enemy` is a pointer.

---

# Arrow Operator (->)

The preferred way is the arrow operator.

```cpp
enemy->health = 100;
```

This is simply a shortcut for

```cpp
(*enemy).health = 100;
```

The two expressions are completely equivalent.

```
enemy->health

↓

(*enemy).health
```

The arrow operator automatically dereferences the pointer before accessing the member.

---

# Dot Operator vs Arrow Operator

| Dot (`.`) | Arrow (`->`) |
|------------|--------------|
| Used with objects | Used with pointers |
| Accesses members directly | Dereferences pointer automatically |
| Most common | Used for dynamically allocated objects |

Example

```cpp
Player emir;

emir.health = 100;
```

Example

```cpp
Player *enemy = new Player;

enemy->health = 100;
```

---

# Working with Multiple Classes

Each class has its own members.

Example

```cpp
Account emir_account;

emir_account.balance = 5200;

emir_account.deposit(850);
```

Objects always use the members defined inside their own class.

```
Account

↓

balance

deposit()

withdraw()
```

---

# Dynamic Memory Reminder

Objects created with

```cpp
new
```

must always be released.

```cpp
delete enemy;

enemy = nullptr;
```

Memory management rule

```
new

↓

delete
```

Never forget this rule.

Later, Smart Pointers will automate this process.

---

# Real Physics Examples

ROOT

```cpp
TH1F histogram;

histogram.Fill(4.5);
```

The dot operator is used because `histogram` is an object.

---

Geant4

```cpp
runManager->Initialize();
```

The arrow operator is used because `runManager` is a pointer.

---

CMSSW

```cpp
event->getByToken(...);
```

Again,

`event`

is a pointer.

Therefore,

```
->

```

is used instead of

```
.
```

---

# Common Beginner Mistakes

## Mistake 1

Using

```cpp
enemy.health
```

Wrong.

`enemy` is a pointer.

Correct

```cpp
enemy->health
```

---

## Mistake 2

Forgetting parentheses.

Wrong

```cpp
*enemy.health
```

Correct

```cpp
(*enemy).health
```

---

## Mistake 3

Using

```cpp
new
```

without

```cpp
delete
```

This causes a memory leak.

---

## Mistake 4

Thinking

```cpp
->

```

is a different operator.

Actually

```
->

↓

(*pointer).
```

They are equivalent.

---

# Best Practices

✔ Use the dot operator for normal objects.

```cpp
object.member
```

---

✔ Use the arrow operator for pointers.

```cpp
pointer->member
```

---

✔ Prefer

```cpp
pointer->member
```

instead of

```cpp
(*pointer).member
```

because it is easier to read.

---

✔ Always delete dynamically allocated objects.

---

✔ Set pointers to

```cpp
nullptr
```

after deletion.

---

# Summary

- Class members become accessible outside the class through the `public` access specifier.
- The **dot operator (`.`)** is used to access members of normal objects.
- The **arrow operator (`->`)** is used to access members through pointers.
- `pointer->member` is exactly the same as `(*pointer).member`.
- Objects created with `new` live on the Heap and must be destroyed using `delete`.
- The dot and arrow operators are fundamental tools used throughout modern C++, ROOT, Geant4, and almost every Object-Oriented software project.

> **Key Takeaway:**  
> Use **`.`** when working with an object, use **`->`** when working with a pointer to an object. Understanding the difference between these two operators is one of the first major milestones in mastering Object-Oriented Programming in C++.