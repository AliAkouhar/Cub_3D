# include "../headers/cub3d.h"

float   getDistance(float x1, float y1, float x2, float y2)
{
    return (sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
}

bool    isAWall(t_cub *cub, t_point point, char c, t_ray ray)
{
    int x;
    int y;

    if (c == 'h' && ray.isRayUp)
        point.y--;
    if (c == 'v' && ray.isRayLeft)
        point.x--;
    x = floor(point.x / TILE);
    y = floor(point.y / TILE);
    if (cub->map_content[y][x] == '1')
        return (true);
    return (false);
}

t_point vertical_intersection(t_cub *cub, t_ray ray, float rayAngle)
{
    t_point inter;
    t_point step;

    // coordonee of the first vertical intersection
    inter.x = floor(cub->player.point.x / TILE) * TILE;
    if (ray.isRayRight)
        inter.x += TILE;
    inter.y = cub->player.point.y + ((inter.x - cub->player.point.x) * tan(rayAngle));
    // xstep and ystep coordonee
    step.x = TILE;
    if (ray.isRayLeft)
        step.x *= -1;
    step.y = TILE * tan(rayAngle);
    if ((ray.isRayUp && step.y > 0) || (ray.isRayDown && step.y < 0))
        step.y *= -1;
    while (inter.x >= 0 && inter.x <= WIDTH * TILE && inter.y >= 0 && inter.y <= HEIGHT * TILE)
    {
        if (isAWall(cub, inter, 'v', ray))
            return (inter);
        else
        {
            inter.x += step.x;
            inter.y += step.y;
        }
    }
    return (inter);
}

void    ray_direction(t_ray *ray, float rayAngle)
{
    ray->isRayDown = rayAngle > 0 && rayAngle < PI;
    ray->isRayUp = !ray->isRayDown;
    ray->isRayRight = rayAngle < 0.5 * PI || rayAngle > 1.5 * PI;
    ray->isRayLeft = !ray->isRayRight;
}

void    normalizing(float *rayAngle)
{
    *rayAngle = fmod(*rayAngle, 2 * PI);
    if (*rayAngle < 0)
        *rayAngle += 2 * PI;
} 