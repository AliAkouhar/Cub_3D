# include "../headers/cub3d.h"

t_point horizontal_intersection(t_cub *cub, t_ray ray, float rayAngle)
{
    t_point inter;
    t_point step_point;

    inter.y = floor(cub->player.point.y / TILE) * TILE;
    if (ray.isRayDown) // if the ray angle is facing down i should add a tile to ystep
        inter.y += TILE;
    inter.x = cub->player.point.x + ((inter.y - cub->player.point.y) / tan(rayAngle));
    step_point.y = TILE;
    // Calculate the increment xstep and ystep
    if (ray.isRayUp)
        step_point.y *= -1;
    step_point.x = step_point.y / tan(rayAngle);
    if ((ray.isRayLeft && step_point.x > 0) || (ray.isRayRight && step_point.x < 0))
        step_point.x *= -1;
    while (inter.x >= 0 && inter.x <= cub->width * TILE && inter.y >= 0 && inter.y <= cub->height * TILE)
    {
        if (isAWall(cub, inter, 'h', ray))
            return (inter);
        inter.x += step_point.x;
        inter.y += step_point.y;
    }
    return (inter);
}

t_point    cast(t_cub *cub, float rayAngle)
{
    t_point pVertical;
    t_point pHorizontal;
    float   verticalDistance;
    float   horizantalDistance;
    t_ray   ray;
    // HORIZONTAL INTERSECTION CODE "ALI" //
    ray_direction(&ray, rayAngle);
    pHorizontal = horizontal_intersection(cub, ray, rayAngle);
    // VERTICAL INTERSECTION CODE "TIIMA" //

    pVertical = vertical_intersection(cub, ray, rayAngle);
    verticalDistance = getDistance(cub->player.point.x, cub->player.point.y, pVertical.x, pVertical.y);
    horizantalDistance = getDistance(cub->player.point.x, cub->player.point.y,pHorizontal.x,pHorizontal.y);
    if (verticalDistance < horizantalDistance)
        return (pVertical);
    return (pHorizontal);
}

void    cast_all_rays(t_cub *cub)
{
    int     i;
    float   rayAngle;
    float   rayIncrement;
    t_point endPoint;

    i = 0;
    rayAngle = cub->player.rotationAngle - (cub->player.FOV_angle / 2);
    rayIncrement = cub->player.FOV_angle / NUMBER_OF_RAYS;
    while (i < NUMBER_OF_RAYS)
    {
        normalizing(&rayAngle);
        endPoint = cast(cub, rayAngle);
        line(cub,
            cub->player.point.x + 5,
            cub->player.point.y + 5,
            endPoint.x,
            endPoint.y
        );
        rayAngle += rayIncrement;
        i++;
    }
}
