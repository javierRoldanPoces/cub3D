NAME = cub3D

ifeq ($(shell uname), Darwin)
	INCFLAGS =  -DEBUG=1 -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
else
	INCFLAGS = -ldl -DEBUG=1 -Iinclude -lglfw -L"usr/lib/x86_64-linux-gnu/"
endif

SRC =		src/main.c							\
			src/gnl/get_next_line.c				\
			src/gnl/get_next_line_utils.c		\
			src/parse/check_map.c				\
			src/parse/get_file_content.c		\
			src/parse/get_map.c					\
			src/parse/get_text_and_colours.c	\
			src/parse/utils.c					\

OBJT_DIR = objt

OBJT = $(addprefix $(OBJT_DIR)/, $(patsubst %.c, %.o, $(SRC)))

LIBFT_DIR = ./libft

LIBFT = libft/libft.a

MLX42_DIR = ./MLX42

MLX42 = $(MLX42_DIR)/libmlx42.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

MAKEFLAGS += --quiet

all: $(LIBFT) $(MLX42) $(NAME)

$(NAME): $(OBJT)
	$(CC) $(CFLAGS) $(OBJT) -o $(NAME) -lm $(LIBFT) $(MLX42) $(INCFLAGS)

$(OBJT_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

$(MLX42):
		$(MAKE) -C $(MLX42_DIR)

clean:
		$(MAKE) clean -C $(LIBFT_DIR)
		$(MAKE) clean -C $(MLX42_DIR)
		$(RM) -r $(OBJT_DIR)

fclean: clean
		$(RM) $(LIBFT)
		$(RM) $(MLX42)
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
