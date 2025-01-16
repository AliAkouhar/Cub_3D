# include "../headers/cub3d_bonus.h"

// void rectangle_mini_map(t_point tile, int color, t_cub *cub)
// {
//     int i;
//     int j;

//     i = 0;
//     while (i < cub->tile_map * 0.2) // Scale for mini-map
//     {
//         j = 0;
//         while (j < cub->tile_map * 0.2)
//         {
//             my_mlx_pixel_put(cub, color, tile.x + j, tile.y + i);
//             j++;
//         }
//         i++;
//     }
// }

// void render_mini_map(t_cub *cub)
// {
//     t_point mini_map_tile;
//     int start_x, start_y, end_x, end_y;
//     int color;

//     // Define the visible area around the player
//     start_x = cub->player.point.x - 500;
//     start_y = cub->player.point.y - 500;
//     end_x = cub->player.point.x + 500;
//     end_y = cub->player.point.y + 500;

//     // Iterate over the visible area
//     for (int map_x = start_x / cub->tile_map; map_x <= end_x / cub->tile_map; map_x++)
//     {
//         for (int map_y = start_y / cub->tile_map; map_y <= end_y / cub->tile_map; map_y++)
//         {
//             // Check bounds to avoid accessing invalid map areas
//             if (map_x < 0 || map_x >= cub->height || map_y < 0 || map_y >= cub->width)
//                 continue;

//             // Determine color based on map content
//             if (cub->map_content[map_x][map_y] == '1')
//                 color = BLACK; // Wall
//             else if (cub->map_content[map_x][map_y] == 'D')
//                 color = 0xff05185; // Door
//             else
//                 color = WHITE; // Empty space

//             // Calculate mini-map tile position relative to (0, 0)
//             mini_map_tile.x = (map_y * cub->tile_map - start_y) * 0.2;
//             mini_map_tile.y = (map_x * cub->tile_map - start_x) * 0.2;

//             // Draw the mini-map tile
//             rectangle_mini_map(mini_map_tile, color, cub);
//         }
//     }

//     // Draw the player on the mini-map
//     t_point player_tile;
//     player_tile.x = (500 - (cub->player.point.x - start_x)) * 0.2; // Centered in the mini-map
//     player_tile.y = (500 - (cub->player.point.y - start_y)) * 0.2;
//     rectangle_mini_map(player_tile, 0xFF0000, cub); // Red for the player
// }


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

void rectangle(int x, int y, int color, t_cub *cub, float scale)
{
    int size = cub->tile_map * scale;
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            if (x + i < SCREEN_WIDTH && y + j < SCREEN_HEIGHT)
                my_mlx_pixel_put(cub, color, x + i, y + j);
        }
    }
}

void render_mini_map(t_cub *cub)
{
    int minimap_x = 0;
    int minimap_y = 0;
    int minimap_width = 200;
    int minimap_height = 100;
    int tile_size = cub->tile_map * 0.2;
    // int visible_tiles = 5; // Number of tiles to show in each direction
    // int half_tiles = visible_tiles / 2;
    int player_tile_x = cub->player.point.x / tile_size;
    int player_tile_y = cub->player.point.y / tile_size;
    int start_x = player_tile_x;
    int start_y = player_tile_y;
    int end_x = start_x;
    int end_y = start_y;

    // Ensure the start and end are within map boundaries
    if (start_x < 0) start_x = 0;
    if (start_y < 0) start_y = 0;
    if (end_x >= cub->width) end_x = cub->width - 1;
    if (end_y >= cub->height) end_y = cub->height - 1;

    // Draw the minimap background
    int i, j;
    for (i = 0; i < minimap_height; i++)
    {
        for (j = 0; j < minimap_width; j++)
        {
            my_mlx_pixel_put(cub, 0xC0C0C0, minimap_x + j, minimap_y + i);
        }
    }

    // Calculate scale
    float scale = (float)minimap_width / tile_size;

    // Draw map tiles
    for (int map_y = start_y; map_y < end_y; map_y++)
    {
        for (int map_x = start_x; map_x < end_x; map_x++)
        {
            char tile = cub->map_content[map_y][map_x];
            int color = 0xC0C0C0; // Default color
            if (tile == '1')
                color = 0x000000; // Wall
            else if (tile == 'D')
                color = 0xFFA500; // Door
            // Calculate minimap coordinates
            int mx = minimap_x + (map_x - start_x) * scale * tile_size;
            int my = minimap_y + (map_y - start_y) * scale * tile_size;
            // Draw tile
            rectangle(mx, my, color, cub, tile_size * scale);
        }
    }

    // Draw player position
    int player_minimap_x = minimap_x + (cub->player.point.x - start_x * tile_size - tile_size / 2) * scale;
    int player_minimap_y = minimap_y + (cub->player.point.y - start_y * tile_size - tile_size / 2) * scale;
    rectangle(player_minimap_x, player_minimap_y, 0xFF0000, cub, tile_size * scale / 2);
}