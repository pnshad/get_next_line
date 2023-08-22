# get_next_line

## Introduction

Welcome to the `get_next_line` project, an essential exercise designed to deepen your understanding of file manipulation, memory management, and the intricate processes involved in reading data from files within an operating system. This project challenges you to implement a highly practical function capable of extracting individual lines from a file descriptor.

## Description

The primary goal of this project is to cultivate your expertise in the intricacies of file operations, illuminating the nuances of opening, reading, and closing files in an OS environment. You will gain insights into how files are interpreted by programming languages for analysis, a foundational skill for developers frequently engaged in data management and persistence tasks.

## Guidelines and Resources

For detailed instructions, refer to the project's subject documentation. Additionally, you can explore further resources such as:

- [Libft](https://github.com/your-username/libft) (or your custom standard library functions implementation)
- [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester) for comprehensive testing

## Features

- A function that reads and returns a line from a file descriptor.
- The capability to efficiently process data from multiple file descriptors simultaneously (bonus).

## Folder Structure

The project repository is organized as follows:

- `get_next_line.c`: Main implementation of the `get_next_line` function.
- `get_next_line_utils.c`: Utility functions required for the main implementation.
- `get_next_line.h`: Header file containing function prototypes and necessary includes.

## Usage

### Incorporating the Function

To integrate the `get_next_line` function into your code, include its header:

```c
#include "get_next_line.h"
```

When compiling your code, ensure you include the source files and set the appropriate buffer size:

```sh
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=<size> get_next_line.c get_next_line_utils.c
```

## Testing

To assess the functionality of the `get_next_line` function, edit the `get_next_line.c` file and uncomment the main function and headers. Modify the `test.txt` file for varying test cases. Execute the following command (replace "xx" with your desired buffer size):

```sh
gcc -Wall -Werror -Wextra -D BUFFER_SIZE=xx get_next_line.c get_next_line_utils.c && ./a.out
```

Alternatively, employ the [Tripouille/gnlTester](https://github.com/Tripouille/gnlTester) tool for comprehensive testing.

## Contributing

Contributions are welcome! If you find any issues or improvements, please feel free to open an issue or create a pull request.

## License

This project is released under the [MIT License](LICENSE), granting you the freedom to use, modify, and distribute the code according to the terms outlined.

## Acknowledgements

We would like to express our gratitude to the developers and contributors of related tools and libraries that have made this project possible.
