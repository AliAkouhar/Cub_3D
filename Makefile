NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
LIBFT = libft/libft.a
GNL = gnl/gnl
SRC = ./src/main.c ./src/parsing.c ./src/utils.c ./src/check_map.c ./src/parse_map.c ./src/parse_textures.c ./src/parse_colors.c ./src/colors_utils.c ./src/map_utils.c ./src/player.c

OBJ = $(SRC:%.c=%.o)

all: $(GNL) $(LIBFT) $(NAME) 

$(GNL):
	make -C gnl

$(LIBFT):
	make -C libft
	make bonus -C libft

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(GNL) $(LIBFT) -L headers/minilibx-linux -lmlx -lXext -lX11 -o $(NAME)
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