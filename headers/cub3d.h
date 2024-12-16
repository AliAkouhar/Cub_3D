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

# define HEIGHT 1500
# define WIDTH 900

typedef struct color
{
	int		r;
	int		g;
	int		b;
}			t_color;

typedef struct cub
{
	char	**map;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	t_color	floor_color;
	t_color	ceiling_color;
	int		player_x;
	int		player_y;
}			t_cub;

void		ft_parcing(t_cub *cub, int ac, char **av);
void		is_extension(char *str);
void		parse_map(t_cub *cub);
void		parse_color(char *line, t_color *color);
char		*parse_texture(char *line);
int			check_color(t_cub *cub);
void		is_valid_map(t_cub *cub, int x);
void		check_side_borders(t_cub *cub, int x);
void    	check_other_char(char **map, int x);
int 		check_char(char c);
void		check_player_position(t_cub *cub, int x);
void		ft_norm(char *line, t_cub *cub);

void		free_2d(char **str);

#endif