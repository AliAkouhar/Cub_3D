# include "../headers/cub3d_bonus.h"

void    free_to_exit(t_cub *cub)
{
    free_all_map(cub);
    printf("Error\nCannot opan the Map\n");
    exit(1);
}

void    render_bonus_features(t_cub *cub)
{
    render_zoom(cub);
	weapon_animation(cub);
    render_weapon(cub, cub->weapon_frame);
    render_mini_map(cub);
}