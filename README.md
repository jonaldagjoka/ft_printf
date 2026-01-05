# ft_printf

*This project has been created by jgjoka.*

## Description

The ft_printf project is a recreation of the standard C library function `printf()`. Its purpose is to introduce the concept of variadic functions and to strengthen your understanding of formatted output, type handling, and modular programming in C.

This project implements a custom version of `printf()` capable of formatting and printing various data types, including characters, strings, pointers, integers, and hexadecimal numbers — without implementing the original buffering system from libc.


### Key Learning Objectives
- Understanding and implementing variadic functions in C
- Handling multiple data type conversions
- Building extensible and well-structured code
- Creating a reusable library following the 42 Norm

## Instructions

### Compilation

To compile the library, run:
```bash
make
```

This will generate the `libftprintf.a` static library file at the root of the repository.

### Available Make Rules

- `make` or `make all` - Compiles the library
- `make clean` - Removes object files (.o)
- `make fclean` - Removes object files and the library (libftprintf.a)
- `make re` - Recompiles the entire library from scratch

### Compilation Flags

The library is compiled with the following flags to ensure code quality:
- `-Wall` - Enable all warnings
- `-Wextra` - Enable extra warnings
- `-Werror` - Treat warnings as errors

### Using the Library

To use this library in your projects:

1. Include the header file in your C files:
```c
#include "ft_printf.h"
```

2. Compile your project with the library:
```bash
cc your_file.c -L. -lftprintf -o your_program
```

## Function Prototype

```c
int ft_printf(const char *, ...);
```

## Supported Conversions

The `ft_printf()` function handles the following format specifiers:

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string (as defined by common C convention) |
| `%p` | Prints a void * pointer in hexadecimal format |
| `%d` | Prints a decimal (base 10) number |
| `%i` | Prints an integer in base 10 |
| `%u` | Prints an unsigned decimal (base 10) number |
| `%x` | Prints a number in hexadecimal (base 16) lowercase format |
| `%X` | Prints a number in hexadecimal (base 16) uppercase format |
| `%%` | Prints a percent sign |

## Algorithm and Data Structure Choices

### Overall Architecture

The implementation follows a modular design pattern where the main `ft_printf()` function acts as a dispatcher that:
1. Parses the format string character by character
2. Identifies format specifiers (%)
3. Calls appropriate conversion functions based on the specifier type
4. Returns the total number of characters printed

### Key Design Decisions

**1. Dispatcher Pattern**
- A central parsing function identifies format specifiers and delegates to specialized handler functions
- Each conversion type (%c, %s, %d, etc.) has its own dedicated function
- This approach ensures code maintainability and extensibility

**2. Character-by-Character Output**
- Since buffer management is not required, output is handled through direct `write()` calls
- Each conversion function returns the number of characters it printed
- The main function aggregates these counts to return the total

**3. Variadic Function Handling**
- Uses `va_start`, `va_arg`, `va_copy`, and `va_end` macros from `<stdarg.h>`
- Safely extracts arguments of different types from the variable argument list
- Proper cleanup of va_list to prevent memory issues

**4. Number Conversion Strategy**
- Recursive or iterative approach to convert integers to their string representation
- For hexadecimal conversions, custom base conversion functions handle both lowercase and uppercase
- Pointer addresses are converted to hexadecimal with "0x" prefix

**5. Error Handling**
- Returns -1 on write errors (following standard printf behavior)
- Handles NULL pointer cases for %s conversion
- Validates format specifiers and handles unknown ones gracefully

### Justification

This modular architecture was chosen because:
- **Maintainability**: Each conversion type is isolated, making debugging and testing easier
- **Extensibility**: New format specifiers can be added without modifying existing code
- **Clarity**: The dispatcher pattern makes the control flow obvious and easy to follow
- **Norm Compliance**: Keeps functions short and focused, adhering to 42 coding standards
- **Reusability**: Individual conversion functions can be tested independently

The decision to avoid buffer management simplifies the implementation while still providing full functionality for the required conversions, making it an ideal learning project for understanding variadic functions and formatted output.

## Resources

### Documentation & References
- [C Standard Library Documentation](https://en.cppreference.com/w/c/)
- [Linux Man Pages - printf](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Variadic Functions in C](https://en.cppreference.com/w/c/variadic)
- [GNU C Library Manual](https://www.gnu.org/software/libc/manual/)
- [42 Norm Documentation](https://github.com/42School/norminette)

### Learning Resources
- K&R "The C Programming Language" (2nd Edition) - Chapter 7 (Input and Output)
- Understanding variadic functions and stdarg.h macros
- Base conversion algorithms and hexadecimal representation
- Format string parsing techniques

This hands-on approach ensured deep understanding of:
- Variadic function mechanics in C
- Type conversion and formatting
- String manipulation and number base conversion
- Building modular, extensible code architectures

## Author

**Jonalda Gjoka** (jgjoka)  
42 Network Student

---

*This library demonstrates proficiency in C programming, variadic functions, and adherence to the 42 Norm, and serves as a foundation for future 42 projects.*
