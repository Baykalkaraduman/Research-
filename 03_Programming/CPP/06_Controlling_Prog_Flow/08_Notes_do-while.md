# Do-While Loops

---

# Introduction

A **do-while loop** is a repetition structure that executes the loop body **before** checking the loop condition.

Because the condition is checked **after** the loop body, the statements inside the loop are guaranteed to execute **at least once**.

For this reason, a do-while loop is known as a **post-test loop**.

---

# General Syntax

```cpp
do
{
    statements;
}
while(condition);
```

Notice that the `while(condition);` line **ends with a semicolon**.

---

# Execution Order

Unlike a `while` loop, execution proceeds as follows.

1. Execute the loop body.
2. Evaluate the condition.
3. If the condition is true, repeat.
4. Otherwise, exit the loop.

---

# Flow Diagram

```
Execute Loop Body
        |
        v
   Condition?
   /       \
true       false
 |           |
 +-----------+
             |
            Exit
```

---

# While vs Do-While

| While Loop | Do-While Loop |
|------------|---------------|
| Pre-test loop | Post-test loop |
| Condition checked first | Condition checked last |
| May execute zero times | Executes at least once |
| Most commonly used | Mainly used for menus and user interaction |

---

# Example 1 — Menu System

```cpp
char choice;

do
{
    cin >> choice;

} while(choice != 'q');
```

This is one of the most common real-world applications.

The menu is displayed at least once, and the program continues until the user chooses to quit.

---

# Example 2 — Password Validation

```cpp
do
{
    cin >> password;

} while(password != 1234);
```

The user must always enter a password at least once.

---

# Example 3 — Input Validation

```cpp
do
{
    cin >> number;

} while(number <= 0);
```

The loop guarantees that only a positive number is accepted.

---

# Example 4 — Countdown

```cpp
int count {5};

do
{
    cout << count << endl;
    --count;

} while(count > 0);
```

Output

```
5
4
3
2
1
```

---

# Typical Applications

Do-while loops are frequently used for

- Interactive menus
- Login systems
- Password verification
- Input validation
- Console applications
- Game menus
- Repeating user choices

---

# Scientific Computing

Although less common than `for` and `while`, do-while loops still appear in scientific software.

Typical examples include

- Interactive analysis tools
- Command-line interfaces
- Simulation menus
- Experimental control software
- Instrument calibration programs

---

# Best Practices

✔ Use a do-while loop when the code must execute at least once.

✔ Keep the stopping condition simple.

✔ Always update the variables used in the condition.

✔ Prefer descriptive variable names.

✔ Use do-while for menu-driven applications.

---

# Common Mistakes

## Forgetting the semicolon

Incorrect

```cpp
while(choice != 'q')
```

Correct

```cpp
while(choice != 'q');
```

---

## Creating an Infinite Loop

```cpp
do
{
    cout << "Hello";
}
while(true);
```

This loop never terminates.

---

## Wrong Loop Condition

Incorrect

```cpp
while(choice == 'q');
```

instead of

```cpp
while(choice != 'q');
```

The logic becomes reversed.

---

## Forgetting to Update Variables

```cpp
do
{
    cout << number;
}
while(number > 0);
```

If `number` never changes, the loop never ends.

---

# Summary

After completing this chapter you should understand

- what a do-while loop is,
- why it is called a post-test loop,
- why it always executes at least once,
- how it differs from a while loop,
- where it is commonly used,
- why it is ideal for menu-driven programs.

---

# Exercises

## Exercise 1

Create a menu that repeatedly displays

```
1. Start
2. Settings
3. Help
Q. Quit
```

until the user enters `Q`.

---

## Exercise 2

Keep asking the user for a positive integer until one is entered.

---

## Exercise 3

Ask the user to enter the password `"cpp"` repeatedly until it is correct.

---

## Exercise 4

Create a do-while countdown from 20 to 1.

---

## Exercise 5 (Challenge)

Create a simple calculator menu.

```
1. Addition
2. Subtraction
3. Multiplication
4. Division
Q. Quit
```

Continue displaying the menu until the user quits.