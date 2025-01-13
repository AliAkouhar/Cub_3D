#include "../headers/cub3d.h"

float	get_distance(float x1, float y1, float x2, float y2)
{
	return (sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
}

bool	is_a_wall(t_cub *cub, t_point point, char c, t_ray ray)
{
	int	x;
	int	y;

	if (c == 'h' && ray.isRayUp)
		point.y--;
	if (c == 'v' && ray.isRayLeft)
		point.x--;
	x = floor(point.x / cub->tile_map);
	y = floor(point.y / cub->tile_map);
	if (x >= 0 && x < cub->width && y >= 0 && y < cub->height)
		if (cub->map_content[y][x] == '1')
			return (true);
	return (false);
}

t_point	vertical_intersection(t_cub *cub, t_ray ray)
{
	t_point	inter;
	t_point	step;

    inter.ver_inter = 1;
	inter.x = floor(cub->player.point.x / cub->tile_map) * cub->tile_map;
	if (ray.isRayRight)
		inter.x += cub->tile_map;
	inter.y = cub->player.point.y + ((inter.x - cub->player.point.x)
			* tan(cub->player.current_ray_angle));
	step.x = cub->tile_map;
	if (ray.isRayLeft)
		step.x *= -1;
	step.y = cub->tile_map * tan(cub->player.current_ray_angle);
	if ((ray.isRayUp && step.y > 0) || (ray.isRayDown && step.y < 0))
		step.y *= -1;
	while (inter.x >= 0 && inter.x <= cub->tile_map * cub->width && inter.y >= 0
		&& inter.y <= cub->tile_map * cub->height)
	{
		if (is_a_wall(cub, inter, 'v', ray))
			return (inter);
		inter.x += step.x;
		inter.y += step.y;
	}
	return (inter);
}

void	ray_direction(t_ray *ray, float rayAngle)
{
	ray->isRayDown = rayAngle >= 0 && rayAngle <= PI;
	ray->isRayUp = !ray->isRayDown;
	ray->isRayRight = rayAngle <= 0.5 * PI || rayAngle >= 1.5 * PI;
	ray->isRayLeft = !ray->isRayRight;
}

void	normalizing(t_cub *cub)
{
	cub->player.current_ray_angle = fmod(cub->player.current_ray_angle, 2 * PI);
	if (cub->player.current_ray_angle < 0)
		cub->player.current_ray_angle += 2 * PI;
}
