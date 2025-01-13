# include "../headers/cub3d.h"

t_point horizontal_intersection(t_cub *cub, t_ray ray)
{
    t_point inter;
    t_point step_point;

    inter.ver_inter = 0;
    inter.y = floor(cub->player.point.y / cub->tile_map) * cub->tile_map;
    if (ray.isRayDown) // if the ray angle is facing down i should add a tile to ystep
        inter.y += cub->tile_map;
    inter.x = cub->player.point.x + ((inter.y - cub->player.point.y) / tan(cub->player.current_ray_angle));
    step_point.y = cub->tile_map;
    // Calculate the increment xstep and ystep
    if (ray.isRayUp)
        step_point.y *= -1;
    step_point.x = step_point.y / tan(cub->player.current_ray_angle);
    if ((ray.isRayLeft && step_point.x > 0) || (ray.isRayRight && step_point.x < 0))
        step_point.x *= -1;
    while (inter.x >= 0 && inter.x < cub->tile_map * cub->width && inter.y >= 0
        && inter.y < cub->tile_map * cub->height)
    {
        if (is_a_wall(cub, inter, 'h', ray))
            return (inter);
        inter.x += step_point.x;
        inter.y += step_point.y;
    }
    return (inter);
}

t_point    cast(t_cub *cub)
{
    t_point pVertical;
    t_point pHorizontal;
    float   verticalDistance;
    float   horizantalDistance;
    t_ray   ray;

    ray_direction(&ray, cub->player.current_ray_angle);
    pHorizontal = horizontal_intersection(cub, ray);
    pVertical = vertical_intersection(cub, ray);
    verticalDistance = get_distance(cub->player.point.x, cub->player.point.y, pVertical.x, pVertical.y);
    horizantalDistance = get_distance(cub->player.point.x, cub->player.point.y,pHorizontal.x,pHorizontal.y);
    if (verticalDistance < horizantalDistance)
        return (pVertical);
    return (pHorizontal);
}

void draw_3d_walls(t_cub *cub, t_point point, int index)
{
    cub->ray_distance = get_distance(cub->player.point.x, cub->player.point.y, point.x, point.y);
    cub->ray_distance *= cos(cub->player.rotationAngle - cub->player.current_ray_angle);
    // distance to projection plane
    cub->distance_pp = (SCREEN_WIDTH / 2) / tan(cub->player.FOV_angle / 2);
    // wall strip height
    cub->wall_strip_height = (cub->tile_map * cub->distance_pp) / cub->ray_distance;
    // top and bottom pixels of the wall
    cub->wall_top_pixel = (SCREEN_HEIGHT / 2) - (cub->wall_strip_height / 2);
    cub->wall_bottom_pixel = (SCREEN_HEIGHT / 2) + (cub->wall_strip_height / 2);
    render_textures_wall(cub, point, index);
}

/* this function draw the walls using the rays */
void cast_all_rays(t_cub *cub)
{
    int     i;
    float   rayIncrement;
    t_point endpoint;
    int     tex_index;

    i = 0;
    cub->player.current_ray_angle = cub->player.rotationAngle - (cub->player.FOV_angle / 2);
    rayIncrement = cub->player.FOV_angle / NUMBER_OF_RAYS;
    while (i < NUMBER_OF_RAYS)
    {
        normalizing(cub);
        cub->ray_id = i;
        endpoint = cast(cub);
        tex_index = get_right_texture(cub, endpoint);
        draw_3d_walls(cub, endpoint, tex_index);
        cub->player.current_ray_angle += rayIncrement;
        i++;
    }
}
