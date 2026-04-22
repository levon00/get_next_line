*This project has been created as part of the 42 curriculum by lkhalaty.*
# Get_next_line

## Description 

The **get_next_line** project is a fundamental challenge in the 42 curriculum that involves creating a function to read a line from a file descriptor.

## Project Goal 

The goal of this project is to write a function that returns a line read from a file descriptor. Whether it is a file, a redirection, or even standard input, the function must return the line ending with a newline character (\n), or NULL if there is nothing else to read or if an error occurred.

## Instructions 

### Compilation

The project must be compiled with the flag `-D BUFFER_SIZE=n` to define the buffer size for the `read()` function.

```
bash

cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

## Algorithm: Selection & Justification

Selected Algorithm: Static Buffer Persistence
The algorithm uses a Static Variable to serve as a persistent "stash" or "remainder" buffer.

### Justification
- Data Preservation: Because read() retrieves data in chunks defined by BUFFER_SIZE, it often reads past the first newline character. A static variable is the only way to store this "extra" data in the heap so it remains available for the next time the function is called.

- Memory Efficiency: By using a single string join approach, the algorithm maintains a clear flow:

Read until a newline is found in the stash.

- Extract the line to be returned to the user.

Update the stash by removing the returned line.

## Resources 

- Linux manual pages (man 3)
- GNU C Library documentation
- W3Schools.com
- 42 intranet Libft subject
- Google search resources
- Peer on the right peer on the left and someone smart in the building