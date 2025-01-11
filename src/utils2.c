# include "../headers/cub3d.h"

float   radian_to_degree(float corner)
{
    return (corner * (180 / PI));
}

int get_right_texture(t_point endPoint, float ray_angle)
{
    if (endPoint.ver_inter) // vertical wall
    {
        if (ray_angle > 3 * PI / 2 || ray_angle <= PI / 2) // East
            return EAST;
        else // West
            return WEST;
    }
    else // horizontal wall
    {
        if (ray_angle > 0 && ray_angle <= PI) // South
            return SOUTH;
        else // North
            return NORTH;
    }
}