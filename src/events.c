#include "../headers/cub3d.h"

int	key_press(int key, t_cub *cub)
{
	// printf("key --> %i\n", key);
	if (key == 65307)
		ft_close(cub);
	if (key == 119 || key == 97 || key == 115 || key == 100 || key == 65363
		|| key == 65361)
	{
		mlx_clear_window(cub->mlx, cub->win);
		update_player(key, cub);
		draw(cub);
	}
	return (0);
}

void	update_player(int key, t_cub *cub)
{
	if (key == 119) // W
		cub->player.walkDirection = 2;
	else if (key == 115) // S
		cub->player.walkDirection = -2;
	else if (key == 97) // A
		cub->player.leftRight = -2;
	else if (key == 100) // D
		cub->player.leftRight = 2;
	else if (key == 65363) // -> right
		cub->player.turnDirection = +2;
	else if (key == 65361) // <- left
		cub->player.turnDirection = -2;
}

int	ft_close(t_cub *cub)
{
	printf("Closing the window..\n");
	mlx_destroy_image(cub->mlx, cub->img);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	free(cub->mlx);
	free_all_map(cub);
	exit(0);
}

int	key_release(int key, t_cub *cub)
{
	if (key == 119) // W
		cub->player.walkDirection = 0;
	else if (key == 115) // S
		cub->player.walkDirection = 0;
	else if (key == 97) // A
		cub->player.leftRight = 0;
	else if (key == 100) // D
		cub->player.leftRight = 0;
	else if (key == 65363) // -> right
		cub->player.turnDirection = 0;
	else if (key == 65361) // <- left
		cub->player.turnDirection = 0;
	return (0);
}
