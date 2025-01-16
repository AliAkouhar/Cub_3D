# include "../headers/cub3d_bonus.h"

void    render_bonus_features(t_cub *cub)
{
    render_zoom(cub);
	weapon_animation(cub);
    render_weapon(cub, cub->weapon_frame); // default weapon
    render_mini_map(cub);
    // draw_mini_map(cub);
}