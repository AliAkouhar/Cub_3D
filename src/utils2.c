# include "../headers/cub3d.h"

float   radian_to_degree(float corner)
{
    return (corner * (180 / PI));
}

int get_right_texture(t_cub *cub, t_point endPoint)
{
    // if (cub->is_ray_hit_door)

    if (endPoint.ver_inter) // vertical wall
    {
        if (cub->player.current_ray_angle > 3 * PI / 2 || cub->player.current_ray_angle < PI / 2) // East
            return EAST;
        else // West
            return WEST;
    }
    else // horizontal wall
    {
        if (cub->player.current_ray_angle > 0 && cub->player.current_ray_angle < PI) // South
            return SOUTH;
        else // North
            return NORTH;
    }
}