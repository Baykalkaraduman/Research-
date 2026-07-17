# C-Style Strings

---

# Introduction

Before the introduction of the C++ `std::string` class, text was stored using **character arrays**.

These are known as **C-Style Strings** because they originate from the C programming language.

Although Modern C++ programs usually prefer `std::string`, understanding C-style strings is still important because many operating systems, embedded systems, scientific libraries, and legacy software continue to use them.

Examples include:

- POSIX APIs
- C Standard Library
- Embedded Systems
- CUDA
- ROOT
- Geant4
- Many Linux system calls

Therefore, every C++ programmer should understand how C-style strings work.

---

# What is a C-Style String?

A C-style string is simply an array of characters that ends with a special character called the **null terminator**.

Example

```cpp
char name[] = "Emir";
```

Memory representation

```
+----+----+----+----+----+
| E  | m  | i  | r  | \0 |
+----+----+----+----+----+
```

The character

```
'\0'
```

marks the end of the string.

Every function from `<cstring>` searches for this character to determine where the string ends.

Without it, the program would continue reading memory beyond the array, causing undefined behavior.

---

# Character Arrays

A C-style string is stored inside a character array.

```cpp
char first_name[20];
```

This reserves space for **20 characters**, not necessarily a 20-character word.

If the user enters

```
John
```

memory becomes

```
J o h n \0 ? ? ? ? ? ...
```

Only the first five positions are used.

The remaining memory is unused.

---

# Initialization

## Empty string

```cpp
char name[20]{};
```

All elements become

```
'\0'
```

This is the recommended way.

---

## Using a string literal

```cpp
char name[] {"Physics"};
```

The compiler automatically appends

```
'\0'
```

Memory

```
P h y s i c s \0
```

---

# Reading Input

Using

```cpp
cin >> name;
```

reads characters until the first whitespace.

Input

```
John Smith
```

Stored

```
John
```

Everything after the space is ignored.

---

## Reading an Entire Line

Use

```cpp
cin.getline(name,50);
```

Example

```cpp
char full_name[50];

cin.getline(full_name,50);
```

Now

```
John Smith
```

is stored completely.

---

# strlen()

Header

```cpp
#include <cstring>
```

Returns the length of the string.

```cpp
strlen(name);
```

Example

```
Physics
```

returns

```
7
```

Notice that the null terminator is **not counted**.

---

# sizeof() vs strlen()

Many beginners confuse these.

Example

```cpp
char name[20] {"Physics"};
```

```
sizeof(name)
```

returns

```
20
```

because the array occupies twenty bytes.

```
strlen(name)
```

returns

```
7
```

because only seven visible characters exist.

| sizeof() | strlen() |
|-----------|-----------|
| Array size in memory | Actual text length |
| Compile-time | Runtime |
| Counts unused memory | Stops at '\0' |

---

# strcpy()

Copies one string into another.

```cpp
strcpy(destination, source);
```

Example

```cpp
strcpy(full_name, first_name);
```

Result

```
full_name = first_name
```

The destination array must already have enough space.

---

# strcat()

Concatenates two strings.

```cpp
strcat(destination, source);
```

Example

```cpp
strcat(full_name," ");
strcat(full_name,last_name);
```

Result

```
John Smith
```

Again, enough memory must already exist.

---

# strcmp()

Compares two strings alphabetically.

```cpp
strcmp(a,b);
```

Returns

```
0
```

if equal.

Negative value

```
a < b
```

Positive value

```
a > b
```

Example

```cpp
strcmp("Apple","Banana")
```

returns a negative number.

---

# Character Functions

Header

```cpp
#include <cctype>
```

Useful functions include

---

## isalpha()

Checks whether a character is a letter.

```cpp
isalpha(c)
```

Returns

```
true
```

for

```
A
b
Z
```

---

## isdigit()

Checks whether the character is a digit.

```cpp
isdigit(c)
```

Returns true for

```
0
1
...
9
```

---

## toupper()

Converts a character to uppercase.

```cpp
toupper(c);
```

Example

```
physics
```

becomes

```
PHYSICS
```

---

## tolower()

Converts a character to lowercase.

```cpp
tolower(c);
```

Example

```
PHYSICS
```

becomes

```
physics
```

---

# Processing Characters

Since C-style strings are arrays,

they can be processed one character at a time.

Example

```cpp
for(size_t i{0}; i<strlen(name); ++i)
```

Inside the loop

```cpp
name[i]
```

refers to one individual character.

---

# Memory Layout

Example

```cpp
char word[] {"HELLO"};
```

Memory

```
Index

0 1 2 3 4 5

+---+---+---+---+---+----+
| H | E | L | L | O | \0 |
+---+---+---+---+---+----+
```

Every function from `<cstring>` searches until it finds

```
'\0'
```

---

# Advantages

- Extremely fast
- Very little overhead
- Compatible with C libraries
- Used by operating systems
- Required in many low-level APIs

---

# Disadvantages

- Fixed size
- Manual memory management
- Buffer overflow risks
- No automatic resizing
- Many functions are unsafe if used incorrectly

---

# C-Style Strings vs std::string

| C-Style | std::string |
|-----------|-------------|
| char[] | string |
| Fixed size | Dynamic size |
| Manual copying | Automatic |
| strcat() | + operator |
| strcpy() | = operator |
| strlen() | size() |
| Easy to overflow | Much safer |

Modern C++ strongly prefers `std::string`.

---

# Scientific Computing Notes

Although modern software often uses `std::string`, C-style strings remain common in scientific computing.

Examples include

- ROOT
- Geant4
- CUDA Runtime
- POSIX APIs
- MPI libraries
- Linux System Calls

Many APIs still expect

```cpp
char*
```

or

```cpp
const char*
```

instead of `std::string`.

Because of this, every scientific programmer should understand C-style strings.

---

# Common Mistakes

## Forgetting the null terminator

Without

```
'\0'
```

functions like `strlen()` continue reading memory.

---

## Array too small

```cpp
char name[5];

strcpy(name,"Physics");
```

This causes a buffer overflow.

---

## Using cin >>

```
John Smith
```

Only

```
John
```

is read.

Use

```cpp
getline()
```

instead.

---

## Forgetting cin.ignore()

After

```cpp
cin >> number;
```

the newline remains in the input buffer.

Always write

```cpp
cin.ignore();
```

before calling

```cpp
getline()
```

---

# Best Practices

✔ Initialize character arrays.

✔ Always allocate enough space.

✔ Prefer `cin.getline()` when spaces are possible.

✔ Prefer `std::string` in modern C++ unless a C API requires `char*`.

✔ Use `<cstring>` functions carefully.

---

# Summary

After completing this chapter you should understand

- What C-style strings are
- Why the null terminator is important
- Character arrays
- strlen()
- strcpy()
- strcat()
- strcmp()
- getline()
- Character processing
- toupper()
- tolower()
- isalpha()
- isdigit()
- Why Modern C++ prefers std::string

---

# Exercises

## Exercise 1

Create a character array that stores your name.

Print its length using `strlen()`.

---

## Exercise 2

Read a full name using `getline()`.

Convert every character to uppercase.

---

## Exercise 3

Ask the user for two words.

Compare them using `strcmp()`.

Display whether they are identical.

---

## Exercise 4

Count how many alphabetic characters exist inside a sentence.

Hint

Use

```cpp
isalpha()
```

---

## Exercise 5

Count how many digits appear inside

```
Physics2025
```

using

```cpp
isdigit()
```

---

## Exercise 6 (Challenge)

Create a program that asks for a full name.

Display

- number of letters
- number of digits
- uppercase version
- lowercase version

using only C-style string functions.