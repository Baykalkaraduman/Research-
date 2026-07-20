# Pointer Arithmetic in C++
## Part 1 — Pointer Arithmetic Fundamentals

---

# Introduction

Pointer arithmetic is one of the most powerful features of C++, allowing programmers to navigate memory efficiently. Unlike ordinary arithmetic on integers, pointer arithmetic is **type-aware**, meaning the compiler automatically adjusts memory addresses based on the size of the data type being pointed to.

Understanding pointer arithmetic is essential before learning:

- Dynamic arrays
- C-style strings
- Iterators
- STL containers
- Dynamic memory allocation
- Linked Lists
- Trees
- Graphs

If you understand this topic well, most advanced C++ pointer concepts become much easier.

---

# What is Pointer Arithmetic?

A pointer stores a **memory address**.

Example:

```cpp
int scores[]{100,95,89,68,-1};

int* ptr{scores};
```

Memory representation:

```
Address        Value

0x1000  --->   100
0x1004  --->    95
0x1008  --->    89
0x100C  --->    68
0x1010  --->    -1
```

Initially,

```
ptr
 ↓
0x1000
```

The pointer is pointing to the first integer.

---

# Why Can We Add Numbers to a Pointer?

Suppose we write

```cpp
ptr++;
```

Many beginners think the pointer moves one byte.

This is incorrect.

Instead, the compiler knows that

```cpp
ptr
```

is an

```cpp
int*
```

Since

```
sizeof(int) == 4 bytes
```

the pointer moves **4 bytes**, not 1.

Memory becomes

```
Before

ptr
 ↓
100
95
89

After ptr++

      ptr
       ↓
100
95
89
```

---

# General Rule

Pointer arithmetic follows this formula:

```
pointer + n

=

Current Address + n × sizeof(type)
```

Examples:

### int*

```
+1

↓

4 bytes
```

### double*

```
+1

↓

8 bytes
```

### char*

```
+1

↓

1 byte
```

The compiler automatically performs this calculation.

---

# Traversing an Array

One of the most common uses of pointer arithmetic is traversing arrays.

Example:

```cpp
int scores[]{100,95,89,68,-1};

int* score_ptr{scores};

while(*score_ptr != -1)
{
    cout << *score_ptr << endl;
    score_ptr++;
}
```

Output

```
100

95

89

68
```

---

# Sentinel Values

Notice the last element

```cpp
-1
```

This is called a **sentinel value**.

A sentinel is a special marker that indicates

> "Stop reading here."

Instead of storing

```
size = 4
```

the program simply checks

```cpp
while(*ptr != -1)
```

Once it encounters

```
-1
```

the loop terminates.

---

# Why Use Sentinel Values?

Advantages:

- No separate size variable
- Easy traversal
- Common in C programming
- Used in many older APIs

Examples include:

- C-style strings (`'\0'`)
- EOF markers
- Null pointers
- Sentinel nodes in linked lists

---

# Pointer Arithmetic Step by Step

Suppose

```cpp
scores[]{100,95,89,68,-1}
```

Memory

```
100
95
89
68
-1
```

Iteration 1

```
ptr

↓

100
```

Print

```
100
```

Move pointer

```
ptr++
```

---

Iteration 2

```
ptr

↓

95
```

Print

```
95
```

---

Iteration 3

```
ptr

↓

89
```

Print

```
89
```

---

Iteration 4

```
ptr

↓

68
```

Print

```
68
```

---

Iteration 5

```
ptr

↓

-1
```

Condition becomes

```
false
```

Loop ends.

---

# Pointer Increment Operators

The following statements are valid.

```cpp
ptr++;
```

Move forward one element.

---

```cpp
++ptr;
```

Also move forward one element.

Difference?

Only evaluation order.

When used alone,

they behave identically.

---

# Post-Increment Dereference

This expression often confuses beginners.

```cpp
*ptr++
```

Many people read it as

```
(*ptr)++
```

That is WRONG.

Operator precedence tells us

```
Postfix ++

↓

Higher priority

↓

Dereference *
```

Therefore,

the compiler interprets

```cpp
*ptr++
```

as

```cpp
*(ptr++)
```

NOT

```cpp
(*ptr)++
```

---

# What Happens Internally?

Suppose

```
ptr

↓

100
95
89
```

Expression

```cpp
*ptr++
```

Steps

1. Read the value

```
100
```

2. Return it

3. Move the pointer

Result

```
ptr

↓

95
89
```

The pointer moved.

The value did **NOT** change.

---

# Expanded Form

This

```cpp
cout << *ptr++;
```

is equivalent to

```cpp
cout << *ptr;

ptr++;
```

This is why it is extremely popular inside loops.

---

# A Cleaner Loop

Instead of writing

```cpp
while(*ptr!=-1)
{
    cout<<*ptr<<endl;
    ptr++;
}
```

many C++ programmers write

```cpp
while(*ptr!=-1)
    cout<<*ptr++<<endl;
```

Exactly the same result.

Less code.

---

# Pointer Arithmetic on Different Types

Suppose

```cpp
char* p;
```

Increment

```
p++
```

moves

```
1 byte
```

---

Suppose

```cpp
double* p;
```

Increment

```
p++
```

moves

```
8 bytes
```

The compiler always knows the correct amount.

---

# Common Beginner Mistakes

## Mistake 1

Thinking

```cpp
ptr++
```

adds one byte.

Wrong.

It adds

```
sizeof(type)
```

bytes.

---

## Mistake 2

Forgetting to stop.

This

```cpp
while(true)
```

may walk beyond the array,

causing **Undefined Behavior**.

Always have a stopping condition.

---

## Mistake 3

Removing the sentinel.

Without

```
-1
```

the loop has no idea where to stop.

---

## Mistake 4

Dereferencing an invalid pointer.

Never write

```cpp
ptr++;

cout<<*ptr;
```

unless you know the pointer is still inside valid memory.

---

# Summary

✔ Pointer arithmetic moves by **elements**, not bytes.

✔ The compiler automatically uses `sizeof(type)`.

✔ `ptr++` moves to the next object.

✔ Sentinel values provide a convenient stopping condition.

✔ `*ptr++` is interpreted as `*(ptr++)`.

✔ Pointer arithmetic is fundamental for arrays, C-style strings, dynamic memory, and the STL.

---

# Coming in Part 2

In the next section, we will cover:

- Pointer comparison (`p1 == p2`)
- Value comparison (`*p1 == *p2`)
- Pointer subtraction
- Character pointer distance
- `(*ptr)++`
- `++*ptr`
- `*(++ptr)`
- Operator precedence table
- Memory diagrams
- Interview questions
- Common pitfalls and best practices

# Pointer Arithmetic in C++
## Part 2 — Pointer Comparison, Pointer Difference & Advanced Expressions

---

# Pointer Comparison

One of the most misunderstood concepts is comparing pointers.

Consider the following code:

```cpp
string s1{"Frank"};
string s2{"Frank"};
string s3{"James"};

string *p1{&s1};
string *p2{&s2};
string *p3{&s1};
```

Memory visualization:

```
Address          Object

0x1000 --------> "Frank"   (s1)
0x2000 --------> "Frank"   (s2)
0x3000 --------> "James"   (s3)

p1 ----> 0x1000
p2 ----> 0x2000
p3 ----> 0x1000
```

Notice that although **s1** and **s2** contain exactly the same text, they are different objects occupying different memory locations.

---

# Comparing Pointer Addresses

```cpp
cout << (p1 == p2);
```

Result

```
false
```

Why?

Because

```
0x1000 != 0x2000
```

Pointers compare **addresses**, not values.

---

Now,

```cpp
cout << (p1 == p3);
```

Result

```
true
```

because

```
0x1000 == 0x1000
```

Both pointers refer to the exact same object.

---

# Comparing Values

If we dereference the pointers

```cpp
cout << (*p1 == *p2);
```

Result

```
true
```

Now the comparison becomes

```
"Frank"

==

"Frank"
```

The addresses no longer matter.

---

Changing

```cpp
p3 = &s3;
```

produces

```
p3

↓

James
```

Now

```cpp
*p1 == *p3
```

becomes

```
Frank

==

James
```

Result

```
false
```

---

# Rule to Remember

```
Pointer comparison

↓

Compares Addresses
```

```
Dereferenced pointer comparison

↓

Compares Values
```

Never confuse these two operations.

---

# Pointer Subtraction

Pointer subtraction tells us the number of **elements** between two pointers.

Example

```cpp
char name[]{"Frank"};

char *p1{&name[0]};
char *p2{&name[3]};

cout << p2 - p1;
```

Output

```
3
```

---

Memory

```
Index

0 1 2 3 4

F r a n k
^     ^
p1    p2
```

Distance

```
3 characters
```

Notice

```
NOT bytes

NOT addresses

ELEMENTS
```

---

# Why Does Pointer Subtraction Work?

Suppose

```
Address

1000 F
1001 r
1002 a
1003 n
1004 k
```

Mathematically

```
1003

-

1000

=

3
```

Since char occupies one byte,

the result is

```
3 elements
```

---

Now imagine

```cpp
int numbers[5];
```

Memory

```
1000
1004
1008
1012
1016
```

Subtracting

```
1012

-

1000

=

12 bytes
```

Compiler divides automatically

```
12 / sizeof(int)

=

12 / 4

=

3 elements
```

This is why pointer subtraction always returns **element distance**, not byte distance.

---

# Pointer Arithmetic Rules

Allowed

```cpp
ptr++
```

```cpp
ptr--
```

```cpp
ptr + n
```

```cpp
ptr - n
```

```cpp
ptr2 - ptr1
```

---

Not Allowed

```cpp
ptr * 5
```

```cpp
ptr / 3
```

```cpp
ptr % 2
```

Pointers only support arithmetic that makes sense in memory.

---

# Understanding Operator Precedence

This is probably the most confusing topic.

Let's examine each expression carefully.

---

## Expression 1

```cpp
*ptr++
```

Compiler reads

```cpp
*(ptr++)
```

Meaning

1. Read current value

2. Move pointer

Memory

```
Before

↓

100 95 89

After

     ↓

100 95 89
```

Returned value

```
100
```

Pointer now points to

```
95
```

---

## Expression 2

```cpp
(*ptr)++
```

Meaning

Increase the VALUE.

Pointer never moves.

Memory

Before

```
↓

100 95 89
```

After

```
↓

101 95 89
```

Pointer stayed.

Data changed.

---

## Expression 3

```cpp
++*ptr
```

Compiler reads

```cpp
++(*ptr)
```

Meaning

Increase value

THEN

return new value.

Memory

```
100

↓

101
```

Returned

```
101
```

---

## Expression 4

```cpp
*(++ptr)
```

Meaning

Move pointer first.

Then read new value.

Memory

Before

```
↓

100 95 89
```

Move pointer

```
     ↓

100 95 89
```

Returned

```
95
```

---

# Quick Comparison Table

| Expression | Pointer Moves | Value Changes |
|------------|---------------|---------------|
| `*ptr++` | ✅ | ❌ |
| `*(ptr++)` | ✅ | ❌ |
| `(*ptr)++` | ❌ | ✅ |
| `++(*ptr)` | ❌ | ✅ |
| `*(++ptr)` | ✅ | ❌ |

This table is worth memorizing.

---

# Pointer Arithmetic Formula

Always remember

```
pointer + n

=

Current Address

+

n × sizeof(type)
```

Examples

```
int*

↓

+4 bytes
```

```
double*

↓

+8 bytes
```

```
char*

↓

+1 byte
```

---

# Common Interview Questions

## Question

Does

```cpp
ptr++
```

increase the address by one byte?

Answer

```
No.

It increases by sizeof(type).
```

---

## Question

What does

```cpp
p1 == p2
```

compare?

Answer

```
Addresses.
```

---

## Question

What does

```cpp
*p1 == *p2
```

compare?

Answer

```
Values.
```

---

## Question

What does

```cpp
ptr2 - ptr1
```

return?

Answer

```
Number of elements between the two pointers.
```

---

# Common Beginner Mistakes

## Mistake 1

Confusing

```cpp
*ptr++
```

with

```cpp
(*ptr)++
```

They are completely different.

---

## Mistake 2

Comparing pointers when you intended to compare values.

Wrong

```cpp
p1 == p2
```

Correct

```cpp
*p1 == *p2
```

---

## Mistake 3

Using pointer subtraction on unrelated arrays.

Pointer subtraction is only valid for pointers referring to elements within the same array (or one past the end). Otherwise, the behavior is undefined.

---

## Mistake 4

Walking past the end of an array.

```cpp
ptr++;
```

is safe **only while the pointer still refers to valid elements**.

Dereferencing an out-of-bounds pointer causes undefined behavior.

---

# Best Practices

✔ Always know where your pointer points.

✔ Never dereference an invalid pointer.

✔ Use pointer arithmetic only when necessary.

✔ Prefer range-based `for` loops or STL iterators in modern C++ unless pointer arithmetic is specifically required.

✔ When reading legacy C/C++ code, recognize expressions like `*ptr++` immediately.

---

# Final Summary

Pointer arithmetic is one of the fundamental mechanisms behind arrays and dynamic memory in C++.

The key ideas are:

- A pointer stores an address.
- Pointer arithmetic advances by **elements**, not bytes.
- The compiler automatically scales movement using `sizeof(type)`.
- Comparing pointers compares **addresses**.
- Comparing dereferenced pointers compares **values**.
- Pointer subtraction returns the number of elements between two pointers.
- Expressions such as `*ptr++`, `(*ptr)++`, `++(*ptr)`, and `*(++ptr)` have different meanings because of operator precedence.

Mastering these concepts makes later topics—dynamic arrays, C-style strings, iterators, linked lists, trees, and many STL algorithms—much easier to understand.

> **Key takeaway:** Always ask yourself two questions when reading pointer code:
>
> 1. **Does the pointer move?**
> 2. **Does the value change?**
>
> If you can answer those correctly, you understand pointer arithmetic.