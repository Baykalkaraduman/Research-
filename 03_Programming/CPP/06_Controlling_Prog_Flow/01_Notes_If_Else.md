# If-Else Statements

---

# Introduction

The `if` statement allows a program to execute code only when a condition is true.

However, real-world programs often need to choose between multiple possible actions.

This is accomplished using **if-else statements**.

---

# Basic Syntax

```cpp
if(condition)
{
    // executed if true
}
else
{
    // executed if false
}
```

Only one of the two blocks executes.

---

# Else-If Chains

Many programs require more than two possibilities.

```cpp
if(score >= 90)
{
    ...
}
else if(score >= 80)
{
    ...
}
else if(score >= 70)
{
    ...
}
else
{
    ...
}
```

Conditions are evaluated from top to bottom.

The first condition that evaluates to `true` is executed.

The remaining conditions are skipped.

---

# Example: Letter Grades

```cpp
if(grade >= 80)
    letter_grade = "AA";
else if(grade >= 75)
    letter_grade = "BA";
else if(grade >= 70)
    letter_grade = "BB";
else
    letter_grade = "FF";
```

If the grade is 82,

only the first condition is executed.

The remaining conditions are ignored.

---

# Nested If Statements

An `if` statement may contain another `if`.

```cpp
if(student_passed)
{
    if(grade >= 90)
    {
        cout << "Excellent!";
    }
}
```

This is called a **nested if statement**.

Nested conditions are useful when one decision depends on another.

---

# Execution Flow

Example

```cpp
if(a)
{
    ...
}
else if(b)
{
    ...
}
else
{
    ...
}
```

Flow

```
Condition A ?

│
├── True  → Execute Block A
│
└── False
      │
      ▼
Condition B ?

│
├── True → Execute Block B
│
└── False
      │
      ▼
 Execute Else Block
```

Only one branch is executed.

---

# Input Validation

Always validate user input before processing it.

Example

```cpp
if(grade < 0 || grade > 100)
{
    cout << "Invalid grade";
}
```

This prevents invalid data from producing incorrect results.

---

# Scientific Computing Notes

Conditional statements appear everywhere in scientific software.

Examples include

- Event selection
- Detector acceptance
- Trigger decisions
- Data quality checks
- Physics cuts
- Simulation control
- Error handling

ROOT and Geant4 analyses frequently contain long chains of `if-else` statements to filter events.

---

# Best Practices

✔ Check invalid inputs first.

✔ Keep conditions simple.

✔ Use braces `{}` even for one-line blocks.

✔ Prefer meaningful variable names.

✔ Order conditions from most restrictive to least restrictive when appropriate.

---

# Common Mistakes

## Forgetting braces

Instead of

```cpp
if(condition)
    statement;
```

prefer

```cpp
if(condition)
{
    statement;
}
```

This avoids many difficult bugs.

---

## Wrong order of conditions

Incorrect

```cpp
if(score >= 50)
```

before

```cpp
if(score >= 90)
```

The second condition would never execute.

Always place more restrictive conditions first.

---

## Using = instead of ==

Incorrect

```cpp
if(grade = 50)
```

Correct

```cpp
if(grade == 50)
```

---

## Not validating input

Never assume the user enters valid data.

Always check ranges before processing.

---

# Summary

After completing this chapter you should understand

- Basic if-else statements
- Else-if chains
- Nested if statements
- Input validation
- Execution order of conditions
- How conditional logic is used in scientific programming

---

# Exercises

## Exercise 1

Ask the user for a temperature.

Display

- Hot
- Warm
- Cold

using an if-else chain.

---

## Exercise 2

Ask the user for an exam score.

Display

- Excellent
- Good
- Average
- Failed

---

## Exercise 3

Ask the user for age.

Determine whether they are

- Child
- Teenager
- Adult
- Senior

---

## Exercise 4

Create a simple login system.

If the username is correct,

ask for the password.

Otherwise,

display an error.

---

## Exercise 5 (Challenge)

Create a university scholarship checker.

Requirements

- GPA ≥ 3.50 → Full Scholarship
- GPA ≥ 3.00 → Half Scholarship
- GPA ≥ 2.50 → Partial Scholarship
- Otherwise → No Scholarship

Display both the scholarship level and an explanatory message.