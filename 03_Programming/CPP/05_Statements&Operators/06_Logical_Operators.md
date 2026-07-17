# Logical Operators

---

# Introduction

Relational operators answer simple questions.

```cpp
x > y
```

But real programs usually require **multiple conditions** to be checked at the same time.

Examples

- Is a particle energetic **and** inside the detector?
- Is the user an adult **or** accompanied by a guardian?
- Is today's temperature below freezing **and** is it windy?

Logical operators allow us to combine multiple Boolean expressions into a single condition.

---

# Boolean Expressions

Logical operators work with Boolean values.

```cpp
true

false
```

Every comparison

```cpp
x > y
```

already produces a Boolean result.

Logical operators combine those results.

---

# Logical AND

Operator

```cpp
&&
```

Both conditions must be true.

Example

```cpp
(age >= 18) && (has_ticket)
```

Truth Table

| A | B | A && B |
|---|---|---------|
| false | false | false |
| false | true | false |
| true | false | false |
| true | true | true |

---

# Logical OR

Operator

```cpp
||
```

Only one condition needs to be true.

Example

```cpp
(student || teacher)
```

Truth Table

| A | B | A \|\| B |
|---|---|----------|
| false | false | false |
| false | true | true |
| true | false | true |
| true | true | true |

---

# Logical NOT

Operator

```cpp
!
```

Reverses a Boolean value.

Example

```cpp
!true
```

Result

```
false
```

---

# Combining Conditions

Logical operators can be combined.

Example

```cpp
(age >= 18 && age <= 65)
```

Another example

```cpp
(score >= 50 || has_bonus)
```

Complex conditions are common in professional software.

---

# Short-Circuit Evaluation

One of the most important optimizations in C++.

Example

```cpp
false && expensive_function()
```

The function is **never called**.

Why?

Because the result is already known to be false.

Similarly,

```cpp
true || expensive_function()
```

also skips evaluating the second expression.

Short-circuit evaluation improves performance and prevents unnecessary computations.

---

# Operator Precedence

Logical operators are evaluated after comparison operators.

Example

```cpp
x > 5 && x < 10
```

is interpreted as

```cpp
(x > 5) && (x < 10)
```

Using parentheses improves readability and is strongly recommended.

---

# Scientific Computing

Logical operators appear everywhere in scientific programming.

Examples

- Event filtering
- Detector acceptance
- Trigger requirements
- Monte Carlo selection
- Quality cuts
- Data cleaning
- Physics analysis

ROOT and Geant4 analyses often contain conditions with many logical operators combined together.

---

# Best Practices

✔ Always use parentheses around comparisons.

✔ Keep complex logical expressions readable.

✔ Give Boolean variables meaningful names.

```cpp
is_valid

is_inside_detector

passed_selection
```

---

# Common Mistakes

## Using = instead of ==

Incorrect

```cpp
if(a = 5)
```

Correct

```cpp
if(a == 5)
```

---

## Forgetting parentheses

Instead of

```cpp
a > b && c < d
```

prefer

```cpp
(a > b) && (c < d)
```

---

## Making conditions too complicated

If an expression becomes difficult to read, split it into smaller Boolean variables.

---

# Summary

After completing this chapter you should understand

- Logical AND (`&&`)
- Logical OR (`||`)
- Logical NOT (`!`)
- Combining multiple comparisons
- Short-circuit evaluation
- Why logical operators are essential in scientific programming

---

# Exercises

## Exercise 1

Ask the user for an age.

Determine whether the age is between 18 and 65.

---

## Exercise 2

Ask the user for temperature and humidity.

Recommend going outside only if

- temperature is above 15°C
- humidity is below 80%

---

## Exercise 3

Ask the user for a password.

Print whether it is **not** empty using `!`.

---

## Exercise 4

Write a program that determines whether a number belongs to the interval

```
[-5, 15]
```

---

## Exercise 5 (Challenge)

Create a simple university admission checker.

Admission requires

- GPA ≥ 3.00 **or**
- Entrance Exam ≥ 90

Display whether the student is accepted.