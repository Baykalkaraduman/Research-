# Move Constructor (Part 1)

---

# Introduction

In the previous lessons, we learned

- Copy Constructor
- Shallow Copy
- Deep Copy

Deep Copy solved the ownership problem by allocating new memory for every copied object.

However,

Deep Copy is not always efficient.

Imagine copying an object that owns

- a large array,
- a huge image,
- millions of numbers,
- or a large physics dataset.

Creating another copy every time can become very expensive.

Modern C++ introduces a better solution for temporary objects:

**Move Semantics.**

---

# Why Do We Need Move Semantics?

Suppose an object owns

```
Heap Memory

↓

10,000,000 integers
```

Deep Copy performs

```
Allocate another heap

↓

Copy every integer

↓

Destroy old object later
```

This is correct,

but it is slow.

Now ask yourself

> What if the original object is about to be destroyed anyway?

Why copy everything,

if nobody will ever use the original object again?

Instead,

we can simply transfer ownership.

This is exactly what a Move Constructor does.

---

# Copy vs Move

Deep Copy

```
Object A

↓

Heap A

↓

100

↓

Copy

↓

Heap B

↓

100
```

Move

```
Object A

↓

Heap

↓

100

↓

Move

↓

Object B

↓

Heap

↓

100

Object A

↓

nullptr
```

Nothing is copied.

Only ownership changes.

---

# What is Moving?

Moving means

> Transfer the ownership of a resource from one object to another.

The resource itself stays exactly where it is.

Only the pointer changes owner.

Imagine moving into a new apartment.

Copying means

```
Buy another apartment

↓

Move every piece of furniture
```

Moving means

```
Take the apartment keys

↓

Old owner leaves
```

The apartment never moves.

Only ownership changes.

---

# Rvalue References

Move Constructors use

```cpp
Type&&
```

Example

```cpp
Move(Move &&source);
```

Notice the double ampersand

```
&&
```

This is called an

**Rvalue Reference.**

It can bind only to temporary objects.

---

# What is an Rvalue?

Very simply,

an rvalue is an object that is about to disappear.

Example

```cpp
Move{10}
```

This object has no name.

It exists only temporarily.

After the current expression finishes,

it will be destroyed.

Since nobody needs it anymore,

its resources can safely be moved.

---

# Constructor Declaration

```cpp
Move(Move &&source) noexcept;
```

There are three important parts.

### Move

The class name.

---

### &&source

The constructor accepts an rvalue reference.

Only temporary objects can call this constructor.

---

### noexcept

```cpp
noexcept
```

tells the compiler

> "This function will never throw an exception."

Many Standard Library containers,

especially

```cpp
std::vector
```

will only use Move Constructors if they are marked

```cpp
noexcept
```

Otherwise,

they often fall back to the Copy Constructor to guarantee exception safety.

---

# Move Constructor Implementation

```cpp
Move::Move(Move &&source) noexcept

    : data{source.data}
{
    source.data = nullptr;
}
```

At first glance,

this looks almost identical to the Shallow Copy Constructor.

It copies the pointer.

So why is it safe?

The answer is

```
source.data = nullptr;
```

Ownership is transferred,

not shared.

---

# Ownership Transfer

Before moving

```
Temporary Object

↓

Heap

100
```

After moving

```
New Object

↓

Heap

100


Temporary Object

↓

nullptr
```

The temporary object no longer owns the memory.

Only the new object does.

This prevents double deletion.

---

# Why Is nullptr Important?

Suppose we forget

```cpp
source.data = nullptr;
```

Then

```
Old Object

↓

Heap


New Object

↓

Same Heap
```

This becomes

Shallow Copy.

Both destructors would delete the same memory.

The program would crash.

Setting the source pointer to `nullptr` removes its ownership.

---

# Common Beginner Mistakes

## Mistake 1

Thinking Move Constructor copies data.

It does not.

It transfers ownership.

---

## Mistake 2

Thinking moving duplicates memory.

No new heap allocation occurs.

---

## Mistake 3

Ignoring

```cpp
source.data = nullptr;
```

Without this line,

Move Constructor becomes unsafe.

---

# Summary (Part 1)

- Move Semantics transfers ownership instead of copying resources.
- A Move Constructor accepts an rvalue reference (`&&`).
- Temporary objects are ideal candidates for moving because they will soon be destroyed.
- Moving avoids expensive memory allocations and data copies.
- Setting the source pointer to `nullptr` ensures that only one object owns the resource after the move.

> **Key Takeaway:**  
> A Move Constructor does **not create another copy of the resource**. Instead, it transfers ownership from a temporary object to a new object, making resource management both safe and highly efficient.

# Move Constructor (Part 2)

---

# Step-by-Step Execution

Let's examine the program exactly as the compiler executes it.

---

# Step 1 — Creating a Temporary Object

```cpp
vec.push_back(Move{10});
```

The compiler first creates

```cpp
Move{10}
```

This object is called a

**temporary object (rvalue).**

Execution

```
Constructor

↓

Allocate Heap

↓

Store value

↓

Temporary Object
```

Memory

```
Temporary Object

↓

data

↓

Heap

10
```

At this point,

the temporary object owns the heap memory.

---

# Step 2 — std::vector Receives the Object

The function

```cpp
push_back()
```

receives an

**rvalue.**

Since the class provides

```cpp
Move(Move&&)
```

the compiler chooses the

**Move Constructor**

instead of the Copy Constructor.

---

# Why Doesn't It Copy?

Without a Move Constructor,

the compiler would execute

```
Allocate new heap

↓

Copy value

↓

Delete old heap
```

This works,

but it is unnecessary.

The temporary object is about to disappear anyway.

Instead,

Move Constructor simply transfers ownership.

---

# Step 3 — Move Constructor

```cpp
Move::Move(Move &&source)

: data{source.data}
{
    source.data = nullptr;
}
```

Execution

```
Temporary Object

↓

Heap

10

↓

Transfer Pointer

↓

Vector Element

↓

Heap

10

↓

Temporary Object

↓

nullptr
```

Notice carefully.

Nothing has been copied.

Only the pointer changed owner.

---

# Step 4 — Temporary Object Dies

Immediately after

```cpp
push_back()
```

finishes,

the temporary object is destroyed.

Destructor

```cpp
delete data;
```

But

```
data == nullptr
```

Therefore

```
delete nullptr;
```

does absolutely nothing.

No memory is freed.

The heap still belongs to the vector element.

---

# Step 5 — Destructor Output

This explains why your program prints

```
Destructor freeing data for nullptr
```

Many beginners think

> "Something went wrong."

Actually,

this message proves

the Move Constructor worked correctly.

The temporary object no longer owns the resource.

---

# What Happens Inside the Vector?

Initially

```
Vector

(empty)
```

After

```cpp
push_back(Move{10});
```

Memory

```
Vector

↓

Move Object

↓

Heap

10
```

The temporary object disappears,

but the vector element keeps the resource.

---

# Why Are There So Many Move Constructor Calls?

Your program pushes

```cpp
10

20

30

40

50

60

70

80
```

into a vector.

However,

a vector stores its elements in one contiguous block of memory.

Sometimes,

the vector becomes full.

When this happens,

it allocates a larger block.

Example

```
Capacity

2
```

You insert

```
Third Object
```

The vector must

```
Allocate larger storage

↓

Move old elements

↓

Destroy old storage
```

Instead of copying every object,

the vector moves them.

This is much faster.

---

# Vector Reallocation

Suppose the vector currently contains

```
10

20
```

Capacity

```
2
```

Now

```cpp
push_back(Move{30});
```

The vector needs more space.

Execution

```
Allocate Bigger Memory

↓

Move 10

↓

Move 20

↓

Insert 30

↓

Destroy Old Storage
```

This is why multiple Move Constructor messages appear,

even though you only inserted one new object.

---

# Why is noexcept Important?

Your Move Constructor is declared as

```cpp
Move(Move&&) noexcept;
```

This tells the compiler

that moving an object cannot throw exceptions.

Because of this,

containers such as

```cpp
std::vector
```

are allowed to move objects during reallocation.

Without

```cpp
noexcept
```

many implementations prefer

the Copy Constructor,

because copying provides stronger exception safety guarantees.

---

# Common Beginner Mistakes

## Mistake 1

Thinking every Move Constructor call comes directly from `push_back()`.

Many of them actually happen during vector reallocation.

---

## Mistake 2

Confusing a moved-from object with a destroyed object.

A moved-from object is still alive.

It simply no longer owns the resource.

---

## Mistake 3

Believing `delete nullptr` causes an error.

It is completely safe.

The C++ Standard guarantees this behavior.

---

# Best Practices

✔ Always leave moved-from pointers in a valid state (usually `nullptr`).

✔ Mark Move Constructors as `noexcept` whenever possible.

✔ Remember that containers prefer moving over copying when available.

✔ Expect additional Move Constructor calls during container reallocation.

---

# Summary (Part 2)

- `push_back(Move{...})` creates a temporary object.
- The Move Constructor transfers ownership of the resource into the vector.
- The temporary object's pointer becomes `nullptr`.
- Destroying the temporary object is therefore completely safe.
- `std::vector` performs additional move operations whenever it reallocates its storage.
- Declaring the Move Constructor as `noexcept` allows standard containers to fully benefit from move semantics.

> **Key Takeaway:**  
> Move Constructors are especially powerful when working with standard containers such as `std::vector`. Instead of repeatedly allocating and copying resources during reallocation, the container simply transfers ownership, making object management significantly faster and more efficient.

# Move Constructor (Part 3)

---

# Copy vs Move

Although both constructors create a new object,

their behavior is fundamentally different.

## Copy Constructor

```
Original Object

↓

Heap A

↓

100

↓

Allocate New Heap

↓

Heap B

↓

100
```

Result

- Two heap allocations
- Two independent owners
- More memory usage
- More CPU time

---

## Move Constructor

```
Original Object

↓

Heap A

↓

100

↓

Transfer Ownership

↓

New Object

↓

Heap A

↓

100

Original Object

↓

nullptr
```

Result

- No additional allocation
- No data copy
- Ownership transferred
- Much faster

---

# Deep Copy vs Move Constructor

| Deep Copy | Move Constructor |
|------------|------------------|
| Allocates new memory | Reuses existing memory |
| Copies the stored data | Transfers ownership |
| More expensive | Very inexpensive |
| Source object remains unchanged | Source object becomes empty (moved-from) |
| Two valid resources exist | Only one resource remains |

---

# The Moved-From Object

After moving,

the original object still exists.

However,

its resource has been transferred.

Example

```cpp
Move obj1{100};

Move obj2{std::move(obj1)};
```

Memory

Before

```
obj1

↓

Heap

100
```

After

```
obj2

↓

Heap

100


obj1

↓

nullptr
```

The moved-from object is still valid,

but it no longer owns the resource.

This state is called

**valid but unspecified**.

---

# Why Doesn't the Program Crash?

The destructor checks

```cpp
if (data != nullptr)
```

When the moved-from object is destroyed

```
data == nullptr
```

Therefore

```cpp
delete nullptr;
```

is executed.

This is perfectly safe.

---

# std::move()

You may wonder

> How does the compiler know that an object should be moved?

The answer is

```cpp
std::move()
```

Example

```cpp
Move obj1{100};

Move obj2{std::move(obj1)};
```

Important

`std::move()` does **not** move anything by itself.

It simply tells the compiler

> "This object may be treated as an rvalue."

The actual move happens inside the Move Constructor or Move Assignment Operator.

---

# Rule of Five

Earlier,

we learned the

**Rule of Three**

```
Destructor

↓

Copy Constructor

↓

Copy Assignment Operator
```

Modern C++ extends this idea.

```
Destructor

↓

Copy Constructor

↓

Copy Assignment Operator

↓

Move Constructor

↓

Move Assignment Operator
```

This is called

**The Rule of Five.**

Whenever a class manually manages resources,

these five special member functions should usually be considered together.

---

# Why Modern C++ Loves Move Semantics

Large applications

- game engines,
- operating systems,
- scientific software,
- physics simulations,

constantly create temporary objects.

Without Move Semantics,

every temporary object would require a Deep Copy.

Move Semantics eliminates most of those unnecessary copies.

This dramatically improves performance.

---

# Move Constructor in Scientific Computing

As a physicist,

you will often work with

- large vectors,
- detector event data,
- ROOT trees,
- Geant4 objects,
- simulation results.

These objects may contain thousands or millions of elements.

Deep Copy

```
Allocate

↓

Copy Everything

↓

Destroy Old Object
```

Move Constructor

```
Transfer Ownership

↓

Continue Working
```

For scientific software,

this difference can save significant execution time.

---

# Relationship with Smart Pointers

Move Semantics is one of the foundations of Smart Pointers.

For example,

```cpp
std::unique_ptr
```

cannot be copied.

It can only be moved.

Example

```cpp
std::unique_ptr<int> p1 =
    std::make_unique<int>(10);

// Illegal
// auto p2 = p1;

auto p2 = std::move(p1);
```

Ownership is transferred,

exactly like your Move class.

Understanding Move Constructor makes Smart Pointers much easier to learn.

---

# Common Beginner Mistakes

## Mistake 1

Thinking `std::move()` physically moves data.

It only enables move semantics.

---

## Mistake 2

Using a moved-from object as if nothing happened.

A moved-from object is valid,

but its internal resource may no longer exist.

---

## Mistake 3

Assuming Move Constructor replaces Copy Constructor.

Both are necessary.

The compiler chooses the appropriate one depending on whether the source object is an lvalue or an rvalue.

---

# Best Practices

✔ Use Move Constructors for resource-owning classes.

✔ Always leave moved-from objects in a valid state.

✔ Mark Move Constructors as `noexcept` whenever possible.

✔ Prefer moving large temporary objects instead of copying them.

✔ Understand ownership before using `std::move()`.

---

# What Comes Next?

After Move Constructors,

the next major topics are usually

1. Move Assignment Operator
2. Rule of Five
3. Smart Pointers (`unique_ptr`, `shared_ptr`, `weak_ptr`)
4. RAII
5. Exception Safety

Move Constructor is the bridge connecting traditional C++ memory management with Modern C++.

---

# Final Summary

- Move Constructor transfers ownership instead of copying data.
- No additional heap allocation is required.
- The moved-from object relinquishes ownership by setting its pointer to `nullptr`.
- `std::vector` and other standard containers heavily rely on move semantics to improve performance.
- `std::move()` enables move semantics but does not move resources itself.
- Move Constructors are one of the five special member functions that form the Rule of Five.
- Understanding Move Semantics is essential before learning Smart Pointers and RAII.

---

# Key Takeaways

- **Copy duplicates resources.**
- **Move transfers ownership.**
- **Moving is usually much faster than copying.**
- **Moved-from objects remain valid but no longer own their previous resources.**
- **Move Semantics is one of the defining features of Modern C++ and is heavily used throughout the Standard Library.**

> **Final Thought:**  
> Move Semantics represents a major shift from traditional C++ programming. Rather than repeatedly duplicating expensive resources, Modern C++ transfers ownership whenever possible. This simple idea dramatically improves performance while preserving safe resource management, making Move Constructors one of the most powerful features introduced in C++11.