# Shallow Copy (Part 1)

---

# Introduction

So far, we have learned about Copy Constructors.

For ordinary classes,

the compiler-generated Copy Constructor performs a **memberwise copy**, which is usually correct.

However,

everything changes when a class owns **dynamic memory**.

Instead of copying simple values,

the object now owns resources located on the heap.

This introduces one of the most common programming mistakes in C++:

**Shallow Copy.**

---

# What is a Shallow Copy?

A Shallow Copy copies **pointer values**, not the memory they point to.

Example

```
Object A

data -----> Heap Memory
```

After a shallow copy

```
Object A

data ----┐
         │
         ▼
      Heap Memory
         ▲
         │
data ----┘

Object B
```

Now both objects point to exactly the same heap memory.

Only the pointer was copied.

The heap memory itself was **not duplicated**.

---

# The Example Class

```cpp
class Shallow
{
private:

    int *data;

public:

    Shallow(int value);

    Shallow(const Shallow &source);

    ~Shallow();
};
```

Unlike previous examples,

this class does **not** store an integer directly.

Instead,

it stores a pointer to dynamically allocated memory.

The object owns a resource.

---

# Constructor

```cpp
Shallow::Shallow(int value)
{
    data = new int;

    *data = value;
}
```

Step by step

1. Allocate memory on the heap.

2. Store the heap address inside `data`.

3. Store the integer value.

Visual representation

```
Object

data
 │
 ▼
Heap

100
```

The object now owns one dynamically allocated integer.

---

# Copy Constructor

```cpp
Shallow::Shallow(const Shallow &source)

: data{source.data}
{

}
```

This looks harmless,

but it is actually wrong.

Only the pointer itself is copied.

No new memory is allocated.

No integer is duplicated.

The result is

```
obj1

data ----┐
         │
         ▼
        100
         ▲
         │
data ----┘

obj2
```

Two objects now believe they own the same heap memory.

---

# Why is This Dangerous?

Normally,

each object should manage its own resources.

After a shallow copy,

both objects think

> "I own this memory."

Eventually,

both objects will try to delete it.

This violates the fundamental rule of resource ownership.

---

# Changing One Object Changes the Other

Suppose

```cpp
obj2.set_data_value(1000);
```

Many beginners expect

```
obj1 = 100

obj2 = 1000
```

Instead,

both objects refer to the same heap memory.

The actual result becomes

```
obj1 = 1000

obj2 = 1000
```

There is only one integer.

Both pointers access it.

---

# Visual Representation

Before copying

```
obj1

data

↓

Heap

100
```

After shallow copy

```
obj1

data ----┐
         │
         ▼
        100
         ▲
         │
data ----┘

obj2
```

There is still only **one** heap allocation.

Only the pointer has been duplicated.

---

# Common Beginner Mistakes

## Mistake 1

Thinking the integer itself is copied.

Only the pointer is copied.

---

## Mistake 2

Believing each object owns different memory.

They actually share the same heap allocation.

---

## Mistake 3

Assuming this behavior is safe.

It is not.

Shared ownership without proper management almost always leads to bugs.

---

# Summary (Part 1)

- Shallow Copy copies pointer values instead of duplicating heap memory.
- After a shallow copy, multiple objects point to the same resource.
- No new memory is allocated during the copy.
- Modifying the shared resource through one object affects every object pointing to it.
- Shallow Copy breaks the idea that each object should independently own its resources.

> **Key Takeaway:**  
> A Shallow Copy duplicates the pointer, **not the data it points to**. As a result, multiple objects mistakenly believe they own the same heap memory. This shared ownership is the root cause of many memory management bugs in C++ and sets the stage for understanding why **Deep Copy** is necessary.

# Shallow Copy (Part 2)

---

# Why Does the Program Crash?

At first glance,

nothing seems wrong.

The program

- creates an object,
- copies it,
- displays its value,
- and exits.

However,

behind the scenes,

both objects own the **same heap memory**.

Eventually,

both objects try to delete the same memory.

This causes one of the most common C++ runtime errors:

**Double Deletion.**

---

# Step 1 — Creating obj1

```cpp
Shallow obj1{100};
```

Constructor

```cpp
data = new int;

*data = 100;
```

Memory

```
Stack

obj1

data
 │
 ▼
Heap

100
```

At this moment,

everything is correct.

obj1 owns the heap memory.

---

# Step 2 — Passing by Value

```cpp
display_shallow(obj1);
```

Function

```cpp
void display_shallow(Shallow object)
```

Notice carefully.

The parameter is

```cpp
Shallow object
```

NOT

```cpp
Shallow&
```

Passing by value automatically creates another object.

Execution

```
obj1

↓

Copy Constructor

↓

temporary object
```

---

# Step 3 — Shallow Copy Happens

Copy Constructor

```cpp
Shallow::Shallow(const Shallow &source)

: data{source.data}
{

}
```

Only the pointer is copied.

Memory now becomes

```
Stack

obj1

data ----┐
         │
         ▼

Heap

100

         ▲
         │

temporary object

data ----┘
```

Two different objects

↓

One heap allocation

---

# Step 4 — Leaving the Function

When

```cpp
display_shallow()
```

finishes,

the temporary object is destroyed.

Destructor

```cpp
delete data;
```

Memory becomes

```
Stack

obj1

data

↓

Invalid Memory

Heap

(deleted)
```

The heap memory no longer exists.

Unfortunately,

obj1 still stores the old address.

This pointer is now called a

**Dangling Pointer.**

---

# Step 5 — Returning to main()

The function has finished.

Program execution continues.

```
obj1

data

↓

Invalid Address
```

The pointer still looks valid,

but the memory has already been freed.

Using it now causes

**Undefined Behavior.**

---

# Step 6 — Program Ends

At the end of `main()`

obj1 is destroyed.

Destructor

```cpp
delete data;
```

But

that memory was already deleted.

Execution becomes

```
delete

↓

delete again

↓

Double Delete

↓

Undefined Behavior

↓

Program Crash
```

---

# The Complete Timeline

```
obj1 created

↓

Heap allocated

↓

Pass by value

↓

Copy Constructor

↓

Temporary object created

↓

Temporary object destroyed

↓

Heap deleted

↓

obj1 still stores old pointer

↓

obj1 destructor

↓

Delete same memory again

↓

Crash
```

---

# What is a Dangling Pointer?

A dangling pointer is

a pointer that still stores an address,

but the memory at that address no longer exists.

Example

```
Pointer

↓

0xA2F31

↓

Memory already deleted
```

The pointer itself is valid,

but the address is not.

Using it produces undefined behavior.

---

# Undefined Behavior

After memory has been deleted,

anything may happen.

Examples include

- program crashes
- corrupted data
- random output
- access violations
- apparently correct execution

Undefined Behavior means

the C++ Standard no longer guarantees anything.

---

# Why Doesn't nullptr Solve This?

Suppose we write

```cpp
delete data;

data = nullptr;
```

This only changes the pointer inside

the object being destroyed.

The other copied object still contains

the old address.

Therefore,

the problem remains.

---

# Common Beginner Mistakes

## Mistake 1

Thinking the crash happens during copying.

It does not.

Copying succeeds.

The crash happens later,

when destructors execute.

---

## Mistake 2

Believing both objects have different memory.

They do not.

Only one heap allocation exists.

---

## Mistake 3

Thinking the pointer becomes nullptr automatically after delete.

It does not.

It becomes a dangling pointer.

---

## Mistake 4

Ignoring pass-by-value.

Passing objects by value silently creates copies.

Sometimes those copies introduce resource ownership bugs.

---

# Best Practices

✔ Understand exactly who owns dynamically allocated memory.

✔ Be careful when copying objects containing raw pointers.

✔ Prefer passing large objects by `const ClassName&`.

✔ Never allow multiple objects to delete the same resource.

---

# Summary (Part 2)

- Passing objects by value invokes the Copy Constructor.
- The shallow Copy Constructor copies only the pointer.
- Both objects end up owning the same heap memory.
- The temporary object deletes the shared memory when it is destroyed.
- The original object is left with a dangling pointer.
- Deleting that dangling pointer again results in a **Double Delete**, causing undefined behavior and usually a program crash.

> **Key Takeaway:**  
> The crash is **not caused by copying itself**, but by **incorrect ownership** of dynamically allocated memory. A shallow copy makes multiple objects believe they own the same resource, leading to dangling pointers, double deletion, and undefined behavior. This is precisely the problem that **Deep Copy** is designed to solve.