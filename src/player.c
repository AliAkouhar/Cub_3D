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
                        printf("Error\nPlayer position %i-- %s\n", i + 1, cub->map_content[i]);
                        free_all_map(cub);
                        exit(1);
                    }
            }
    }
}

void    line(t_cub *cub, float x0, float y0, float x1, float y1)
{
    // int x = ((xs * TILE) - 1) + (30 / 2);
    // int y = ((ys * TILE) - 1) + (30 / 2);
    // int i;
    // int j;

    // i = 0;
    float dx = fabs(x1 - x0);
    float dy = fabs(y1 - y0);
    float sx = x0 < x1 ? 1 : -1;
    float sy = y0 < y1 ? 1 : -1;
    float err = dx - dy;

    while (1)
    {
        my_mlx_pixel_put(cub, 0xFF0000, x0, y0); // Draw the current pixel

        if ((int)x0 == (int)x1 && (int)y0 == (int)y1)
            break;

        float e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void    player(t_cub *cub, int tile)
{
    int     i;
    int     j;

    cub->rotationAngle += cub->turnDirection * cub->rotationSpeed;
    cub->player_x += cub->walkDirection * cos(cub->rotationAngle) * cub->speed;
    cub->player_y += cub->walkDirection * sin(cub->rotationAngle) * cub->speed;
    i = 0;
    while (i < tile)
    {
        j = 0;
        while (j < tile)
        {
                my_mlx_pixel_put(cub, 0x00FF00, (cub->player_x * TILE) + j, (cub->player_y * TILE) + i);
            j++;
        }
        i++;
    }
    // line(cub, cub->player_x * TILE,
    //     cub->player_y * TILE,
    //     cos(cub->rotationAngle) * 20,
    //     sin(cub->rotationAngle) * 20);
}

void    draw_player(t_cub *cub)
{
    player(cub, 10);
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
}

void    update_player(int key, t_cub *cub)
{
    if (key == 119)
        cub->walkDirection = 0.5;
    else if (key == 97)
        cub->turnDirection = -0.5; 
    else if (key == 115)
        cub->walkDirection = -0.5;
    else if (key == 100)
        cub->turnDirection = 0.5;
}