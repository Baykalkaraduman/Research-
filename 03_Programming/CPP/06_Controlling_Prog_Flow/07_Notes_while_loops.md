# While Loops

---

# Introduction

A **while loop** repeatedly executes a block of code **as long as a given condition remains true**.

Unlike a `for` loop, a `while` loop is usually preferred when **the exact number of iterations is not known beforehand**.

A while loop is called a **pre-test loop** because the condition is checked **before** the loop body executes.

If the condition is false the first time it is evaluated, the loop body will never run.

---

# General Syntax

```cpp
while (condition)
{
    statements;
}
```

Execution order

1. Evaluate the condition.
2. If the condition is true, execute the loop body.
3. Return to step 1.
4. Stop when the condition becomes false.

---

# Flow Diagram

```

Condition?
|
v
true -------------------------+
|                             |
Execute Loop Body             |
|                             |
+-----------------------------+
|
false
|
Exit Loop

```

---

# Example 1 — Countdown

```cpp
int count {5};

while(count > 0)
{
    cout << count << endl;
    --count;
}
```

Output

```

5
4
3
2
1

```

This is one of the simplest applications of a while loop.

---

# Example 2 — Counting Up

```cpp
int i {1};

while(i <= 10)
{
    cout << i << endl;
    ++i;
}
```

Output

```

1
2
3
...
10

```

---

# Example 3 — Input Validation

One of the most common applications.

```cpp
int number;

cin >> number;

while(number < 1 || number > 100)
{
    cout << "Invalid input. Try again: ";
    cin >> number;
}
```

The loop continues until the user enters a valid value.

This technique appears constantly in real software.

---

# Example 4 — Boolean Flag

Instead of repeatedly checking complicated conditions, programmers often use a Boolean variable.

```cpp
bool done {false};

while(!done)
{
    ...

    if(correct_input)
        done = true;
}
```

Advantages

- easier to read
- easier to debug
- easy to extend

---

# Sentinel Controlled Loops

Sometimes we do not know how many values the user will enter.

Instead, we choose a **sentinel value** that tells the program to stop.

Example

```cpp
int number;

cin >> number;

while(number != -1)
{
    ...
    cin >> number;
}
```

Here

```
-1
```

is not treated as data.

It simply signals the end of the input.

This is one of the most common while-loop patterns.

---

# Running Totals

A while loop can continuously accumulate values.

Example

```cpp
sum += number;
```

Combined with a sentinel loop, we can process an unlimited amount of input.

Examples

- total sales
- detector hits
- temperatures
- exam scores

---

# Running Average

Instead of only computing a sum,

we can also count how many values have been entered.

```cpp
sum += value;
count++;
```

Later

```cpp
average = sum / count;
```

This technique appears constantly in data analysis.

---

# Infinite Loops

A loop whose condition never becomes false.

Example

```cpp
while(true)
{
    ...
}
```

Infinite loops are useful for

- game engines
- operating systems
- servers
- GUI applications

However,

forgetting to update the loop variable accidentally creates an unwanted infinite loop.

---

# While vs For

| For Loop | While Loop |
|-----------|------------|
| Number of iterations usually known | Number of iterations often unknown |
| Compact syntax | More flexible |
| Initialization included | Initialization usually done before the loop |
| Counter-controlled | Condition-controlled |

General rule

Use

- `for` when you know how many times.
- `while` when you do not.

---

# Scientific Computing

While loops appear frequently in scientific software.

Examples

- Reading detector events until EOF
- Monte Carlo simulations
- Iterative numerical algorithms
- Newton-Raphson root finding
- Optimization algorithms
- Reading experimental measurements
- Processing sensor data streams

ROOT and Geant4 applications often contain many while loops.

---

# Best Practices

✔ Always update the loop variable.

✔ Keep the loop condition simple.

✔ Prefer Boolean flags for complex stopping conditions.

✔ Use sentinel values when the amount of input is unknown.

✔ Make sure the loop eventually terminates.

✔ Initialize variables before entering the loop.

---

# Common Mistakes

## Forgetting to update the counter

```cpp
while(i < 10)
{
    cout << i << endl;
}
```

Infinite loop.

---

## Wrong condition

Incorrect

```cpp
while(i >= 10)
```

instead of

```cpp
while(i <= 10)
```

The loop may never execute.

---

## Using uninitialized variables

```cpp
int number;

while(number != 0)
```

Undefined behavior.

Always initialize variables.

---

## Forgetting to read new input

Incorrect

```cpp
while(number != -1)
{
    sum += number;
}
```

The value of `number` never changes.

---

# Summary

After completing this chapter you should understand

- what a while loop is,
- why it is called a pre-test loop,
- how loop conditions work,
- input validation,
- Boolean flags,
- sentinel-controlled loops,
- running totals,
- running averages,
- infinite loops,
- when to use while instead of for.

---

# Exercises

## Exercise 1

Print the numbers from 1 to 50 using a while loop.

---

## Exercise 2

Ask the user for positive integers.

Stop when they enter -1.

Display the total sum.

---

## Exercise 3

Read temperatures until the user enters 0.

Display the average temperature.

---

## Exercise 4

Keep asking the user for a password until they enter

```
cpp123
```

---

## Exercise 5 (Challenge)

Create a simple ATM menu.

Display

```
1. Deposit
2. Withdraw
3. Balance
0. Exit
```

Continue displaying the menu until the user chooses **0**.

(Hint: Use a `while` loop together with a menu variable.)