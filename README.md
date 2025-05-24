# ft_printf

Reimplementation of the C standard `printf()` function as part of the 42 School curriculum. This version includes a complete set of commonly used format specifiers and flags, all implemented from scratch using variadic functions.

---

## Features

This library provides a custom implementation of `printf` that supports the following **conversion specifiers**:

- `%c` : Character
- `%s` : String
- `%p` : Pointer (hexadecimal format)
- `%d`, `%i` : Signed decimal integer
- `%u` : Unsigned decimal integer
- `%x`, `%X` : Unsigned hexadecimal integer (lower/uppercase)
- `%%` : Literal percent sign

In addition to these specifiers, the implementation also supports various **formatting flags and options**, including:

- **Flags**: `-` (left-align), `0` (zero-padding), `#` (alternate form), `+` (force sign), and space (add a space for positive numbers)
- **Minimum field width** and **precision** controls for all applicable conversions

All of these features work together to allow flexible and customizable output formatting, similar to the standard `printf`.

---

## How to Use

### 🔧 Compilation

```bash
git clone https://github.com/hyun-1324/ft_printf.git
cd ft_printf
make
```

This will generate the static library `libftprintf.a`.

### 💡 Example

```c
#include "ft_printf.h"

int main(void)
{
    int len = ft_printf("Hello, %s! Number: %+08d\n", "world", 42);
    ft_printf("Printed %d characters.\n", len);
    return 0;
}
```

Compile the program using:

```bash
cc main.c libftprintf.a
```

---

## License

This project is licensed under the MIT License.
See the [LICENSE](./LICENSE) file for details.
