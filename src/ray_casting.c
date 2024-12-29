# include "../headers/cub3d.h"

// t_point horizontal_intersection(t_cub *cub, float rayAngle){}

// t_point vertical_intersection(t_cub *cub, float rayAngle){}


// t_point    cast(t_cub *cub, float rayAngle)
// {
//     t_point pHorizontal;
//     t_point pVertical;
//     ////////////////////////////////////////
//     // HORIZONTAL INTERSECTION CODE "ALI" //
//     ////////////////////////////////////////
//     pHorizontal = horizontal_intersection(cub, rayAngle);


//     ////////////////////////////////////////
//     // VERTICAL INTERSECTION CODE "TIIMA" //
//     ////////////////////////////////////////
//     pVertical = vertical_intersection(cub, rayAngle);
//     return (/*the closest one*/);
// }

void    cast_all_rays(t_cub *cub)
{
    int     i;
    float   rayAngle;
    float   rayIncrement;
    // t_point endPoint;

    i = 0;
    rayAngle = cub->player.rotationAngle - (cub->player.FOV_angle / 2);
    rayIncrement = cub->player.FOV_angle / NUMBER_OF_RAYS;
    while (i < NUMBER_OF_RAYS)
    {
        normalizing(&rayAngle);
        // endPoint = cast(cub, rayAngle);
        line(cub,
            cub->player.point.x + 5,
            cub->player.point.y + 5,
            cub->player.point.x + 5 + cos(rayAngle) * LINE_SIZE,
            cub->player.point.y + 5 + sin(rayAngle) * LINE_SIZE
        );
        rayAngle += rayIncrement;
        i++;
    }
}
