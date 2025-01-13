# include "../headers/cub3d_bonus.h"

int mouse_press(int botton, int x, int y, t_cub *cub)
{
    (void)x;
    (void)y;
    if (botton == LEFT_MOUSE)
        cub->player.turn_direction = -1;
    else if (botton == RIGHT_MOUSE)
        cub->player.turn_direction = 1;
    return (0);
}

int mouse_release(int botton, int x, int y, t_cub *cub)
{
    (void)x;
    (void)y;
    if (botton == LEFT_MOUSE)
        cub->player.turn_direction = 0;
    else if (botton == RIGHT_MOUSE)
        cub->player.turn_direction = 0;
    return (0);
}