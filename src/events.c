#include "../headers/cub3d.h"

int	key_press(int key, t_cub *cub)
{
	printf("key --> %i\n", key);
	if (key == 65307)
		exit(0);
	if (key ==  119 || key == 97 || key == 115 || key == 100 || key == 65363 || key == 65361)
	{
		mlx_clear_window(cub->mlx, cub->win);
		update_player(key, cub);
		draw_big_map(cub);
	}
	return 0;
}

int	print2(int mouse, int x, int y, t_cub *cub)
{
	(void)mouse;
	(void)x; 
	(void)y;
	(void)cub;
	// printf("mouse --> %c\n", cub->map_content[y / TILE][x / TILE]);
	return (0);
}

int	ft_close(t_cub *cub)
{
	(void)cub;
	printf("Closing the window..\n");
	exit(0);
}

int key_release(int key, t_cub* cub)
{
    if (key == 119) // W
        cub->walkDirection = 0;
    else if (key == 115) // S
        cub->walkDirection = 0;
    else if (key == 97) // A
        cub->leftRight = 0;
    else if (key == 100) // D
        cub->leftRight = 0;
    else if (key == 65363) // -> right
        cub->turnDirection = 0;
    else if (key == 65361) // <- left
        cub->turnDirection = 0;
    return (0);
}