# 🖨️ **ft_printf - A reimplementation of the beautiful printf!**

## 🚀 **Project Overview**  
The project involves rewriting the original printf function from stdio.h in C.
If you are unfamiliar with `printf()`, see this simple introduction: https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm

An essential part of my implementation of `ft_printf()` is the `va_start()`, `va_arg()` and `va_end()` macros
from the `stdarg.h` library. They are used for handling variable argument lists in functions.
- `va_start()` initializes a `va_list` variable to be used with `va_arg` and `va_end`. It must be called before accessing the variable arguments.
- `va_arg()` retrieves the next argument in the list. The type of the expected argument needs to be specified.
- `va_end()` cleans up the va_list when you are done with it. It should be called before the function returns.

The `ft_printf()` function is declared like this:
```bash
int ft_printf(const char *, ...);
```

`ft_printf()` writes to the standard output, and is limited to handling the following conversions:
- `%c` Prints a single character.
- `%s` Prints a string (as defined by the common C convention).
- `%p` The void * pointer argument has to be printed in hexadecimal format.
- `%d` Prints a decimal (base 10) number.
- `%i` Prints an integer in base 10.
- `%u` Prints an unsigned decimal (base 10) number.
- `%x` Prints a number in hexadecimal (base 16) lowercase format.
- `%X` Prints a number in hexadecimal (base 16) uppercase format.
- `%%` Prints a percent sign.

The `const char *` is a string that can contain both text and type identifiers, like "%s", "%p", etc.  
By using the function `va_start()`, the **type identifiers** in `const char *` gets connected to the data `...`.  
For example: `ft_printf("%i", 42);`  
In this example, `const char *` is `%i` and `...` is `42`.  

The function `va_arg()` is used to iterate through the type identifiers and their respective data.  
In `ft_printf()` -> whenever a type identifier is found in `const char *`, it gets connected to the next argument in `...`.  
For example: `ft_printf("Hello, world! My name is %s\n", "Bob");`  
In this example, `const char *` is `"Hello, world! My name is %s\n"`, and `...` is `"Bob"`.  
What will be printed on the standard output: `"Hello, world! My name is Bob"`.  

When `const char *` has reached the `'\0'`, meaning it has reached its end, `va_end()` is called to clean up the `va_list`.  

The return value for `ft_printf()` is an `int`, indicating **how many characters were printed**.  
It returns `-1` upon error.

---

## 🧰 **Included Files**  
- The `ft_printf.c` containing the main `ft_printf()` function, and all the printing functions for the different types.
- A `Makefile`.
- A header file.

---

## 🧑‍💻 **Cloning the Repository**

To get started, first clone the repository.
This command will clone the repo, and move you to the right directory:
```bash
git clone https://github.com/busedame/ft_printf/ ft_printf && cd ft_printf
```
---

## 🖥️ **How to Compile and Run**  

1. **Compile the library**:  
	Run the following command to compile the library:  
	```bash
	make
	```
	This simply compiles the library, but does **not** make an executable.
2. **Test the function**:
	- Either use the existing main function in `ft_printf.c` (needs to be commented out), or add a `main.c` file with a new main function.
	- Compile using this command: `cc *.c -o ft_printf`
	- Run using this command: `./ft_printf`
