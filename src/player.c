#include "../headers/cub3d.h"

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
			if (cub->map_content[py][px] == '1')
				return (0);
			dy += step;
		}
		dx += step;
	}
	return (1);
}
/* update the player position */
void	player(t_cub *cub)
{
	float	moveStepX;
	float	moveStepY;
	float	newPosX;
	float	newPosY;

	cub->player.rotationAngle += cub->player.turnDirection
		* cub->player.rotationSpeed;
	moveStepX = cos(cub->player.rotationAngle) * cub->player.walkDirection
		- sin(cub->player.rotationAngle) * cub->player.leftRight;
	moveStepY = sin(cub->player.rotationAngle) * cub->player.walkDirection
		+ cos(cub->player.rotationAngle) * cub->player.leftRight;
	newPosX = cub->player.point.x + moveStepX * cub->player.speed;
	newPosY = cub->player.point.y + moveStepY * cub->player.speed;
	if (is_wall(cub, newPosX, newPosY))
	{
		cub->player.point.x = newPosX;
		cub->player.point.y = newPosY;
	}
	// draw_player_rectangle(cub, tile);
}

void	line(t_cub *cub, float x0, float y0, float x1, float y1)
{
	float	dx;
	float	dy;
	float	steps;
    int     i;

	dx = x1 - x0;
	dy = y1 - y0;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
    i = 0;
	while (i <= steps)
	{
		my_mlx_pixel_put(cub, 0x00FF00, round(x0), round(y0));
		x0 += dx / steps;
		y0 += dy / steps;
        i++;
	}
}

void	draw_player(t_cub *cub)
{
	player(cub);
	cast_all_rays(cub);
	line(cub, cub->player.point.x + 5, cub->player.point.y + 5,
		(cub->player.point.x + 5) + (cos(cub->player.rotationAngle)
			* LINE_SIZE), (cub->player.point.y + 5)
		+ (sin(cub->player.rotationAngle) * LINE_SIZE));
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
}