# Equality and Comparison Operators

---

# Introduction

Programs constantly need to make decisions.

Examples include

- Is the user old enough?
- Are two values equal?
- Is one number larger than another?
- Has an experiment reached a threshold?
- Did a detector record enough energy?

All of these questions rely on **comparison operators**.

Comparison operators compare two values and always produce a Boolean (`bool`) result.

That result is either

```text
true
```

or

```text
false
```

---

# Boolean Values

The Boolean data type stores only two possible values.

```cpp
bool finished {false};
```

Possible values

```cpp
true
false
```

Internally,

```
false → 0

true → 1
```

---

# boolalpha

Normally,

```cpp
std::cout << true;
```

prints

```
1
```

To print readable words,

```cpp
std::cout << std::boolalpha;
```

Output becomes

```
true
false
```

---

# Equality Operators

## Equal To

```cpp
==
```

Example

```cpp
10 == 10
```

Result

```
true
```

---

## Not Equal To

```cpp
!=
```

Example

```cpp
10 != 5
```

Result

```
true
```

---

# Relational Operators

Less Than

```cpp
<
```

Greater Than

```cpp
>
```

Less Than or Equal

```cpp
<=
```

Greater Than or Equal

```cpp
>=
```

---

# Character Comparison

Characters can also be compared.

```cpp
'A' == 'A'
```

returns

```
true
```

because characters are internally stored as integer ASCII values.

---

# Mixed-Type Comparison

Different numeric types can be compared.

```cpp
12 == 12.0
```

returns

```
true
```

because C++ automatically converts one operand into the appropriate type.

This process is called **implicit type conversion**.

---

# Floating-Point Comparison

Many beginners expect

```cpp
0.1 + 0.2 == 0.3
```

to be

```
true
```

Surprisingly,

it is usually

```
false
```

Why?

Because floating-point numbers cannot represent every decimal number exactly.

Computers store an approximation.

This is one of the most important concepts in numerical computing.

---

# Scientific Computing

In scientific software,

floating-point values are **almost never compared using `==`.**

Instead,

we compare whether two numbers are "close enough."

Example

```cpp
fabs(a-b) < tolerance
```

This avoids numerical precision problems.

---

# Best Practices

✔ Use `boolalpha` while learning.

✔ Compare integers using `==`.

✔ Avoid comparing floating-point values directly.

✔ Choose meaningful variable names like

```cpp
is_valid

is_finished

is_detected
```

instead of

```cpp
banana
```

---

# Common Mistakes

## Assignment instead of comparison

Incorrect

```cpp
if(a = b)
```

Correct

```cpp
if(a == b)
```

---

## Comparing floating-point numbers

Avoid

```cpp
0.1 + 0.2 == 0.3
```

Prefer a tolerance.

---

# Scientific Applications

Comparison operators appear everywhere.

Examples include

- Event selection
- Trigger decisions
- Detector thresholds
- Energy cuts
- Monte Carlo filtering
- Particle identification

Understanding comparison operators is essential before learning

- if statements
- loops
- algorithms
- object-oriented programming

---

# Summary

After this chapter you should understand

- bool
- boolalpha
- equality operators
- relational operators
- implicit conversions
- floating-point comparison
- why scientific software rarely compares doubles using `==`

---

# Exercises

## Exercise 1

Ask the user for two integers.

Display every comparison operator.

---

## Exercise 2

Ask the user for two characters.

Compare them.

---

## Exercise 3

Create a simple age verification program.

---

## Exercise 4

Experiment with

```cpp
0.1 + 0.2 == 0.3
```

Explain the result.

---

## Exercise 5 (Challenge)

Ask the user for a temperature.

Display

- Above freezing?
- Equal to zero?
- Below boiling?

using comparison operators only.