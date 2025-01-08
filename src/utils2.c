# include "../headers/cub3d.h"

float   radian_to_degree(float corner)
{
    return (corner * (180 / PI));
}

int get_wall_color(t_point endPoint, float ray_angle)
{
    if (endPoint.ver_inter) // vertical wall
    {
        if (ray_angle > 3 * PI / 2 || ray_angle <= PI / 2) // East
            return COLOR_EAST;
        else // West
            return COLOR_WEST;
    }
    else // horizontal wall
    {
        if (ray_angle > 0 && ray_angle <= PI) // South
            return COLOR_SOUTH;
        else // North
            return COLOR_NORTH;
    }
}