NAME = get_next_line.a

SRC =	get_next_line_utils.c	\
		get_next_line.c			\

OBJT = $(SRC:.c=.o)

CC = gcc

AR = ar rcs

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

MAKEFLAGS += --quiet

all: $(NAME)

$(NAME): $(OBJT)
	$(CC) $(CFLAGS) -c $(SRC)
	$(AR) $(NAME) $(OBJT)

clean:
	$(RM) $(OBJT)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
