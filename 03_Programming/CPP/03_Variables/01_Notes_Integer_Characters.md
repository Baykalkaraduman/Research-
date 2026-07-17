# Integer and Character Data Types

---

# Objective

Understand how C++ stores whole numbers and characters.

---

# Integer Types

C++ provides several integer types.

```
short

int

long

long long
```

Unsigned versions also exist.

---

# Signed vs Unsigned

Signed

```
-5

0

15
```

Unsigned

```
0

15

300
```

Unsigned cannot store negative values.

---

# Digit Separators

Modern C++ allows

```cpp
300'000'000
```

instead of

```cpp
300000000
```

This improves readability.

---

# Character Type

Characters are stored using

```cpp
char
```

Example

```cpp
char letter {'A'};
```

Internally

```
'A'

↓

65
```

according to the ASCII table.

---

# Character Arithmetic

Characters behave like integers.

```cpp
letter++;
```

changes

```
A

↓

B
```

because

```
65

↓

66
```

---

# Overflow

Every integer type has a maximum value.

Example

```
short

-32768

↓

32767
```

If the result exceeds this range

Overflow occurs.

The stored value becomes incorrect.

---

# Best Practices

✔ Prefer brace initialization

```cpp
int value {5};
```

✔ Use meaningful variable names.

---

# Common Mistakes

Using

```cpp
short
```

for very large numbers.

Ignoring overflow.

Using

```cpp
char
```

instead of

```cpp
std::string
```

for text.

---

# Physics Applications

Examples

```
Run number

Event number

Detector ID

Particle ID

ASCII detector labels

Number of events

Counters
```

Integer data types are heavily used in every physics analysis.

---

# Exercises

1. Create one variable of each integer type.

2. Print all of them.

3. Print ASCII letters.

4. Convert

```
'A'

↓

'Z'
```

using a loop (after learning loops).

5. Create an overflow example.

---

# Summary

You learned

- char
- short
- int
- long
- long long
- unsigned
- ASCII
- Overflow