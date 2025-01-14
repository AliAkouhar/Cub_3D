# include "../headers/cub3d_bonus.h"

void    door_animation(t_cub *cub, t_point point)
{
    int i;

    i = 0;
    while (i < DOOR_FRAME_NUMBER)
    {
        render_textures_wall(cub, point, cub->doors[i]);
        i++;
    }
}

void    render_doors(t_cub *cub, t_point point)
{
    float   distance_to_door;

    distance_to_door = get_distance(cub->player.point.x, cub->player.point.y,
                        point.x, point.y);
    if (distance_to_door > 100)
        return ;
    door_animation(cub, point);
}