# include "../headers/cub3d.h"

// t_point horizontal_intersection(t_cub *cub, t_ray ray, float rayAngle){}

t_point    cast(t_cub *cub, float rayAngle)
{
    // t_point pHorizontal;
    t_point pVertical;
    // float   verticalDistance;
    // float   horizantalDistance;
    t_ray   ray;
    // HORIZONTAL INTERSECTION CODE "ALI" //
    ray_direction(&ray, rayAngle);
    // pHorizontal = horizontal_intersection(cub, ray, rayAngle);
    // VERTICAL INTERSECTION CODE "TIIMA" //
    pVertical = vertical_intersection(cub, ray, rayAngle);
    // verticalDistance = getDistance(cub->player.point.x, cub->player.point.y, pVertical.x, pVertical.y);
    // horizantalDistance = getDistance(cub->player.point.x, cub->player.point.y,pHorizontal.x,pHorizontal.y);
    // if (verticalDistance < horizantalDistance)
        return (pVertical);
    // return (pHorizontal);
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
