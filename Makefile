NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
LIBFT = libft/libft.a
GNL = gnl/gnl
SRC = ./src/main.c ./src/parsing/parsing.c ./src/parsing/utils.c ./src/parsing/check_map.c ./src/parsing/parse_map.c  ./src/parsing/parse_textures.c ./src/parsing/parse_colors.c
OBJ_DIR = obj
OBJ = $(SRC:src/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: src/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

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
	rm -rf $(OBJ_DIR) 

fclean: clean
	make fclean -C libft
	make fclean -C gnl
	rm -rf $(NAME)

re: fclean all
