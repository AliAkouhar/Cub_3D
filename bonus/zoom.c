# include "../headers/cub3d_bonus.h"

void    load_zoom(t_cub *cub)
{
    cub->zoom.img = mlx_xpm_file_to_image(cub->mlx,
				"./textures/zoom.xpm", &cub->zoom.texture_width,
				&cub->zoom.texture_height);
	if (!cub->zoom.img)
	{
		free_all_map(cub);
		exit(printf("Error\nFailed to load texture\n"));
	}
	cub->zoom.addr = mlx_get_data_addr(cub->zoom.img,
			&cub->zoom.b_per_pixel, &cub->zoom.line_length,
			&cub->zoom.endian);
}

void    render_zoom(t_cub *cub)
{
    int     i;
    int     j;
    unsigned int     color;
    t_point img_zoom;

    img_zoom.x = (SCREEN_WIDTH - cub->zoom.texture_width + 85) / 2;
    img_zoom.y = (SCREEN_HEIGHT - cub->zoom.texture_height) / 2;
    i = 0;
    while (i < cub->zoom.texture_height)
    {
        j = 0;
        while (j < cub->zoom.texture_width)
        {
            color = *(unsigned int *)(cub->zoom.addr + (i * cub->zoom.line_length + j * (cub->zoom.b_per_pixel / 8)));
            if (color != 0xFF000000)
                my_mlx_pixel_put(cub, color, img_zoom.x + j, img_zoom.y + i);
            j++;
        }
        i++;
    }
}
