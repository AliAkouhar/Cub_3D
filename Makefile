NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g3
LIBFT = libft/libft.a
GNL = gnl/gnl
SRC = src/main.c src/parcing.c src/utils.c src/parse_map.c src/color.c src/check_map.c
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
