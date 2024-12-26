# include "../headers/cub3d.h"

void    check_player_spaces_position(t_cub *cub)
{
    int i;
    int j;

    i = -1;
    while (cub->map_content[++i])
    {
        j = -1;
        while (cub->map_content[i][++j])
            if (cub->map_content[i][j] == '0' || cub->map_content[i][j] == 'N' || cub->map_content[i][j] == 'S' || cub->map_content[i][j] == 'E' || cub->map_content[i][j] == 'W')
            {
                if (cub->map_content[i][j + 1] == 'a' || cub->map_content[i][j - 1] == 'a' ||
                    cub->map_content[i + 1][j] == 'a' || cub->map_content[i - 1][j] == 'a')
                    {
                        printf("Error\nPlayer position\n");
                        free_all_map(cub);
                        exit(1);
                    }
            }
    }
}

void    player(t_cub *cub, int tile)
{
    int     i;
    int     j;
    float   moveStepX;
    float   moveStepY;
    float   newPosX;
    float   newPosY;
    int     mapX;
    int     mapY;

    cub->rotationAngle += cub->turnDirection * cub->rotationSpeed;
    // moveStepX = cub->leftRight * cub->speed;
    // moveStepY = cub->walkDirection * cub->speed;
    // //
    // newPosX = cub->player_x + cos(cub->rotationAngle) * moveStepX;
    // newPosY = cub->player_y + sin(cub->rotationAngle) * moveStepY;
    moveStepX = cos(cub->rotationAngle) * cub->walkDirection - sin(cub->rotationAngle) * cub->leftRight;
    moveStepY = sin(cub->rotationAngle) * cub->walkDirection + cos(cub->rotationAngle) * cub->leftRight;

    newPosX = cub->player_x + moveStepX * cub->speed;
    newPosY = cub->player_y + moveStepY * cub->speed;
    mapX = floor(newPosX / TILE);
    mapY = floor(newPosY / TILE);
    if (mapX >= 0 && mapX < WIDTH && mapY >= 0 && mapY < HEIGHT &&
        cub->map_content[mapY][mapX] != '1')
    {
        cub->player_x = newPosX;
        cub->player_y = newPosY;
    }
    i = 0;
    while (i < tile)
    {
        j = 0;
        while (j < tile)
        {
            my_mlx_pixel_put(cub, 0x00FF00, cub->player_x + j, cub->player_y + i);
            j++;
        }
        i++;
    }
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
    line(cub, cub->player_x + 5,
        cub->player_y + 5,
        (cub->player_x + 5) + (cos(cub->rotationAngle) * TILE),
        (cub->player_y + 5) + (sin(cub->rotationAngle) * TILE));
        
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
    cub->walkDirection = 0;
    cub->turnDirection = 0;
    cub->leftRight = 0;
}

void    update_player(int key, t_cub *cub)
{
    if (key == 119) // W
        cub->walkDirection = 4;
    else if (key == 115) // S
        cub->walkDirection = -4;
    else if (key == 97) // A
        cub->leftRight = -4;
    else if (key == 100) // D
        cub->leftRight = 4;
    else if (key == 65363) // -> right
        cub->turnDirection = -4;
    else if (key == 65361) // <- left
        cub->turnDirection = 4;
}