# Range-Based For Loops

---

# Introduction

Introduced in **C++11**, the **Range-Based For Loop** provides a simpler and safer way to iterate through every element of a collection.

Instead of manually managing an index variable, checking loop conditions, and incrementing the counter, the compiler automatically iterates over every element.

Because of its readability and safety, this loop is widely used in Modern C++ and throughout the Standard Template Library (STL).

---

# Traditional for Loop vs Range-Based for Loop

Traditional loop

```cpp
std::vector<int> numbers {10,20,30,40};

for (size_t i = 0; i < numbers.size(); ++i)
{
    std::cout << numbers[i] << std::endl;
}
```

Range-based loop

```cpp
for (int number : numbers)
{
    std::cout << number << std::endl;
}
```

Both produce the same output, but the second version is much easier to read.

---

# General Syntax

```cpp
for(type variable : collection)
{
    statements;
}
```

The loop automatically visits every element inside the collection.

The programmer does not need to write

- initialization
- condition
- increment

The compiler generates these internally.

---

# Using auto

Instead of writing the type manually,

```cpp
for(double value : temperatures)
```

we usually write

```cpp
for(auto value : temperatures)
```

The compiler automatically determines the correct type.

This makes code shorter and easier to maintain.

Modern C++ heavily relies on `auto`.

---

# Supported Collections

Range-based loops work with many different containers.

Examples include

- Arrays
- std::vector
- std::string
- std::array
- std::list
- std::set
- std::map
- Initializer Lists

Example

```cpp
for(auto value : {1,2,3,4,5})
{
    std::cout << value << std::endl;
}
```

---

# Iterating Over Arrays

```cpp
int scores[]{10,20,30};

for(auto score : scores)
{
    std::cout << score << std::endl;
}
```

Output

```
10
20
30
```

---

# Iterating Over Vectors

```cpp
std::vector<double> temperatures
{
    17.5,
    18.2,
    21.3
};

for(auto temp : temperatures)
{
    std::cout << temp << std::endl;
}
```

---

# Calculating an Average

Range-based loops are perfect for summations.

```cpp
double sum{0};

for(auto value : temperatures)
{
    sum += value;
}

double average = sum / temperatures.size();
```

This pattern appears constantly in scientific programming.

---

# Iterating Over Strings

A string is simply a collection of characters.

```cpp
std::string detector {"CMS"};

for(char letter : detector)
{
    std::cout << letter << ' ';
}
```

Output

```
C M S
```

---

# Modifying Elements

Normally,

```cpp
for(auto value : numbers)
```

creates a **copy** of each element.

Changing the copy does **not** change the original vector.

Example

```cpp
for(auto value : numbers)
{
    value *= 10;
}
```

The original vector remains unchanged.

---

# Using References

To modify the actual elements,

use a reference.

```cpp
for(auto &value : numbers)
{
    value *= 10;
}
```

Now every element inside the vector is updated.

Original

```
1 2 3 4 5
```

After modification

```
10 20 30 40 50
```

---

# Using const References

The most common professional style is

```cpp
for(const auto& value : numbers)
```

Advantages

- No copying
- Faster
- Cannot accidentally modify the data

Whenever you only need to read data, this is usually the preferred approach.

---

# Copy vs Reference

Copy

```cpp
for(auto value : numbers)
```

Changes do not affect the original container.

Reference

```cpp
for(auto &value : numbers)
```

Changes affect the original container.

Constant Reference

```cpp
for(const auto& value : numbers)
```

Read-only access with maximum efficiency.

---

# When Should You Use Range-Based Loops?

Use them whenever

- every element must be visited,
- the index itself is unnecessary,
- readability is important.

Do **not** use them if

- you need the element index,
- you must skip arbitrary positions,
- you need complex indexing logic.

---

# Scientific Computing Notes

Range-based loops appear frequently in scientific software.

Examples include

- ROOT event collections
- Geant4 particle lists
- Detector hit collections
- Monte Carlo particles
- Eigen containers
- Standard Template Library algorithms

Typical HEP code

```cpp
for(const auto& particle : particles)
{
    std::cout << particle.energy() << std::endl;
}
```

This style is extremely common in High Energy Physics analyses.

---

# Best Practices

✔ Prefer range-based loops whenever possible.

✔ Use `auto` to improve readability.

✔ Use `const auto&` when reading complex objects.

✔ Use `auto&` only when modifying elements.

✔ Avoid unnecessary copies of large objects.

---

# Common Mistakes

## Modifying Copies

Incorrect

```cpp
for(auto value : numbers)
{
    value *= 2;
}
```

The vector does not change.

Correct

```cpp
for(auto &value : numbers)
{
    value *= 2;
}
```

---

## Forgetting const

If elements should not be modified,

prefer

```cpp
for(const auto& value : numbers)
```

This prevents accidental changes.

---

## Using Range-Based Loops When the Index is Needed

Sometimes the position is important.

Example

```cpp
numbers[5]
```

In such situations, a traditional `for` loop is the better choice.

---

# Summary

After completing this chapter you should understand

- why range-based loops exist,
- how they simplify iteration,
- how `auto` works,
- the difference between copies and references,
- when to use `auto&`,
- when to use `const auto&`,
- where range-based loops are used in scientific programming.

---

# Exercises

## Exercise 1

Create an array of five integers.

Print every element using a range-based loop.

---

## Exercise 2

Create a vector containing ten temperatures.

Calculate the average using a range-based loop.

---

## Exercise 3

Create a string.

Print every character on a separate line.

---

## Exercise 4

Create a vector of integers.

Multiply every element by 5 using `auto&`.

Display the updated vector.

---

## Exercise 5 (Challenge)

Create a vector containing particle energies.

Using a range-based loop,

print only the energies larger than **20 GeV**.

(Hint: Combine `const auto&` with an `if` statement.)