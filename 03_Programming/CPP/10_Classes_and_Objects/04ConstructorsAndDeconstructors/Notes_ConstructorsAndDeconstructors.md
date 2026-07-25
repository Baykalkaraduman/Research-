# Constructors and Destructors (Part 1)

---

# Introduction

Every object in C++ has a **lifecycle**.

An object

- is created,
- initialized,
- used,
- and finally destroyed.

C++ provides two special member functions to manage this lifecycle.

```
Constructor

↓

Object Creation
```

```
Destructor

↓

Object Destruction
```

These functions are automatically called by the compiler.

The programmer never calls them directly.

Constructors and destructors are among the most important concepts in Object-Oriented Programming because they ensure that every object begins and ends its life in a valid state.

---

# Object Lifecycle

Every object follows the same lifecycle.

```
Memory Allocated

↓

Constructor Called

↓

Object Exists

↓

Member Functions Execute

↓

Destructor Called

↓

Memory Released
```

This process happens automatically for every object.

---

# What is a Constructor?

A **constructor** is a special member function that is automatically executed whenever an object is created.

Its primary responsibility is to initialize the object's data members.

Without constructors, every object would contain undefined values until the programmer manually assigned them.

Example

```cpp
Player emir;
```

Immediately after this statement,

the compiler automatically calls

```cpp
Player();
```

before the object can be used.

---

# Constructor Characteristics

Constructors have several unique properties.

They

- have the same name as the class,
- have no return type,
- are automatically called,
- may receive parameters,
- can be overloaded.

Example

```cpp
class Player
{
public:

    Player();

    Player(std::string);

    Player(std::string, int, int);
};
```

---

# Why Constructors Exist

Imagine creating an object without initialization.

```cpp
Player emir;
```

Without a constructor,

```
name

health

xp
```

would contain undefined values.

Instead, a constructor gives every object meaningful initial values.

Example

```cpp
Player()
{
    name = "None";
    health = 100;
    xp = 0;
}
```

Now every newly created player starts in a valid state.

---

# Default Constructor

A **Default Constructor** is a constructor that requires no arguments.

Example

```cpp
Player()
{
    name = "None";
    health = 100;
    xp = 0;
}
```

Object creation

```cpp
Player hero;
```

Compiler action

```
Allocate Memory

↓

Call Default Constructor

↓

Object Ready
```

The programmer never explicitly calls the constructor.

---

# Parameterized Constructors

Sometimes different objects should start with different values.

Instead of assigning values afterward,

they can be provided during object creation.

Example

```cpp
Player("Emir");
```

calls

```cpp
Player(std::string name)
```

Example

```cpp
Player("Villain",100,15);
```

calls

```cpp
Player(std::string,int,int)
```

This process is called **Object Initialization**.

---

# Constructor Overloading

A class may contain multiple constructors.

This is called **Constructor Overloading**.

Example

```cpp
Player();

Player(std::string);

Player(std::string,int,int);
```

The compiler chooses the correct constructor based on the supplied arguments.

```
Player()

↓

Default Constructor
```

```
Player("Hero")

↓

One-Argument Constructor
```

```
Player("Boss",250,40)

↓

Three-Argument Constructor
```

---

# Automatic Constructor Selection

The compiler automatically selects the correct constructor.

Example

```cpp
Player hero;
```

↓

Default Constructor

---

```cpp
Player hero("Hero");
```

↓

One-Argument Constructor

---

```cpp
Player boss("Boss",300,50);
```

↓

Three-Argument Constructor

The programmer does not need to specify which constructor should be called.

---

# Constructors Initialize Objects

One common beginner mistake is believing constructors exist only to print messages.

Example

```cpp
Player()
{
    std::cout << "Constructor Called";
}
```

This demonstrates when the constructor executes,

but it does **not** initialize the object.

Instead,

constructors should prepare the object for immediate use.

Example

```cpp
Player()
{
    name = "Unknown";
    health = 100;
    xp = 0;
}
```

After construction,

the object is already valid.

---

# Object Initialization vs Assignment

These two operations are different.

Initialization

```cpp
Player hero("Hero");
```

The constructor sets the values immediately.

Assignment

```cpp
Player hero;

hero.set_name("Hero");
```

The object is created first,

then modified afterward.

Initialization is generally preferred because the object is valid from the moment it exists.

---

# Constructors and Encapsulation

Constructors help preserve encapsulation.

Instead of allowing users to modify internal data immediately,

the constructor guarantees that every object starts with meaningful values.

Example

```
Player

↓

Constructor

↓

Valid Object

↓

Program Uses Object
```

This reduces bugs and makes classes safer to use.

---

# Common Beginner Mistakes

## Mistake 1

Thinking constructors are ordinary member functions.

They are special functions automatically called during object creation.

---

## Mistake 2

Giving constructors a return type.

Wrong

```cpp
void Player();
```

Correct

```cpp
Player();
```

Constructors never have a return type.

---

## Mistake 3

Creating objects with uninitialized data.

Always initialize member variables inside constructors.

---

## Mistake 4

Using setter functions when constructor initialization would be more appropriate.

Prefer

```cpp
Player("Hero");
```

instead of

```cpp
Player hero;

hero.set_name("Hero");
```

---

# Best Practices

✔ Always initialize your objects.

✔ Use constructors to establish a valid initial state.

✔ Overload constructors when different initialization options are needed.

✔ Prefer object initialization over assignment after construction.

✔ Keep constructors focused on initialization.

---

# Summary (Part 1)

- Constructors are special member functions automatically called when objects are created.
- Every object follows a lifecycle beginning with constructor execution.
- Constructors initialize objects and ensure they begin in a valid state.
- Constructors have no return type and share the class name.
- Multiple constructors can exist through constructor overloading.
- The compiler automatically selects the appropriate constructor based on the arguments supplied.
- Initializing objects during construction is safer and more efficient than assigning values afterward.

> **Key Takeaway:**  
> A constructor is responsible for creating a valid object from the very beginning of its lifetime. Proper constructor design is one of the foundations of reliable Object-Oriented Programming in C++.

# Constructors and Destructors (Part 2)

---

# What is a Destructor?

Just as every object has a beginning, every object also has an end.

When an object's lifetime finishes, C++ automatically calls a special member function called the **Destructor**.

The destructor is responsible for cleaning up any resources owned by the object before its memory is released.

A destructor is automatically invoked by the compiler.

The programmer never calls it directly for stack objects.

---

# Destructor Characteristics

A destructor has several unique properties.

- It has the same name as the class.
- Its name begins with a tilde (`~`).
- It has no return type.
- It cannot receive parameters.
- Every class can have only one destructor.
- It is called automatically.

Example

```cpp
~Player()
{
    std::cout << "Destructor Called";
}
```

---

# Constructor vs Destructor

Every object's lifetime follows the same order.

```
Object Created

↓

Constructor Called

↓

Object Exists

↓

Program Uses Object

↓

Destructor Called

↓

Memory Released
```

Constructors prepare an object for use.

Destructors clean the object before it disappears.

---

# When Does a Destructor Execute?

For **stack objects**, the destructor executes automatically when the object leaves its scope.

Example

```cpp
{
    Player hero;
}
```

Execution

```
Enter Scope

↓

Constructor

↓

Object Exists

↓

Leave Scope

↓

Destructor
```

The programmer does not need to write anything.

---

# Stack Objects

Objects created normally

```cpp
Player hero;
```

are called **stack objects**.

Their lifetime is managed automatically.

Creation

```
Player hero;
```

↓

Constructor

↓

Object Exists

↓

Scope Ends

↓

Destructor

↓

Memory Released
```

Stack objects are the safest type of object in C++.

---

# Heap Objects

Objects created with

```cpp
new
```

are stored in the heap.

Example

```cpp
Player *enemy = new Player;
```

Execution

```
Allocate Heap Memory

↓

Constructor

↓

Object Exists
```

Unlike stack objects,

heap objects are **not destroyed automatically**.

The programmer must explicitly release them.

---

# delete

Heap memory is returned using

```cpp
delete enemy;
```

Execution

```
delete

↓

Destructor

↓

Heap Memory Released
```

Without `delete`, the destructor never executes.

---

# Memory Leak

One of the most common programming mistakes is forgetting to delete dynamically allocated objects.

Example

```cpp
Player *enemy = new Player;
```

Program Ends

↓

Pointer Lost

↓

Heap Memory Still Allocated

↓

Memory Leak

A memory leak means allocated memory is no longer accessible, wasting system resources.

---

# Constructor and Destructor Order

Suppose we write

```cpp
{
    Player hero;
}
```

Output

```
Constructor

Destructor
```

The constructor always executes first.

The destructor always executes last.

---

# Multiple Objects

Consider

```cpp
Player a;

Player b;

Player c;
```

Creation Order

```
a

↓

b

↓

c
```

Destruction Order

```
c

↓

b

↓

a
```

Objects are destroyed in the **reverse order** of their creation.

This behavior is known as **Last In, First Out (LIFO)**.

---

# Nested Scopes

Objects only exist inside their scope.

Example

```cpp
{
    Player hero;

    {
        Player enemy;
    }

}
```

Execution

```
hero Constructor

↓

enemy Constructor

↓

enemy Destructor

↓

hero Destructor
```

Inner scope objects always disappear before outer scope objects.

---

# Constructors for Heap Objects

Example

```cpp
Player *enemy = new Player("Enemy");
```

Execution

```
Allocate Heap Memory

↓

Call Constructor

↓

Object Exists
```

The constructor behaves exactly the same as for stack objects.

Only the lifetime management changes.

---

# Destructor for Heap Objects

Example

```cpp
delete enemy;
```

Execution

```
Destructor

↓

Memory Returned

↓

Pointer Invalid
```

After deletion,

the pointer should no longer be used.

Accessing deleted memory results in **Undefined Behavior**.

---

# Stack vs Heap Lifetime

Stack

```
Automatic

↓

Compiler Managed

↓

Destructor Automatic
```

Heap

```
Manual

↓

Programmer Managed

↓

Must Call delete
```

Understanding this difference is one of the most important topics in modern C++.

---

# Why Destructors Matter

Simple classes may not appear to need destructors.

However,

real classes often own resources such as

- dynamic memory
- files
- sockets
- databases
- mutexes
- GPU memory

Destructors guarantee these resources are released correctly.

Without destructors,

large applications would quickly exhaust system resources.

---

# Common Beginner Mistakes

## Mistake 1

Calling the destructor manually.

Wrong

```cpp
hero.~Player();
```

Except for very advanced situations, destructors should never be called directly.

---

## Mistake 2

Forgetting `delete`.

```cpp
Player *enemy = new Player;
```

without

```cpp
delete enemy;
```

causes a memory leak.

---

## Mistake 3

Using a pointer after deletion.

```cpp
delete enemy;

enemy->set_name("Boss");
```

This is undefined behavior.

---

## Mistake 4

Thinking constructors and destructors behave differently for stack and heap objects.

Both are always called.

Only **when** they execute is different.

---

# Best Practices

✔ Prefer stack objects whenever possible.

✔ If using `new`, always remember `delete`.

✔ Never use a deleted pointer.

✔ Let constructors initialize objects.

✔ Let destructors clean resources.

✔ Keep destructors simple and reliable.

---

# Summary (Part 2)

- Every object has a destructor.
- Destructors execute automatically when an object's lifetime ends.
- Stack objects are destroyed automatically.
- Heap objects require `delete`.
- Constructors execute in creation order.
- Destructors execute in reverse order.
- Forgetting `delete` causes memory leaks.
- Destructors are responsible for releasing resources before memory is returned.

> **Key Takeaway:**  
> Constructors begin an object's lifetime, while destructors end it. Understanding when and how these functions are called is essential for managing memory safely and writing reliable C++ programs.

# Constructors and Destructors (Part 3)

---

# Constructors and Destructors in Professional Software

In small educational programs, constructors and destructors may seem simple.

However, in professional software they are responsible for managing resources safely and automatically.

Examples include

- dynamically allocated memory
- files
- network connections
- database connections
- GPU memory
- physics detector objects
- simulation components

A well-designed constructor creates a valid object.

A well-designed destructor guarantees that all owned resources are released correctly.

---

# RAII (Resource Acquisition Is Initialization)

One of the most important ideas in modern C++ is

**RAII**

Resource Acquisition Is Initialization.

The idea is simple.

Whenever an object acquires a resource,

its constructor should obtain it,

and its destructor should release it.

```
Constructor

↓

Acquire Resource

↓

Object Exists

↓

Destructor

↓

Release Resource
```

Because destructors are automatically called,

resources are automatically released.

This makes programs much safer.

---

# Example of RAII

Imagine a class managing a file.

```cpp
class File
{
public:

    File()
    {
        // Open file
    }

    ~File()
    {
        // Close file
    }

};
```

The user never needs to remember to close the file manually.

When the object disappears,

the destructor automatically performs cleanup.

---

# Why Constructors Matter

Suppose we have

```cpp
Player hero;
```

Without a constructor

```
name

health

xp
```

may all contain invalid values.

The constructor guarantees that every object begins life in a predictable state.

Example

```cpp
Player()
{
    name = "Unknown";
    health = 100;
    xp = 0;
}
```

Every object is immediately usable.

---

# Why Destructors Matter

Imagine allocating memory.

```cpp
int *ptr = new int;
```

Without deleting it,

memory remains allocated forever.

A class destructor prevents this problem.

```cpp
~ClassName()
{
    delete ptr;
}
```

The programmer cannot accidentally forget to free the memory when the object dies.

---

# Constructors and Smart Pointers

Later you will study

```
unique_ptr

shared_ptr

weak_ptr
```

These classes rely entirely on constructors and destructors.

Example

```cpp
std::unique_ptr<Player> hero
        = std::make_unique<Player>();
```

When the smart pointer is destroyed,

its destructor automatically deletes the managed object.

Notice that the programmer never writes

```cpp
delete
```

Modern C++ achieves automatic memory management through RAII.

---

# Constructors in Scientific Software

Scientific software often creates extremely complex objects.

Examples

Geant4

```
Detector

↓

Physics List

↓

Sensitive Detector

↓

Particle Gun
```

Every one of these objects is initialized using constructors.

---

ROOT

```
TH1F histogram;

↓

Constructor

↓

Histogram Ready
```

The constructor allocates the internal histogram data structures automatically.

---

CMSSW

Every event, detector module, producer, and analyzer is created through constructors.

When processing finishes,

their destructors clean up resources automatically.

---

# Constructor Initialization

So far,

our constructors looked like

```cpp
Player(string name)
{
    this->name = name;
}
```

Soon you will learn a better approach.

```cpp
Player(string name)

: name{name}
{

}
```

This syntax is called the

**Constructor Initialization List**.

It is

- faster
- cleaner
- preferred in professional C++
- required for certain member types

Most large C++ projects use initialization lists almost exclusively.

---

# Object Lifetime

Every object has a clearly defined lifetime.

```
Memory Allocated

↓

Constructor

↓

Object Ready

↓

Member Functions

↓

Destructor

↓

Memory Released
```

Understanding this lifecycle is essential for writing reliable software.

---

# Common Beginner Mistakes

## Mistake 1

Using constructors only to print messages.

Constructors should initialize objects.

---

## Mistake 2

Leaving member variables uninitialized.

Always give every object a valid initial state.

---

## Mistake 3

Using

```cpp
new
```

without understanding who is responsible for deleting the object.

Every dynamically allocated object must eventually be destroyed.

---

## Mistake 4

Thinking destructors only free memory.

In reality, destructors release **all kinds of resources**, including files, sockets, locks, and simulation objects.

---

## Mistake 5

Calling constructors manually.

Wrong

```cpp
hero.Player();
```

Constructors are called automatically when objects are created.

---

# Best Practices

✔ Always initialize every data member.

✔ Prefer constructors over setter functions for initial values.

✔ Keep constructors focused on initialization.

✔ Keep destructors focused on cleanup.

✔ Prefer automatic (stack) objects whenever possible.

✔ Avoid unnecessary dynamic allocation.

✔ Design every class so that an object is valid immediately after construction.

✔ Follow the RAII principle whenever a class owns resources.

---

# Looking Ahead

The next topic is

**Constructor Initialization Lists**

Instead of

```cpp
Player(string name)
{
    this->name = name;
}
```

you will learn

```cpp
Player(string name)

: name{name}
{

}
```

Initialization Lists

- construct objects directly,
- avoid unnecessary assignments,
- improve performance,
- are required for `const` members,
- are required for reference members,
- are required for many advanced C++ features.

This is the style used throughout modern C++ libraries such as ROOT, Geant4, Qt, and the C++ Standard Library.

---

# Summary

- Constructors create valid objects.
- Destructors safely destroy objects.
- Together they define an object's lifetime.
- Professional C++ relies heavily on constructors and destructors to manage resources automatically.
- RAII is one of the most important design principles in C++ and is built upon constructors and destructors.
- Smart Pointers, Copy Constructors, Move Constructors, and many advanced C++ techniques all depend on understanding object lifetime.
- Constructor Initialization Lists are the next step toward writing efficient and idiomatic modern C++ code.

> **Key Takeaway:**  
> Constructors and destructors are much more than special member functions—they are the foundation of object lifetime management in C++. Mastering them is essential for writing safe, efficient, and professional software, from small applications to large scientific frameworks such as ROOT, Geant4, and CMSSW.