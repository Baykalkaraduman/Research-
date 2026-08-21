# C++ I/O Stream Manipulators: Integer Formatting

## Concept Overview & Core Mechanics
C++ streams allow you to format integer output into different numerical bases (Decimal, Hexadecimal, Octal) and control the visual presentation of these numbers (prefixes, casing, explicit signs).

* **Statefulness:** Just like boolean manipulators, integer base manipulators (`std::hex`, `std::oct`, `std::dec`) are **stateful**. Once you switch `std::cout` to hex, *every* subsequent integer printed to the console will be in base 16 until you explicitly switch it back to decimal.
* **The `basefield`:** Internally, the base format is controlled by a bitmask called `std::ios::basefield`. You cannot simply toggle hex "off"; you must either set another base (like `std::dec`) or clear the entire basefield to restore the default.
* **Prefixes (`showbase`):** In programming, `0x` denotes a hexadecimal number, and a leading `0` denotes an octal number. The `showbase` manipulator automatically prepends these to avoid ambiguity.

## Syntax & Minimal Clean Code Examples

### Changing Bases and Showing Prefixes
```cpp
#include <iostream>

int main() {
    int memoryAddress = 255;
    
    // Using inline manipulators
    std::cout << std::showbase << std::hex << memoryAddress << "\n"; // Output: 0xff
    std::cout << std::uppercase << memoryAddress << "\n";            // Output: 0XFF
    
    // Reverting to normal decimal
    std::cout << std::dec << std::nouppercase << std::noshowbase;
    std::cout << memoryAddress << "\n";                              // Output: 255
    
    return 0;
}
```

### Forcing Positive Signs
```cpp
#include <iostream>

int main() {
    int velocity = 150;
    // Forces a '+' sign. Only works for base 10 (std::dec).
    std::cout << std::showpos << velocity << "\n"; // Output: +150
    return 0;
}
```

## Common Pitfalls & Edge Cases

* **The Silent Hex Bug:**
  * *Anti-pattern:* Setting `std::cout << std::hex` to print a debug memory address, but forgetting to set it back to `std::dec`. Later in the code, a user's health points (`100`) print as `64`.
  * *Best Practice:* Always immediately restore `std::dec` after a hex print, or write a custom logging macro that isolates stream states.
* **Resetting the Base Properly:**
  * *Anti-pattern:* `std::resetiosflags(std::ios::hex);` does **not** work correctly on all compilers because the base is controlled by a unified bitmask, not individual flags.
  * *Fix:* Use `std::resetiosflags(std::ios::basefield);` to completely reset the numerical base to default (decimal).
* **`showpos` and Non-Decimal Bases:**
  * *Edge Case:* The `std::showpos` manipulator is explicitly ignored by `std::hex` and `std::oct`. Hex and octal representations are traditionally used for raw bit patterns (unsigned concepts), so C++ does not prepend `+` or `-` to them even if `showpos` is active.

## Scientific & Physics Simulation Applications

Integer manipulation is vital when stepping out of pure math and interacting with hardware, memory, or specific data file formats.

* **Physics Collision Bitmasks (Hexadecimal):**
  * **Scenario:** In physics engines (like Box2D or PhysX), collision layers are stored as 32-bit integers (e.g., Layer 1 = `0x0001`, Layer 2 = `0x0002`, Layer 3 = `0x0004`).
  * **Application:** When logging which collision layers an object belongs to, printing `15` is useless. You print `std::showbase << std::hex << 15`, which outputs `0xf` (binary `1111`), immediately showing the developer that the object exists on the first 4 collision layers.
* **Telemetry Data Standardization (`showpos`):**
  * **Scenario:** Logging acceleration vectors `(Ax, Ay, Az)` to a CSV file.
  * **Application:** Parsing data in Python/MATLAB is often cleaner if columns align perfectly. Using `std::showpos` ensures that positive values get a `+` sign (e.g., `+9.81`), perfectly aligning with negative values (`-9.81`) in monospaced log files.
* **Binary File Magic Numbers:**
  * Many scientific file formats (like custom CFD binary caches) start with a "Magic Number" to identify the file type. When reading the header for debugging, printing it in Hexadecimal is the industry standard (e.g., reading `0xDEADBEEF` to confirm the file is valid).

## Key Takeaways & Cheatsheet

* **`std::dec` / `std::hex` / `std::oct`**: Changes the numerical base.
* **`std::showbase`**: Adds `0x` for hex, `0` for octal. (`std::noshowbase` removes it).
* **`std::uppercase`**: Converts `0x` and `a-f` to `0X` and `A-F`. (`std::nouppercase` reverts).
* **`std::showpos`**: Forces a `+` sign for positive *decimal* numbers only. (`std::noshowpos` reverts).
* **Resetting Base**: `std::cout << std::resetiosflags(std::ios::basefield);` returns the stream to standard base 10.