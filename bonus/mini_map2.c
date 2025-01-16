// #include "../headers/cub3d_bonus.h"

// void    rectangle(int x, int y, int color, t_cub *cub, int tile)
// {
//     int i;
//     int j;

//     i = 0;
//     while (i < tile * 0.2)
//     {
//         j = 0;
//         while (j < tile * 0.2)
//         {
//             my_mlx_pixel_put(cub, color, x + j, y + i);
//             j++;
//         }
//         i++;
//     }
// }


// void	line(t_cub *cub, float x0, float y0, float x1, float y1)
// {
// 	float	dx;
// 	float	dy;
// 	float	steps;
//     int     i;

// 	dx = x1 - x0;
// 	dy = y1 - y0;
// 	if (fabs(dx) > fabs(dy))
// 		steps = fabs(dx);
// 	else
// 		steps = fabs(dy);
//     i = 0;
// 	int color = 0x00FFFF;
// 	while (i <= steps)
// 	{
// 		// if (cub->is_ray_hit_door)
// 		// 	color = 0x00FF00;
// 		my_mlx_pixel_put(cub, color, round(x0), round(y0));
// 		x0 += dx / steps;
// 		y0 += dy / steps;
//         i++;
// 	}
// }

// void mini_rays(t_cub *cub)
// {
//     int     i;
//     float   rayIncrement;
//     t_point endpoint;

//     i = 0;
//     cub->player.current_ray_angle = cub->player.rotation_angle - (cub->player.fov_angle / 2);
//     rayIncrement = cub->player.fov_angle / NUMBER_OF_RAYS;
//     while (i < NUMBER_OF_RAYS)
//     {
//         normalizing(cub);
//         // cub->player.current_ray_angle = ray_angle;
//         cub->ray_id = i;
//         endpoint = cast(cub);
//         line(cub, (cub->player.point.x + 32) * 0.2, (cub->player.point.y + 32) * 0.2, 
//                     endpoint.x * 0.2,
//                     endpoint.y * 0.2
//             );
//         cub->player.current_ray_angle += rayIncrement;
//         i++;
//     }
// }

// void    draw_mini_map(t_cub *cub)
// {
//     // int i;
//     // int j;
//     // int tileX;
//     // int tileY;
//     // int color;
//     // i = 0;
//     // while (i < cub->height)
//     // {
//     //     j = 0;
//     //     while (j < cub->width)
//     //     {
//     //         tileX = j * cub->tile_map * 0.2;
//     //         tileY = i * cub->tile_map * 0.2;
//     //         if (cub->map_content[i][j] == '1')
//     //             color = BLACK;
//     //         else if (cub->map_content[i][j] == 'D') ///
//     //              color = 0xff05185;
//     //         else
//     //             color = WHITE;
//     //         rectangle(tileX, tileY, color, cub, cub->tile_map);
//     //         j++;
//     //     }
//     //     i++;
//     // }
//     // rectangle(cub->player.point.x * 0.2, cub->player.point.y * 0.2, 0xFF00FF00, cub, cub->player.tile);
//     // mini_rays(cub);
//     int minimap_size = 150;    // Size of the minimap in pixels
//     float scale = 0.2;         // Scale of the minimap (adjust for larger/smaller maps)
//     int player_range = 5;      // Render 5x5 tiles around the player

//     int start_x = fmax(0, cub->player.point.x - player_range);
//     int start_y = fmax(0, cub->player.point.y - player_range);
//     int end_x = fmin(cub->width, cub->player.point.x + player_range);
//     int end_y = fmin(cub->height, cub->player.point.y + player_range);

//     for (int y = start_y; y < end_y; y++)
//     {
//         for (int x = start_x; x < end_x; x++)
//         {
//             int screen_x = (x - start_x) * (minimap_size / (2 * player_range));
//             int screen_y = (y - start_y) * (minimap_size / (2 * player_range));
            
//             if (cub->map_content[y][x] == '1') // Wall
//                 rectangle(screen_x, screen_y, BLACK, cub, scale);
//             else
//                 rectangle(screen_x, screen_y, WHITE, cub, scale);
//         }
//     }

//     // Draw the player
//     int player_screen_x = minimap_size / 2;
//     int player_screen_y = minimap_size / 2;
//     // draw_rectangle(player_screen_x, player_screen_y, scale, PLAYER_COLOR);
//     rectangle(player_screen_x, player_screen_y, 0.2, cub, 0xff0000);
// }