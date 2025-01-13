#include "../headers/cub3d_bonus.h"

void    load_weapon(t_cub *cub)
{
    cub->weapon.img = mlx_xpm_file_to_image(cub->mlx,
				"./textures/weapon.xpm", &cub->weapon.texture_width,
				&cub->weapon.texture_height);
	if (!cub->weapon.img)
	{
		free_all_map(cub);
		exit(printf("Error\nFailed to load texture\n"));
	}
	cub->weapon.addr = mlx_get_data_addr(cub->weapon.img,
			&cub->weapon.b_per_pixel, &cub->weapon.line_length,
			&cub->weapon.endian);
}

void    render_weapon(t_cub *cub)
{
    int     i;
    int     j;
    unsigned int     color;
    t_point weapon_img;

    weapon_img.x = (SCREEN_WIDTH - cub->weapon.texture_width) / 2;
    weapon_img.y = SCREEN_HEIGHT - cub->weapon.texture_height;
    i = 0;
    while (i < cub->weapon.texture_height)
    {
        j = 0;
        while (j < cub->weapon.texture_width)
        {
            color = *(unsigned int *)(cub->weapon.addr + (i * cub->weapon.line_length + j * (cub->weapon.b_per_pixel / 8)));
            if (color != 0xFF000000)
                my_mlx_pixel_put(cub, color, weapon_img.x + j, weapon_img.y + i);
            j++;
        }
        i++;
    }
}
