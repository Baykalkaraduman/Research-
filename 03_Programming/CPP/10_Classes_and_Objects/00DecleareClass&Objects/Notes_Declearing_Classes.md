# Declaring Classes and Creating Objects

---

# Introduction

Object-Oriented Programming (OOP) is one of the most important programming paradigms in C++. Almost every major C++ project, including ROOT, Geant4, CLHEP, Eigen, Qt, Unreal Engine and many scientific libraries, is built around classes and objects.

Instead of writing programs only with variables and functions, OOP allows us to model real-world entities as objects.

Examples:

- A particle
- A detector
- A bank account
- A player in a game
- A physics event
- A histogram

Each object contains both **data** and **behavior**.

---

# What is a Class?

A **class** is a blueprint (template) used to create objects.

Think of a class as an architectural blueprint.

The blueprint itself is **not** a building.

Instead, many buildings can be created from the same blueprint.

Likewise,

```
Class
        ↓
Blueprint
        ↓
Creates Objects
```

Example

```cpp
class Player
{
    string name;
    int health;
    int xp;
};
```

Here,

`Player`

is **not** an object.

It is only the description of future objects.

---

# What is an Object?

An object is an **instance** of a class.

Example

```cpp
Player frank;
Player emir;
```

Now

```
Player
        ↓

frank

emir
```

Two completely independent objects are created.

Each object owns its own copy of the attributes.

For example

```
frank

Health = 100
XP = 3
```

and

```
emir

Health = 100
XP = 3
```

Although both come from the same class, they are independent.

Changing one object does not automatically change the other.

---

# Anatomy of a Class

A class usually consists of two main parts.

## 1. Attributes (Data Members)

Attributes store information about the object.

Example

```cpp
string name;

int health;

int xp;
```

They describe the object's state.

For example

```
Player

↓

Name

Health

XP
```

---

## 2. Methods (Member Functions)

Methods describe what an object can do.

Example

```cpp
void talk();

bool is_dead();
```

Methods define the behavior of an object.

Examples

```
Player

↓

Move

Attack

Jump

Talk

Take Damage
```

---

# Declaring Member Functions

Inside the class we usually write only the function declaration.

Example

```cpp
void talk(string text);

bool is_dead();
```

These are called **member function declarations**.

The actual implementation is usually written later.

This improves readability and organization.

---

# Creating Objects

Creating an object is very similar to declaring a variable.

Example

```cpp
Player frank;
```

This creates one Player object.

Another object

```cpp
Player emir;
```

creates another completely independent object.

Memory

```
Player

↓

frank

↓

name

health

xp

----------------

Player

↓

emir

↓

name

health

xp
```

---

# Arrays of Objects

Objects can be stored inside arrays.

Example

```cpp
Player players[]
{
    frank,
    emir
};
```

Memory

```
players

↓

Player

Player
```

Each array element is an entire Player object.

---

# Vectors of Objects

Modern C++ usually prefers vectors over arrays.

Example

```cpp
vector<Player> player_vector;

player_vector.push_back(frank);

player_vector.push_back(emir);
```

Advantages

- Dynamic size
- Easy insertion
- Automatic memory management
- STL compatibility

In modern C++, vectors are generally preferred over raw arrays.

---

# Dynamically Allocating Objects

Objects can also be created on the Heap.

Example

```cpp
Player *enemy {nullptr};

enemy = new Player;
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

The pointer stores the address of the dynamically created object.

---

# Releasing Heap Memory

Every object created with

```cpp
new
```

must eventually be released.

Example

```cpp
delete enemy;

enemy = nullptr;
```

Always remember

```
new

↓

delete
```

Otherwise,

a memory leak occurs.

---

# Why Use Dynamic Objects?

Dynamic allocation becomes useful when

- the number of objects is unknown,
- objects must live longer than a function,
- objects are created during runtime,
- polymorphism is used.

Later, Smart Pointers will replace most manual memory management.

---

# Class vs Object

| Class | Object |
|--------|---------|
| Blueprint | Instance |
| Defines structure | Holds actual data |
| No memory for instances | Occupies memory |
| Used to create objects | Created from a class |

Example

```
Player

↓

frank

↓

Actual Object
```

---

# Important Vocabulary

| Term | Meaning |
|------|----------|
| Class | Blueprint |
| Object | Instance of a class |
| Attribute | Data member |
| Method | Member function |
| Instance | Another name for an object |
| Member | Anything inside a class |

---

# Common Beginner Mistakes

## Mistake 1

Thinking a class is an object.

Wrong.

A class is only a blueprint.

---

## Mistake 2

Thinking all objects share the same variables.

Wrong.

Every object owns its own copy of the attributes.

---

## Mistake 3

Forgetting to delete dynamically allocated objects.

Wrong

```cpp
Player *enemy = new Player;
```

without

```cpp
delete enemy;
```

causes a memory leak.

---

## Mistake 4

Believing methods automatically execute.

Wrong.

Methods must be called explicitly.

---

# Best Practices

✔ Give classes meaningful names.

```cpp
Player

Account

Particle

Detector
```

---

✔ Group attributes together.

---

✔ Group member function declarations together.

---

✔ Prefer `std::vector` over raw arrays.

---

✔ Always initialize pointers.

```cpp
Player *enemy {nullptr};
```

---

✔ Always match

```cpp
new

↓

delete
```

---

# Real Physics Applications

Classes are everywhere in scientific software.

ROOT

```cpp
TH1F

TTree

TFile

TLorentzVector
```

Geant4

```cpp
G4Track

G4ParticleDefinition

G4Event

G4RunManager
```

CMSSW

```cpp
Event

Muon

Electron

Track
```

Every one of these is a C++ class.

Understanding classes is therefore essential for scientific computing and High Energy Physics.

---

# Summary

- A class is a blueprint used to create objects.
- An object is an instance of a class.
- Attributes store data.
- Methods define behavior.
- Objects can be stored in arrays and vectors.
- Objects may be created on either the Stack or the Heap.
- Objects created with `new` must always be destroyed with `delete`.
- Classes form the foundation of Object-Oriented Programming and modern scientific C++ software.

> **Key Takeaway:**  
> A class describes **what an object is**, while an object is the **actual entity created from that description**. Almost every major C++ library used in High Energy Physics is built upon this concept.