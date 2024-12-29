# include "../headers/cub3d.h"

void    draw_player_rectangle(t_cub *cub, int tile)
{
    int     i;
    int     j;

    i = 0;
    while (i < tile)
    {
        j = 0;
        while (j < tile)
        {
            my_mlx_pixel_put(cub, 0xFF0000, cub->player.point.x + j, cub->player.point.y + i);
            j++;
        }
        i++;
    }
}

void    player(t_cub *cub, int tile)
{
    float   moveStepX;
    float   moveStepY;
    float   newPosX;
    float   newPosY;
    int     mapX;
    int     mapY;

    cub->player.rotationAngle += cub->player.turnDirection * cub->player.rotationSpeed;
    moveStepX = cos(cub->player.rotationAngle) * cub->player.walkDirection - sin(cub->player.rotationAngle) * cub->player.leftRight;
    moveStepY = sin(cub->player.rotationAngle) * cub->player.walkDirection + cos(cub->player.rotationAngle) * cub->player.leftRight;

    newPosX = cub->player.point.x + moveStepX * cub->player.speed;
    newPosY = cub->player.point.y + moveStepY * cub->player.speed;
    mapX = floor(newPosX / TILE);
    mapY = floor(newPosY / TILE);
    if (mapX >= 0 && mapX < WIDTH && mapY >= 0 && mapY < HEIGHT &&
        cub->map_content[mapY][mapX] != '1')
    {
        cub->player.point.x = newPosX;
        cub->player.point.y = newPosY;
    }
    draw_player_rectangle(cub, tile);
}

void    line(t_cub *cub, float x0, float y0, float x1, float y1)
{
    float dx;
    float dy;
    float steps;
    float xIncrement;
    float yIncrement;
    
    dx = x1 - x0;
    dy = y1 - y0;
    if (fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);
    xIncrement = dx / steps;
    yIncrement = dy / steps;
    for (int i = 0; i <= steps; i++)
    {
        my_mlx_pixel_put(cub, 0x00FF00, round(x0), round(y0));
        x0 += xIncrement;
        y0 += yIncrement;
    }
}

void    draw_player(t_cub *cub)
{
    player(cub, 10);
    // line(cub, cub->player.point.x + 5,
    //     cub->player.point.y + 5,
    //     (cub->player.point.x + 5) + (cos(cub->player.rotationAngle) * LINE_SIZE),
    //     (cub->player.point.y + 5) + (sin(cub->player.rotationAngle) * LINE_SIZE));
    cast_all_rays(cub);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
}