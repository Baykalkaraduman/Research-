# Returning Pointers from Functions
## Part 1 — Returning Dynamically Allocated Memory

---

# Introduction

Until now, we have learned how to:

- Create pointers
- Dereference pointers
- Pass pointers to functions
- Perform pointer arithmetic
- Allocate dynamic memory using `new`

In this chapter, we combine all of these concepts.

Instead of returning a normal value such as an `int` or a `double`, a function will return a **pointer**.

That pointer will point to dynamically allocated memory on the **Heap**.

This is one of the most important pointer concepts because it introduces **memory ownership** and prepares us for modern C++ containers such as `std::vector` and smart pointers.

---

# Returning Normal Values

We already know functions like

```cpp
int square(int x)
{
    return x * x;
}
```

Calling

```cpp
int answer = square(5);
```

returns

```
25
```

The returned value is copied into `answer`.

Simple.

---

# Returning a Pointer

Now consider

```cpp
int* create_array(size_t size);
```

Notice the return type.

Instead of

```cpp
int
```

we now have

```cpp
int*
```

This means

> The function returns the address of an integer (or the first element of an integer array).

---

# Why Return a Pointer?

Imagine we want a function to create an array.

How large should the array be?

```
5 ?

20 ?

100 ?

1000 ?
```

We don't know until runtime.

Local arrays require a compile-time size.

Dynamic memory solves this problem.

---

# Dynamic Allocation

Inside the function

```cpp
int *new_storage {new int[size]};
```

Let's examine this line.

---

## Step 1

```cpp
new int[size]
```

asks the Heap for memory.

Example

```
size = 5
```

Heap

```
Address

0x5000

↓

+----+----+----+----+----+
| ?? | ?? | ?? | ?? | ?? |
+----+----+----+----+----+
```

Memory has been reserved.

---

## Step 2

The address of the first element is returned.

```
0x5000
```

---

## Step 3

That address is stored inside

```cpp
new_storage
```

Memory now looks like

```
Stack

new_storage

↓

0x5000


Heap

0x5000

↓

+----+----+----+----+----+
| ?? | ?? | ?? | ?? | ?? |
+----+----+----+----+----+
```

---

# Initializing the Array

Your code uses

```cpp
for(size_t i{0}; i<size; ++i)
    *(new_storage+i)=init_value;
```

Suppose

```
init_value = 7
```

After the loop

```
Heap

+---+---+---+---+---+
| 7 | 7 | 7 | 7 | 7 |
+---+---+---+---+---+
```

Every element has been initialized.

---

# Pointer Arithmetic

This line

```cpp
*(new_storage+i)
```

uses pointer arithmetic.

Remember

```
new_storage

↓

First element
```

Then

```
new_storage+1

↓

Second element
```

```
new_storage+2

↓

Third element
```

and so on.

---

The following expressions are equivalent.

```cpp
new_storage[i]
```

and

```cpp
*(new_storage+i)
```

Both access exactly the same memory location.

---

# Returning the Pointer

The function ends with

```cpp
return new_storage;
```

Notice carefully.

We are **NOT returning the array**.

We are returning only

```
0x5000
```

the address of the first element.

---

# Memory Diagram

Inside create_array()

```
Stack

new_storage

↓

0x5000


Heap

+---+---+---+---+
| 5 | 5 | 5 | 5 |
+---+---+---+---+
```

Function returns

```
0x5000
```

The pointer variable disappears.

However,

the Heap memory **does not disappear**.

---

# Why Doesn't Heap Memory Disappear?

Because Heap memory is **not owned by the function**.

Only the local pointer

```
new_storage
```

is destroyed.

The actual memory remains allocated until someone calls

```cpp
delete[]
```

This is the fundamental difference between

## Stack

and

## Heap.

---

# Receiving the Returned Pointer

Back inside `main`

```cpp
int *my_array {nullptr};

my_array = create_array(size, init_value);
```

Before

```
my_array

↓

nullptr
```

After

```
my_array

↓

0x5000
```

Now

```
main()
```

owns the allocated memory.

---

# Display Function

Prototype

```cpp
void display(const int *const array,
             size_t size);
```

The function receives

```
0x5000
```

and prints

```
array[0]

array[1]

array[2]

...
```

No copy of the array is made.

Only one pointer is passed.

---

# Why Use const?

Notice

```cpp
const int *const array
```

There are two different protections.

The first

```cpp
const int
```

means

```
The array contents cannot be modified.
```

Illegal

```cpp
array[0]=100;
```

---

The second

```cpp
*const array
```

means

```
The pointer cannot point somewhere else.
```

Illegal

```cpp
array++;
```

The compiler prevents both mistakes.

---

# Ownership

One of the most important concepts in C++ is

## Ownership.

After

```cpp
my_array=create_array(...);
```

the program now owns

```
Heap Memory
```

Ownership also means

```
Responsibility
```

If you allocate memory,

you are responsible for releasing it.

---

# Common Beginner Mistakes

## Mistake 1

Returning a local array.

Wrong

```cpp
int array[10];

return array;
```

The array lives on the Stack.

After the function ends,

it no longer exists.

---

## Mistake 2

Returning the address of a local variable.

Wrong

```cpp
int value{5};

return &value;
```

Again,

the variable disappears after the function returns.

The pointer becomes invalid.

---

## Mistake 3

Thinking the pointer contains the array.

Wrong idea

```
Pointer

↓

Array
```

Correct idea

```
Pointer

↓

Address

↓

Array
```

The pointer stores only an address.

---

# Summary

✔ Functions can return pointers.

✔ Returning a pointer is actually returning a memory address.

✔ Dynamic memory created with `new` continues to exist after the function returns.

✔ Heap memory survives because it is independent of the function's local variables.

✔ Ownership of the allocated memory transfers to the caller.

✔ The caller is now responsible for eventually releasing that memory.

---

# Coming in Part 2

In the next section we will cover:

- `delete[]` and why it is mandatory
- Memory leaks
- Dangling pointers
- Returning local variables vs returning heap memory
- Lifetime of objects
- Ownership rules
- Stack vs Heap comparison table
- Modern C++ alternatives (`std::vector`, `std::unique_ptr`)
- Best practices for returning pointers

# Returning Pointers from Functions
## Part 2 — Memory Ownership, Lifetime, Memory Leaks & Modern C++ Practices

---

# Releasing Dynamic Memory

When we allocate memory using

```cpp
new
```

or

```cpp
new[]
```

the operating system reserves a portion of the **Heap** for our program.

Example

```cpp
int *array {new int[5]};
```

Memory

```
Heap

0x5000

↓

+---+---+---+---+---+
|   |   |   |   |   |
+---+---+---+---+---+
```

This memory will remain allocated until we explicitly release it.

---

# Why Must We Use delete[] ?

Since the memory was allocated using

```cpp
new[]
```

it must be released using

```cpp
delete[] array;
```

Notice the brackets.

Allocation

```cpp
new[]
```

↓

Deallocation

```cpp
delete[]
```

---

For single variables

```cpp
int *ptr {new int};
```

we use

```cpp
delete ptr;
```

For arrays

```cpp
int *ptr {new int[50]};
```

we use

```cpp
delete[] ptr;
```

Always match

```
new

↓

delete
```

and

```
new[]

↓

delete[]
```

---

# What Happens After delete[] ?

Suppose

```cpp
delete[] my_array;
```

The Heap memory is returned to the operating system.

```
Before

my_array

↓

0x5000

↓

Heap
```

After

```
Heap memory released
```

However...

the pointer itself still stores

```
0x5000
```

That address is no longer valid.

---

# Dangling Pointers

A pointer that still contains an address to released memory is called a

# Dangling Pointer

Example

```cpp
delete[] my_array;

cout << my_array[0];
```

This is **Undefined Behavior**.

The program may

- crash
- print garbage
- appear to work
- corrupt memory

Never access memory after deleting it.

---

# Best Practice

Immediately after deleting memory

```cpp
delete[] my_array;

my_array = nullptr;
```

Now

```
my_array

↓

nullptr
```

If the pointer is accidentally used later,

it is much easier to detect because comparisons against `nullptr` are possible.

---

# Memory Leak

Imagine

```cpp
int *data {new int[100]};
```

and later

```cpp
data = nullptr;
```

What happened?

The only pointer pointing to the Heap memory was lost.

```
Heap

↓

Still allocated

↓

No pointer exists
```

This memory can never be released.

This is called a

# Memory Leak

---

# Why Are Memory Leaks Dangerous?

Every leak wastes RAM.

One leak may not matter.

Thousands of leaks can eventually

- slow down the program
- consume all available memory
- crash the application
- crash the operating system

Large software projects spend significant effort preventing memory leaks.

---

# Returning Local Variables

Consider

```cpp
int* bad_function()
{
    int value {10};

    return &value;
}
```

Looks innocent.

But it is wrong.

---

Memory

```
Stack

value

↓

10
```

When the function ends,

```
value
```

is destroyed.

The returned pointer now points to memory that no longer belongs to the program.

This is another dangling pointer.

---

# Returning Heap Memory

Now compare

```cpp
int* good_function()
{
    int *ptr {new int{10}};

    return ptr;
}
```

Memory

```
Stack

ptr

↓

0x5000


Heap

0x5000

↓

10
```

The pointer variable disappears,

but

```
Heap memory
```

still exists.

Therefore,

returning heap memory is safe **as long as the caller eventually deletes it.**

---

# Lifetime Comparison

## Local Variables

```
Created

↓

Function executes

↓

Destroyed automatically
```

Lifetime ends when the function returns.

---

## Heap Memory

```
Created with new

↓

Exists

↓

Exists

↓

Exists

↓

delete

↓

Destroyed
```

The lifetime is completely controlled by the programmer.

---

# Ownership Rule

Whenever a function returns a raw pointer,

ask

> Who owns this memory?

Usually,

the caller.

Example

```cpp
int *numbers;

numbers = create_array(...);
```

Now

```
numbers
```

owns the allocated memory.

Therefore,

```cpp
delete[] numbers;
```

must eventually be called.

Ownership and responsibility always go together.

---

# Stack vs Heap

| Stack | Heap |
|--------|------|
| Automatic | Manual |
| Fast allocation | Slower allocation |
| Automatically released | Programmer releases memory |
| Small size | Much larger size |
| Local variables | Dynamic objects |
| Safe lifetime | Requires careful management |

---

# Why Do We Need Dynamic Memory?

Sometimes the program doesn't know the required memory size until runtime.

Example

```cpp
How many students?

250
```

or

```
1,000,000
```

A fixed array cannot adapt.

Dynamic memory solves this problem.

---

# Modern C++ Solution

Although raw pointers are important to understand,

modern C++ rarely allocates arrays like this.

Instead,

```cpp
vector<int>
```

is preferred.

Example

```cpp
vector<int> numbers(size, init_value);
```

Advantages

- automatic memory management
- automatic cleanup
- knows its own size
- exception safe
- no memory leaks

---

Another alternative is

```cpp
unique_ptr
```

which automatically releases memory when it goes out of scope.

This follows the RAII (Resource Acquisition Is Initialization) principle, one of the foundations of modern C++.

---

# Best Practices

✔ Match every `new` with `delete`.

✔ Match every `new[]` with `delete[]`.

✔ Set pointers to `nullptr` after deleting them.

✔ Never return pointers to local variables.

✔ Never access deleted memory.

✔ Clearly document ownership of dynamically allocated memory.

✔ Prefer `std::vector` for dynamic arrays whenever possible.

✔ Prefer smart pointers (`std::unique_ptr`, `std::shared_ptr`) over raw pointers in modern C++ unless low-level control is required.

---

# Common Beginner Mistakes

## Forgetting delete[]

```cpp
int *array {new int[100]};
```

Program ends without

```cpp
delete[] array;
```

→ Memory Leak

---

## Using delete Instead of delete[]

Wrong

```cpp
delete array;
```

Correct

```cpp
delete[] array;
```

---

## Returning Local Variables

Wrong

```cpp
int value {5};

return &value;
```

The variable is destroyed immediately after the function returns.

---

## Using Deleted Memory

Wrong

```cpp
delete[] array;

cout << array[0];
```

Undefined Behavior.

---

## Forgetting nullptr

Safer

```cpp
delete[] array;

array = nullptr;
```

instead of leaving a dangling pointer behind.

---

# Final Summary

Returning pointers from functions is one of the most powerful features of C++, but it also introduces responsibility.

The most important ideas are:

- A function may safely return a pointer to dynamically allocated (Heap) memory.
- Heap memory survives after the function returns.
- The caller becomes responsible for managing that memory.
- Every allocation with `new` or `new[]` must eventually be matched by `delete` or `delete[]`.
- Failing to release memory causes **memory leaks**.
- Accessing memory after it has been deleted causes **dangling pointers** and undefined behavior.
- Modern C++ generally replaces raw dynamic arrays with `std::vector` or smart pointers to eliminate these problems automatically.

> **Key takeaway:**  
> A raw pointer returned from a function is not just an address—it represents ownership of a resource. Whenever you receive such a pointer, you should immediately ask: **"Who is responsible for deleting this memory?"** If the answer is "me," then make sure you release it exactly once.