# Arrays and Pointers in C++

# Part 1 — Understanding the Relationship Between Arrays and Pointers

---

# Introduction

One of the most important concepts in C++ is understanding how **arrays and pointers** are related.

Many beginners hear the sentence

> "Arrays are pointers."

This is **NOT** completely true.

A more accurate statement is

> **An array is NOT a pointer, but in most expressions its name decays into a pointer to its first element.**

Understanding this single sentence makes pointer arithmetic, dynamic arrays, function parameters, and even the STL much easier to learn.

---

# Memory Representation of an Array

Suppose we have

```cpp
int scores[]{100,95,89};
```

Memory may look like this

```
Address        Value

0x1000   --->   100
0x1004   --->    95
0x1008   --->    89
```

Since an `int` occupies **4 bytes** on most systems, every element is stored immediately after the previous one.

Arrays are stored in **contiguous memory locations**.

This is one of the biggest advantages of arrays.

---

# The Array Name

Consider

```cpp
int scores[]{100,95,89};
```

The identifier

```cpp
scores
```

is **the name of the array.**

However,

in most expressions,

the compiler automatically converts it into

```cpp
&scores[0]
```

Therefore,

```cpp
cout << scores;
```

prints

```
0x61ff10
```

which is the address of the first element.

---

# Important Rule

The following expressions are equivalent

```cpp
scores

&scores[0]
```

Example

```cpp
cout << scores << endl;

cout << &scores[0] << endl;
```

Output

```
0x61ff10

0x61ff10
```

They print the same address.

---

# Is an Array a Pointer?

No.

An array is **not** a pointer.

Example

```cpp
int scores[3];
```

creates

```
Three integers
```

A pointer

```cpp
int* ptr;
```

creates

```
One variable capable of storing an address.
```

These are completely different objects.

---

# Array vs Pointer

Array

```
scores

↓

+-----+-----+-----+
|100  |95   |89   |
+-----+-----+-----+
```

Pointer

```
ptr

↓

0x61ff10
```

The pointer merely stores an address.

The array stores actual integers.

---

# Initializing a Pointer with an Array

Example

```cpp
int scores[]{100,95,89};

int* score_ptr{scores};
```

Since

```cpp
scores
```

becomes

```cpp
&scores[0]
```

this is equivalent to

```cpp
int* score_ptr{&scores[0]};
```

Both are correct.

---

# Visual Representation

```
scores

↓

+-----+-----+-----+
|100  |95   |89   |
+-----+-----+-----+

score_ptr

↓

+-----+-----+-----+
|100  |95   |89   |
+-----+-----+-----+
```

Both refer to exactly the same memory.

---

# Accessing Elements Using Array Notation

The traditional way

```cpp
scores[0]

scores[1]

scores[2]
```

Output

```
100

95

89
```

Most programmers use this notation.

---

# Accessing Elements Using Pointer Indexing

Because the pointer points to the first element,

we may also write

```cpp
score_ptr[0]

score_ptr[1]

score_ptr[2]
```

Output

```
100

95

89
```

The compiler generates identical machine code.

---

# Therefore

The following expressions are identical

```cpp
scores[0]

score_ptr[0]
```

Likewise

```cpp
scores[2]

score_ptr[2]
```

produce exactly the same value.

---

# Why Does This Work?

Internally,

array indexing is defined using pointer arithmetic.

The compiler interprets

```cpp
scores[2]
```

as

```cpp
*(scores + 2)
```

Similarly,

```cpp
score_ptr[2]
```

means

```cpp
*(score_ptr + 2)
```

There is no difference.

---

# Memory Illustration

```
scores

↓

Index

0        1        2

+--------+--------+--------+
| 100    | 95     | 89     |
+--------+--------+--------+

Address

1000     1004     1008
```

Reading

```cpp
scores[1]
```

means

```
Go to address

1000 + sizeof(int)

↓

1004

↓

Read the value

95
```

---

# Address Comparison

Suppose

```cpp
int* score_ptr{scores};
```

Then

```cpp
cout << score_ptr;
```

prints

```
0x61ff10
```

Likewise

```cpp
cout << scores;
```

prints

```
0x61ff10
```

Finally,

```cpp
cout << &scores[0];
```

prints

```
0x61ff10
```

All three addresses are identical.

---

# Checking with boolalpha

```cpp
cout << boolalpha;

cout << (&scores[0] == score_ptr);
```

Output

```
true
```

This confirms that both refer to the same memory location.

---

# Array Decay

One of the most important concepts in C++.

When an array appears in most expressions,

it **decays** into

```
pointer to the first element
```

Example

```cpp
scores
```

becomes

```cpp
&scores[0]
```

This automatic conversion is called

> **Array Decay**

---

# When Does Array Decay NOT Happen?

Array decay does **not** occur in a few special situations.

Examples include

```cpp
sizeof(scores)
```

```cpp
&typeid(scores)
```

```cpp
&scores
```

These preserve the array type.

Everywhere else,

the array becomes a pointer.

---

# Common Beginner Mistakes

## Mistake 1

Thinking

```cpp
scores
```

is the first value.

Wrong.

It is the address of the first element.

---

## Mistake 2

Thinking arrays are pointers.

Wrong.

Arrays and pointers are different objects.

Only the array name often behaves like a pointer.

---

## Mistake 3

Confusing

```cpp
scores
```

with

```cpp
*scores
```

Remember

```cpp
scores
```

means

```
Address
```

while

```cpp
*scores
```

means

```
Value stored at that address
```

These are completely different.

---

# Key Takeaways (Part 1)

- Arrays occupy contiguous memory.
- The array name usually decays into a pointer to its first element.
- `scores` is equivalent to `&scores[0]` in most expressions.
- Arrays and pointers are different types, even though they often behave similarly.
- Both array notation (`scores[i]`) and pointer notation (`score_ptr[i]`) access the same memory.
- Understanding array decay is essential before learning pointer arithmetic.

# Arrays and Pointers in C++

# Part 2 — Pointer Arithmetic, Offset Notation and sizeof()

---

# Pointer Arithmetic

One of the biggest advantages of pointers is that we can move through memory.

Suppose we have

```cpp
int scores[]{100,95,89};

int* score_ptr{scores};
```

Memory

```
Address

1000
1004
1008

Values

100
95
89
```

Initially

```
score_ptr

↓

1000
```

---

# Incrementing a Pointer

If we execute

```cpp
score_ptr++;
```

many beginners think

```
1000

↓

1001
```

This is WRONG.

Pointers do **NOT** move one byte.

Instead,

they move by

```
sizeof(type)
```

Since

```cpp
score_ptr
```

is an

```cpp
int*
```

the compiler knows

```
sizeof(int)

=

4 bytes
```

Therefore

```
1000

↓

1004
```

---

# Pointer Arithmetic Formula

General rule

```
pointer + n

=

Current Address + n × sizeof(type)
```

Examples

```
int*

+1

↓

4 bytes
```

```
double*

+1

↓

8 bytes
```

```
char*

+1

↓

1 byte
```

---

# Example

```cpp
cout << *score_ptr << endl;
```

Output

```
100
```

Then

```cpp
score_ptr++;
```

Now

```cpp
cout << *score_ptr << endl;
```

Output

```
95
```

Again

```cpp
score_ptr++;
```

Output

```
89
```

---

# Offset Notation

Instead of changing the pointer,

we can temporarily move it.

Example

```cpp
*(score_ptr+1)
```

means

```
Move one integer forward

↓

Read the value
```

Likewise

```cpp
*(score_ptr+2)
```

means

```
Move two integers forward

↓

Read the value
```

---

# Pointer Offset Notation

```cpp
cout << *score_ptr << endl;

cout << *(score_ptr+1) << endl;

cout << *(score_ptr+2) << endl;
```

Output

```
100

95

89
```

---

# Array Offset Notation

Since

```
scores

↓

pointer to first element
```

we may also write

```cpp
*(scores+0)

*(scores+1)

*(scores+2)
```

Output

```
100

95

89
```

---

# The Most Important Equality

These expressions are completely identical.

```
scores[0]

=

*(scores)

=

score_ptr[0]

=

*(score_ptr)
```

Likewise

```
scores[1]

=

*(scores+1)

=

score_ptr[1]

=

*(score_ptr+1)
```

And

```
scores[2]

=

*(scores+2)

=

score_ptr[2]

=

*(score_ptr+2)
```

---

# Formula to Memorize

This is probably the most famous formula in pointer programming.

```
array[index]

=

*(array + index)
```

Example

```cpp
scores[5]
```

is interpreted by the compiler as

```cpp
*(scores+5)
```

Always.

---

# Even More General Formula

For any pointer

```
pointer[index]

=

*(pointer+index)
```

Therefore

```cpp
score_ptr[2]
```

is exactly

```cpp
*(score_ptr+2)
```

---

# Looping with Pointers

Instead of writing

```cpp
for(size_t i{}; i<3; i++)
    cout << scores[i];
```

we may write

```cpp
for(size_t i{}; i<3; i++)
    cout << *(score_ptr+i);
```

Both produce

```
100

95

89
```

---

# sizeof(Array)

Suppose

```cpp
int scores[3];
```

Then

```cpp
sizeof(scores)
```

returns

```
3 × sizeof(int)

=

12 bytes
```

because the compiler knows

the entire array.

---

# sizeof(Pointer)

Suppose

```cpp
int* score_ptr;
```

Then

```cpp
sizeof(score_ptr)
```

returns

```
8 bytes
```

on most 64-bit computers.

Why?

Because it only stores

an address.

It knows nothing about the array size.

---

# Important Difference

```
sizeof(scores)

↓

Entire array
```

```
sizeof(score_ptr)

↓

One address
```

These are completely different.

---

# Why Arrays Lose Their Size

Consider

```cpp
void print(int arr[])
```

Inside the function,

the parameter

```cpp
arr
```

is actually

```cpp
int*
```

Therefore

```cpp
sizeof(arr)
```

returns

```
Pointer size

NOT

array size
```

This is why we almost always pass

```cpp
size
```

as a second parameter.

Example

```cpp
print(scores,size);
```

---

# Memory Diagram

```
scores

↓

+-------+-------+-------+
|100    |95     |89     |
+-------+-------+-------+

Address

1000

1004

1008
```

Pointer

```
score_ptr

↓

1000
```

Expression

```
score_ptr+2

↓

1008
```

Dereferencing

```
*(score_ptr+2)

↓

89
```

---

# Common Mistakes

## Mistake 1

Thinking

```cpp
pointer+1
```

moves one byte.

Wrong.

It moves one element.

---

## Mistake 2

Confusing

```cpp
pointer
```

with

```cpp
*pointer
```

Remember

```
pointer

↓

Address
```

```
*pointer

↓

Value
```

---

## Mistake 3

Writing

```cpp
*(pointer+100)
```

without checking array bounds.

This produces Undefined Behavior.

---

## Mistake 4

Thinking

```cpp
sizeof(pointer)
```

returns array size.

It does not.

---

## Mistake 5

Trying to assign a new address to an array.

Wrong

```cpp
scores++;
```

Arrays are **not modifiable lvalues**.

Pointers may move.

Arrays cannot.

---

# Interview Questions

### Why does `scores` print an address?

Because the array name decays into a pointer to its first element.

---

### What does `*(scores+2)` mean?

Read the third element of the array.

---

### What is the difference between

```cpp
scores[2]
```

and

```cpp
*(scores+2)
```

None.

They are identical.

---

### Why is `sizeof(scores)` different from `sizeof(score_ptr)`?

Because one is the whole array,

the other is only a pointer.

---

### Can arrays move?

No.

Pointers move.

Arrays do not.

---

# Real-Life Usage

Pointer arithmetic is heavily used in

- Operating Systems
- Embedded Programming
- Device Drivers
- Game Engines
- Image Processing
- Computer Graphics
- CUDA Programming
- Scientific Computing
- ROOT Framework
- Geant4
- Numerical Simulations

Even STL iterators internally behave much like pointers.

---

# Key Takeaways

- Pointer arithmetic advances by **`sizeof(type)`**, not by one byte.
- `array[index]` and `*(array + index)` are exactly equivalent.
- `pointer[index]` and `*(pointer + index)` are also equivalent.
- Array names usually decay to pointers, but arrays themselves are **not pointers**.
- `sizeof(array)` returns the total array size in bytes, while `sizeof(pointer)` returns only the size of the address stored by the pointer.
- Arrays cannot be incremented or reassigned, but pointers can.
- Mastering the relationship between arrays and pointers is essential for dynamic memory allocation, function parameters, C-style strings, and low-level systems programming.