#include "../headers/cub3d.h"
void    rectangle(int x, int y, int color, t_cub *cub)
{
    int i;
    int j;

    i = 0;
    while (i < cub->tile_map * 0.2)
    {
        j = 0;
        while (j < cub->tile_map * 0.2)
        {
            my_mlx_pixel_put(cub, color, x + j, y + i);
            j++;
        }
        i++;
    }
}

void mini_rays(t_cub *cub)
{
    int     i;
    float   ray_angle;
    float   rayIncrement;
    t_point endpoint;
    int     color;
    (void)color;

    i = 0;
    ray_angle = cub->player.rotationAngle - (cub->player.FOV_angle / 2);
    rayIncrement = cub->player.FOV_angle / NUMBER_OF_RAYS;
    while (i < NUMBER_OF_RAYS)
    {
        normalizing(&ray_angle);
        cub->player.current_ray_angle = ray_angle;
        endpoint = cast(cub, ray_angle);
        line(cub, (cub->player.point.x + 32) * 0.2, (cub->player.point.y + 32) * 0.2, 
                endpoint.x * 0.2,
                endpoint.y * 0.2
        );
        ray_angle += rayIncrement;
        i++;
    }
}

void    draw_mini_map(t_cub *cub)
{
    int i;
    int j;
    int tileX;
    int tileY;
    int color;
    i = 0;
    while (i < cub->height)
    {
        j = 0;
        while (j < cub->width)
        {
            tileX = j * cub->tile_map * 0.2;
            tileY = i * cub->tile_map * 0.2;
            if (cub->map_content[i][j] == '1')
                color = BLACK;
            else
                color = WHITE;
            rectangle(tileX, tileY, color, cub);
            j++;
        }
        i++;
    }
    rectangle(cub->player.point.x * 0.2, cub->player.point.y * 0.2, 0xFF00FF00, cub);
    mini_rays(cub);
}
