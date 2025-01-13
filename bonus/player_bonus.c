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

	step = 1.0;
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
	float	moveStepX;
	float	moveStepY;
	float	newPosX;
	float	newPosY;

	cub->player.rotation_angle += cub->player.turn_direction
		* cub->player.rotation_speed;
	moveStepX = cos(cub->player.rotation_angle) * cub->player.walk_direction
		- sin(cub->player.rotation_angle) * cub->player.left_right;
	moveStepY = sin(cub->player.rotation_angle) * cub->player.walk_direction
		+ cos(cub->player.rotation_angle) * cub->player.left_right;
	newPosX = cub->player.point.x + moveStepX * cub->player.speed;
	newPosY = cub->player.point.y + moveStepY * cub->player.speed;
	//wall collision
	if (is_wall(cub, newPosX, cub->player.point.y))
		cub->player.point.x = newPosX;
	if (is_wall(cub, cub->player.point.x, newPosY))
		cub->player.point.y = newPosY;
}

void	render_3d(t_cub *cub)
{
	player_position(cub);
	cast_all_rays(cub);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
}
