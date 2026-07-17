# Assignment Operators

---

# Introduction

Every program stores information inside variables.

Sooner or later, those variables need to change.

Changing the value stored inside a variable is called **assignment**.

Assignment is one of the most fundamental operations in C++.

---

# Initialization vs Assignment

These two concepts are often confused.

Initialization creates a variable and gives it its first value.

```cpp
int number {10};
```

The variable is created.

Its initial value is 10.

---

Assignment changes the value of an already existing variable.

```cpp
number = 25;
```

The variable already exists.

Only its value changes.

---

# Assignment Operator

The assignment operator is

```cpp
=
```

Example

```cpp
int age {20};

age = 25;
```

Result

```
age = 25
```

---

# Assigning Variables

The value of one variable can be assigned to another.

```cpp
int x {10};
int y {20};

x = y;
```

Now

```
x = 20

y = 20
```

The value is copied.

The variables remain independent.

---

# Chained Assignment

Assignments may be chained together.

```cpp
x = y = 100;
```

This is evaluated from **right to left**.

Equivalent to

```cpp
y = 100;

x = y;
```

Result

```
x = 100

y = 100
```

---

# l-value and r-value

Every assignment has two parts.

```cpp
number = 15;
```

Left side

```
number
```

This represents a memory location.

It is called an **l-value**.

---

Right side

```
15
```

This is the value being assigned.

It is called an **r-value**.

---

# Compound Assignment Operators

Instead of writing

```cpp
x = x + 5;
```

we may write

```cpp
x += 5;
```

Both mean exactly the same thing.

---

Common compound operators

Addition

```cpp
+=
```

Subtraction

```cpp
-=
```

Multiplication

```cpp
*=
```

Division

```cpp
/=
```

Remainder

```cpp
%=
```

---

# Examples

```cpp
score += 10;
```

Equivalent to

```cpp
score = score + 10;
```

---

```cpp
counter *= 2;
```

Equivalent to

```cpp
counter = counter * 2;
```

---

# Why Use Compound Assignment?

Advantages

- shorter code
- easier to read
- less repetitive
- very common in professional software

---

# Scientific Computing Examples

ROOT

```cpp
totalEnergy += particleEnergy;
```

---

Monte Carlo

```cpp
acceptedEvents += 1;
```

---

Statistics

```cpp
sum += measurement;
```

---

Loops

```cpp
counter += step;
```

---

# Best Practices

✔ Initialize variables whenever possible.

✔ Use assignment only after a variable already exists.

✔ Prefer compound assignment operators when appropriate.

✔ Use meaningful variable names.

---

# Common Mistakes

## Confusing initialization with assignment

Initialization

```cpp
int x {5};
```

Assignment

```cpp
x = 10;
```

---

## Forgetting assignment order

```cpp
a = b = c = 100;
```

Evaluation starts from the **rightmost assignment**.

---

## Accidentally using uninitialized variables

Avoid

```cpp
int x;

std::cout << x;
```

Always initialize variables.

---

# Summary

After completing this chapter you should understand

- initialization
- assignment
- assignment operator
- l-values
- r-values
- chained assignment
- compound assignment operators
- why compound assignments are common in scientific software

---

# Exercises

## Exercise 1

Create two integers.

Assign one to the other.

Print both values.

---

## Exercise 2

Start with

```cpp
int value {10};
```

Apply

```cpp
+=
-=
*=
/=
%=
```

Display the result after each operation.

---

## Exercise 3

Predict the output.

```cpp
int a {5};
int b {10};

a = b;

b = 20;
```

---

## Exercise 4

Write a simple score counter.

Increase the score using

```cpp
+=
```

---

## Exercise 5 (Challenge)

Ask the user for five numbers.

Keep a running total using

```cpp
total += number;
```

Display the final sum.