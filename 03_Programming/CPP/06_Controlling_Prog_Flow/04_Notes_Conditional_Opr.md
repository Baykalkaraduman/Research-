# Conditional (Ternary) Operator

---

# Introduction

The Conditional Operator, also known as the **Ternary Operator**, is a shorthand way of writing simple `if-else` statements.

Instead of writing multiple lines of code, we can select between two values using a single expression.

Syntax

```cpp
(condition) ? value_if_true : value_if_false;
```

It evaluates the condition.

- If the condition is true, the first value is returned.
- Otherwise, the second value is returned.

---

# Basic Example

Traditional `if-else`

```cpp
if(number % 2 == 0)
    cout << "Even";
else
    cout << "Odd";
```

Equivalent ternary operator

```cpp
cout << ((number % 2 == 0) ? "Even" : "Odd");
```

Both programs produce exactly the same output.

---

# Syntax Breakdown

```cpp
(condition)
    ? expression_if_true
    : expression_if_false;
```

Think of it as asking a question.

```
Is the condition true?

YES → first expression

NO → second expression
```

---

# Returning Values

The conditional operator returns a value.

Example

```cpp
int larger = (a > b) ? a : b;
```

If

```
a > b
```

then

```
larger = a
```

otherwise

```
larger = b
```

---

# Using Strings

```cpp
string status = (age >= 18)
                    ? "Adult"
                    : "Minor";
```

Output

```
Adult
```

or

```
Minor
```

---

# Nested Conditional Operators

Conditional operators may be nested.

Example

```cpp
int maximum =
    (a > b)
        ? ((a > c) ? a : c)
        : ((b > c) ? b : c);
```

Although this is valid C++, deeply nested ternary operators quickly become difficult to read.

---

# Operator Precedence

The conditional operator has relatively low precedence.

Using parentheses improves readability.

Instead of

```cpp
a > b ? a : b
```

prefer

```cpp
(a > b) ? a : b
```

---

# When Should We Use It?

Good use cases

- Selecting one of two values
- Simple assignments
- Returning values
- Simple output statements

Avoid using it for long or complicated decision trees.

---

# if-else vs Conditional Operator

| if-else | Conditional Operator |
|----------|----------------------|
| Multiple statements | Single expression |
| Better for complex logic | Better for simple decisions |
| Easier to debug | More compact |
| More readable for large programs | Excellent for short assignments |

---

# Scientific Computing Notes

Conditional operators appear frequently in scientific software.

Examples include

- Event selection
- Detector acceptance
- Choosing calibration constants
- Data quality flags
- Simulation status
- Particle identification

For example

```cpp
double mass =
    (isMuon)
        ? muonMass
        : electronMass;
```

ROOT analyses often contain hundreds of simple conditional assignments like this.

---

# Best Practices

✔ Use the ternary operator only for simple decisions.

✔ Prefer readability over writing fewer lines.

✔ Store the result in a variable whenever appropriate.

✔ Use parentheses around the condition.

---

# Common Mistakes

## Writing complicated nested expressions

Avoid

```cpp
(condition1)
    ? value1
    : (condition2)
        ? value2
        : (condition3)
            ? value3
            : value4;
```

An `if-else if` chain is usually much easier to understand.

---

## Forgetting Parentheses

Instead of

```cpp
a > b ? a : b
```

prefer

```cpp
(a > b) ? a : b
```

---

## Using Ternary for Side Effects

Avoid writing code such as

```cpp
(condition)
    ? cout << "A"
    : cout << "B";
```

Although valid, an ordinary `if-else` is usually clearer for actions rather than value selection.

---

# Summary

After completing this chapter you should understand

- What the conditional (ternary) operator is
- Its syntax
- How it replaces simple `if-else` statements
- Returning values with the operator
- Nested ternary operators
- When it should and should not be used

---

# Exercises

## Exercise 1

Ask the user for a number.

Print whether it is positive or negative using the conditional operator.

---

## Exercise 2

Read two integers.

Display the larger one using a ternary operator.

---

## Exercise 3

Ask the user for an exam score.

Store

```
"Pass"
```

or

```
"Fail"
```

inside a string using the conditional operator.

---

## Exercise 4

Ask the user for three numbers.

Find the largest using nested conditional operators.

---

## Exercise 5 (Challenge)

Create a simple BMI classifier.

Input

- Weight
- Height

Calculate BMI.

Use nested conditional operators to print

- Underweight
- Normal
- Overweight
- Obese

without using an `if-else` chain.