#include "../headers/cub3d.h"

unsigned int	rgb_to_hex(t_color color)
{
	unsigned int color1;

	color1 = (color.r << 16) | (color.g << 8) | color.b;
	return (color1);
}

/* coloring the image */
int	draw(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(cub->mlx, cub->win);
	while (i < SCREEN_WIDTH)
	{
		j = 0;
		while (j < SCREEN_HEIGHT / 2)
		{
			my_mlx_pixel_put(cub, rgb_to_hex(cub->ceiling_color), i, j);
			j++;
		}
		while (j < SCREEN_HEIGHT)
		{
			my_mlx_pixel_put(cub, rgb_to_hex(cub->floor_color), i, j);
			j++;
		}
		i++;
	}
	render_3d(cub);
	return (0);
}
