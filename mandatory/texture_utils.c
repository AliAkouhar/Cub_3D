#include "../headers/cub3d.h"

float	get_wall_x(t_cub *cub, t_point point)
{
	if (point.ver_inter)
		return (fmod(point.y, cub->tile_map));
	return (fmod(point.x, cub->tile_map));
}

int	get_texture_x(t_cub *cub, float wall_x, int tex_index)
{
	return ((int)(wall_x * (cub->textures[tex_index].texture_width
			/ cub->tile_map)));
}

int	get_texture_y(t_cub *cub, int y, int tex_index)
{
	return (((y - cub->wall_top_pixel)
			* cub->textures[tex_index].texture_height)
		/ cub->wall_strip_height);
}

unsigned int	get_texture_color(t_cub *cub, int tex_index)
{
	unsigned int	color;

	color = *(unsigned int *)(cub->textures[tex_index].addr + (cub->texture_y
				* cub->textures[tex_index].line_length + cub->texture_x
				* (cub->textures[tex_index].b_per_pixel / 8)));
	return (color);
}

void	render_textures_wall(t_cub *cub, t_point point, int tex_index)
{
	float	wall_x;
	int		y;
	int		color;

	wall_x = get_wall_x(cub, point);
	cub->texture_x = get_texture_x(cub, wall_x, tex_index);
	y = cub->wall_top_pixel;
	while (y <= cub->wall_bottom_pixel)
	{
		cub->texture_y = get_texture_y(cub, y, tex_index);
		color = get_texture_color(cub, tex_index);
		my_mlx_pixel_put(cub, color, cub->ray_id, y);
		y++;
	}
}
