# Variables and Assignment

---

# Objective

Learn how variables are declared and assigned values.

---

## Declaration

```cpp
int favorite_number;
```

This tells the compiler to reserve memory for an integer.

At this point the variable exists but has no assigned value.

---

## Assignment

```cpp
favorite_number = 12;
```

Stores the value `12` inside the variable.

---

## Output

```cpp
std::cout << favorite_number;
```

Prints the stored value.

---

# Declaration vs Assignment

Declaration

```cpp
int x;
```

Assignment

```cpp
x = 10;
```

Declaration + Initialization

```cpp
int x = 10;
```

---

# Memory

Before assignment

```
favorite_number

?
```

After assignment

```
favorite_number

12
```

---

# Common Errors

Using an undeclared variable

```cpp
x = 5;
```

Declaring twice

```cpp
int x;
int x;
```

Using the wrong operator

```cpp
x == 5;
```

instead of

```cpp
x = 5;
```

---

# Exercises

- Create three variables.
- Store your age.
- Store your GPA.
- Print all variables.
- Change one value and print it again.

---

# Summary

This lesson introduced

- Variables
- Assignment
- Initialization
- Memory
- Console Output