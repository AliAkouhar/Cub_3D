#include "../headers/cub3d_bonus.h"

t_point	horizontal_intersection(t_cub *cub, t_ray ray)
{
	t_point	inter;
	t_point	step_point;

	inter.ver_inter = 0;
	inter.y = floor(cub->player.point.y / cub->tile_map) * cub->tile_map;
	if (ray.isRayDown)
		inter.y += cub->tile_map;
	inter.x = cub->player.point.x + ((inter.y - cub->player.point.y)
			/ tan(cub->player.current_ray_angle));
	step_point.y = cub->tile_map;
	if (ray.isRayUp)
		step_point.y *= -1;
	step_point.x = step_point.y / tan(cub->player.current_ray_angle);
	if ((ray.isRayLeft && step_point.x > 0) || (ray.isRayRight
			&& step_point.x < 0))
		step_point.x *= -1;
	while (inter.x >= 0 && inter.x < cub->tile_map * cub->width && inter.y >= 0
		&& inter.y < cub->tile_map * cub->height)
	{
		if (is_a_wall(cub, &inter, 'h', ray))
			return (inter);
		inter.x += step_point.x;
		inter.y += step_point.y;
	}
	return (inter);
}

t_point	cast(t_cub *cub)
{
	t_point	p_vertical;
	t_point	p_horizontal;
	float	vertical_distance;
	float	horizantal_distance;
	t_ray	ray;

	ray_direction(&ray, cub->player.current_ray_angle);
	p_horizontal = horizontal_intersection(cub, ray);
	p_vertical = vertical_intersection(cub, ray);
	vertical_distance = get_distance(cub->player.point.x, cub->player.point.y,
			p_vertical.x, p_vertical.y);
	horizantal_distance = get_distance(cub->player.point.x, cub->player.point.y,
			p_horizontal.x, p_horizontal.y);
	if (vertical_distance < horizantal_distance)
		return (p_vertical);
	return (p_horizontal);
}

void	draw_3d_walls(t_cub *cub, t_point point, t_texture texture)
{
	cub->ray_distance = get_distance(cub->player.point.x, cub->player.point.y,
			point.x, point.y);
	cub->ray_distance *= cos(cub->player.rotation_angle
			- cub->player.current_ray_angle);
	if (cub->ray_distance < 1)
		cub->ray_distance = 1;
	cub->distance_pp = (SCREEN_WIDTH / 2) / tan(cub->player.fov_angle / 2);
	cub->wall_strip_height = (cub->tile_map * cub->distance_pp)
		/ cub->ray_distance;
	cub->wall_top_pixel = (SCREEN_HEIGHT / 2) - (cub->wall_strip_height / 2);
	cub->wall_bottom_pixel = (SCREEN_HEIGHT / 2) + (cub->wall_strip_height / 2);
	render_textures_wall(cub, point, texture);
}

/* this function draw the walls using the rays */
void	cast_all_rays(t_cub *cub)
{
	int			i;
	float		ray_increment;
	t_point		endpoint;
	t_texture	texture;

	i = 0;
	cub->player.current_ray_angle = cub->player.rotation_angle
		- (cub->player.fov_angle / 2);
	ray_increment = cub->player.fov_angle / NUMBER_OF_RAYS;
	while (i < NUMBER_OF_RAYS)
	{
		normalizing(cub);
		cub->ray_id = i;
		endpoint = cast(cub);
		texture = get_right_texture(cub, endpoint);
		if (endpoint.is_door)
			texture = render_doors(cub, endpoint);
		draw_3d_walls(cub, endpoint, texture);
		cub->player.current_ray_angle += ray_increment;
		i++;
	}
}
