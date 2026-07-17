# Switch Statement

---

# Introduction

The `switch` statement is a selection structure used when one variable needs to be compared against several fixed values.

Instead of writing long `if-else if` chains, `switch` provides a cleaner and more readable solution.

---

# Syntax

```cpp
switch(expression)
{
    case value1:
        // statements
        break;

    case value2:
        // statements
        break;

    default:
        // statements
}
```

The expression is evaluated once.

Program execution jumps directly to the matching `case`.

---

# How Switch Works

Suppose we have

```cpp
char grade {'B'};
```

Then

```cpp
switch(grade)
```

checks each case until it finds

```cpp
case 'B':
```

Only that block executes.

---

# Case Labels

Each possible value is represented using a `case`.

Example

```cpp
case 1:
case 2:
case 3:
```

Each case must represent a **constant value**.

Variables are **not allowed**.

Incorrect

```cpp
int x {5};

case x:
```

Correct

```cpp
case 5:
```

---

# The break Statement

The `break` statement exits the switch block.

Without it, execution continues into the next case.

Example

```cpp
case 1:
    cout << "One";

case 2:
    cout << "Two";
```

Output

```
One
Two
```

This behavior is called **fall-through**.

Normally, every case should end with `break`.

---

# Multiple Cases

Multiple labels can execute the same code.

Example

```cpp
case 'A':
case 'a':
```

Both uppercase and lowercase letters execute the same statements.

This is one of the most common switch techniques.

---

# Default Case

The `default` case is similar to the `else` block.

It executes when no case matches.

Example

```cpp
default:
    cout << "Invalid input";
```

Although optional, it is considered good programming practice to always include it.

---

# Scope Inside Cases

Variables declared inside a case should be enclosed within braces.

Correct

```cpp
case 'F':
{
    int score {};
    break;
}
```

Without braces, compilation errors may occur because of variable initialization rules.

---

# Data Types Supported

Switch works with

- int
- char
- enum
- enum class (Modern C++)

Switch **does not work** with

- double
- float
- string

For those types, use `if-else`.

---

# Switch vs If-Else

| Switch | If-Else |
|---------|----------|
| Cleaner for fixed values | Better for ranges |
| Faster in many situations | More flexible |
| Easy to read | Handles complex conditions |
| Constant values only | Any Boolean expression |

---

# Fall-through

Sometimes fall-through is intentional.

Example

```cpp
case 1:
case 2:
case 3:
    cout << "Small number";
    break;
```

Here, all three values execute the same code.

Modern C++ also provides

```cpp
[[fallthrough]];
```

to explicitly indicate intentional fall-through.

---

# Scientific Computing Notes

Switch statements appear frequently in scientific software.

Examples include

- Selecting detector regions
- Particle identification
- Choosing analysis modes
- Parsing configuration options
- Simulation states
- Event categories

ROOT and Geant4 often use `switch` statements together with enumerations to improve readability and performance.

---

# Best Practices

✔ Always include a `default` case.

✔ Use `break` unless fall-through is intentional.

✔ Group identical cases together.

✔ Keep each case short and readable.

✔ Prefer `switch` over long `if-else if` chains when comparing one variable against many fixed values.

---

# Common Mistakes

## Forgetting `break`

```cpp
case 1:
    ...
```

Execution continues into the next case.

---

## Using Variables as Case Labels

Incorrect

```cpp
case x:
```

Case labels must be compile-time constants.

---

## Using Floating-Point Values

Incorrect

```cpp
switch(temperature)
```

when `temperature` is a `double`.

Use `if-else` instead.

---

## Declaring Variables Without Braces

Incorrect

```cpp
case 'A':
    int x;
```

Correct

```cpp
case 'A':
{
    int x {};
    break;
}
```

---

# Summary

After completing this chapter you should understand

- What a switch statement is
- How `case` labels work
- Why `break` is necessary
- The purpose of `default`
- Fall-through behavior
- When to use `switch` instead of `if-else`

---

# Exercises

## Exercise 1

Ask the user to enter a number between 1 and 7.

Print the corresponding day of the week.

---

## Exercise 2

Ask the user to enter a character.

Determine whether it is a vowel using a switch statement.

---

## Exercise 3

Create a simple calculator.

The user enters

- first number
- operator (`+`, `-`, `*`, `/`)
- second number

Use `switch` to perform the correct operation.

---

## Exercise 4

Create a menu

```
1. Physics
2. Mathematics
3. Programming
4. Exit
```

Display a different message depending on the user's choice.

---

## Exercise 5 (Challenge)

Create a mini text adventure.

The player chooses

- Left
- Right
- Forward

Use a switch statement to determine what happens next.