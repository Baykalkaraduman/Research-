# Default Constructors (Part 1)

---

# Introduction

Whenever an object is created in C++, one of its constructors is automatically executed.

If the programmer does not define any constructor, the compiler will usually generate a **Default Constructor** automatically.

However, as soon as the programmer defines a custom constructor, this automatic behavior changes.

Understanding default constructors is essential because nearly every C++ object begins its life through one.

---

# What is a Default Constructor?

A **Default Constructor** is a constructor that can be called without providing any arguments.

Example

```cpp
Player hero;
```

The compiler automatically executes

```cpp
Player();
```

before the object becomes usable.

The programmer never calls this constructor manually.

---

# Compiler-Generated Default Constructor

Suppose we write

```cpp
class Player
{
private:
    std::string name;
    int health;
    int xp;
};
```

Notice that no constructor exists.

The compiler automatically generates one similar to

```cpp
Player()
{
}
```

This constructor performs **default initialization**.

It simply creates the object.

It does **not** necessarily initialize primitive variables such as

```
int

double

bool
```

to meaningful values.

For example

```
health

xp
```

may contain unpredictable values unless initialized.

---

# Why Write Our Own Default Constructor?

Instead of leaving member variables uninitialized,

we can provide meaningful starting values.

Example

```cpp
Player()
{
    name = "Nameless";
    health = 100;
    xp = 4;
}
```

Now every newly created player begins with a valid state.

```
Player hero;

↓

Default Constructor

↓

name = "Nameless"

health = 100

xp = 4
```

This makes the object immediately usable.

---

# User-Defined Default Constructor

A programmer may replace the compiler-generated constructor with a custom one.

Example

```cpp
Player()
{
    name = "Nameless";
    health = 100;
    xp = 4;

    std::cout << "Default Constructor Called";
}
```

Now every object created without arguments executes this constructor.

Example

```cpp
Player hero;
```

Output

```
Default Constructor Called
```

---

# Object Initialization

Creating an object automatically performs initialization.

Example

```cpp
Player hero;
```

Execution

```
Allocate Memory

↓

Call Constructor

↓

Initialize Members

↓

Object Ready
```

This process happens automatically for every object.

---

# Default Constructor vs Setter Functions

Without a constructor

```cpp
Player hero;

hero.set_name("Hero");
```

the object exists before meaningful values are assigned.

With a default constructor

```cpp
Player hero;
```

the object is already valid before any setter function is called.

Setter functions modify an object.

Constructors create a valid object.

These are different responsibilities.

---

# Constructor Overloading

A class may contain multiple constructors.

Example

```cpp
Player();

Player(string,int,int);
```

This is called **Constructor Overloading**.

Each constructor initializes objects differently.

```
Player hero;

↓

Default Constructor
```

```
Player("Emir",220,15);

↓

Three-Argument Constructor
```

The compiler automatically chooses the correct constructor.

---

# Common Beginner Mistakes

## Mistake 1

Believing the compiler always creates a default constructor.

This is only true if no other constructors are defined.

---

## Mistake 2

Thinking constructors must always receive arguments.

Default constructors require no arguments.

---

## Mistake 3

Leaving member variables uninitialized.

Always prefer meaningful default values whenever possible.

---

# Best Practices

✔ Give every object a valid initial state.

✔ Prefer meaningful default values over uninitialized variables.

✔ Let constructors initialize objects automatically.

✔ Keep constructors focused on initialization only.

---

# Summary (Part 1)

- Every object begins its lifetime by calling a constructor.
- A Default Constructor can be called without arguments.
- If no constructor is written, the compiler usually generates one automatically.
- Compiler-generated constructors do not necessarily initialize primitive data members.
- Writing your own default constructor allows every object to start with meaningful values.
- Constructor overloading allows multiple ways to initialize the same class.

> **Key Takeaway:**  
> A default constructor guarantees that every newly created object begins its life in a valid and predictable state. Proper default initialization is one of the foundations of reliable Object-Oriented Programming in C++.

# Default Constructors (Part 2)

---

# What Happens When We Define Our Own Constructor?

One of the most common misunderstandings is believing that the compiler always creates a default constructor.

This is **not always true**.

Consider the following class.

```cpp
class Player
{
public:

    Player(std::string name);
};
```

Now try creating

```cpp
Player hero;
```

The compiler reports an error.

Why?

Because once a programmer defines **any constructor**, the compiler no longer generates its own default constructor automatically.

---

# Compiler Rule

The compiler follows a simple rule.

## No Constructors Defined

```cpp
class Player
{

};
```

Compiler automatically creates

```cpp
Player();
```

---

## Programmer Defines Any Constructor

```cpp
Player(std::string);
```

Compiler assumes

> "The programmer is responsible for all constructors."

Therefore,

the automatic default constructor is **not generated**.

---

# Restoring the Default Constructor

If we still want objects without arguments,

we must define a default constructor ourselves.

Example

```cpp
Player()
{
    name = "Nameless";
    health = 100;
    xp = 4;
}
```

Now both of these become valid.

```cpp
Player hero;
```

and

```cpp
Player emir("Emir",220,12);
```

This is the reason many classes contain multiple constructors.

---

# Constructor Overloading

Constructors can be overloaded just like ordinary functions.

Example

```cpp
Player();

Player(std::string);

Player(std::string,int,int);
```

Each constructor provides a different way of creating an object.

The compiler selects the correct constructor automatically.

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

# Why Multiple Constructors?

Different situations require different initial states.

Example

Default Player

```cpp
Player hero;
```

↓

```
Name : Nameless

Health : 100

XP : 4
```

---

Custom Player

```cpp
Player("Emir",220,12);
```

↓

```
Name : Emir

Health : 220

XP : 12
```

Constructor overloading allows one class to support many initialization styles.

---

# Constructors Are Chosen Automatically

Notice

```cpp
Player hero;
```

and

```cpp
Player hero("Hero");
```

Both use the same class,

but completely different constructors.

The programmer never specifies which constructor should run.

The compiler determines the correct one from the supplied arguments.

---

# Constructors Are Not Ordinary Functions

Although constructors resemble functions,

they behave differently.

Constructors

- have no return type,
- execute automatically,
- run only once during object creation,
- cannot be called like ordinary member functions.

Wrong

```cpp
hero.Player();
```

Correct

```cpp
Player hero;
```

The constructor is executed automatically.

---

# Constructor Responsibilities

A constructor should

✔ initialize data members

✔ prepare the object

✔ establish a valid initial state

A constructor should **not**

✘ perform large calculations

✘ interact heavily with the user

✘ contain complicated business logic

Its primary responsibility is initialization.

---

# Modern C++ Notes

Beginning with C++11,

the language introduced

```cpp
= default;
```

Example

```cpp
Player() = default;
```

This explicitly asks the compiler to generate its normal default constructor.

Likewise,

```cpp
Player() = delete;
```

prevents objects from being created without arguments.

You will encounter these features frequently in modern C++ libraries.

---

# Looking Ahead

So far, constructors initialize members like this.

```cpp
Player()
{
    name = "Nameless";
    health = 100;
    xp = 4;
}
```

The next topic introduces a more efficient technique.

```cpp
Player()

: name{"Nameless"},
  health{100},
  xp{4}
{

}
```

This syntax is called a **Constructor Initialization List**.

It

- constructs members directly,
- avoids unnecessary assignments,
- improves performance,
- is required for `const` members,
- is required for reference members.

Nearly every professional C++ project uses this syntax.

---

# Common Beginner Mistakes

## Mistake 1

Expecting the compiler to generate a default constructor after defining another constructor.

It does not.

---

## Mistake 2

Creating constructors that do far more than initialization.

Constructors should keep one clear responsibility.

---

## Mistake 3

Forgetting to define a default constructor after creating parameterized constructors.

This often causes compilation errors when writing

```cpp
Player hero;
```

---

## Mistake 4

Calling setter functions immediately after object creation when the constructor could perform the initialization directly.

Prefer

```cpp
Player("Hero",100,5);
```

instead of

```cpp
Player hero;

hero.set_name("Hero");
```

---

# Best Practices

✔ Always think about how an object should begin its lifetime.

✔ Provide a meaningful default constructor whenever appropriate.

✔ Overload constructors for different initialization scenarios.

✔ Keep constructors simple and focused on initialization.

✔ Use constructor overloading instead of unnecessary setter calls during object creation.

✔ Prepare for Constructor Initialization Lists, which provide a cleaner and more efficient way to initialize members.

---

# Summary

- The compiler generates a default constructor only if no constructors are defined.
- Defining any constructor disables the compiler-generated default constructor.
- Constructor overloading allows multiple ways to initialize an object.
- Constructors are selected automatically based on their arguments.
- Constructors should focus on initialization rather than general program logic.
- Modern C++ provides `= default` and `= delete` to explicitly control constructor generation.
- Constructor Initialization Lists are the preferred modern technique and naturally follow this topic.

> **Key Takeaway:**  
> A programmer who defines constructors also becomes responsible for the object's initialization strategy. Understanding when the compiler generates—or stops generating—a default constructor is essential before learning Constructor Initialization Lists and other advanced constructor techniques.