# Variables - Example Project

## Objective

In this project we combine everything learned so far.

- Variables
- User Input
- Output
- Basic Arithmetic
- Strings

---

# New Concepts

## string

```cpp
string employee_name;
```

Stores text instead of numbers.

Example

```
Emir
```

---

## int

```cpp
int age;
```

Stores whole numbers.

Example

```
18

25

42
```

---

## double

```cpp
double wage;
```

Stores decimal numbers.

Example

```
3200.50
```

---

# Variable Initialization

```cpp
int age {18};
```

This is called **brace initialization**.

Modern C++ recommends this style.

---

# Reading Input

```cpp
cin >> age;
```

The user types a value.

The value is stored inside the variable.

---

# Arithmetic

```cpp
monthly_salary = wage * working_days;
```

The multiplication operator

```
*
```

multiplies two values.

---

# Program Flow

```
Start

↓

Ask Name

↓

Store Name

↓

Ask Age

↓

Store Age

↓

Ask Working Days

↓

Store Days

↓

Calculate Salary

↓

Display Result

↓

End
```

---

# Memory Example

After input

```
employee_name

Emir

------------------

age

22

------------------

working_days

5

------------------

wage

3200.50

------------------

monthly_salary

16002.5
```

---

# Improvements

This program can later be improved by

- Asking surname
- Asking department
- Asking hourly wage
- Calculating yearly salary
- Calculating taxes
- Using functions
- Using loops
- Using classes

We will revisit this project after learning those topics.

---

# Common Beginner Mistakes

❌ Forgetting `#include <string>`

❌ Using `int` for decimal numbers

❌ Misspelling variable names

❌ Forgetting semicolons

❌ Using `=` instead of `==` inside conditions

---

# Exercises

Modify this project so that it also asks

- Employee surname
- Department
- Hourly wage
- Weekly working hours

Then calculate

- Weekly salary
- Monthly salary
- Annual salary

Bonus:

Display everything in a formatted table.

---

# Summary

This project combines

- Variables
- Initialization
- Input
- Output
- Arithmetic
- Strings

It is the first mini interactive C++ application.