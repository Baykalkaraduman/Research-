# Copy Assignment & Move Assignment in C++

> [!abstract] Goal
> Understand how C++ assigns one existing object to another, why copy assignment and move assignment are different from constructors, and how dynamic memory ownership affects their implementation.

---

# 1. Assignment vs. Construction

One of the most important distinctions in C++ is:

* **Construction** → creates a new object.
* **Assignment** → modifies an object that already exists.

For example:

```cpp
Particle p1{1, "Electron", 0.000511, -1, 10.0, 0, true};
Particle p2;
```

At this point, two different objects already exist.

When we write:

```cpp
p2 = p1;
```

we are **not creating `p2`**.

We are replacing the contents of the already-existing `p2` with the contents of `p1`.

Therefore, assignment operators do **not** use an initialization list.

---

# 2. Copy Constructor vs. Copy Assignment

These two are related but happen at different times.

## Copy Constructor

Used when a **new object is created from an existing object**.

```cpp
Particle p1;
Particle p2{p1};
```

Conceptually:

```text
p1 ───────────────► p2
     copy during
     construction
```

Declaration:

```cpp
Particle(const Particle& source);
```

---

## Copy Assignment Operator

Used when **both objects already exist**.

```cpp
Particle p1;
Particle p2;

p2 = p1;
```

Declaration:

```cpp
Particle& operator=(const Particle& rhs);
```

Conceptually:

```text
p1 ───────────────► p2
     copy into an
     existing object
```

---

# 3. Why Does `operator=` Return `Particle&`?

Our copy assignment operator is:

```cpp
Particle& Particle::operator=(const Particle& rhs)
```

The return type is:

```cpp
Particle&
```

because assignment should return a reference to the object that was assigned to.

For example:

```cpp
a = b = c;
```

This works because:

```cpp
b = c
```

returns `b` by reference, which can then be assigned to `a`.

Returning `Particle&` also avoids creating an unnecessary temporary `Particle`.

---

# 4. The `rhs` Parameter

We commonly name the right-hand-side object:

```cpp
rhs
```

which means:

> right-hand side

For:

```cpp
p2 = p1;
```

we have:

```text
p2 = p1
↑    ↑
lhs  rhs
```

Therefore:

```cpp
rhs
```

refers to `p1`.

The left-hand-side object is the object represented by:

```cpp
this
```

---

# 5. Copy Assignment Operator

Our basic structure is:

```cpp
Particle& Particle::operator=(const Particle& rhs)
{
    if (this == &rhs)
        return *this;

    delete[] momentum;

    particle_id = rhs.particle_id;
    name = rhs.name;
    mass = rhs.mass;
    charge = rhs.charge;
    detector_layer = rhs.detector_layer;
    alive = rhs.alive;

    momentum = new double[3];

    momentum[0] = rhs.momentum[0];
    momentum[1] = rhs.momentum[1];
    momentum[2] = rhs.momentum[2];

    return *this;
}
```

There are several important ideas here.

---

# 6. Self-Assignment

The first check is:

```cpp
if (this == &rhs)
    return *this;
```

This protects against:

```cpp
particle = particle;
```

Here:

```cpp
this
```

points to the object on the left.

And:

```cpp
&rhs
```

is the address of the object on the right.

If they are the same object:

```text
this == &rhs
```

is `true`.

Without the check, we could accidentally destroy our own resources before attempting to copy them.

---

# 7. Why Do We Delete `momentum` First?

Our `Particle` class owns dynamically allocated memory:

```cpp
double* momentum;
```

and the constructor creates it:

```cpp
momentum = new double[3];
```

Suppose:

```cpp
Particle p1;
Particle p2;
```

Both objects own their own memory:

```text
p1 → [memory A]

p2 → [memory B]
```

Now:

```cpp
p2 = p1;
```

Before copying the new momentum into `p2`, we must release the memory that `p2` already owns:

```cpp
delete[] momentum;
```

Otherwise:

```text
p2 → [memory B]

p2 → [memory A]
```

would cause a memory leak because nobody would own `[memory B]`.

---

# 8. Deep Copy

Because `momentum` is a pointer, this would be dangerous:

```cpp
momentum = rhs.momentum;
```

This performs a **shallow copy**.

After that:

```text
p1 ─────┐
        ▼
      [memory A]
        ▲
        │
p2 ─────┘
```

Both objects would point to the same dynamically allocated array.

Then:

```cpp
delete[] p1.momentum;
```

would leave `p2.momentum` dangling.

Later, `p2` could attempt:

```cpp
delete[] p2.momentum;
```

resulting in undefined behavior.

---

## Deep Copy

Instead, we allocate a new array:

```cpp
momentum = new double[3];
```

and copy the values:

```cpp
momentum[0] = rhs.momentum[0];
momentum[1] = rhs.momentum[1];
momentum[2] = rhs.momentum[2];
```

Now:

```text
p1 → [memory A]

p2 → [memory B]
```

The values are the same, but the memory is different.

This is a **deep copy**.

---

# 9. Copying `std::string`

Unlike our manually allocated `momentum`, `name` is:

```cpp
std::string name;
```

We can simply write:

```cpp
name = rhs.name;
```

`std::string` manages its own memory internally.

We do not need:

```cpp
new
delete
```

for the string ourselves.

This is one of the major advantages of using standard library types instead of manually managing memory.

---

# 10. `num_particle` Does Not Change During Assignment

This is an important distinction.

Suppose:

```cpp
Particle p1;
Particle p2;
```

The number of particles is:

```text
num_particle = 2
```

Then:

```cpp
p2 = p1;
```

does **not** create another particle.

Therefore:

```text
num_particle = 2
```

remains unchanged.

Assignment changes the **contents** of an existing object.

It does not change the number of objects.

---

# 11. Copy Assignment vs. Copy Constructor

Consider:

```cpp
Particle p1;
Particle p2{p1};
```

The copy constructor runs.

A new object is created:

```text
p1 ─────► p2
```

Therefore the particle count increases.

But:

```cpp
Particle p1;
Particle p2;

p2 = p1;
```

does not create a new object.

Therefore:

```text
num_particle
```

does not increase.

This distinction is extremely important when managing resources.

---

# 12. Move Assignment

Move assignment is used when the right-hand side is a temporary or an object whose resources can be transferred.

Example:

```cpp
Particle p1;
Particle p2;

p2 = std::move(p1);
```

Declaration:

```cpp
Particle& operator=(Particle&& rhs);
```

The important difference is:

```cpp
const Particle& rhs
```

for copying versus:

```cpp
Particle&& rhs
```

for moving.

---

# 13. What Does `std::move` Actually Do?

A common misconception is:

> "`std::move` moves the object."

It does not actually move the data by itself.

Instead, it tells C++:

> "This object may be treated as an rvalue, so its resources may be moved from."

For example:

```cpp
p2 = std::move(p1);
```

allows the move assignment operator to take ownership of resources from `p1`.

---

# 14. Move Assignment in `Particle`

Our implementation is:

```cpp
Particle& Particle::operator=(Particle&& rhs)
{
    if (this == &rhs)
        return *this;

    delete[] momentum;

    particle_id = rhs.particle_id;
    name = rhs.name;
    mass = rhs.mass;
    charge = rhs.charge;
    detector_layer = rhs.detector_layer;
    alive = rhs.alive;

    momentum = rhs.momentum;
    rhs.momentum = nullptr;

    return *this;
}
```

The important difference is the treatment of `momentum`.

---

# 15. Copy vs. Move of `momentum`

### Copy Assignment

We need a new allocation:

```cpp
momentum = new double[3];

momentum[0] = rhs.momentum[0];
momentum[1] = rhs.momentum[1];
momentum[2] = rhs.momentum[2];
```

Conceptually:

```text
Before:

rhs ──► [A]
this ─► [B]


After:

rhs ──► [A]
this ─► [C]
```

The values are copied.

---

### Move Assignment

We transfer ownership:

```cpp
momentum = rhs.momentum;
rhs.momentum = nullptr;
```

Conceptually:

```text
Before:

rhs ──► [A]
this ─► [B]


After:

this ──► [A]
rhs  ──► nullptr
```

No new array needs to be allocated.

This is why moving can be significantly cheaper for objects that own expensive resources.

---

# 16. Why Must the Source Become `nullptr`?

After:

```cpp
momentum = rhs.momentum;
```

both pointers temporarily point to the same memory.

We therefore immediately do:

```cpp
rhs.momentum = nullptr;
```

Now ownership is clear:

```text
this ──► [A]

rhs  ──► nullptr
```

When `rhs` is eventually destroyed:

```cpp
delete[] rhs.momentum;
```

is safe because:

```cpp
delete[] nullptr;
```

is valid and does nothing.

This prevents double deletion.

---

# 17. Moved-From Objects

After:

```cpp
Particle tau;

tau = std::move(muon);
```

`muon` is still a valid C++ object.

However, its previous resources may have been transferred away.

For our class:

```cpp
muon.momentum == nullptr
```

after the move.

A moved-from object should generally be considered:

> valid but with an unspecified / moved-from state.

It can safely be:

* destroyed,
* assigned a new value,
* reset,
* used in operations that are documented to support moved-from objects.

But we should not assume it still contains its original value.

---

# 18. Why Move Assignment Does Not Increase `num_particle`

Consider:

```cpp
Particle muon;
Particle tau;

tau = std::move(muon);
```

We still have exactly two objects:

```text
muon
tau
```

We merely transferred resources from one object to another.

Therefore:

```cpp
num_particle
```

does not change.

This is different from the move constructor:

```cpp
Particle tau{std::move(muon)};
```

because here a **new object** is being constructed.

---

# 19. The Four Important Special Member Functions

Once a class manually manages a resource, these functions become especially important:

```text
Destructor
Copy Constructor
Move Constructor
Copy Assignment Operator
Move Assignment Operator
```

For our `Particle` class:

```cpp
~Particle();

Particle(const Particle& source);

Particle(Particle&& source);

Particle& operator=(const Particle& rhs);

Particle& operator=(Particle&& rhs);
```

These functions are commonly discussed together as the **Rule of Five**.

---

# 20. Rule of Five

If a class manually manages a resource and needs one of these special member functions, it often needs to explicitly consider all five:

```cpp
~Particle();

Particle(const Particle&);

Particle(Particle&&);

Particle& operator=(const Particle&);

Particle& operator=(Particle&&);
```

Why?

Because resource ownership must be handled correctly during:

* destruction,
* copying,
* moving,
* copy assignment,
* move assignment.

---

# 21. Equality Operator

We also implemented:

```cpp
bool Particle::operator==(const Particle& rhs) const
```

This allows:

```cpp
if (p1 == p2)
{
    ...
}
```

Instead of manually comparing every attribute.

For example:

```cpp
if (ele1 == ele2)
    std::cout << "They are the same.\n";
```

The operator can compare:

```cpp
mass
charge
detector_layer
alive
momentum[0]
momentum[1]
momentum[2]
```

according to the definition we choose for "equal."

---

# 22. Important: Pointer Equality vs. Value Equality

This is a particularly important lesson from our `Particle` class.

This:

```cpp
momentum == rhs.momentum
```

compares the **addresses**.

It asks:

> "Do these two pointers point to the exact same memory?"

It does NOT ask:

> "Do these two particles have the same momentum values?"

For value comparison we need:

```cpp
momentum[0] == rhs.momentum[0]
momentum[1] == rhs.momentum[1]
momentum[2] == rhs.momentum[2]
```

Therefore:

```cpp
p1.momentum == p2.momentum
```

and:

```cpp
p1.momentum[0] == p2.momentum[0]
```

are fundamentally different comparisons.

---

# 23. `const` in Assignment and Equality

The copy assignment operator uses:

```cpp
Particle& operator=(const Particle& rhs);
```

The source is `const` because copying should not modify the source.

Similarly:

```cpp
bool operator==(const Particle& rhs) const;
```

has two `const`s with different meanings.

### First `const`

```cpp
const Particle& rhs
```

means:

> This function will not modify the right-hand-side particle.

### Final `const`

```cpp
operator==(...) const
```

means:

> This function will not modify the object on which it is called.

Therefore:

```cpp
p1 == p2;
```

can be called even when `p1` is a const object.

---

# 24. Assignment Operator Syntax

When we write:

```cpp
p2 = p1;
```

C++ interprets this conceptually as:

```cpp
p2.operator=(p1);
```

Similarly:

```cpp
p2 = std::move(p1);
```

selects the move assignment overload:

```cpp
p2.operator=(std::move(p1));
```

This is the basic idea behind operator overloading:

> We define how an operator behaves for our own class.

---

# 25. Copy Assignment Example

```cpp
Particle electron;
Particle positron;

positron = electron;
```

After assignment:

```text
positron
├── same particle_id
├── same name
├── same mass
├── same charge
├── same detector layer
├── same alive state
└── independent momentum array
```

The two objects are still separate objects.

---

# 26. Move Assignment Example

```cpp
Particle muon;
Particle tau;

tau = std::move(muon);
```

After the operation:

```text
tau
└── owns the original momentum memory

muon
└── momentum == nullptr
```

The resource was transferred rather than copied.

---

# 27. A Useful Mental Model

Think of an object as having two parts:

```text
Particle object
│
├── ordinary data
│   ├── particle_id
│   ├── mass
│   ├── charge
│   └── detector_layer
│
└── owned resource
    └── momentum ─────► dynamic memory
```

Copying means:

```text
copy the values
+
create independent resources
```

Moving means:

```text
transfer ownership of resources
+
leave source in a valid moved-from state
```

---

# 28. Why This Matters for Real Physics Software

In a larger detector/particle simulation, objects can contain much more expensive resources:

```text
Particle
│
├── momentum
├── detector information
├── track data
├── hit information
├── decay products
├── calibration data
└── other dynamically managed resources
```

Copying a large object can become expensive.

Moving allows ownership of large resources to be transferred without unnecessarily duplicating them.

This becomes particularly relevant when working with:

* particle collections,
* detector hits,
* event objects,
* reconstructed tracks,
* simulation data,
* large containers.

---

# 29. Modern C++ Note

Although manually managing:

```cpp
new
delete[]
```

is useful for learning ownership and the Rule of Five, modern C++ generally prefers RAII and standard library resource-managing types.

For example, instead of:

```cpp
double* momentum;
```

a real implementation might eventually use:

```cpp
std::array<double, 3> momentum;
```

or:

```cpp
std::vector<double> momentum;
```

or another appropriate abstraction.

Then much of the manual memory-management code disappears.

However, manually implementing the current `Particle` class is excellent practice for understanding:

* ownership,
* shallow copy,
* deep copy,
* move semantics,
* resource lifetime,
* Rule of Five.

---

# 30. Key Takeaways

> [!important]
> **Construction creates an object. Assignment modifies an existing object.**

### Copy Constructor

```cpp
Particle p2{p1};
```

Creates a new object and copies resources.

### Copy Assignment

```cpp
p2 = p1;
```

Copies data into an existing object.

### Move Constructor

```cpp
Particle p2{std::move(p1)};
```

Creates a new object and transfers resources.

### Move Assignment

```cpp
p2 = std::move(p1);
```

Transfers resources into an already-existing object.

### Deep Copy

```cpp
new resource
+
copy values
```

### Move

```cpp
transfer resource
+
source = nullptr
```

### Rule of Five

```cpp
~T();

T(const T&);

T(T&&);

T& operator=(const T&);

T& operator=(T&&);
```

---

# 31. Quick Comparison Table

| Operation        | New object? | Copies resource? | Transfers resource? | Changes object count? |
| ---------------- | ----------: | ---------------: | ------------------: | --------------------: |
| Copy Constructor |         Yes |              Yes |                  No |                   Yes |
| Move Constructor |         Yes |               No |                 Yes |                   Yes |
| Copy Assignment  |          No |              Yes |                  No |                    No |
| Move Assignment  |          No |               No |                 Yes |                    No |
| Destructor       |          No |               No |            Releases |        Yes, decreases |

---

# 32. Current `Particle` Class Progress

At this stage, the `Particle` class has been used to practice:

* Classes and objects
* Constructors
* Default arguments
* Constructor initialization lists
* Getters
* Setters
* `const` member functions
* Static data members
* Static member functions
* Destructors
* Dynamic memory
* Pointers
* Deep copying
* Copy constructor
* Move constructor
* Copy assignment
* Move assignment
* `std::move`
* `nullptr`
* Equality operator
* Operator overloading
* Resource ownership
* Rule of Five

This gives a strong foundation for moving toward more advanced object-oriented C++ concepts such as:

```text
Operator Overloading
        ↓
Inheritance
        ↓
Polymorphism
        ↓
Particle hierarchy
        ↓
Detector–Particle interaction
        ↓
Larger simulation architecture
```

> [!note]
> The important goal is not merely memorizing the syntax of these operators. The real concept is understanding **who owns a resource, when that resource is copied, when it is transferred, and when it must be destroyed**.
