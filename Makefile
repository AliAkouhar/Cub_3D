NAME = cub3D
NAME_BONUS = cub3D_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
LIBFT = libft/libft.a
GNL = gnl/gnl
SRC = ./mandatory/main.c ./mandatory/parsing/parsing.c ./mandatory/parsing/utils.c ./mandatory/parsing/check_map.c ./mandatory/parsing/parse_map.c ./mandatory/parsing/parse_textures.c \
	 ./mandatory/parsing/parse_colors.c ./mandatory/parsing/colors_utils.c ./mandatory/parsing/map_utils.c ./mandatory/player.c ./mandatory/draw.c ./mandatory/events.c ./mandatory/ray_casting.c \
	 ./mandatory/casting_utils.c ./mandatory/utils2.c ./mandatory/init.c ./mandatory/texture_utils.c

SRC_BONUS = ./bonus/main_bonus.c ./bonus/parsing/parsing_bonus.c ./bonus/parsing/utils_bonus.c ./bonus/parsing/check_map_bonus.c ./bonus/parsing/parse_map_bonus.c ./bonus/parsing/parse_textures_bonus.c \
	 ./bonus/parsing/parse_colors_bonus.c ./bonus/parsing/colors_utils_bonus.c ./bonus/parsing/map_utils_bonus.c ./bonus/player_bonus.c ./bonus/draw_bonus.c ./bonus/events_bonus.c ./bonus/ray_casting_bonus.c \
	 ./bonus/casting_utils_bonus.c ./bonus/utils2_bonus.c ./bonus/init_bonus.c ./bonus/texture_utils_bonus.c ./bonus/zoom.c ./bonus/render_bonus_features.c ./bonus/mouse.c ./bonus/weapon.c

OBJ = $(SRC:%.c=%.o)
OBJ_BONUS = $(SRC_BONUS:%.c=%.o)

all: $(GNL) $(LIBFT) $(NAME) 

$(GNL):
	make -C gnl

$(LIBFT):
	make -C libft
	make bonus -C libft

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) $(CFLAGS) $(GNL) $(LIBFT) -L headers/minilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME)
	@make clean

bonus: $(GNL) $(LIBFT) $(OBJ_BONUS)
	$(CC) $(OBJ_BONUS) $(CFLAGS) $(GNL) $(LIBFT) -L headers/minilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME_BONUS)
	@make clean

clean:
	make clean -C libft
	make clean -C gnl
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	make fclean -C libft
	make fclean -C gnl
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all