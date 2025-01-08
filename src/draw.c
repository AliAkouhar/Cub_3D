#include "../headers/cub3d.h"

void	rectangle(int x, int y, int color, t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < cub->tile_map)
	{
		my_mlx_pixel_put(cub, BLACK, x, y + i);
		j = 1;
		while (j < cub->tile_map)
		{
			my_mlx_pixel_put(cub, color, x + j, y + i);
			j++;
		}
		j = 0;
		if (i == 0)
		{
			while (j < cub->tile_map)
			{
				my_mlx_pixel_put(cub, BLACK, x + j, y + i);
				j++;
			}
		}
		i++;
	}
}

unsigned int	rgb_to_hex(t_cub *cub, t_color color)
{
	unsigned int color1;

	color1 = (color.r << 16) | (color.g << 8) | color.b;
	if (!cub->endian) // Big endian
	{
		color1 = ((color1 & 0xFF000000) >> 24) |
			   ((color1 & 0x00FF0000) >> 8)  |
			   ((color1 & 0x0000FF00) << 8)  |
			   ((color1 & 0x000000FF) << 24);
	}
	return (color1);
}

/* coloring the image */
void	draw(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_WIDTH)
	{
		j = 0;
		while (j < SCREEN_HEIGHT / 2)
		{
			my_mlx_pixel_put(cub, rgb_to_hex(cub, cub->ceiling_color), i, j);
			j++;
		}
		while (j < SCREEN_HEIGHT)
		{
			my_mlx_pixel_put(cub, rgb_to_hex(cub, cub->floor_color), i, j);
			j++;
		}
		i++;
	}
	draw_player(cub);
}
