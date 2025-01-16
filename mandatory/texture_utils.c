/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:27:24 by fbazaz            #+#    #+#             */
/*   Updated: 2025/01/16 11:08:14 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if (cub->texture_x < 0 || cub->texture_x >= cub->textures[tex_index].texture_width ||
    	cub->texture_y < 0 || cub->texture_y >= cub->textures[tex_index].texture_height)
    	exit(printf("Texture coordinates out of bounds\n"));
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
	if (cub->texture_x < 0)
		cub->texture_x = 0;
	if (cub->texture_x >= cub->textures[tex_index].texture_width)
		cub->texture_x = cub->textures[tex_index].texture_width - 1;
	y = cub->wall_top_pixel;
	while (y <= cub->wall_bottom_pixel)
	{
		cub->texture_y = get_texture_y(cub, y, tex_index);
		if (cub->texture_y < 0)
			cub->texture_y = 0;
		if (cub->texture_y >= cub->textures[tex_index].texture_height)
			cub->texture_y = cub->textures[tex_index].texture_height - 1;
		color = get_texture_color(cub, tex_index);
		my_mlx_pixel_put(cub, color, cub->ray_id, y);
		y++;
	}
}
