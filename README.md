# C Code Formatter

This project is a simple **C source code formatter** written in C.  
It processes C code from standard input (`stdin`) and prints a formatted version to standard output (`stdout`).

---

## Features

- Handles **indentation** using `{` and `}` blocks.
- Preserves **preprocessor directives** (`#include`, `#define`, etc.).
- Correctly manages:
  - **Parentheses**
  - **Quotes** (single `'` and double `"`)
  - **Escaped characters** (`\`, `\\`)
- Normalizes **whitespace**.

---

## Build & Run

```bash
# Compile
make

# Run on a file
./formatter < input.c > output.c
```

Example:

Input:
```C
#include <stdio.h>
int main(){printf("Hello, world!\n");return 0;}
```

Output:
```C
#include <stdio.h>

int main() {
    printf("Hello, world!\n");
    return 0;
}
```
