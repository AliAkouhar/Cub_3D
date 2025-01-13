#include "../headers/cub3d_bonus.h"

float	radian_to_degree(float corner)
{
	return (corner * (180 / PI));
}

int	get_right_texture(t_cub *cub, t_point endPoint)
{
	if (endPoint.ver_inter)
	{
		if (cub->player.current_ray_angle > 3 * PI / 2
			|| cub->player.current_ray_angle < PI / 2)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (cub->player.current_ray_angle > 0
			&& cub->player.current_ray_angle < PI)
			return (SOUTH);
		else
			return (NORTH);
	}
}
