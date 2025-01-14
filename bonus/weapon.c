#include "../headers/cub3d_bonus.h"

void    load_weapon(t_cub *cub)
{
    int i;

    i = 0;
    while (i < WEAPON_FRAME_NUMBER)
    {
        cub->weapon[i].img = mlx_xpm_file_to_image(cub->mlx,
                    cub->weapon[i].path, &cub->weapon[i].texture_width,
                    &cub->weapon[i].texture_height);
        if (!cub->weapon[i].img)
        {
            free_all_map(cub);
            exit(printf("Error\nFailed to load texture\n"));
        }
        cub->weapon[i].addr = mlx_get_data_addr(cub->weapon[i].img,
                &cub->weapon[i].b_per_pixel, &cub->weapon[i].line_length,
                &cub->weapon[i].endian);
        i++;
    }
}

void    render_weapon(t_cub *cub, int index)
{
    int     i;
    int     j;
    unsigned int     color;
    t_point weapon_img;

    weapon_img.x = (SCREEN_WIDTH - cub->weapon[index].texture_width) / 2;
    weapon_img.y = SCREEN_HEIGHT - cub->weapon[index].texture_height;
    i = 0;
    while (i < cub->weapon[index].texture_height)
    {
        j = 0;
        while (j < cub->weapon[index].texture_width)
        {
            color = *(unsigned int *)(cub->weapon[index].addr + (i * cub->weapon[index].line_length + j * (cub->weapon[index].b_per_pixel / 8)));
            if (color != 0xFF000000)
                my_mlx_pixel_put(cub, color, weapon_img.x + j, weapon_img.y + i);
            j++;
        }
        i++;
    }
}

void    weapon_animation(t_cub *cub)
{
    if (cub->weapon_shooting)
    {
        cub->weapon_frame++;
        if (cub->weapon_frame >= WEAPON_FRAME_NUMBER)
        {
            cub->weapon_frame = 0;
            cub->weapon_shooting = 0; // Stop animation
        }
    }
    else if (!cub->weapon_shooting && cub->weapon_frame != 0)
    {
        usleep(40000);
        cub->weapon_frame--;
    }
}
