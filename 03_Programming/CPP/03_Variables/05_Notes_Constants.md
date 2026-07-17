# Constants in C++

---

# Objective

Learn how constants work in C++ and understand why they improve code safety, readability, and maintainability.

---

# What is a Constant?

A constant is a variable whose value cannot be changed after it is initialized.

```cpp
const double tax_rate {0.06};
```

Once created,

```cpp
tax_rate = 0.08;
```

is illegal.

The compiler will generate an error.

---

# Why Use Constants?

Imagine writing

```cpp
0.06
```

many times in your program.

If the tax changes to

```
8%
```

you must update every occurrence.

Instead,

```cpp
const double tax_rate {0.06};
```

allows you to modify the value in only one place.

---

# Syntax

```cpp
const double pi {3.141592653589793};
```

```cpp
const int maximum_events {1000};
```

```cpp
const bool detector_ready {true};
```

---

# Constant Naming

Use descriptive names.

Good examples

```cpp
tax_rate

speed_of_light

planck_constant

electron_mass

beam_energy
```

Avoid

```cpp
a

b

x

constant1
```

---

# Memory

Constants occupy memory just like ordinary variables.

The difference is that they become read-only after initialization.

```
Memory

↓

tax_rate

↓

0.06

↓

Cannot be modified
```

---

# Best Practices

✔ Use `const` whenever a value should never change.

✔ Give constants descriptive names.

✔ Group related constants together.

✔ Replace magic numbers with named constants.

---

# What is a Magic Number?

A magic number is a numerical value written directly into the code without explanation.

Example

```cpp
price * 0.06
```

Better

```cpp
price * tax_rate
```

The second version is easier to understand and maintain.

---

# Physics Applications

Constants are essential in scientific programming.

Examples

```cpp
const double speed_of_light {299792458.0};

const double planck_constant {6.62607015e-34};

const double proton_mass {1.6726219e-27};

const double electron_charge {1.602176634e-19};
```

Scientific software often contains hundreds of physical constants.

---

# Exercises

1. Create a constant for π.

2. Create a constant for the speed of light.

3. Create a constant for Planck's constant.

4. Calculate kinetic energy using constants.

5. Replace every magic number in one of your previous programs with named constants.

---

# Connections

This topic will be used later in

- Functions
- Arrays
- Loops
- Classes
- Templates
- ROOT
- Geant4
- Scientific Simulations

---

# Summary

Today you learned

- const
- Read-only variables
- Magic numbers
- Better program design
- Scientific constants
- Professional coding practices