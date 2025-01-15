# include "../headers/cub3d_bonus.h"

t_texture    render_doors(t_cub *cub, t_point point)
{
    float   distance_to_door;

    distance_to_door = get_distance(cub->player.point.x, cub->player.point.y,
                        point.x, point.y);
    if (distance_to_door <= 50)
        cub->is_door_open = 1;
    else
        cub->is_door_open = 0;
    door_animation(cub);
    if (cub->door_frame < 0)
        cub->door_frame = 0;
    return (cub->doors[cub->door_frame]);
}

void    door_animation(t_cub *cub)
{
    if (cub->is_door_open)
    {
        cub->door_frame++;
        if (cub->door_frame >= DOOR_FRAME_NUMBER)
        {
            cub->door_frame = DOOR_FRAME_NUMBER - 1;
            cub->is_door_open = 0;
        }
    }
    if (!cub->is_door_open && cub->door_frame != 0)
        cub->door_frame--;
}