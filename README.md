*This project has been created as part of the 42 curriculum by mohodeh for the libft project.*

# libft

## Description

libft is a personal C library. It reimplements a set of standard C library functions, adds a few helpers for working with strings and file descriptors, and provides a singly linked list. The goal is to understand how these functions work by writing them from scratch, and to end up with a reusable library for later C projects.

The library is built as a static archive, `libft.a`, using only the functions the subject allows. The three parts are:

- **Part 1, libc functions:** character tests and conversions, string and memory functions, `atoi`, `calloc`, and `strdup`.
- **Part 2, additional functions:** string utilities (`substr`, `strjoin`, `strtrim`, `split`, `strmapi`, `striteri`), `itoa`, and output helpers that write to a file descriptor.
- **Part 3, linked lists (bonus):** a `t_list` node type and functions to create, add, count, search, iterate, map, and delete nodes.

## Instructions

### Requirements

- A C compiler (`cc`) and `make`.

### Build

```sh
make          # builds the mandatory library, libft.a
make bonus    # also adds the linked-list functions to libft.a
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # fclean, then make again
```

Every `.c` file is compiled with `-Wall -Wextra -Werror`.

### Use the library

Include the headers and link against the archive:

```c
#include "libft.h"          /* or "libft_bonus.h" for the list functions */

int main(void)
{
    ft_putendl_fd("hello", 1);
    return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c libft.a -I. -o program
```

## Library reference

### Headers

- `libft.h` declares the mandatory functions and the `t_list` structure.
- `libft_bonus.h` declares the linked-list functions. It includes `libft.h`.

### Character functions

- `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`: return `1` if the character is in the class, `0` otherwise.
- `ft_toupper`, `ft_tolower`: convert a letter's case. Other characters are returned unchanged.

### String functions

- `ft_strlen`: length of a string, not counting the terminator.
- `ft_strlcpy`, `ft_strlcat`: size-limited copy and concatenation. Both always terminate the destination when `dstsize` allows, never write past `dstsize`, and return the length the result would have had without truncation.
- `ft_strchr`, `ft_strrchr`: first or last occurrence of a character. Searching for `'\0'` returns a pointer to the terminator.
- `ft_strncmp`: compares at most `n` characters.
- `ft_strnstr`: finds a needle in the first `len` characters of a haystack. An empty needle returns the haystack.
- `ft_substr`: a new string copied from `s`, starting at `start`, at most `len` characters. Returns an empty string if `start` is past the end.
- `ft_strjoin`: a new string made from `s1` followed by `s2`.
- `ft_strtrim`: a new string with the characters in `set` removed from both ends.
- `ft_split`: splits a string on a delimiter character. Returns a `NULL`-terminated array of new strings. Free each string, then the array.
- `ft_strmapi`: a new string made by applying `f(index, character)` to each character.
- `ft_striteri`: applies `f(index, &character)` to each character in place.
- `ft_strdup`: a new copy of a string.

### Memory functions

- `ft_memset`, `ft_bzero`: fill memory with a byte, or with zeros.
- `ft_memcpy`: copies `n` bytes. The regions must not overlap.
- `ft_memmove`: copies `n` bytes, and works even when the regions overlap.
- `ft_memchr`: first occurrence of a byte within `n` bytes.
- `ft_memcmp`: compares `n` bytes as unsigned characters.
- `ft_calloc`: allocates zeroed memory for `count` items of `size` bytes. Returns `NULL` if the multiplication would overflow or the allocation fails.

### Conversion functions

- `ft_atoi`: skips leading whitespace, reads an optional sign, then reads digits. Stops at the first non-digit. Handles `INT_MIN`.
- `ft_itoa`: a new string holding the decimal form of an `int`, with a leading `-` for negative numbers.

### Output functions

- `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`: write a character, string, string with newline, or integer to a file descriptor using `write`.

### Linked lists (bonus)

`t_list` has two members: `content`, a `void *` to the data, and `next`, a pointer to the following node (`NULL` for the last one).

- `ft_lstnew`: creates a node with the given content.
- `ft_lstadd_front`, `ft_lstadd_back`: insert a node at the start or end of a list.
- `ft_lstsize`: number of nodes in a list.
- `ft_lstlast`: the last node of a list.
- `ft_lstdelone`: frees one node and its content, using a `del` function. Does not touch the next node.
- `ft_lstclear`: frees every node in a list and sets the list pointer to `NULL`.
- `ft_lstiter`: applies `f` to each node's content.
- `ft_lstmap`: builds a new list where each node's content is `f` applied to the original. If an allocation fails, it frees the partial list and returns `NULL`.

## Resources

### References

- `man 3` pages for the standard functions reimplemented here, such as `man 3 strlen`, `man 3 strlcpy`, `man 3 memmove`, `man 3 calloc`, and `man 3 write`. On Linux, install `libbsd` for `strlcpy` and `strlcat`.
- Brian W. Kernighan and Dennis M. Ritchie, *The C Programming Language*, for pointers, strings, and the standard library.
- [strlcpy(3) on man7.org](https://www.man7.org/linux/man-pages/man3/strlcpy.3.html): the return value and truncation rules.
- [OpenBSD strlcpy(3)](https://man.openbsd.org/strlcpy.3) and [FreeBSD strlcpy](https://man.freebsd.org/strlcpy): the original BSD descriptions.
- The 42 curriculum subject for this project, which defines the required prototypes and behavior.

### AI usage

An AI assistant (Claude) was used during this project. Its role was:

- **Explanations:** explaining C concepts (pointers, `const`, `size_t`, buffer limits) and the rules in the subject, so the author could write each function.
- **Review:** the AI assistant was used to help troubleshoot, find inconsistencies, and help debug by going through the sequence of events in the code.
- **Edge Cases:** the AI assistant was also used to help find edge cases and pick up any issues that the author may have missed.

