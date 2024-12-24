/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:30:00 by fbazaz            #+#    #+#             */
/*   Updated: 2024/12/16 15:43:35 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define HEIGHT 11 // 11
# define WIDTH 15 // 15

# define PI 3.14159265358979323846
# define R_ANGLE PI / 2


# define TILE 50

# define NORTH 0
# define SOUTH 1
# define EAST 2
# define WEST 3

# define BLACK 0x00000000
# define WHITE 0xFFFFFFFF

typedef struct color
{
	int		r;
	int		g;
	int		b;
}			t_color;

typedef struct cub
{
	char	*content;
	char	**map_content; // to free
	char 	*textures_path[4]; // to free
	t_color	floor_color;
	t_color	ceiling_color;
	float	player_x;
	float	player_y;
	void	*mlx;
	void	*win;
	void	*img;
	void	*add;
	int		bit_per_pixel;
	int		size_line;
	int		endian;
	//
	int		turnDirection;
	int		walkDirection;
	int		speed;
	int		rotationAngle;
	int		rotationSpeed;
}			t_cub;

void		ft_parsing(t_cub *cub, int ac, char **av);
void		is_extension(char *str);
void		parse_map(t_cub *cub);
void		parse_line(char *line, t_cub *cub, int *flag);
void		parse_color(char *line, t_color *color, int *flag);
char		*parse_texture(char *line);
void		check_colors(t_cub *cub);
void		is_valid_map(t_cub *cub);
void		check_side_borders(t_cub *cub);
int			check_char(char c);
int    		check_other_char(char **map);
void		check_map(t_cub*cub);
void		check_player_position(t_cub *cub);
int 		is_all_whitespaces(char *str);
void    	check_textures(t_cub *cub);
void    	assign_color(t_cub *cub, char **split, char c);
void    	ft_norm_25_2(char *trim, t_cub *cub, int i, int *j);
void    	check_rgb(int *j, char *str, t_cub *cub, char c, char *to_free);
void    	adjust_map(t_cub *cub);
int 		size_map(char **map);
void    	switch_spaces(t_cub *cub);
void    	adjust_length(t_cub *cub);
void    	check_player_spaces_position(t_cub *cub);
void    	init_mlx(t_cub *cub);


void    	draw_kbira(t_cub *cub);
void		my_mlx_pixel_put(t_cub *cub, int color, float x, float y);
void    	draw_player(t_cub *cub);
void    	update_player(int key, t_cub *cub);

void		free_2d(char **str);
void		free_all_map(t_cub *cub);
void		fre(char *str);
int			array_size(char **str);
char		*new_string(char a, int size);

#endif