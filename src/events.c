#include "../headers/cub3d.h"

int	ft_close(t_cub *cub)
{
	printf("Closing the window..\n");
	free_all_map(cub);
	mlx_destroy_image(cub->mlx, cub->img);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	free(cub->mlx);
	exit(0);
}

int	key_press(int key, t_cub *cub)
{
	if (key == ESC)
		ft_close(cub);
	if (key == W) // W
		cub->player.walkDirection = 2;
	else if (key == S) // S
		cub->player.walkDirection = -2;
	else if (key == A) // A
		cub->player.leftRight = -2;
	else if (key == D) // D
		cub->player.leftRight = 2;
	else if (key == RIGHT) // -> right
		cub->player.turnDirection = +1;
	else if (key == LEFT) // <- left
		cub->player.turnDirection = -1;
	return (0);
}

int	key_release(int key, t_cub *cub)
{
	if (key == W) // W
		cub->player.walkDirection = 0;
	else if (key == S) // S
		cub->player.walkDirection = 0;
	else if (key == A) // A
		cub->player.leftRight = 0;
	else if (key == D) // D
		cub->player.leftRight = 0;
	else if (key == RIGHT) // -> right
		cub->player.turnDirection = 0;
	else if (key == LEFT) // <- left
		cub->player.turnDirection = 0;
	return (0);
}
