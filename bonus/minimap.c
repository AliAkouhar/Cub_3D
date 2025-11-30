/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:51:03 by fbazaz            #+#    #+#             */
/*   Updated: 2025/01/17 17:51:04 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void	set_start_and_end(t_cub *cub)
{
	cub->start.x = cub->player.point.x / cub->tile_map - RANGE_MINIMAP
		/ cub->tile_map;
	cub->start.y = cub->player.point.y / cub->tile_map - RANGE_MINIMAP
		/ cub->tile_map;
	if (cub->start.x < 0)
		cub->start.x = 0;
	if (cub->start.y < 0)
		cub->start.y = 0;
	cub->end.x = cub->start.x + (SCREEN_WIDTH * MINI_MAP) / MINI_TILE;
	cub->end.y = cub->start.y + (SCREEN_HEIGHT * MINI_MAP) / MINI_TILE;
	if (cub->end.x > cub->width)
		cub->end.x = cub->width;
	if (cub->end.y > cub->height)
		cub->end.y = cub->height;
}

void	render_square(t_cub *cub, float x, float y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < MINI_TILE)
	{
		i = 0;
		while (i < MINI_TILE)
		{
			my_mlx_pixel_put(cub, color, x + i, y + j);
			i++;
		}
		j++;
	}
}

void	render_player_square(t_cub *cub, float x, float y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < MINI_TILE * 0.6)
	{
		i = 0;
		while (i < MINI_TILE * 0.6)
		{
			my_mlx_pixel_put(cub, color, x + i, y + j);
			i++;
		}
		j++;
	}
}

void	determine_square(t_cub *cub, t_point map)
{
	if (cub->map_content[(int)map.y][(int)map.x] == '1')
		render_square(cub, cub->render.x, cub->render.y, 0x778899);
	else if (cub->map_content[(int)map.y][(int)map.x] == 'D')
		render_square(cub, cub->render.x, cub->render.y, 0xF4A460);
	else
		render_square(cub, cub->render.x, cub->render.y, 0xDCDCDC);
}

void	render_mini_map(t_cub *cub)
{
	t_point	map_tmp;

	set_start_and_end(cub);
	map_tmp.y = cub->start.y;
	while (map_tmp.y < cub->end.y)
	{
		map_tmp.x = cub->start.x;
		while (map_tmp.x < cub->end.x)
		{
			cub->render.x = (map_tmp.x - cub->start.x) * MINI_TILE;
			cub->render.y = (map_tmp.y - cub->start.y) * MINI_TILE;
			determine_square(cub, map_tmp);
			map_tmp.x++;
		}
		map_tmp.y++;
	}
	render_player_square(cub, ((cub->player.point.x / cub->tile_map
				- cub->start.x) * MINI_TILE), ((cub->player.point.y
				/ cub->tile_map - cub->start.y) * MINI_TILE), 0xFFE4B5);
}
