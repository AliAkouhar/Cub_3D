/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:51:09 by fbazaz            #+#    #+#             */
/*   Updated: 2025/01/17 17:51:10 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void	draw_player_rectangle(t_cub *cub, int tile)
{
	int	i;
	int	j;

	i = 0;
	while (i < tile)
	{
		j = 0;
		while (j < tile)
		{
			my_mlx_pixel_put(cub, 0xFF0000, cub->player.point.x + j,
				cub->player.point.y + i);
			j++;
		}
		i++;
	}
}

int	is_wall(t_cub *cub, float x, float y)
{
	int		px;
	int		py;
	float	dx;
	float	dy;
	float	step;

	step = 5.0;
	dx = -step;
	while (dx <= step)
	{
		dy = -step;
		while (dy <= step)
		{
			px = floor((x + dx) / cub->tile_map);
			py = floor((y + dy) / cub->tile_map);
			if (px < 0 || px >= cub->width || py < 0 || py >= cub->height)
				return (0);
			if (cub->map_content[py][px] == '1')
				return (0);
			dy += step;
		}
		dx += step;
	}
	return (1);
}

void	player_position(t_cub *cub)
{
	float	move_step_x;
	float	move_step_y;
	float	new_pos_x;
	float	new_pos_y;

	cub->player.rotation_angle += cub->player.turn_direction
		* cub->player.rotation_speed;
	move_step_x = cos(cub->player.rotation_angle) * cub->player.walk_direction
		- sin(cub->player.rotation_angle) * cub->player.left_right;
	move_step_y = sin(cub->player.rotation_angle) * cub->player.walk_direction
		+ cos(cub->player.rotation_angle) * cub->player.left_right;
	new_pos_x = cub->player.point.x + move_step_x * cub->player.speed;
	new_pos_y = cub->player.point.y + move_step_y * cub->player.speed;
	if (is_wall(cub, new_pos_x, cub->player.point.y))
		cub->player.point.x = new_pos_x;
	if (is_wall(cub, cub->player.point.x, new_pos_y))
		cub->player.point.y = new_pos_y;
}

void	render_3d(t_cub *cub)
{
	player_position(cub);
	cast_all_rays(cub);
	render_bonus_features(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
}
