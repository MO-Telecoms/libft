# The name of the library this Makefile produces.
NAME = libft.a

# The compiler and the flags the subject requires.
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Mandatory sources: every ft_*.c file except the _bonus.c files.
SRCS = $(filter-out %_bonus.c,$(wildcard ft_*.c))
OBJS = $(SRCS:.c=.o)

# Bonus sources: the linked-list functions, built only by "make bonus".
BONUS_SRCS = $(wildcard ft_lst*_bonus.c)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# These names are commands, not files.
.PHONY: all bonus clean fclean re

# Running plain "make" builds the mandatory library.
all: $(NAME)

# Build the library from the mandatory object files.
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Add the bonus object files to the library.
bonus: $(NAME) $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

# Compile one .c file into its .o file.
# $< is the .c file, $@ is the .o file being built.
# The headers are listed so changing them rebuilds the objects that use them.
%.o: %.c libft.h libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# Delete the object files, mandatory and bonus.
clean:
	rm -f $(OBJS) $(BONUS_OBJS)

# Delete the object files and the library.
fclean: clean
	rm -f $(NAME)

# Start over.
re: fclean all
