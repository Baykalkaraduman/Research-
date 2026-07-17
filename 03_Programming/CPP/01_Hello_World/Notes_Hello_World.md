# User Input in C++

---

# Objective

Learn how to receive information from the user using `std::cin`.

---

# New Concepts

## Variable

A variable is a named location in memory that stores data.

Example

```cpp
int favourite_number;
```

This creates an integer variable.

---

## std::cin

`std::cin` reads data from the keyboard.

```cpp
std::cin >> favourite_number;
```

The `>>` operator extracts data from the input stream and stores it inside the variable.

---

## std::cout

Displays information on the screen.

```cpp
std::cout << favourite_number;
```

---

## std::endl

Moves the cursor to the next line and flushes the output buffer.

```cpp
std::cout << std::endl;
```

---

# Program Flow

```
Start

↓

Ask user

↓

User types a number

↓

Store number in memory

↓

Print message

↓

Print stored number

↓

End
```

---

# Memory Illustration

Before input

```
favourite_number

?

(Uninitialized)
```

After input

```
favourite_number

42
```

---

# Common Beginner Mistakes

❌ Forgetting `std::cin`

❌ Misspelling the variable name

❌ Missing semicolons

❌ Writing

```cpp
std::cin << favourite_number;
```

instead of

```cpp
std::cin >> favourite_number;
```

---

# Exercises

1. Ask the user for their age.

2. Ask for height.

3. Ask for weight.

4. Print all values in one sentence.

5. Ask for two numbers and print both.

---

# Summary

This lesson introduced

- Variables
- User Input
- std::cin
- std::cout
- Program flow