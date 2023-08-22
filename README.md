# Get Next Line

Get Next Line is a project from the 42 school curriculum designed to create a function that reads a line ending with a newline character (`\n`) from a file descriptor, without prior knowledge of its size. This utility allows reading text from a file or standard input, line by line.

## How it Works

### Function Prototype

```c
char *get_next_line(int fd);
```

The `get_next_line` function takes a file descriptor `fd` as an argument and returns a pointer to a string containing the next line read from `fd`. If there's nothing else to read or an error occurs, it returns `NULL`. The returned string includes the newline character, unless the end of the file is reached.

### Implementation Details

The function operates by utilizing a static variable to store remaining text from the previous read call. This remaining text is appended to the next read buffer, and the function searches for the first newline character within the combined string. The portion before the newline character is returned as the next line, and the content after the newline character is stored in the static variable for subsequent calls.

To configure the read behavior, a macro named `BUFFER_SIZE` determines the size of the read buffer. This macro can be modified at compile time using `-D BUFFER_SIZE=xx`, where `xx` represents the desired buffer size. For instance:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

Supporting utility functions (`ft_strlen`, `ft_strchr`, `ft_strdup`, `ft_strjoin`, and `ft_substr`) are defined in `get_next_line_utils.c`. These functions assist in various string manipulations.

The `get_next_line` function and its utility functions are declared in the header file `get_next_line.h`.

## Bonus Features

The project's bonus section introduces two additional features:

- Achieving `get_next_line` with a single static variable.
- Managing multiple file descriptors with `get_next_line`. This means you can seamlessly call `get_next_line` on multiple file descriptors without losing reading context.

The bonus functionalities are implemented in files named `get_next_line_bonus.c`, `get_next_line_utils_bonus.c`, and `get_next_line_bonus.h`. These files mirror the core logic of the mandatory files but utilize a linked list structure to retain static variables for each file descriptor. Each node in the list comprises:

- File descriptor number (`fd`).
- Remaining text from the previous read call (`rest`).
- A pointer to the next node (`next`).

The function locates the matching node for a given file descriptor or creates a new one if none exists. Then, it proceeds as in the mandatory part, utilizing the `rest` field of the node as the static variable.

## Testing and Verification

For testing the function, you can utilize the provided `main.c` file. This file accepts one or more file names as arguments and uses `get_next_line` to print their contents line by line. Standard input can be used by passing no arguments or using `-` as an argument.

External testers such as [gnlTester](https://github.com/topics/get-next-line), [gnl-unit-test](https://github.com/Yaten/42-get_next_line), and [gnl-station-tester](https://github.com/mcombeau/get_next_line) are available to validate your function against leaks, errors, and edge cases. These can aid in comprehensive testing of your implementation.
