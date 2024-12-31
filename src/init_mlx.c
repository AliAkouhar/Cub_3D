#include "../headers/cub3d.h"

void	init_mlx(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		exit(printf("Error\nInit_mlx\n"));
	cub->win = mlx_new_window(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"CUB3D");
	cub->img = mlx_new_image(cub->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	cub->add = mlx_get_data_addr(cub->img, &cub->bit_per_pixel, &cub->size_line,
			&cub->endian);
}

void	my_mlx_pixel_put(t_cub *cub, int color, float x, float y)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = cub->add + (((int)y * cub->size_line) + ((int)x * (cub->bit_per_pixel
					/ 8)));
	if (cub->endian == 0) // Big endian
		*(unsigned int *)dst = ((color & 0xFF000000) >> 24) | ((color & 0x00FF0000) >> 8) | ((color & 0x0000FF00) << 8) | ((color & 0x000000FF) << 24);
	else // Little endian
		*(unsigned int *)dst = color;
}

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

void	draw_big_map(t_cub *cub)
{
	int	i;
	int	j;
	int	tileX;
	int	tileY;
	int	color;

	i = 0;
	while (i < cub->height)
	{
		j = 0;
		while (j < cub->width)
		{
			tileX = j * cub->tile_map;
			tileY = i * cub->tile_map;
			if (cub->map_content[i][j] == '1')
				color = BLACK;
			else if (cub->map_content[i][j] == '0' || cub->map_content[i][j] == cub->char_player)
				color = WHITE;
			rectangle(tileX, tileY, color, cub);
			j++;
		}
		i++;
	}
	draw_player(cub);
}
