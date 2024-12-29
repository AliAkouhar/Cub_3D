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
    x = floor(point.x / TILE);
    y = floor(point.y / TILE);
    if (cub->map_content[y][x] == '1')
        return (true);
    return (false);
}

t_point vertical_intersection(t_cub *cub, t_ray ray, float rayAngle)
{
    t_point firstInter;
    t_point step;

    // coordonee of the first vertical intersection
    firstInter.x = floor(cub->player.point.x / TILE) * TILE;
    firstInter.y = cub->player.point.y + ((firstInter.x - cub->player.point.x) * tan(rayAngle));

    // xstep and ystep coordonee
    step.x = TILE;
    if (ray.isRayLeft)
        step.x *= -1;
    step.y = TILE * tan(rayAngle);
    if ((ray.isRayUp && step.y > 0) || (ray.isRayDown && step.y < 0))
        step.y *= -1;
    while (firstInter.x >= 0 && firstInter.x <= WIDTH * TILE && firstInter.y >= 0 && firstInter.y <= HEIGHT * TILE)
    {
        if (isAWall(cub, firstInter, 'h', ray))
            return (firstInter);
        else
        {
            firstInter.x += step.x;
            firstInter.y += step.y;
        }
    }
    return (firstInter);
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