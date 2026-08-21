# C++ Operator Overloading — Stream Insertion & Extraction

## 1. Overview

C++ allows us to overload the stream operators:

```cpp
<<
>>
```

This allows our custom classes to work naturally with:

```cpp
std::cout
std::cin
```

For example, instead of:

```cpp
larry.display();
```

we can write:

```cpp
std::cout << larry;
```

And instead of manually calling a setter:

```cpp
// complicated manual input
```

we can write:

```cpp
std::cin >> larry;
```

The important idea is that these operators are normally implemented as **non-member/global functions**.

---

# 2. Stream Insertion Operator `<<`

The insertion operator is used when an object is sent **to an output stream**.

```cpp
std::cout << larry;
```

The corresponding overloaded function is:

```cpp
std::ostream &operator<<(std::ostream &os, const Mystring &rhs)
{
    os << rhs.str;
    return os;
}
```

## Parameters

### `std::ostream &os`

This represents the output stream.

For example:

```cpp
std::cout
```

is an `std::ostream` object.

We use a reference because we want to operate on the existing stream rather than create a copy.

---

### `const Mystring &rhs`

This is the object being printed.

For example:

```cpp
std::cout << larry;
```

means that:

```cpp
larry
```

is passed as `rhs`.

It is:

```cpp
const
```

because printing the object should not modify it.

It is passed by reference because we do not need to copy the entire object.

---

# 3. Why Does `operator<<` Return `std::ostream&`?

The function returns:

```cpp
std::ostream&
```

instead of `void`.

This is what allows **stream chaining**:

```cpp
std::cout << larry << ", " << moe << std::endl;
```

Conceptually:

```cpp
(std::cout << larry) << ", "
```

The first operation returns the same stream:

```cpp
std::cout
```

so the next `<<` can continue working on it.

Therefore:

```cpp
return os;
```

is essential.

---

# 4. Why Is `operator<<` a Friend?

Our `Mystring` class contains:

```cpp
private:
    char *str;
```

The global function cannot normally access:

```cpp
rhs.str
```

because `str` is private.

Therefore the class declares:

```cpp
friend std::ostream &operator<<(std::ostream &os,
                                const Mystring &rhs);
```

This gives the global function permission to access the private data.

Then we can write:

```cpp
os << rhs.str;
```

without making `str` public.

---

# 5. Complete Insertion Operator

```cpp
std::ostream &operator<<(std::ostream &os, const Mystring &rhs)
{
    os << rhs.str;
    return os;
}
```

The flow is:

```text
std::cout << larry
       ↓
operator<<(std::cout, larry)
       ↓
os << rhs.str
       ↓
Larry
       ↓
return os
```

---

# 6. Stream Extraction Operator `>>`

The extraction operator is used when data is read **from an input stream**.

For example:

```cpp
std::cin >> curly;
```

The overloaded function is:

```cpp
std::istream &operator>>(std::istream &in, Mystring &rhs)
{
    char *buff = new char[1000];

    in >> buff;

    rhs = Mystring{buff};

    delete [] buff;

    return in;
}
```

---

# 7. Parameters of `operator>>`

The first parameter:

```cpp
std::istream &in
```

represents the input stream.

For example:

```cpp
std::cin
```

is an `std::istream`.

The second parameter:

```cpp
Mystring &rhs
```

represents the object that will receive the input.

Unlike `operator<<`, this parameter **cannot be const** because we need to modify the object.

For example:

```cpp
std::cin >> curly;
```

must change:

```cpp
curly
```

---

# 8. Why Does `operator>>` Return `std::istream&`?

Just like `operator<<`, the extraction operator returns the stream:

```cpp
return in;
```

This allows chaining:

```cpp
std::cin >> larry >> moe >> curly;
```

Conceptually:

```text
cin >> larry
     ↓
returns cin
     ↓
cin >> moe
     ↓
returns cin
     ↓
cin >> curly
```

Therefore returning the stream is what makes chained input possible.

---

# 9. Temporary Input Buffer

The example creates:

```cpp
char *buff = new char[1000];
```

This provides temporary storage for the incoming C-style string.

Then:

```cpp
in >> buff;
```

reads the input into the buffer.

For example, if the user enters:

```text
Larry
```

then:

```text
buff
 ↓
"Larry"
```

---

# 10. Converting the Buffer into Mystring

After reading:

```cpp
in >> buff;
```

the buffer contains a C-style string.

We then construct a `Mystring`:

```cpp
rhs = Mystring{buff};
```

This creates a temporary `Mystring` object and assigns it to `rhs`.

The assignment uses the previously implemented:

```cpp
Mystring::operator=(Mystring &&rhs)
```

when appropriate.

So the previously learned topics work together:

```text
operator>>
    ↓
temporary Mystring
    ↓
move/copy assignment
    ↓
rhs
```

---

# 11. Releasing the Temporary Buffer

The buffer was created using:

```cpp
new char[1000]
```

Therefore it must eventually be released with:

```cpp
delete [] buff;
```

The rule is:

```text
new       → delete
new[]     → delete[]
```

Since we used:

```cpp
new char[1000]
```

we use:

```cpp
delete [] buff;
```

---

# 12. Complete Extraction Operator

```cpp
std::istream &operator>>(std::istream &in, Mystring &rhs)
{
    char *buff = new char[1000];

    in >> buff;

    rhs = Mystring{buff};

    delete [] buff;

    return in;
}
```

The logical flow is:

```text
User enters text
       ↓
std::cin
       ↓
temporary char buffer
       ↓
Mystring object
       ↓
assignment to rhs
       ↓
temporary buffer deleted
       ↓
return std::cin
```

---

# 13. Friend Declarations

The header contains:

```cpp
friend std::ostream &operator<<(std::ostream &os,
                                const Mystring &rhs);

friend std::istream &operator>>(std::istream &in,
                                Mystring &rhs);
```

These declarations mean:

> These global functions are allowed to access the private members of `Mystring`.

They are **not member functions**.

This distinction is important.

### Member operator

```cpp
Mystring Mystring::operator+(const Mystring &rhs) const
```

belongs to `Mystring`.

### Global operator

```cpp
Mystring operator+(const Mystring &lhs,
                   const Mystring &rhs)
```

does not belong to `Mystring`.

It exists outside the class.

A `friend` declaration simply gives it access to private members.

---

# 14. Why `<<` and `>>` Are Usually Non-Member Operators

Consider:

```cpp
std::cout << larry;
```

The left-hand operand is:

```cpp
std::cout
```

which is an `std::ostream`.

If `operator<<` were a member of `Mystring`, the left operand would have to be a `Mystring` object.

But it isn't.

The actual structure is:

```text
std::cout << larry
     ↑        ↑
  ostream   Mystring
```

Therefore the operator is naturally implemented as a non-member function:

```cpp
operator<<(std::ostream&, const Mystring&)
```

The same reasoning applies to:

```cpp
std::cin >> larry;
```

because the left-hand operand is:

```cpp
std::cin
```

which is an `std::istream`.

---

# 15. Full Usage

The following becomes possible:

```cpp
Mystring larry{"Larry"};
Mystring moe{"Moe"};
Mystring curly;

std::cout << "Enter the third stooge's first name: ";
std::cin >> curly;

std::cout << "The three stooges are "
          << larry
          << ", "
          << moe
          << ", and "
          << curly
          << std::endl;
```

Instead of:

```cpp
larry.display();
moe.display();
curly.display();
```

we can treat `Mystring` almost like a built-in type.

---

# 16. Input Chaining

This:

```cpp
std::cin >> larry >> moe >> curly;
```

works because:

```cpp
operator>>(std::cin, larry)
```

returns:

```cpp
std::cin
```

Then:

```cpp
std::cin >> moe
```

can continue.

The same mechanism applies to:

```cpp
std::cout << larry << moe << curly;
```

because every `operator<<` returns the stream.

---

# 17. Important `const` Difference

Insertion:

```cpp
std::ostream &operator<<(std::ostream &os,
                         const Mystring &rhs)
```

uses:

```cpp
const Mystring &rhs
```

because printing should not modify the object.

Extraction:

```cpp
std::istream &operator>>(std::istream &in,
                         Mystring &rhs)
```

uses:

```cpp
Mystring &rhs
```

without `const` because input **must modify the object**.

Remember:

```text
<<  → read FROM object → object should be const

>>  → write INTO object → object cannot be const
```

---

# 18. Operator Overloading Progression

At this point, the `Mystring` project has demonstrated several important forms of operator overloading.

### Member operators

```cpp
Mystring &operator=(const Mystring &rhs);
Mystring &operator=(Mystring &&rhs);

Mystring operator-() const;

Mystring operator+(const Mystring &rhs) const;

bool operator==(const Mystring &rhs) const;
```

### Global operators

```cpp
bool operator==(const Mystring &lhs,
                const Mystring &rhs);

Mystring operator-(const Mystring &obj);

Mystring operator+(const Mystring &lhs,
                   const Mystring &rhs);
```

### Stream operators

```cpp
std::ostream &operator<<(std::ostream &os,
                         const Mystring &rhs);

std::istream &operator>>(std::istream &in,
                         Mystring &rhs);
```

This gives a useful progression:

```text
Member Operator
      ↓
Global Operator
      ↓
Friend Function
      ↓
Stream Insertion <<
      ↓
Stream Extraction >>
      ↓
Custom class behaves more like a built-in type
```

---

# 19. Core Rules to Remember

## `operator<<`

```cpp
std::ostream &operator<<(std::ostream &os,
                         const Mystring &rhs);
```

Remember:

* first parameter → output stream
* second parameter → object
* object should normally be `const`
* return `std::ostream&`
* usually implemented as a non-member
* often declared as `friend` when private data must be accessed

---

## `operator>>`

```cpp
std::istream &operator>>(std::istream &in,
                         Mystring &rhs);
```

Remember:

* first parameter → input stream
* second parameter → object being modified
* object cannot be `const`
* return `std::istream&`
* usually implemented as a non-member
* often declared as `friend` when private data must be accessed

---

# 20. Mental Model

Think of the operators as ordinary functions hidden behind convenient syntax.

Instead of:

```cpp
operator<<(std::cout, larry);
```

C++ lets us write:

```cpp
std::cout << larry;
```

Instead of:

```cpp
operator>>(std::cin, larry);
```

we write:

```cpp
std::cin >> larry;
```

The operator syntax is simply a much more natural interface.

---

# 21. Final Picture

Our `Mystring` class now behaves increasingly like a native C++ type:

```cpp
Mystring first{"Hello"};
Mystring second{"World"};

if (first == second)
    ...

Mystring lower = -first;

Mystring combined = first + second;

std::cout << combined;

std::cin >> first;
```

The important lesson is not memorizing individual operators.

The important lesson is understanding:

```text
What are the operands?
        ↓
Should this be a member or non-member?
        ↓
Does the operator modify an object?
        ↓
Should the parameter be const?
        ↓
What should the operator return?
        ↓
Does it need access to private data?
        ↓
If so, should it be a friend?
```

Once this pattern becomes familiar, adding new overloaded operators becomes much easier.
