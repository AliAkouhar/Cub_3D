NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
LIBFT = libft/libft.a
GNL = gnl/gnl
SRC = ./src/main.c ./src/parsing/parsing.c ./src/parsing/utils.c ./src/parsing/check_map.c ./src/parsing/parse_map.c ./src/parsing/parse_textures.c ./src/parsing/parse_colors.c ./src/parsing/colors_utils.c ./src/parsing/map_utils.c ./src/player.c ./src/draw.c ./src/events.c ./src/ray_casting.c ./src/casting_utils.c ./src/utils2.c ./src/init.c ./src/mini_map.c

OBJ = $(SRC:%.c=%.o)

all: $(GNL) $(LIBFT) $(NAME) 

$(GNL):
	make -C gnl

$(LIBFT):
	make -C libft
	make bonus -C libft

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(GNL) $(LIBFT) -L headers/minilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME)
	#@make clean

clean:
	make clean -C libft
	make clean -C gnl
	rm -rf $(OBJ) 

fclean: clean
	make fclean -C libft
	make fclean -C gnl
	rm -rf $(NAME)

re: fclean all