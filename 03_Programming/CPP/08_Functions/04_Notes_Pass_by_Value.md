# Pass by Value

---

# Introduction

Whenever a function is called, information can be passed to it through **parameters**.

There are several ways to pass data in C++.

The simplest and most common method is **Pass by Value**.

In Pass by Value, the function receives **a copy** of the original variable.

This means that any modification made inside the function affects **only the copy**, not the original object.

---

# What Does "Pass by Value" Mean?

Suppose we have a variable.

```cpp
int number {10};
```

and call

```cpp
change(number);
```

The function receives a completely new variable.

```
Main Function

number
+-----+
| 10  |
+-----+

        copy

Function

num
+-----+
| 10  |
+-----+
```

These are **two different variables** stored in different memory locations.

---

# Basic Example

```cpp
void change(int num)
{
    num = 100;
}

int main()
{
    int number {10};

    change(number);

    cout << number;
}
```

Output

```
10
```

Even though the function changes `num`, the original variable remains unchanged.

---

# Memory Representation

Original variable

```
Address: 0x100

number = 10
```

Function copy

```
Address: 0x250

num = 10
```

After

```cpp
num = 100;
```

Memory becomes

```
Main

number = 10

Function

num = 100
```

The original variable is untouched.

---

# Why Does This Happen?

When Pass by Value is used,

the compiler creates a **copy** of the argument.

The function works with that copy until it returns.

When the function ends,

the copied variable is destroyed automatically.

---

# Passing Primitive Types

Primitive types are inexpensive to copy.

Examples

```cpp
int

double

char

bool
```

Example

```cpp
void increment(int x)
{
    x++;
}
```

Calling

```cpp
increment(number);
```

does not modify `number`.

---

# Passing Strings

Strings are objects.

```cpp
string name {"Emir"};
```

Passing

```cpp
change(name);
```

creates a copy of the entire string.

Example

```cpp
void change(string text)
{
    text = "Changed";
}
```

The original string remains unchanged.

---

# Passing Vectors

Vectors are also objects.

```cpp
vector<int> numbers {1,2,3};
```

Calling

```cpp
modify(numbers);
```

copies the whole vector.

Example

```cpp
void modify(vector<int> values)
{
    values.clear();
}
```

Output

Original vector

```
1 2 3
```

After returning

```
1 2 3
```

The original vector is unaffected because only the copy was modified.

---

# Copying Large Objects

Pass by Value is perfectly acceptable for

- integers
- doubles
- booleans
- characters

However,

copying large objects can be expensive.

Examples

```cpp
vector

string

map

unordered_map

large classes
```

Every function call creates another copy.

This may reduce performance.

---

# Temporary Objects

Pass by Value also accepts temporary values.

Example

```cpp
print_number(100);
```

or

```cpp
print_text("Hello");
```

The compiler creates temporary objects and passes them to the function.

---

# Function Parameters

General syntax

```cpp
return_type function_name(type parameter)
```

Example

```cpp
void print_number(int number)
```

Multiple parameters

```cpp
double area(double radius)

double volume(double radius,
              double height)
```

Parameters are always local variables inside the function.

---

# Local Variables

Parameters behave exactly like local variables.

```cpp
void example(int x)
{
    x = 50;
}
```

The variable `x`

- is created when the function begins,
- exists only inside the function,
- is destroyed automatically when the function ends.

---

# Variable Lifetime

```
Function Call

↓

Create Parameter Copy

↓

Execute Function

↓

Destroy Parameter

↓

Return to Caller
```

This process occurs every time the function is called.

---

# Advantages of Pass by Value

✔ Safe

The original variable cannot accidentally be modified.

---

✔ Easy to understand

Every function works on its own copy.

---

✔ Excellent for small types

Copying integers and doubles is extremely fast.

---

✔ Prevents unintended side effects

Functions cannot change the caller's data.

---

# Disadvantages

Creating copies consumes memory.

Large objects may require

- additional memory
- additional copy operations
- additional execution time

For very large containers,

Pass by Value may become inefficient.

---

# Pass by Value vs Pass by Reference

Pass by Value

```
Original

↓

Copy

↓

Function
```

Pass by Reference

```
Original

↓

Function directly accesses
the original object
```

We will study Pass by Reference in a later chapter.

---

# Scientific Computing Notes

Scientific software often processes enormous datasets.

Examples include

- particle collections
- detector hits
- simulation events
- matrices
- tensors

Copying these objects repeatedly would waste both memory and execution time.

For this reason,

scientific libraries such as

- ROOT
- Geant4
- Eigen

often prefer **Pass by Reference** for large objects.

However,

Pass by Value is still commonly used for

- integers
- floating-point values
- small structures
- flags
- configuration values

---

# Best Practices

✔ Use Pass by Value for small objects.

✔ Use meaningful parameter names.

✔ Keep functions independent whenever possible.

✔ Prefer Pass by Value when the function should not modify the caller's data.

✔ Understand that parameters are local variables.

---

# Common Mistakes

## Mistake 1

Expecting the original variable to change.

```cpp
void change(int x)
{
    x = 50;
}
```

This does **not** modify the caller's variable.

---

## Mistake 2

Passing very large vectors by value unnecessarily.

```cpp
void process(vector<double> data)
```

A complete copy is created.

Later we will replace this with references.

---

## Mistake 3

Confusing parameters with arguments.

Parameter

```cpp
void square(int number)
```

Argument

```cpp
square(value);
```

The parameter belongs to the function.

The argument belongs to the caller.

---

## Mistake 4

Assuming identical values mean identical variables.

```
number = 10

↓

copy

↓

num = 10
```

Equal values do **not** mean they occupy the same memory.

---

# Summary

After completing this chapter you should understand

- what Pass by Value means,
- why functions receive copies,
- how parameter copying works,
- why the original object remains unchanged,
- the lifetime of function parameters,
- the advantages and disadvantages of copying,
- when Pass by Value should be preferred.

---

# Exercises

## Exercise 1

Write a function

```cpp
void double_value(int number);
```

Inside the function,

double the value.

Print the variable before and after the function call.

Observe that the original value does not change.

---

## Exercise 2

Create a function

```cpp
void capitalize(string text);
```

Convert every character to uppercase.

Verify that the original string remains unchanged.

---

## Exercise 3

Create a vector containing five integers.

Pass it to a function by value.

Inside the function,

clear the vector.

Print the vector before and after the function call.

---

## Exercise 4

Print the addresses of

- the original variable
- the function parameter

Verify that they are different.

---

## Exercise 5 (Challenge)

Create a function

```cpp
void sort_vector(vector<int> values);
```

Sort the copied vector.

Print

- the sorted copy,
- the original vector.

Explain why only one of them changes.