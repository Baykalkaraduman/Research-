# C++ — Operator Overloading

> [!abstract] Goal
> Operator overloading allows user-defined classes to behave more naturally, similar to built-in C++ types.
>
> In this project, operator overloading is demonstrated using a custom `Mystring` class.

---

## 1. What Is Operator Overloading?

C++ allows us to redefine the behavior of operators for our own classes.

For example, with ordinary built-in types:

```cpp
int a{10};
int b{20};

int c = a + b;
```

The `+` operator already knows how to work with integers.

But if we create our own class:

```cpp
Mystring first{"Hello"};
Mystring second{" World"};

Mystring result = first + second;
```

C++ does not automatically know what `+` should mean for two `Mystring` objects.

We can therefore define:

```cpp
Mystring operator+(const Mystring &rhs) const;
```

Now the class determines what `+` means.

---

# 2. Operators Used in This Project

The `Mystring` class currently overloads:

| Operator  | Purpose                        |
| --------- | ------------------------------ |
| `==`      | Compare two `Mystring` objects |
| unary `-` | Convert a string to lowercase  |
| `+`       | Concatenate two strings        |

The class also contains the special member functions:

| Function         | Purpose                                                         |
| ---------------- | --------------------------------------------------------------- |
| Copy constructor | Create a new object by copying another object                   |
| Move constructor | Transfer resources from another object                          |
| Copy assignment  | Copy an existing object's contents into another existing object |
| Move assignment  | Transfer resources between existing objects                     |
| Destructor       | Release dynamically allocated memory                            |

---

# 3. Operator Function General Structure

An overloaded operator is essentially a special member function.

For example:

```cpp
bool operator==(const Mystring &rhs) const;
```

The operator itself becomes the function name:

```cpp
operator==
```

Similarly:

```cpp
operator+
operator-
operator=
```

The `operator` keyword tells C++ that this is an overloaded operator function.

---

# 4. `const Mystring &rhs`

Consider:

```cpp
Mystring operator+(const Mystring &rhs) const;
```

There are two different `const`s here.

## 4.1 `const Mystring &rhs`

This means:

* `rhs` is passed by reference
* no unnecessary copy is created
* the function promises not to modify `rhs`

For example:

```cpp
Mystring a{"Hello"};
Mystring b{"World"};

a + b;
```

Inside the function:

```cpp
rhs
```

refers to `b`.

Because it is:

```cpp
const Mystring &rhs
```

the function cannot modify `b`.

---

## 4.2 The final `const`

The final:

```cpp
const
```

belongs to the current object.

For example:

```cpp
Mystring operator+(const Mystring &rhs) const;
```

means:

> This operation does not modify the current `Mystring` object.

So:

```cpp
first + second;
```

does not modify `first`.

This is an important distinction:

```cpp
const Mystring &rhs
```

protects the **right-hand-side object**.

```cpp
... operator+(...) const
```

protects the **current object** (`*this`).

---

# 5. Equality Operator `==`

## Declaration

```cpp
bool operator==(const Mystring &rhs) const;
```

## Purpose

Normally:

```cpp
int a{10};
int b{10};

if (a == b)
```

compares values.

For our class:

```cpp
Mystring first{"Frank"};
Mystring second{"Frank"};

if (first == second)
```

we want to compare the **contents** of the strings.

---

## Important: Pointer Comparison

The class stores:

```cpp
char *str;
```

Therefore this would be wrong:

```cpp
str == rhs.str
```

because it compares the **addresses** stored in the pointers.

Two different dynamically allocated strings may contain the same characters but have different addresses.

Example conceptually:

```text
first.str  ---> "Frank"
                  ^
second.str ---> "Frank"
```

The addresses are different even though the contents are identical.

Therefore we use:

```cpp
std::strcmp(str, rhs.str)
```

---

## Implementation

```cpp
bool Mystring::operator==(const Mystring &rhs) const
{
    return (std::strcmp(str, rhs.str) == 0);
}
```

`strcmp()` returns:

```text
0       -> strings are identical
non-zero -> strings are different
```

Therefore:

```cpp
return (std::strcmp(str, rhs.str) == 0);
```

converts the result into a `bool`.

---

## Usage

```cpp
Mystring larry{"Larry"};
Mystring moe{"Moe"};

if (larry == moe)
    cout << "Equal\n";
else
    cout << "Different\n";
```

Output:

```text
Different
```

And:

```cpp
Mystring larry2{"Larry"};

if (larry == larry2)
    cout << "Equal\n";
```

Output:

```text
Equal
```

---

# 6. Unary Minus Operator `-`

This project gives unary `-` a custom meaning.

Instead of performing mathematical negation:

```cpp
-x
```

we use:

```cpp
-name
```

to convert a string to lowercase.

---

## Declaration

```cpp
Mystring operator-() const;
```

Notice that there is **no parameter**.

Why?

Because this is a **unary** operator.

Unary means:

```cpp
-name;
```

only requires one operand.

Compare:

```cpp
a + b;
```

which has two operands and is therefore binary.

---

## Example

```cpp
Mystring upper{"THIS IS A TEST"};

Mystring lower = -upper;
```

Result:

```text
upper -> "THIS IS A TEST"
lower -> "this is a test"
```

The original object remains unchanged.

---

# 7. Why Is Unary `-` `const`?

The declaration is:

```cpp
Mystring operator-() const;
```

The operation creates a new object instead of modifying the current object.

Therefore:

```cpp
upper
```

should remain unchanged.

Conceptually:

```text
upper
  |
  | operator-
  v
new Mystring
```

The original object is read, not modified.

Therefore:

```cpp
const
```

is appropriate.

---

# 8. Implementation of Unary `-`

First, temporary memory is allocated:

```cpp
char *buffer = new char[std::strlen(str) + 1];
```

The `+1` is required for:

```cpp
'\0'
```

the null terminator of a C-style string.

---

## Copy the original string

```cpp
std::strcpy(buffer, str);
```

Now `buffer` contains a copy of the original string.

---

## Convert characters

```cpp
for (size_t i = 0; i < std::strlen(buffer); i++)
{
    buffer[i] = std::tolower(buffer[i]);
}
```

Each character is passed through:

```cpp
std::tolower()
```

For example:

```text
'H' -> 'h'
'E' -> 'e'
'L' -> 'l'
```

---

## Construct a new object

```cpp
Mystring temp{buffer};
```

The constructor creates a new `Mystring`.

---

## Release temporary memory

Because we used:

```cpp
new[]
```

we must use:

```cpp
delete[]
```

```cpp
delete[] buffer;
```

---

## Return the new object

```cpp
return temp;
```

Modern C++ may use:

* Return Value Optimization (RVO)
* Move construction

instead of performing an unnecessary deep copy.

---

# 9. Concatenation Operator `+`

## Declaration

```cpp
Mystring operator+(const Mystring &rhs) const;
```

This allows:

```cpp
Mystring first{"Hello"};
Mystring second{" World"};

Mystring sentence = first + second;
```

Result:

```text
Hello World
```

---

# 10. Why Does `+` Return a New Object?

The built-in `+` operator normally produces a new value.

For example:

```cpp
int a{10};
int b{20};

int c = a + b;
```

`a` and `b` are not changed.

We follow the same idea:

```cpp
Mystring result = first + second;
```

Neither:

```cpp
first
```

nor:

```cpp
second
```

is modified.

Instead:

```text
first  +  second
   \       /
    \     /
     new object
```

is created.

---

# 11. Building the Concatenated String

First calculate the required size:

```cpp
char *buffer = new char[
    std::strlen(str)
    + std::strlen(rhs.str)
    + 1
];
```

The final `+1` is for:

```cpp
'\0'
```

---

## Copy the first string

```cpp
std::strcpy(buffer, str);
```

Example:

```text
buffer = "Hello"
```

---

## Append the second string

```cpp
std::strcat(buffer, rhs.str);
```

Now:

```text
buffer = "Hello World"
```

---

## Create the result object

```cpp
Mystring temp{buffer};
```

The `Mystring` constructor creates its own dynamically allocated string.

---

## Delete the temporary buffer

```cpp
delete[] buffer;
```

The temporary buffer is no longer needed.

The returned `Mystring` owns its own memory.

---

# 12. Operator Chaining

One of the useful properties of returning an object from an operator is **operator chaining**.

Example:

```cpp
Mystring excited = first + second + Mystring{"!!!"};
```

Conceptually this happens as:

```text
first + second
      |
      v
"Hello World"

"Hello World" + "!!!"
      |
      v
"Hello World!!!"
```

The first `+` produces a `Mystring`.

That resulting object can then participate in another `+`.

This is why the return type:

```cpp
Mystring
```

is important.

---

# 13. Operator Overloading and `this`

Inside a member operator function, the current object is accessible through:

```cpp
this
```

For example:

```cpp
first + second;
```

can conceptually be thought of as:

```cpp
first.operator+(second);
```

Inside the function:

```cpp
this
```

points to:

```cpp
first
```

and:

```cpp
rhs
```

refers to:

```cpp
second
```

So:

```cpp
str
```

belongs to the current object, while:

```cpp
rhs.str
```

belongs to the right-hand-side object.

---

# 14. Member Operator vs Free Operator

A member operator such as:

```cpp
Mystring operator+(const Mystring &rhs) const;
```

belongs to the `Mystring` class.

It can therefore directly access private members such as:

```cpp
str
```

A member operator is conceptually called as:

```cpp
first.operator+(second);
```

For this project, this approach keeps the implementation simple and closely connected to the class.

---

# 15. Operators Are Still Functions

Operator overloading does **not** create a completely different programming mechanism.

For example:

```cpp
first + second
```

is essentially a more readable syntax for an operator function.

Likewise:

```cpp
first == second
```

uses:

```cpp
operator==
```

and:

```cpp
-first
```

uses:

```cpp
operator-
```

The operator syntax is simply a convenient interface.

---

# 16. `const` and Operator Overloading

A useful rule:

### If the operator should not modify the current object

Consider:

```cpp
const
```

For example:

```cpp
bool operator==(const Mystring &rhs) const;
```

and:

```cpp
Mystring operator+(const Mystring &rhs) const;
```

and:

```cpp
Mystring operator-() const;
```

All three operations only read the current object.

Therefore they are marked `const`.

---

# 17. Assignment Operators Are Different

Assignment operators behave differently.

For example:

```cpp
Mystring a{"Hello"};
Mystring b{"World"};

a = b;
```

The left-hand-side object:

```cpp
a
```

**must be modified**.

Therefore assignment operators cannot be:

```cpp
const
```

The current object changes.

For this project:

```cpp
Mystring &operator=(const Mystring &rhs);
```

and:

```cpp
Mystring &operator=(Mystring &&rhs);
```

are non-const member functions.

---

# 18. Returning `*this`

Assignment operators return:

```cpp
Mystring&
```

and normally finish with:

```cpp
return *this;
```

Why?

Because this allows assignment chaining:

```cpp
a = b = c;
```

The assignment:

```cpp
b = c;
```

returns `b`.

Then:

```cpp
a = b;
```

can continue.

This is similar to how built-in assignment behaves.

---

# 19. Copy Assignment vs Copy Constructor

These are easy to confuse.

## Copy Constructor

```cpp
Mystring b{a};
```

A **new object** is being created.

Therefore:

```cpp
Mystring(const Mystring &source);
```

is called.

---

## Copy Assignment

```cpp
Mystring b;

b = a;
```

`b` already exists.

Therefore:

```cpp
Mystring& operator=(const Mystring &rhs);
```

is called.

### Key distinction

```text
Copy Constructor
    ↓
new object is created

Copy Assignment
    ↓
existing object is replaced
```

---

# 20. Move Construction vs Move Assignment

The same distinction applies to move operations.

### Move Constructor

```cpp
Mystring b{std::move(a)};
```

A new object is created.

### Move Assignment

```cpp
b = std::move(a);
```

Both objects already exist.

The resources of `a` are transferred into `b`.

---

# 21. Why Operator Overloading Matters

Operator overloading allows classes to have interfaces that feel natural.

Without operator overloading:

```cpp
Mystring result = first.concatenate(second);
```

With operator overloading:

```cpp
Mystring result = first + second;
```

Without:

```cpp
if (first.is_equal(second))
```

With:

```cpp
if (first == second)
```

The second form is often easier to read because it resembles normal C++ syntax.

---

# 22. Important Design Rule

Operator overloading should make an operator behave **intuitively**.

Good:

```cpp
first + second
```

meaning:

```text
concatenate strings
```

Good:

```cpp
first == second
```

meaning:

```text
compare their contents
```

Less desirable would be giving an operator a completely unrelated meaning that surprises the reader.

The goal is not:

> "Can I overload this operator?"

The better question is:

> "Does this operator naturally represent the operation I want?"

---

# 23. Current `Mystring` Operator Summary

| Operator  | Type   | Returns     | Modifies current object? | `const`? |
| --------- | ------ | ----------- | ------------------------ | -------- |
| `==`      | Binary | `bool`      | No                       | Yes      |
| unary `-` | Unary  | `Mystring`  | No                       | Yes      |
| `+`       | Binary | `Mystring`  | No                       | Yes      |
| copy `=`  | Binary | `Mystring&` | Yes                      | No       |
| move `=`  | Binary | `Mystring&` | Yes                      | No       |

---

# 24. Mental Model

A useful way to think about the operators in this project:

```text
                Mystring
                   |
       ┌───────────┼───────────┐
       │           │           │
       ==          +           -
       │           │           │
   compare      combine     transform
       │           │           │
      bool      new object   new object
```

Assignment operators are different:

```text
             Assignment
                 |
          ┌──────┴──────┐
          │             │
       copy           move
          │             │
     duplicate       transfer
      resource        resource
```

---

# 25. What To Remember

> [!important]
>
> ### Core Rules

1. Operator overloading allows user-defined classes to work naturally with operators.
2. `operator==` compares objects according to the class's definition of equality.
3. `operator+` normally creates and returns a new result.
4. Unary operators have one operand.
5. Binary operators have two operands.
6. `const Mystring &rhs` prevents modification of the right-hand-side object and avoids an unnecessary copy.
7. A final `const` prevents modification of the current object.
8. `operator=` modifies the current object, so it cannot be `const`.
9. Returning `*this` from assignment operators enables chaining.
10. `first + second` is essentially an operator-function call involving `first` and `second`.
11. Operator overloading should make code more natural, not more confusing.
12. When dynamically allocated memory is involved, operator implementations must respect the class's resource-management rules.

---

# 26. Connection to the `Particle` Project

The same ideas can be applied to the `Particle` class.

Possible future operators include:

```cpp
particle1 == particle2
```

to compare particles.

Or:

```cpp
particle3 = particle1;
```

using copy assignment.

Or:

```cpp
particle3 = std::move(particle1);
```

using move assignment.

Later, after inheritance and polymorphism are introduced, operator overloading can become even more interesting.

For example, a particle-physics-inspired class might eventually support operations representing:

```text
Particle + Particle
Particle == Particle
Particle != Particle
Particle << output stream
```

The important part is that the operator should represent a meaningful operation for the class.

---

# 27. Current Learning Progression

The current progression of the project is approximately:

```text
Classes & Objects
        ↓
Constructors
        ↓
Destructors
        ↓
Encapsulation
        ↓
Getters / Setters
        ↓
Static Members
        ↓
Dynamic Memory
        ↓
Copy Constructor
        ↓
Move Constructor
        ↓
Copy Assignment
        ↓
Move Assignment
        ↓
Operator Overloading
        ↓
Inheritance
        ↓
Polymorphism
```

This progression is especially useful because the later topics build directly on the earlier ones.

---

# 28. Practice Checklist

Before moving forward, make sure you can explain these without looking at the code:

* [ ] What does `operator` mean in a function declaration?
* [ ] What is the difference between unary and binary operators?
* [ ] Why does `operator==` return `bool`?
* [ ] Why does `operator+` return a new `Mystring`?
* [ ] Why is `operator+` marked `const`?
* [ ] Why is `operator==` marked `const`?
* [ ] What is the difference between `const Mystring &rhs` and the final `const`?
* [ ] Why can `operator=` not be `const`?
* [ ] Why does an assignment operator return `Mystring&`?
* [ ] Why do we return `*this`?
* [ ] What is operator chaining?
* [ ] Why can't we compare `char*` strings with `==` when we want content equality?
* [ ] What does `strcmp()` return when strings are identical?
* [ ] Why does a C-style string require `'\0'`?
* [ ] Why does dynamically allocated temporary memory need `delete[]`?
* [ ] What is the difference between copy construction and copy assignment?
* [ ] What is the difference between move construction and move assignment?
* [ ] Why should overloaded operators have intuitive meanings?

---

> [!tip] Project Principle
> Keep expanding `Mystring` and `Particle` as training projects.
>
> The goal is not to recreate the entire C++ standard library or Geant4. The goal is to make each new C++ concept solve a real problem inside a small project.
>
> **Learn the language feature → implement it → test it → observe object lifetime → explain why it works.**
