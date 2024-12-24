# include "../headers/cub3d.h"

void    init_mlx(t_cub *cub)
{
	cub->mlx = mlx_init();
    if (!cub->mlx)
        exit(printf("Error\nInit_mlx\n"));
    cub->win = mlx_new_window(cub->mlx, WIDTH * TILE, HEIGHT * TILE, "CUB3D");
    cub->img = mlx_new_image(cub->mlx, WIDTH * TILE, HEIGHT * TILE);
    cub->add = mlx_get_data_addr(cub->img, &cub->bit_per_pixel,
			&cub->size_line, &cub->endian);
}

void my_mlx_pixel_put(t_cub *cub, int color, float x, float y)
{
    char *dst;

    if (x < 0 || x >= (WIDTH * TILE) || y < 0 || y >= (HEIGHT * TILE))
        return;
    dst = cub->add + (((int)y * cub->size_line) + ((int)x * (cub->bit_per_pixel / 8)));

    if (cub->endian == 0) // Big endian
        *(unsigned int *)dst = ((color & 0xFF000000) >> 24) |
                               ((color & 0x00FF0000) >> 8) |
                               ((color & 0x0000FF00) << 8) |
                               ((color & 0x000000FF) << 24);
    else // Little endian
        *(unsigned int *)dst = color;
}

void    rectangle(int x, int y, int color, t_cub *cub)
{
    int i;
    int j;

    i = 0;
    while (i < TILE)
    {
        j = 0;
        while (j < TILE)
        {
            my_mlx_pixel_put(cub, color, x + j, y + i);
            // mlx_pixel_put(cub->mlx, cub->win, x + j, y + i, color);
            j++;
        }
        i++;
    }
}

void    draw_kbira(t_cub *cub)
{
    int i;
    int j;
    int tileX;
    int tileY;
    int color;

    i = 0;
    while (i < HEIGHT)
    {
        j = 0;
        while (j < WIDTH)
        {
            tileX = j * TILE;
            tileY = i * TILE;
            if (cub->map_content[i][j] == '1')
                color = BLACK;
            else
                color = WHITE;
            rectangle(tileX, tileY, color, cub);
            j++;
        }
        i++;
    }
}
