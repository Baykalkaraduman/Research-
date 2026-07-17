# Boolean Data Type

---

# Objective

Learn how the Boolean data type works in C++ and understand why it is one of the most frequently used data types in programming.

---

# What is a Boolean?

A Boolean is the simplest data type in C++.

It can store only **two possible values**:

```cpp
true
false
```

Internally these values are usually stored as

```
true  -> 1

false -> 0
```

Although only two values exist, Boolean variables are extremely powerful because almost every decision a program makes depends on them.

---

# Syntax

```cpp
bool learning_stopped {false};
```

Modern C++ recommends brace initialization.

---

# Memory Representation

```
Variable

learning_stopped

↓

false

↓

0
```

After

```cpp
learning_stopped = true;
```

```
learning_stopped

↓

true

↓

1
```

---

# Printing Booleans

Without any formatting

```cpp
std::cout << learning_stopped;
```

Output

```
0

or

1
```

If you prefer

```
true

false
```

you can write

```cpp
std::cout << std::boolalpha;
```

before printing.

---

# Best Practices

✔ Use descriptive names

```cpp
bool detector_ready;

bool event_selected;

bool trigger_passed;
```

Avoid names like

```cpp
bool a;
bool x;
```

---

# Common Mistakes

❌ Writing

```cpp
bool value = 5;
```

Although valid, it is confusing.

Instead

```cpp
bool detector_ready {true};
```

---

# Physics Applications

Booleans are everywhere in High Energy Physics.

Examples

```cpp
trigger_passed

event_selected

good_muon

good_tau

isSignal

isBackground
```

ROOT, Geant4 and Coffea analyses use thousands of Boolean variables.

---

# Exercises

1. Create three Boolean variables.

2. Print them.

3. Change their values.

4. Print again.

5. Try using `std::boolalpha`.

---

# Summary

Today you learned

- bool
- true
- false
- Memory representation
- Boolean output
- Scientific applications