# include "../headers/cub3d_bonus.h"

void rectangle_mini_map(t_point tile, int color, t_cub *cub)
{
    int i;
    int j;

    i = 0;
    while (i < cub->tile_map * 0.2) // Scale for mini-map
    {
        j = 0;
        while (j < cub->tile_map * 0.2)
        {
            my_mlx_pixel_put(cub, color, tile.x + j, tile.y + i);
            j++;
        }
        i++;
    }
}

void render_mini_map(t_cub *cub)
{
    t_point mini_map_tile;
    int start_x, start_y, end_x, end_y;
    int color;

    // Define the visible area around the player
    start_x = cub->player.point.x - 500;
    start_y = cub->player.point.y - 500;
    end_x = cub->player.point.x + 500;
    end_y = cub->player.point.y + 500;

    // Iterate over the visible area
    for (int map_x = start_x / cub->tile_map; map_x <= end_x / cub->tile_map; map_x++)
    {
        for (int map_y = start_y / cub->tile_map; map_y <= end_y / cub->tile_map; map_y++)
        {
            // Check bounds to avoid accessing invalid map areas
            if (map_x < 0 || map_x >= cub->height || map_y < 0 || map_y >= cub->width)
                continue;

            // Determine color based on map content
            if (cub->map_content[map_x][map_y] == '1')
                color = BLACK; // Wall
            else if (cub->map_content[map_x][map_y] == 'D')
                color = 0xff05185; // Door
            else
                color = WHITE; // Empty space

            // Calculate mini-map tile position relative to (0, 0)
            mini_map_tile.x = (map_y * cub->tile_map - start_y) * 0.2;
            mini_map_tile.y = (map_x * cub->tile_map - start_x) * 0.2;

            // Draw the mini-map tile
            rectangle_mini_map(mini_map_tile, color, cub);
        }
    }

    // Draw the player on the mini-map
    t_point player_tile;
    player_tile.x = (500 - (cub->player.point.x - start_x)) * 0.2; // Centered in the mini-map
    player_tile.y = (500 - (cub->player.point.y - start_y)) * 0.2;
    rectangle_mini_map(player_tile, 0xFF0000, cub); // Red for the player
}


// void    render_mini_map(t_cub *cub)
// {
//     t_point mini_map;
//     int     color;

//     mini_map.x = cub->player.point.x - 500;
//     while (mini_map.x < cub->height)
//     {
//         mini_map.y = cub->player.point.y - 500;
//         while (mini_map.y < cub->width)
//         {
//             if (cub->map_content[(int)mini_map.x / cub->tile_map][(int)mini_map.y / cub->tile_map] == '1')
//                 color = BLACK;
//             else if (cub->map_content[(int)mini_map.x][(int)mini_map.y] == 'D')
//                  color = 0xff05185;
//             else
//                 color = WHITE;
//             my_mlx_pixel_put(cub, color, mini_map.y, mini_map.x);
//             mini_map.y++;
//         }
//         mini_map.x++;
//     }
// }