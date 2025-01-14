#include "../headers/cub3d_bonus.h"

float	radian_to_degree(float corner)
{
	return (corner * (180 / PI));
}

t_texture	get_right_texture(t_cub *cub, t_point endPoint)
{
	if (endPoint.is_door)
		return (cub->doors[20]);
	if (endPoint.ver_inter)
	{
		if (cub->player.current_ray_angle > 3 * PI / 2
			|| cub->player.current_ray_angle < PI / 2)
			return (cub->textures[EAST]);
		else
			return (cub->textures[WEST]);
	}
	else
	{
		if (cub->player.current_ray_angle > 0
			&& cub->player.current_ray_angle < PI)
			return (cub->textures[SOUTH]);
		else
			return (cub->textures[NORTH]);
	}
}
