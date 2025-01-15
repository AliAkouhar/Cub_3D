# include "../headers/cub3d_bonus.h"

void    init_weapon_textures(t_cub *cub)
{
    int i;
    
    i = 0;
    while (i < WEAPON_FRAME_NUMBER)
    {
        cub->weapon[i].img = NULL;
        if (i <= 9)
            cub->weapon[i].path = ft_strdup("./textures/weapon/weapon_0");
        else
            cub->weapon[i].path = ft_strdup("./textures/weapon/weapon_");
        cub->weapon[i].path = ft_strjoin2(cub->weapon[i].path, ft_itoa(i));
        cub->weapon[i].path = ft_strjoin2(cub->weapon[i].path, ".xpm");
        i++;
    }
}

void    init_door_textures(t_cub *cub)
{
    int i;
    
    i = 0;
    while (i < DOOR_FRAME_NUMBER)
    {
        cub->doors[i].img = NULL;
        if (i <= 9)
            cub->doors[i].path = ft_strdup("./textures/doors/door_0");
        else
            cub->doors[i].path = ft_strdup("./textures/doors/door_");
        cub->doors[i].path = ft_strjoin2(cub->doors[i].path, ft_itoa(i));
        cub->doors[i].path = ft_strjoin2(cub->doors[i].path, ".xpm");
        i++;
    }
    cub->is_door_open = 0;
    cub->door_frame = 0;
}
