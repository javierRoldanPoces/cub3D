NAME = cub3D

ifeq ($(shell uname), Darwin)
	INCFLAGS =  -DEBUG=1 -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
else
	INCFLAGS = -ldl -DEBUG=1 -Iinclude -lglfw -L"usr/lib/x86_64-linux-gnu/"
endif

SRC =	src/									\
		src/									\
		src/									\
		src/									\
		src/									\
		src/									\
		src/									\

OBJT_DIR = objt

OBJT = $(addprefix $(OBJT_DIR)/, $(patsubst %.c, %.o, $(patsubst src/%, , $(SRC))))

LIBFT_DIR = ./libft

LIBFT = libft/libft.a

MLX42_DIR = ./MLX42

MLX42 = $(MLX42_DIR)/libmlx42.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

#MAKEFLAGS += --quiet

all: $(LIBFT) $(MLX42) $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJT)
		$(CC) $(CFLAGS) $(SRC) -o $(NAME) -lm $(LIBFT) $(MLX42) $(INCFLAGS)

$(LIBFT):
		$(MAKE) -C $(LIBFT_DIR)

$(MLX42):
		$(MAKE) -C $(MLX42_DIR)

clean:
		$(MAKE) clean -C $(LIBFT_DIR)
		$(MAKE) clean -C $(MLX42_DIR)
		$(RM) $(OBJT)

fclean: clean
		$(MAKE) fclean -C $(LIBFT_DIR)
		$(MAKE) fclean -C $(MLX42_DIR)
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
