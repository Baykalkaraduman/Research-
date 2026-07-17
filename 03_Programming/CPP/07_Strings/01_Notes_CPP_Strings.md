# C++ `std::string`

---

# Introduction

`std::string` is the standard string class in Modern C++.

Unlike C-style strings (`char[]`), `std::string` automatically manages memory, resizes itself when necessary, and provides many built-in functions for manipulating text.

Because of its safety and flexibility, `std::string` should almost always be preferred over C-style strings in modern C++.

To use it, include

```cpp
#include <string>
```

---

# Why use std::string?

Suppose we want to store a person's name.

Using a C-style string

```cpp
char name[20];
```

Problems:

- Fixed size
- Manual memory management
- Requires null terminator
- Uses functions like `strcpy()` and `strlen()`

Using Modern C++

```cpp
std::string name;
```

Advantages

- Dynamic size
- Automatic memory management
- Easier syntax
- Rich member functions
- Much safer

---

# Creating Strings

Empty string

```cpp
std::string s1;
```

Initialized string

```cpp
std::string s2 {"Apple"};
```

Copy another string

```cpp
std::string s3 {s2};
```

Substring constructor

```cpp
std::string s4 {s2,0,3};
```

Result

```
App
```

Repeated character constructor

```cpp
std::string s5(10,'X');
```

Result

```
XXXXXXXXXX
```

---

# String Length

Use

```cpp
length()
```

or

```cpp
size()
```

Example

```cpp
std::string word {"Physics"};

std::cout << word.length();
```

Output

```
7
```

Unlike C-style strings, no null character search is required.

Length is stored internally.

---

# Accessing Characters

Using operator []

```cpp
word[0]
```

Example

```cpp
std::cout << word[0];
```

Output

```
P
```

---

Using `.at()`

```cpp
word.at(0);
```

Advantages

- Performs bounds checking
- Throws an exception if the index is invalid
- Safer while learning

Example

```cpp
std::cout << word.at(3);
```

Output

```
s
```

---

# Modifying Characters

Characters may be changed directly.

```cpp
std::string word {"Apple"};

word[0]='M';
```

Output

```
Mpple
```

Using `.at()`

```cpp
word.at(1)='o';
```

Output

```
Mople
```

Remember

Characters use

```cpp
'A'
```

not

```cpp
"A"
```

because a single character is different from a string.

---

# Comparing Strings

Unlike C-style strings,

`std::string`

supports comparison operators directly.

Example

```cpp
s1==s2
```

```cpp
s1!=s2
```

```cpp
s1<s2
```

```cpp
s1>s2
```

---

Example

```cpp
std::string a {"Apple"};
std::string b {"Banana"};

std::cout << (a<b);
```

Output

```
true
```

Comparison is performed lexicographically (dictionary order).

---

Uppercase vs Lowercase

```cpp
Apple

apple
```

These are **not equal**.

ASCII / Unicode ordering means

```
'A' < 'a'
```

Therefore

```cpp
"Apple" < "apple"
```

---

# Assigning Strings

Strings may be reassigned.

```cpp
std::string fruit;

fruit="Apple";
```

Later

```cpp
fruit="Watermelon";
```

The previous contents are replaced automatically.

---

Assigning another string

```cpp
std::string a {"Apple"};

std::string b;

b=a;
```

Now

```
b
```

contains

```
Apple
```

Both strings are independent.

Changing one does **not** change the other.

---

# Concatenation

Strings can be combined using

```cpp
+
```

Example

```cpp
std::string first {"Albert"};

std::string last {"Einstein"};

std::string full = first + " " + last;
```

Output

```
Albert Einstein
```

---

Appending text

```cpp
message += "!";
```

Example

```cpp
std::string msg {"Hello"};

msg += " World";
```

Output

```
Hello World
```

---

Important

This is valid

```cpp
std::string s="Hello";

s+="!";
```

But this is **not**

```cpp
"Hello"+"World"
```

because both operands are C-style string literals.

---

# Looping Through Strings

Traditional for loop

```cpp
for(size_t i{0};i<s.length();++i)
    std::cout<<s[i];
```

Output

```
Hello
```

---

Range-based for loop

```cpp
for(char c:s)
    std::cout<<c;
```

Output

```
Hello
```

This syntax is cleaner when every character will be processed.

---

# Character Functions

Character manipulation comes from

```cpp
#include <cctype>
```

Common functions

```cpp
toupper()
tolower()
isdigit()
isalpha()
isspace()
```

Example

```cpp
char c='a';

std::cout<<char(toupper(c));
```

Output

```
A
```

---

Uppercase conversion example

```cpp
for(char &c:text)
    c=toupper(c);
```

Output

```
THIS IS A TEST
```

Notice the use of

```cpp
char &
```

Without the reference (`&`), only copies of the characters would be modified.

---

# Common Member Functions (Part 1)

| Function | Purpose |
|-----------|---------|
| `length()` | Returns number of characters |
| `size()` | Same as `length()` |
| `at()` | Safe access |
| `operator[]` | Fast access |
| `+=` | Append |
| `+` | Concatenate |
| `=` | Assign |
| `empty()` | Checks whether the string is empty |

Example

```cpp
if(name.empty())
    std::cout<<"Empty!";
```

---

# Summary (Part 1)

After this section you should understand

- Why `std::string` is preferred over C-style strings
- Creating strings
- Different constructors
- Accessing characters
- Changing characters
- Comparing strings
- Assigning strings
- Concatenating strings
- Looping through characters
- Character manipulation using `<cctype>`
# Searching Inside Strings

One of the most useful string operations is searching.

The function used is

```cpp
find()
```

Syntax

```cpp
string.find(text);
```

It returns

- the index where the text begins
- or `string::npos` if the text cannot be found

Example

```cpp
std::string sentence {"The secret word is boo"};

size_t pos = sentence.find("secret");
```

Output

```
4
```

because `"secret"` starts at index 4.

---

## Checking if a word exists

```cpp
if(sentence.find("boo") != std::string::npos)
    std::cout << "Found!";
```

Output

```
Found!
```

---

## Searching from a specific position

```cpp
std::string text {"one two one two"};

text.find("one",5);
```

Output

```
8
```

The search begins at index 5.

---

# Extracting Part of a String

The function

```cpp
substr()
```

creates a new string from part of another string.

Syntax

```cpp
string.substr(start,length);
```

Example

```cpp
std::string sentence {"This is a test"};

std::cout << sentence.substr(0,4);
```

Output

```
This
```

---

Example

```cpp
std::cout << sentence.substr(5,2);
```

Output

```
is
```

---

Example

```cpp
std::cout << sentence.substr(10,4);
```

Output

```
test
```

---

# Inserting Characters

The function

```cpp
insert()
```

adds text at any position.

Syntax

```cpp
string.insert(index,text);
```

Example

```cpp
std::string word {"Oyun"};

word.insert(0,"K");
```

Output

```
KOyun
```

---

Another example

```cpp
std::string language {"C++"};

language.insert(0,"Modern ");
```

Output

```
Modern C++
```

---

# Erasing Characters

The function

```cpp
erase()
```

removes characters.

Syntax

```cpp
string.erase(start,length);
```

Example

```cpp
std::string text {"This is a test"};

text.erase(0,5);
```

Output

```
is a test
```

---

## Erasing everything

```cpp
text.clear();
```

Afterwards

```cpp
text.empty()
```

returns

```
true
```

---

# Replacing Text

One of the most useful functions is

```cpp
replace()
```

```cpp
std::string sentence {"I like apples"};

sentence.replace(7,6,"oranges");
```

Output

```
I like oranges
```

// added

---

# Appending Strings

Besides using

```cpp
+
```

there is another function

```cpp
append()
```

Example

```cpp
std::string s {"Hello"};

s.append(" World");
```

Output

```
Hello World
```

// added

---

# front() and back()

Just like vectors,

strings also have

```cpp
front()
```

and

```cpp
back()
```

Example

```cpp
std::string word {"Physics"};

std::cout << word.front();
```

Output

```
P
```

---

Example

```cpp
std::cout << word.back();
```

Output

```
s
```

// added

---

# Swapping Strings

Instead of copying,

two strings may exchange their contents.

```cpp
swap()
```

Example

```cpp
std::string first {"Apple"};

std::string second {"Banana"};

first.swap(second);
```

Result

```
first  -> Banana

second -> Apple
```

This operation is very efficient.

---

# Reading Entire Lines

Normal

```cpp
cin
```

stops at whitespace.

Example

Input

```
Albert Einstein
```

Using

```cpp
cin >> name;
```

stores only

```
Albert
```

---

Instead use

```cpp
getline(cin,name);
```

Example

```cpp
std::string full_name;

getline(cin,full_name);
```

Output

```
Albert Einstein
```

---

## Mixing cin and getline()

Very common beginner mistake.

```cpp
cin >> age;

getline(cin,name);
```

The newline remains inside the input buffer.

Correct solution

```cpp
cin >> age;

cin.ignore();

getline(cin,name);
```

// added

---

# Capacity vs Length

Many beginners think

```cpp
length()
```

and

```cpp
capacity()
```

are identical.

They are not.

```
length()
```

returns

```
actual characters
```

```
capacity()
```

returns

```
allocated memory
```

Example

```cpp
std::string text {"Physics"};

std::cout << text.length();
std::cout << text.capacity();
```

Capacity is usually larger than the current length.

This improves performance by reducing reallocations.

// added

---

# reserve()

Sometimes we already know a string will become very large.

```cpp
text.reserve(1000);
```

This allocates memory beforehand.

Useful in

- file processing
- scientific software
- log generation

// added

---

# String Memory Model

Unlike C-style strings,

`std::string`

owns its memory.

```
string

↓

allocated characters
```

When more space is needed,

the string automatically

- allocates larger memory
- copies old characters
- releases old memory

The programmer never calls

```cpp
new
```

or

```cpp
delete
```

---

# std::string vs C-style Strings

| C-style | std::string |
|----------|-------------|
| Fixed arrays | Dynamic |
| Uses null terminator | Stores size internally |
| Manual functions | Member functions |
| Error-prone | Much safer |
| Harder to concatenate | Easy using `+` |
| Easy buffer overflow | Much safer |

Modern C++ code almost always prefers

```cpp
std::string
```

---

# Best Practices

✔ Prefer `std::string` over `char[]`.

✔ Use `getline()` for complete sentences.

✔ Prefer `.at()` while learning.

✔ Use range-based for loops when processing characters.

✔ Use meaningful variable names.

✔ Reserve memory for very large strings.

✔ Use member functions instead of manual loops whenever possible.

---

# Common Mistakes

## Mixing `cin` and `getline()`

Always remember

```cpp
cin.ignore();
```

---

## Using `==` on C-style strings

Incorrect

```cpp
char a[20];
char b[20];

a==b
```

Correct

```cpp
strcmp(a,b)
```

For

```cpp
std::string
```

simply use

```cpp
a==b;
```

---

## Accessing invalid indices

Incorrect

```cpp
text[100];
```

Prefer

```cpp
text.at(100);
```

during development.

---

## Forgetting strings are case-sensitive

```cpp
Apple

apple
```

are different strings.

---

# Scientific Computing Notes

Strings appear everywhere in scientific software.

Examples include

- reading configuration files
- parsing detector geometry
- processing event names
- ROOT branch names
- Geant4 material names
- command-line arguments
- file paths
- CSV processing
- JSON parsing

Although scientific calculations mostly use numbers,

almost every program also processes large amounts of textual information using `std::string`.

---

# Summary

After completing this chapter you should understand

- Creating strings
- String constructors
- Character access
- String comparison
- Assignment
- Concatenation
- Character manipulation
- Looping through strings
- `substr()`
- `find()`
- `insert()`
- `erase()`
- `replace()`
- `append()`
- `swap()`
- `getline()`
- `front()` and `back()`
- `capacity()` and `reserve()`
- Memory management
- Why `std::string` is preferred over C-style strings

---

# Exercises

## Exercise 1

Ask the user for a full name.

Display

- first character
- last character
- length

---

## Exercise 2

Convert every letter of a string to uppercase.

---

## Exercise 3

Count how many vowels exist in a sentence.

---

## Exercise 4

Search for a word inside a sentence using `find()`.

Display whether it exists.

---

## Exercise 5

Extract the first word of a sentence using `substr()`.

---

## Exercise 6

Replace one word inside a sentence using `replace()`.

// added

---

## Exercise 7

Ask the user for a filename.

Determine whether it ends with

```
.txt
```

or

```
.csv
```

using string functions.

// added

---

## Exercise 8 (Challenge)

Read a complete sentence.

Display

- total characters
- total words
- uppercase version
- lowercase version
- longest word

using only `std::string` functions and loops.