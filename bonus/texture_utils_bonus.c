#include "../headers/cub3d_bonus.h"

float	get_wall_x(t_cub *cub, t_point point)
{
	if (point.ver_inter)
		return (fmod(point.y, cub->tile_map));
	return (fmod(point.x, cub->tile_map));
}

int	get_texture_x(t_cub *cub, float wall_x, t_texture texture)
{
	if (wall_x < 0)
		wall_x = 0;
	if (wall_x >= cub->tile_map)
		wall_x = cub->tile_map - 1;
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

	if (cub->texture_x < 0 || cub->texture_x >= texture.texture_width ||
    	cub->texture_y < 0 || cub->texture_y >= texture.texture_height)
		{
			free_all_map(cub);
    		exit(printf("Texture coordinates out of bounds\n"));
		}
	color = *(unsigned int *)(texture.addr + ((cub->texture_y * texture.line_length) + (cub->texture_x * (texture.b_per_pixel / 8))));
	return (color);
}

void	render_textures_wall(t_cub *cub, t_point point, t_texture texture)
{
	float	wall_x;
	int		y;
	int		color;

	wall_x = get_wall_x(cub, point);
	cub->texture_x = get_texture_x(cub, wall_x, texture);
	if (cub->texture_x < 0)
		cub->texture_x = 0;
	if (cub->texture_x >= texture.texture_width)
		cub->texture_x = texture.texture_width - 1;
	y = cub->wall_top_pixel;
	while (y <= cub->wall_bottom_pixel)
	{
		cub->texture_y = get_texture_y(cub, y, texture);
		if (cub->texture_y < 0)
			cub->texture_y = 0;
		if (cub->texture_y >= texture.texture_height)
			cub->texture_y = texture.texture_height - 1;
		color = get_texture_color(cub, texture);
		my_mlx_pixel_put(cub, color, cub->ray_id, y);
		y++;
	}
}
