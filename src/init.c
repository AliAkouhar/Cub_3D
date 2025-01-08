# include "../headers/cub3d.h"

void	init_cub(t_cub *cub)
{
	cub->content = NULL;
	cub->map_content = NULL;
	cub->textures_path[NORTH] = NULL;
	cub->textures_path[SOUTH] = NULL;
	cub->textures_path[EAST] = NULL;
	cub->textures_path[WEST] = NULL;
	cub->floor_color.r = -1;
	cub->floor_color.g = -1;
	cub->floor_color.b = -1;
	cub->ceiling_color.r = -1;
	cub->ceiling_color.g = -1;
	cub->ceiling_color.b = -1;
	cub->player.turnDirection = 0;
	cub->player.walkDirection = 0;
	cub->player.leftRight = 0;
	cub->player.speed = 3.0;
	cub->player.FOV_angle = 60 * (PI / 180);
	cub->player.rotationAngle = PI / 2;
	cub->player.rotationSpeed = 2 * (PI / 180);
}

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
		*(unsigned int *)dst =  ((color & 0xFF000000) >> 24) | ((color & 0x00FF0000) >> 8) | ((color & 0x0000FF00) << 8) | ((color & 0x000000FF) << 24);
	else // Little endian
		*(unsigned int *)dst = color;
}