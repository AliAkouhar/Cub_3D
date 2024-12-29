# include "../headers/cub3d.h"

void    cast_all_rays(t_cub *cub)
{
    int i;
    float ray_angle;
    float ray_increment;

    i = 0;
    ray_angle = cub->player.rotationAngle - (cub->player.FOV_angle / 2);
    ray_increment = cub->player.FOV_angle / NUMBER_OF_RAYS;
    while (i < NUMBER_OF_RAYS)
    {
        line(cub,
            cub->player.player_x + 5,
            cub->player.player_y + 5,
            cub->player.player_x + 5 + cos(ray_angle) * LINE_SIZE,
            cub->player.player_y + 5 + sin(ray_angle) * LINE_SIZE
        );
        ray_angle += ray_increment;
        i++;
    }
}
