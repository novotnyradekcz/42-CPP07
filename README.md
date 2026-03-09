*This project has been created as part of the 42 curriculum by rnovotny.*

# C++ Module 07 - C++ Templates

## Description

This project is part of the 42 C++ modules series, focusing on **template programming** in C++. The module introduces generic programming through function templates and class templates, enabling code reuse and type safety.

The project demonstrates how templates allow writing type-independent code that works with any data type, eliminating the need for code duplication while maintaining compile-time type checking.

The project is divided into three progressive exercises:

- **Exercise 00**: Basic function templates (`swap`, `min`, `max`)
- **Exercise 01**: Advanced function template (`iter`) that applies functions to array elements
- **Exercise 02**: Class template (`Array<T>`) implementing a generic array with bounds checking

### Key Concepts Covered

- **Function templates**: Generic functions that work with any type
- **Class templates**: Generic classes with type parameters
- **Template instantiation**: How the compiler generates code for each type
- **Template specialization**: Customizing templates for specific types
- **Template implementation in headers**: Why templates must be defined in header files
- **Two-phase compilation**: Template definition vs. template instantiation
- **Type deduction**: Automatic type inference by the compiler
- **.tpp files**: Separating template declarations from implementations

## Instructions

### Compilation

Each exercise can be compiled independently using the provided Makefile:

```bash
# Navigate to an exercise directory
cd ex00  # or ex01, ex02

# Compile
make

# Run
./whatever  # ex00
./iter      # ex01
./array     # ex02
```

### Compilation Flags

All exercises compile with:
```
c++ -Wall -Wextra -Werror -std=c++98
```

### Clean Up

```bash
make clean   # Remove object files
make fclean  # Remove object files and executable
make re      # Recompile from scratch
```

## Exercise Details

### Exercise 00: Start with a Few Functions
**Files**: `whatever.hpp`, `main.cpp`

**Features**:
- `swap<T>`: Swaps two values of any type
- `min<T>`: Returns the smaller of two values (returns second if equal)
- `max<T>`: Returns the larger of two values (returns second if equal)
- All templates defined in header file
- Works with any type that supports comparison operators

**Usage Example**:
```cpp
int a = 2, b = 3;
swap(a, b);
std::cout << "min(a, b) = " << min(a, b) << std::endl;  // 2
std::cout << "max(a, b) = " << max(a, b) << std::endl;  // 3

std::string c = "chaine1", d = "chaine2";
swap(c, d);
std::cout << "min(c, d) = " << min(c, d) << std::endl;  // chaine1
```

### Exercise 01: Iter
**Files**: `iter.hpp`, `main.cpp`

**Features**:
- Template function that takes:
  1. Array address
  2. Array length
  3. Function to apply to each element
- Works with any array type and any function
- Supports both const and non-const elements through template overloading
- Function parameter can be:
  - Regular function
  - Function template
  - Takes argument by const reference or non-const reference

**Implementation Highlights**:
```cpp
template <typename T, typename F>
void iter(T* array, size_t length, F func)
{
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}

// Const overload for const arrays
template <typename T, typename F>
void iter(const T* array, size_t length, F func)
{
    for (size_t i = 0; i < length; i++)
        func(array[i]);
}
```

**Usage Example**:
```cpp
int arr[] = {1, 2, 3, 4, 5};

// Apply function to each element
iter(arr, 5, increment<int>);  // Modifies elements

// Print each element
iter(arr, 5, print<int>);      // Read-only operation
```

### Exercise 02: Array
**Files**: `Array.hpp`, `Array.tpp`, `main.cpp`

**Features**:
- Generic array class template `Array<T>`
- Default constructor creates empty array
- Parameterized constructor `Array(unsigned int n)` creates array of n elements
- Copy constructor performs deep copy
- Assignment operator performs deep copy
- Subscript operator `[]` with bounds checking
- `size()` method returns number of elements
- Custom exception `OutOfBoundsException` for invalid indices
- Both const and non-const versions of `operator[]`

**Why .tpp File?**:
- Separates template declaration (`.hpp`) from implementation (`.tpp`)
- Keeps code organized and readable
- Still included in header (templates need visible implementation)
- Common convention for template implementation files

**Usage Example**:
```cpp
// Create array of 5 integers
Array<int> numbers(5);

// Access and modify elements
numbers[0] = 42;
numbers[1] = 100;

// Get size
std::cout << "Size: " << numbers.size() << std::endl;

// Deep copy
Array<int> copy(numbers);
copy[0] = 999;  // Doesn't affect original

// Out of bounds throws exception
try {
    numbers[10] = 0;  // Throws OutOfBoundsException
} catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
}
```

## Template Programming Concepts

### Why Templates?

Templates solve the code duplication problem:

**Without templates**:
```cpp
void swap(int& a, int& b) { /* ... */ }
void swap(double& a, double& b) { /* ... */ }
void swap(string& a, string& b) { /* ... */ }
// Need separate function for each type!
```

**With templates**:
```cpp
template <typename T>
void swap(T& a, T& b) { /* ... */ }
// Works with all types!
```

### Template Instantiation

When you use a template, the compiler generates actual code:

```cpp
Array<int> intArray(5);     // Compiler generates Array<int> class
Array<string> strArray(3);  // Compiler generates Array<string> class
```

Each instantiation creates a separate class - it's like having `ArrayInt` and `ArrayString`.

### Why Templates in Headers?

Templates need to be fully visible at compile time:

```cpp
// ❌ DOESN'T WORK
// Array.hpp (declaration only)
template <typename T> class Array { ... };

// Array.cpp (implementation)
template <typename T> T& Array<T>::operator[](size_t i) { ... }
// Linker error! Implementation not visible during compilation
```

```cpp
// ✅ WORKS
// Array.hpp (declaration)
template <typename T> class Array { ... };
#include "Array.tpp"  // Include implementation

// Array.tpp (implementation)
template <typename T> T& Array<T>::operator[](size_t i) { ... }
```

### Type Requirements

Templates require types to support certain operations:

- `swap<T>`: Needs copy constructor and assignment operator
- `min<T>`, `max<T>`: Need `operator<` and `operator>`
- `Array<T>`: Needs default constructor, copy constructor, assignment operator

## Project Structure

```
CPP/07/
├── README.md
├── ex00/
│   ├── whatever.hpp
│   ├── main.cpp
│   └── Makefile
├── ex01/
│   ├── iter.hpp
│   ├── main.cpp
│   └── Makefile
└── ex02/
    ├── Array.hpp
    ├── Array.tpp
    ├── main.cpp
    └── Makefile
```

## Technical Choices

### typename vs class

```cpp
template <typename T>  // ✅ Modern, preferred
template <class T>     // ✅ Also valid, same meaning
```

Both are interchangeable. `typename` is preferred because `T` doesn't have to be a class type.

### .tpp Extension

Using `.tpp` (Template PreProcessor) for template implementations:
- **Pros**: Clearly separates declaration from implementation
- **Pros**: Improves code organization and readability
- **Cons**: Must be included in header (can't compile separately)

Alternative: Put everything in `.hpp` file (also valid but less organized).

### Two-Phase Name Lookup

Templates are compiled in two phases:

**Phase 1**: Template definition
- Check syntax
- Check non-dependent names

**Phase 2**: Template instantiation
- Check dependent names (names that depend on template parameters)
- Generate actual code

This is why template errors can be cryptic!

### Supporting Const and Non-Const

In Exercise 01, two overloads handle const-ness:

```cpp
template <typename T, typename F>
void iter(T* array, size_t length, F func);  // Non-const version

template <typename T, typename F>
void iter(const T* array, size_t length, F func);  // Const version
```

The compiler automatically selects the appropriate version based on array type.

## Resources

### Official Documentation
- [C++ Templates](https://en.cppreference.com/w/cpp/language/templates)
- [Function Templates](https://en.cppreference.com/w/cpp/language/function_template)
- [Class Templates](https://en.cppreference.com/w/cpp/language/class_template)
- [Template Specialization](https://en.cppreference.com/w/cpp/language/template_specialization)
- [Template Argument Deduction](https://en.cppreference.com/w/cpp/language/template_argument_deduction)

### Books and Tutorials
- [C++ Templates: The Complete Guide](https://www.oreilly.com/library/view/c-templates-the/9780134778006/) - Comprehensive reference
- [Learn C++ Templates](https://www.learncpp.com/cpp-tutorial/template-classes/)
- [GeeksforGeeks: Templates in C++](https://www.geeksforgeeks.org/templates-cpp/)
- [cplusplus.com: Templates](http://www.cplusplus.com/doc/oldtutorial/templates/)

### Advanced Topics (Beyond C++98)
- Variadic templates (C++11)
- Template metaprogramming
- SFINAE (Substitution Failure Is Not An Error)
- Concepts (C++20)
- Perfect forwarding (C++11)

### AI Usage

AI assistance was used for the following tasks in this project:

- **Exercise 00 - Function Templates**:
  - Basic template syntax and structure for `swap`, `min`, and `max`
  - Understanding how to return references (`const T&`) vs values
  - Test cases covering different types (int, double, string)

- **Exercise 01 - Iter Template**:
  - Template function accepting function pointers/functors as parameters
  - Understanding template type deduction with function parameters
  - Implementing two overloads for const and non-const array support
  - Creating test functions that work with the iter template (increment, print, toUpperCase)
  - Test cases demonstrating both modifying and non-modifying operations

- **Exercise 02 - Array Class Template**:
  - Class template structure with separate `.hpp` and `.tpp` files
  - Understanding why `new T[n]()` default-initializes elements
  - Implementing deep copy in copy constructor and assignment operator
  - Both const and non-const versions of `operator[]`
  - Exception handling for out-of-bounds access
  - Understanding why template implementations must be in headers
  - Proper memory management with `new[]` and `delete[]`

- **General Template Understanding**:
  - Template instantiation process
  - Two-phase compilation model
  - How the compiler generates code for each template instantiation

- **Testing**: Generated comprehensive test cases including:
  - Multiple data types (int, double, string, char)
  - Edge cases (empty arrays, single elements)
  - Copy semantics verification (deep copy testing)
  - Exception handling for boundary conditions
  - Const-correctness testing

- **Documentation**:
  - Code examples demonstrating template usage
  - This README structure and content

All AI-generated code was thoroughly reviewed, tested, and understood. Special attention was paid to understanding template mechanics, compilation models, and why certain design choices (like header-only implementation) are necessary in C++98.

## Notes

- All template code is in header files (`.hpp` and `.tpp`)
- No function implementations in `.cpp` files (except `main.cpp`)
- Templates follow C++98 standard (no variadic templates, no perfect forwarding)
- Deep copying is properly implemented in `Array<T>`
- Memory management prevents leaks (tested with valgrind)
- Exception safety maintained throughout
- Orthodox Canonical Form followed for `Array<T>` class

### Common Pitfalls Avoided

1. **Forgetting default initialization**: Using `new T[n]()` instead of `new T[n]`
2. **Shallow copying**: Properly implementing deep copy in copy constructor and assignment
3. **Missing const overloads**: Providing both const and non-const versions where needed
4. **Template code in .cpp**: All template code kept in headers
5. **Self-assignment**: Checking `if (this != &other)` in assignment operator

### Why This Module Matters

Templates are fundamental to modern C++ because they:
- Enable generic programming and code reuse
- Provide type safety at compile time (unlike void*)
- Have zero runtime overhead (everything resolved at compile time)
- Form the foundation of the STL (Standard Template Library)
- Allow creation of container classes like vector, map, etc.

Understanding templates is essential for:
- Reading and understanding STL code
- Creating reusable libraries
- Writing efficient, type-safe generic code
- Advanced C++ programming (metaprogramming, SFINAE, etc.)

---

*Project completed as part of the 42 Common Core curriculum.*
