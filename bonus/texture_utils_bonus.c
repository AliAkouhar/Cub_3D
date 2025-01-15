#include "../headers/cub3d_bonus.h"

float	get_wall_x(t_cub *cub, t_point point)
{
	if (point.ver_inter)
		return (fmod(point.y, cub->tile_map));
	return (fmod(point.x, cub->tile_map));
}

int	get_texture_x(t_cub *cub, float wall_x, t_texture texture)
{
	return ((int)(wall_x * (texture.texture_width / cub->tile_map)));
}

int	get_texture_y(t_cub *cub, int y, t_texture texture)
{
	return (((y - cub->wall_top_pixel) * texture.texture_height)
		/ cub->wall_strip_height);
}

unsigned int	get_texture_color(t_cub *cub, t_texture texture)
{
	unsigned int	color;

	color = *(unsigned int *)(texture.addr + (cub->texture_y
				* texture.line_length + cub->texture_x
				* (texture.b_per_pixel / 8)));
	return (color);
}

void	render_textures_wall(t_cub *cub, t_point point, t_texture texture)
{
	float	wall_x;
	int		y;
	int		color;

	wall_x = get_wall_x(cub, point);
	cub->texture_x = get_texture_x(cub, wall_x, texture);
	y = cub->wall_top_pixel;
	while (y <= cub->wall_bottom_pixel)
	{
		cub->texture_y = get_texture_y(cub, y, texture);
		color = get_texture_color(cub, texture);
		my_mlx_pixel_put(cub, color, cub->ray_id, y);
		y++;
	}
}
