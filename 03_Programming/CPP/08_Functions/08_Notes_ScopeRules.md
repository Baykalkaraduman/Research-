# Scope Rules

---

# Introduction

Every variable in a C++ program has **rules** that determine

- where it can be accessed,
- how long it exists,
- and when it is destroyed.

These rules are called **scope rules**.

Understanding scope is one of the most important concepts in C++, because almost every program relies on variables that exist in different parts of memory.

Scope determines the **visibility** of a variable, while its **lifetime** determines how long the variable remains in memory.

---

# What is Scope?

Scope defines **where a variable can be accessed**.

A variable can only be used inside the scope where it is declared.

For example,

```cpp
int age {20};
```

If `age` is declared inside a function,

only that function can access it.

Trying to use it outside that function results in a compiler error.

---

# Local Scope

Variables declared inside a function are called **local variables**.

Example

```cpp
void display() {

    int value {100};

    cout << value;

}
```

The variable

```cpp
value
```

exists only inside

```cpp
display()
```

Trying to access it elsewhere is illegal.

---

# Characteristics of Local Variables

Local variables

- are created when the function starts
- are destroyed when the function finishes
- cannot be accessed outside the function
- are stored separately for each function call

Example

```cpp
void func() {

    int x {5};

}
```

Every call creates a brand new

```cpp
x
```

---

# Function Parameters

Function parameters are also local variables.

Example

```cpp
void print(int number)
```

Here,

```cpp
number
```

exists only inside

```cpp
print()
```

After the function returns,

the parameter is destroyed.

---

# Block Scope

Every pair of braces

```cpp
{
}
```

creates a new scope.

Example

```cpp
int x {10};

{

    int y {20};

}
```

Outside the braces,

```cpp
y
```

no longer exists.

---

# Nested Scopes

Scopes can exist inside other scopes.

Example

```cpp
int a {10};

{

    int b {20};

}
```

The inner scope can access variables from the outer scope.

Therefore

```cpp
cout << a;
```

is valid inside the block.

However,

outside the block,

```cpp
cout << b;
```

is illegal.

Think of nested scopes like rooms inside a building.

A smaller room can see everything outside it,

but the hallway cannot see inside the room.

---

# Variable Shadowing

A local variable may have the same name as another variable in an outer scope.

Example

```cpp
int value {100};

{

    int value {200};

    cout << value;

}
```

Output

```
200
```

The inner variable hides the outer variable.

This behavior is called **variable shadowing**.

---

# Shadowing Example

```cpp
int number {50};

{

    int number {100};

    cout << number;

}
```

Output

```
100
```

Outside the block

```cpp
cout << number;
```

prints

```
50
```

because the inner variable no longer exists.

---

# Global Scope

Variables declared outside every function are called **global variables**.

Example

```cpp
int counter {0};
```

Every function in the program can access this variable.

Example

```cpp
void increment() {

    counter++;

}
```

The variable exists during the entire execution of the program.

---

# Lifetime of Global Variables

Global variables

- are created before `main()` starts
- remain in memory during the entire program
- are destroyed after the program finishes

Unlike local variables,

they are **not recreated** every time a function is called.

---

# Scope Resolution Operator

Sometimes a local variable hides a global variable.

Example

```cpp
int number {100};

void func() {

    int number {500};

}
```

Inside

```cpp
func()
```

the name

```cpp
number
```

refers to the local variable.

To access the global variable,

C++ provides the **scope resolution operator**.

Syntax

```cpp
::variable_name
```

Example

```cpp
cout << ::number;
```

This tells the compiler

"Use the global variable."

---

# Example

```cpp
int number {10};

int main() {

    int number {20};

    cout << number << endl;

    cout << ::number << endl;

}
```

Output

```
20
10
```

---

# Static Local Variables

Normally,

local variables disappear when a function finishes.

However,

adding

```cpp
static
```

changes this behavior.

Example

```cpp
void counter() {

    static int count {0};

    count++;

    cout << count;

}
```

Output after three calls

```
1
2
3
```

Unlike ordinary local variables,

a static local variable keeps its value between function calls.

---

# Local Variable vs Static Local Variable

Normal local variable

```cpp
void func() {

    int x {0};

}
```

Every function call creates a new variable.

Static local variable

```cpp
void func() {

    static int x {0};

}
```

Created only once.

Its value is preserved until the program ends.

---

# Memory Overview

A simplified memory model looks like this

```
Program Starts
       │
       ▼

Global Variables
       │
       ▼

main()

       │

Local Variables

       │

Inner Blocks

       │

Function Calls

       │

Static Variables

       ▼

Program Ends
```

Each category has different lifetime and visibility rules.

---

# Why Scope Matters

Proper scope management makes programs

- easier to understand
- easier to debug
- safer
- more memory efficient

Professional software tries to keep variables inside the smallest scope possible.

This minimizes accidental modifications and improves readability.
---

# Lifetime vs Scope

Although they are closely related, **scope** and **lifetime** are different concepts.

- **Scope** determines **where** a variable can be accessed.
- **Lifetime** determines **how long** the variable exists in memory.

A variable may still exist in memory but be inaccessible due to its scope.

Likewise, a variable may go out of scope and be destroyed immediately if its lifetime ends.

Example

```cpp
void example() {

    int x {10};

}
```

The variable `x`

- is visible only inside `example()`
- is created when the function begins
- is destroyed when the function returns

---

# Storage Duration

Every variable belongs to one of several storage durations.

## Automatic Storage

Default local variables use automatic storage.

Example

```cpp
void func() {

    int value {10};

}
```

Characteristics

- Created when entering the scope.
- Destroyed when leaving the scope.
- Recreated every function call.

---

## Static Storage

Static variables are initialized only once.

Example

```cpp
static int counter {0};
```

Characteristics

- Exists during the entire program.
- Initialization happens only once.
- Keeps its previous value between function calls.

---

## Global Storage

Global variables also have static storage duration.

Example

```cpp
int global_counter {0};
```

Characteristics

- Created before `main()`
- Destroyed after program termination
- Accessible from every function (unless hidden)

---

# Variable Lifetime Illustration

Consider

```cpp
void demo() {

    int a {10};

    static int b {20};

}
```

Function Call #1

```
a created

b created
```

Function exits

```
a destroyed

b remains
```

Function Call #2

```
a created again

b already exists
```

This explains why static variables preserve their values.

---

# Variable Shadowing Revisited

Suppose we write

```cpp
int number {100};

int main() {

    int number {50};

}
```

There are now two completely different variables.

```
Global number

↓

100


Main number

↓

50
```

Inside `main()`

```cpp
number
```

refers to

```
50
```

To access the global one

```cpp
::number
```

must be used.

---

# Scope in Scientific Computing

Scope management becomes very important in scientific software.

Examples include

- detector simulations
- Monte Carlo generators
- numerical integration
- optimization algorithms
- matrix calculations
- event reconstruction

Large scientific projects often contain thousands of variables.

Keeping variables inside the smallest possible scope

- improves readability
- reduces bugs
- simplifies maintenance
- improves compiler optimization

Projects such as

- ROOT
- Geant4
- CERN software frameworks
- Eigen
- OpenFOAM

all rely heavily on proper scope management.

---

# Best Practices

✔ Declare variables in the smallest scope possible.

✔ Prefer local variables over global variables.

✔ Avoid modifying global variables whenever possible.

✔ Use descriptive variable names.

✔ Use `static` only when persistent state is required.

✔ Minimize variable shadowing.

✔ Keep functions independent of global state whenever possible.

---

# Common Mistakes

## Using Too Many Global Variables

Bad

```cpp
int score;
int counter;
int value;
int total;
```

Large numbers of global variables make debugging much harder.

---

## Variable Shadowing

Bad

```cpp
int number {100};

void func() {

    int number {50};

}
```

This is legal but can confuse readers.

Prefer different names whenever possible.

---

## Misusing Static Variables

Bad

```cpp
static int counter;
```

Using static variables everywhere makes programs difficult to reason about.

Use them only when persistent state is truly needed.

---

## Accessing Local Variables Outside Their Scope

Wrong

```cpp
void func() {

    int value {10};

}

cout << value;
```

The compiler correctly reports an error because `value` no longer exists.

---

## Confusing Scope with Lifetime

Remember

Scope answers

> "Where can I use this variable?"

Lifetime answers

> "How long does this variable exist?"

These are different concepts.

---

# Summary

After completing this chapter you should understand

- Local scope
- Global scope
- Block scope
- Nested scopes
- Variable shadowing
- Scope resolution operator (`::`)
- Static local variables
- Lifetime vs scope
- Storage duration
- Best practices for variable visibility

---

# Exercises

## Exercise 1

Create a program containing

- one global variable
- one local variable

Print both variables inside a function.

---

## Exercise 2

Write a function using a static local variable that counts how many times it has been called.

Call it five times.

---

## Exercise 3

Create nested blocks.

Declare variables with the same name.

Observe variable shadowing.

---

## Exercise 4

Declare a global variable named

```cpp
count
```

Create a local variable with the same name.

Print both using

```cpp
count

::count
```

---

## Exercise 5

Write a program demonstrating

- automatic storage
- static storage
- global storage

Explain why each variable behaves differently.

---

## Exercise 6 (Challenge)

Write a simple menu program.

Use

- local variables for menu choices
- a static variable to count how many menu selections have been made
- a global constant for the program title

Observe which values persist during execution.

---

## Exercise 7 (Challenge)

Implement a function

```cpp
generate_id()
```

that returns consecutive IDs

```
1001
1002
1003
...
```

using a **static local variable** without any global variables.