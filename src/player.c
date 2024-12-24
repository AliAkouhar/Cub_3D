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

void    player(t_cub *cub, int tile)
{
    int     i;
    int     j;
    float     moveStep;

    printf("turn ->%f\n", cub->turnDirection);
    printf("walk ->%f\n", cub->walkDirection);

    cub->rotationAngle += cub->turnDirection * cub->rotationSpeed;
    // printf("rota --> %f, %f, %f\n", cub->rotationAngle, cub->turnDirection, cub->rotationSpeed);

    moveStep = cub->walkDirection * cub->speed;
    cub->player_x += cos(cub->rotationAngle) * moveStep;
    cub->player_y += sin(cub->rotationAngle) * moveStep;
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
    int  i;

    i = y0;
    (void)x1;
    while (i < y1)
    {
        my_mlx_pixel_put(cub, 0xFF0000, x0, i);
        i++;
    }
}

void    draw_player(t_cub *cub)
{
    player(cub, 10);
    line(cub, cub->player_x + 5,
        cub->player_y + 5,
        cub->player_x + (cos(cub->rotationAngle) * TILE),
        cub->player_y + (sin(cub->rotationAngle) * TILE));
        
    mlx_put_image_to_window(cub->mlx, cub->win, cub->img, 0, 0);
    cub->walkDirection = 0;
    cub->turnDirection = 0;
}

void    update_player(int key, t_cub *cub)
{
    if (key == 119)
        cub->walkDirection = 4;
    else if (key == 97)
        cub->turnDirection = -4;
    else if (key == 115)
        cub->walkDirection = -4;
    else if (key == 100)
        cub->turnDirection = 4;
}