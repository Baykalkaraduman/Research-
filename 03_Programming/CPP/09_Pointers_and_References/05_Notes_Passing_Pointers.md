# Passing Pointers to Functions
## Part 1 — Fundamentals of Passing Pointers

---

# Introduction

One of the biggest advantages of pointers is that they allow functions to **access and modify the original variables** stored in memory.

Until now, we have learned **Pass by Value**, where a function receives a copy of a variable. In this chapter, we introduce **Pass by Pointer**, where instead of sending the value itself, we send its **memory address**.

This allows a function to work directly with the original object.

Passing pointers is widely used in:

- Dynamic memory management
- Arrays
- C-style strings
- Large objects (to avoid expensive copies)
- Linked Lists
- Trees
- Graphs
- Operating systems
- Game engines
- Embedded systems

Understanding this topic is essential before learning **References**, **Dynamic Arrays**, and **Object-Oriented Programming**.

---

# Review: Pass by Value

Previously, we wrote functions like:

```cpp
void double_data(int num)
{
    num *= 2;
}
```

Calling

```cpp
int value{10};

double_data(value);
```

produces

```
value = 10
```

Why?

Because

```
main

value = 10

↓

copy value

↓

double_data

num = 10

↓

num becomes 20

↓

Function ends

↓

Copy disappears
```

The original variable never changes.

---

# Why Pass a Pointer?

Instead of sending

```
10
```

we send

```
0x61FF18
```

(the address where 10 is stored).

Example

```cpp
double_data(&value);
```

Notice the

```cpp
&
```

operator.

It means

> "Send the address of this variable."

---

# Function Prototype

```cpp
void double_data(int *int_ptr);
```

Read it as

> "This function expects a pointer to an integer."

Notice that

```cpp
int
```

became

```cpp
int*
```

because we are receiving an **address**, not a value.

---

# Receiving the Address

Suppose

```cpp
int value{10};
```

Memory

```
Address

0x1000

↓

10
```

Calling

```cpp
double_data(&value);
```

passes

```
0x1000
```

into the function.

Inside the function

```
int_ptr

↓

0x1000
```

Now both

```
value

and

int_ptr
```

refer to the same memory location.

---

# Dereferencing Inside the Function

Function

```cpp
void double_data(int *int_ptr)
{
    *int_ptr *= 2;
}
```

Remember

```
int_ptr

↓

Address
```

while

```
*int_ptr

↓

Value stored at that address
```

If

```
value = 10
```

then

```
*int_ptr

↓

10
```

After

```cpp
*int_ptr *= 2;
```

memory becomes

```
20
```

When the function finishes,

```
value

↓

20
```

The original variable changed.

---

# Visual Representation

Before

```
main()

value

↓

10
```

Call

```
double_data(&value)
```

Function

```
int_ptr

↓

10
```

Modify

```
*int_ptr *= 2
```

After

```
main()

value

↓

20
```

Only one variable exists.

The function simply accessed it through its address.

---

# Passing a Pointer Variable

Instead of

```cpp
double_data(&value);
```

we may write

```cpp
int *value_ptr{&value};

double_data(value_ptr);
```

These are identical.

Because

```
value_ptr

↓

Address of value
```

which is exactly what the function expects.

---

# Passing Address vs Passing Value

### Pass by Value

```
Function receives

10
```

Changes affect only the copy.

---

### Pass by Pointer

```
Function receives

0x1000
```

Function accesses the original variable.

Changes remain after returning.

---

# Why Is This Useful?

Imagine a vector containing one million elements.

If you write

```cpp
void process(vector<int> data)
```

the entire vector is copied.

That is expensive.

Instead,

```cpp
void process(vector<int> *data)
```

passes only

```
one memory address
```

which is usually just **8 bytes** on a 64-bit system.

This is much faster.

---

# Example: Doubling a Value

Code

```cpp
int value{10};

double_data(&value);
```

Execution

```
Before

value = 10

↓

Function

↓

20

↓

Return

↓

value = 20
```

Output

```
Original value : 10

After function : 20
```

---

# Passing Multiple Pointers

A function may receive more than one pointer.

Example

```cpp
void swap_values(int *a, int *b);
```

Memory

```
x

↓

100


y

↓

200
```

Call

```cpp
swap_values(&x,&y);
```

Function receives

```
a

↓

x


b

↓

y
```

Both original variables are now accessible.

This is the foundation of the classic **swap** algorithm, which we'll examine in detail in the next section.

---

# nullptr Safety

Never assume that a pointer is valid.

Bad

```cpp
*ptr = 10;
```

If

```
ptr == nullptr
```

the program crashes.

Instead

```cpp
if(ptr == nullptr)
    return;
```

This simple check prevents dereferencing an invalid pointer.

Professional C++ code almost always validates pointers before using them.

---

# Common Beginner Mistakes

## Mistake 1

Passing the value instead of the address.

Wrong

```cpp
double_data(value);
```

Correct

```cpp
double_data(&value);
```

---

## Mistake 2

Forgetting to dereference.

Wrong

```cpp
int_ptr *= 2;
```

This changes the address, not the value.

Correct

```cpp
*int_ptr *= 2;
```

---

## Mistake 3

Dereferencing a nullptr.

Wrong

```cpp
*ptr = 100;
```

Always check

```cpp
if(ptr != nullptr)
```

before accessing memory.

---

# Summary

✔ Pass by Pointer sends the **address**, not the value.

✔ Functions receive pointer parameters (e.g., `int*`).

✔ Dereferencing (`*ptr`) accesses the original variable.

✔ Any modification affects the original object in memory.

✔ Pointer parameters are efficient because only an address is copied.

✔ Always validate pointers before dereferencing them.

---

# Coming in Part 2

In the next section, we will cover:

- Swapping variables using pointers
- Passing arrays to functions
- Array decay (`array → pointer`)
- Passing vectors by pointer
- `const` pointers and pointer-to-const
- Best practices
- Pointer vs Reference comparison
- Modern C++ recommendations

# Passing Pointers to Functions
## Part 2 — Arrays, Vectors, const Pointers & Best Practices

---

# Swapping Variables Using Pointers

One of the classic uses of pointers is swapping two variables.

Without pointers, this would not work because the function would receive copies of the variables.

Example

```cpp
void swap_values(int *a, int *b)
{
    int temp {*a};

    *a = *b;
    *b = temp;
}
```

Calling

```cpp
int x {100};
int y {200};

swap_values(&x, &y);
```

---

Memory before the function call

```
main()

x ---------> 100

y ---------> 200
```

Passing addresses

```
swap_values()

a ---------> x

b ---------> y
```

Now

```
*a

↓

100
```

and

```
*b

↓

200
```

The function modifies the original variables.

---

Step 1

```cpp
temp = *a;
```

```
temp = 100
```

---

Step 2

```cpp
*a = *b;
```

Memory

```
x

↓

200
```

---

Step 3

```cpp
*b = temp;
```

Memory

```
y

↓

100
```

---

Function returns

```
x = 200

y = 100
```

No copies were modified.

The original variables changed.

---

# Passing Arrays to Functions

Suppose

```cpp
int scores[]
{
    100,
    98,
    95,
    90,
    -1
};
```

When passed to a function

```cpp
display_array(scores,-1);
```

something interesting happens.

The array itself is **not copied**.

Instead,

the compiler converts

```
scores

↓

int*
```

This automatic conversion is called

# Array Decay

Array

↓

Pointer

```
int scores[5]

↓

int*
```

This is why the function prototype is

```cpp
void display_array(const int *array,int sentinel);
```

NOT

```cpp
void display_array(int array[5]);
```

Inside the function,

both represent the same thing.

---

# Why Doesn't the Function Know the Size?

Because only the address is passed.

The following information is lost

```
5 elements
```

Only this remains

```
0x61FF20
```

That is why we usually pass

- size

or

- sentinel

along with the pointer.

---

# Sentinel Values

Your code uses

```cpp
-1
```

as the sentinel.

Loop

```cpp
while(*array != sentinel)
```

Execution

```
100

98

95

90

-1

↓

Stop
```

This is exactly the same idea used by C-style strings.

```
'\0'

↓

End of string
```

---

# Passing Vectors

Unlike arrays,

vectors know their own size.

Instead of

```cpp
vector<string> data
```

we can pass

```cpp
const vector<string> *const v
```

Only one address is copied.

No expensive vector copy occurs.

---

# Understanding

```cpp
const vector<string> *const v
```

Let's read it from right to left.

```
v

↓

constant pointer

↓

to

↓

constant vector<string>
```

Meaning

```
Pointer cannot move

AND

Vector cannot be modified
```

---

# Why Two const Keywords?

The first one

```cpp
const vector<string>
```

protects the object.

This becomes illegal

```cpp
(*v).push_back("CMS");
```

or

```cpp
(*v)[0] = "Muon";
```

The compiler prevents modifications.

---

The second const

```cpp
*const v
```

protects the pointer itself.

Illegal

```cpp
v = nullptr;
```

The pointer must continue pointing to the same vector.

---

# The Four Pointer Forms

Understanding these combinations is very important.

---

## 1)

```cpp
int *ptr;
```

Meaning

```
Pointer

↓

modifiable

Value

↓

modifiable
```

Everything can change.

---

## 2)

```cpp
const int *ptr;
```

Meaning

```
Pointer

↓

modifiable

Value

↓

read only
```

The pointer may point elsewhere,

but the object cannot be modified through it.

---

## 3)

```cpp
int *const ptr;
```

Meaning

```
Pointer

↓

fixed

Value

↓

modifiable
```

The pointer cannot point somewhere else,

but the object may change.

---

## 4)

```cpp
const int *const ptr;
```

Meaning

```
Pointer

↓

fixed

Value

↓

read only
```

Nothing can change.

This is the safest form.

---

# Why Use const?

Imagine a function

```cpp
display_vector(...)
```

Its purpose is only

```
Display data
```

It should never accidentally modify the vector.

Using

```cpp
const
```

lets the compiler protect you from mistakes.

---

# Advantages of Passing Pointers

✔ No expensive copies

✔ Functions can modify original objects

✔ Required for dynamic memory

✔ Required for many C libraries

✔ Efficient for large objects

✔ Useful for arrays

✔ Useful for optional parameters (`nullptr`)

---

# Pointer vs Pass by Value

Pass by Value

```
Copies object

↓

Safe

↓

Can be expensive
```

---

Pass by Pointer

```
Copies address

↓

Fast

↓

Can modify original object
```

---

# Pointer vs Reference

Pointers and references are closely related.

| Pointer | Reference |
|----------|-----------|
| Can be nullptr | Cannot be nullptr |
| Can change what it points to | Cannot be rebound |
| Requires `*` and `&` | Looks like a normal variable |
| Optional ownership semantics | Always aliases an existing object |

In modern C++, references are preferred when a parameter must refer to a valid object, while pointers are preferred when a parameter may be absent (`nullptr`) or needs to be reseated.

---

# Best Practices

✔ Always initialize pointers.

```cpp
int *ptr {nullptr};
```

---

✔ Check pointers before dereferencing.

```cpp
if(ptr != nullptr)
```

---

✔ Use `const` whenever modification is unnecessary.

---

✔ Prefer references when null is not a valid state.

---

✔ Use descriptive names.

Good

```cpp
student_ptr
```

Better than

```cpp
p
```

---

✔ Keep pointer lifetime clear.

Never return or store pointers to local variables that no longer exist.

---

# Common Beginner Mistakes

## Forgetting '&'

Wrong

```cpp
swap_values(x,y);
```

Correct

```cpp
swap_values(&x,&y);
```

---

## Forgetting '*'

Wrong

```cpp
ptr = 10;
```

Correct

```cpp
*ptr = 10;
```

---

## Dereferencing nullptr

Wrong

```cpp
*ptr = 5;
```

Always check first.

---

## Modifying Data Through a const Pointer

Wrong

```cpp
(*v)[0] = "Physics";
```

The compiler correctly rejects this.

---

## Assuming Arrays Know Their Size

Inside a function,

```cpp
int array[]
```

is simply

```cpp
int*
```

The size information is gone.

Pass the size or use a sentinel.

---

# Real-World Applications

Passing pointers is common in:

- Dynamic memory management
- C APIs
- Graphics programming
- Embedded systems
- Operating systems
- Device drivers
- Scientific computing
- High-performance computing (HPC)
- Game engines
- Physics simulations

Although modern C++ often uses references and smart pointers, understanding raw pointer parameters is essential because they are still heavily used in existing codebases and system-level programming.

---

# Final Summary

Passing pointers allows functions to work directly with objects stored in memory instead of working on copies.

The key ideas are:

- A pointer parameter receives an **address**.
- Dereferencing (`*ptr`) accesses the original object.
- Arrays automatically decay into pointers when passed to functions.
- Large objects such as vectors can be passed efficiently using pointers.
- `const` protects both data and pointers from unintended modification.
- Always initialize pointers and validate them before dereferencing.

> **Key takeaway:**  
> When reading any function with pointer parameters, ask yourself two questions:
>
> 1. **What object does this pointer refer to?**
> 2. **Am I allowed to modify that object?**
>
> If you can answer those questions, you understand how pointer parameters work.