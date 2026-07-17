# If Statements

---

# Introduction

The `if` statement is one of the most fundamental decision-making structures in C++.

Until now, every program we have written executed line by line from top to bottom.

Real programs, however, rarely execute every line. They make decisions based on user input, calculations, or external conditions.

The `if` statement allows a program to execute a block of code **only when a condition is true**.

---

# Why do we need if statements?

Imagine writing software without conditions.

A calculator would always perform every operation.

A game would always display "Game Over."

A bank would always approve every transaction.

Clearly this is impossible.

Programs must be able to make decisions.

The `if` statement provides this ability.

---

# Basic Syntax

```cpp
if (condition)
{
    // statements
}
---

# Scientific Computing Notes

Although `if` statements are introduced as one of the simplest control structures in C++, they are among the most frequently used features in scientific programming.

In High Energy Physics, nearly every event passes through numerous conditional checks before it is accepted into an analysis. Event selection, detector acceptance, trigger decisions, particle identification, and data quality filtering all rely heavily on `if` statements.

For example, a simplified particle selection might look like:

```cpp
if (particle.pt() > 25 && abs(particle.eta()) < 2.4)
{
    // Accept the particle
}
```

Similarly, ROOT and Geant4 analyses often contain long sequences of `if` statements that determine whether an event should be processed or discarded.

Mastering conditional statements is therefore an essential skill for anyone interested in scientific computing, data analysis, or High Energy Physics.

---

# Best Practices

✔ Always use braces `{}` even if the `if` statement contains only one line.

```cpp
if (score >= 50)
{
    cout << "Passed";
}
```

Using braces prevents many bugs when the code is modified later.

---

✔ Keep conditions simple and readable.

Instead of writing very long expressions, divide them into smaller logical parts whenever possible.

---

✔ Use meaningful variable names.

Good:

```cpp
if (is_valid)
```

Better than

```cpp
if (x)
```

Your code becomes much easier to understand.

---

✔ Prefer logical operators over deeply nested `if` statements.

Instead of

```cpp
if (age >= 18)
{
    if (age <= 65)
    {
        ...
    }
}
```

write

```cpp
if (age >= 18 && age <= 65)
{
    ...
}
```

This is shorter and more readable.

---

✔ Validate user input before using it.

For example:

```cpp
if (score >= 0 && score <= 100)
{
    // Valid input
}
```

Checking input validity prevents unexpected behavior later in the program.

---

# Common Mistakes

## Forgetting braces

Incorrect:

```cpp
if (score >= 50)
    cout << "Passed";
    cout << "Congratulations!";
```

Only the first line belongs to the `if`.

Correct:

```cpp
if (score >= 50)
{
    cout << "Passed";
    cout << "Congratulations!";
}
```

---

## Confusing `=` with `==`

Incorrect:

```cpp
if (score = 100)
```

This assigns a value instead of comparing it.

Correct:

```cpp
if (score == 100)
```

---

## Writing impossible conditions

Incorrect:

```cpp
if (score > 100 && score < 0)
```

No number can satisfy both conditions at the same time.

---

## Forgetting to validate the input range

Instead of writing

```cpp
if (score >= 60)
```

first verify that the entered score is valid.

```cpp
if (score >= 0 && score <= 100)
{
    if (score >= 60)
    {
        ...
    }
}
```

---

## Excessive nesting

Avoid code like

```cpp
if (...)
{
    if (...)
    {
        if (...)
        {
            if (...)
            {
                ...
            }
        }
    }
}
```

When possible, simplify the logic using Boolean variables or logical operators.

---

# Summary

After completing this chapter, you should understand:

- What an `if` statement is.
- How conditional execution works.
- How `else` provides an alternative execution path.
- How logical operators combine multiple conditions.
- Why braces improve readability and safety.
- How to validate user input before processing it.
- Why conditional statements are fundamental in scientific programming.

Conditional statements are one of the most important building blocks in C++. Nearly every real-world application—from operating systems to scientific simulations—uses them extensively.

---

# Exercises

## Exercise 1

Ask the user for an integer.

Print whether the number is positive, negative, or zero.

---

## Exercise 2

Ask the user for a temperature.

Print one of the following:

- Cold
- Warm
- Hot

using `if` and `else if`.

---

## Exercise 3

Ask the user for an age.

Determine whether the person is

- Child
- Teenager
- Adult
- Senior

---

## Exercise 4

Ask the user for a username and password.

Print **"Login Successful"** only if both values are correct.

(Hint: Use logical operators.)

---

## Exercise 5 (Challenge)

Create a simple particle-selection program.

Ask the user to enter:

- Transverse momentum (`pt`)
- Pseudorapidity (`eta`)

Accept the particle only if

- `pt > 25`
- `|eta| < 2.4`

Otherwise, reject the particle.

This is a simplified version of the selection criteria commonly used in High Energy Physics analyses.