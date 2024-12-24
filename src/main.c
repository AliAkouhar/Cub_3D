/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:41:52 by fbazaz            #+#    #+#             */
/*   Updated: 2024/12/16 16:01:26 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	init_cub(t_cub *cub)
{
	cub->content = NULL;
	cub->map_content = NULL;
	cub->textures_path[NORTH] = NULL;
	cub->textures_path[SOUTH] = NULL;
	cub->textures_path[EAST] = NULL;
	cub->textures_path[WEST] = NULL;
	cub->floor_color.r = -1;
	cub->floor_color.g = -1;
	cub->floor_color.b = -1;
	cub->ceiling_color.r = -1;
	cub->ceiling_color.g = -1;
	cub->ceiling_color.b = -1;
	cub->turnDirection = 0;
	cub->walkDirection = 0;
	cub->speed = 2;
	cub->rotationAngle = PI / 2;
	cub->rotationSpeed = 2 * (PI / 180);
}

int	print(int key, t_cub *cub)
{
	printf("key --> %i\n", key);
	if (key == 65307)
		exit(0);
	if (key ==  119 || key == 97 || key == 115 || key == 100)
	{
		mlx_clear_window(cub->mlx, cub->win);
		update_player(key, cub);
		draw_kbira(cub);
		draw_player(cub);
	}
	return 0;
}

int	print2(int mouse, int x, int y, t_cub *cub)
{
	(void)mouse;
	printf("mouse --> %c\n", cub->map_content[y / TILE][x / TILE]);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	init_cub(&cub);
	ft_parsing(&cub, ac, av);
	//
	cub.player_x *= TILE;
	cub.player_y *= TILE;
	init_mlx(&cub);
	draw_kbira(&cub);
	draw_player(&cub);
	mlx_key_hook(cub.win, print, &cub);
	mlx_mouse_hook(cub.win,print2, &cub);
	mlx_loop(cub.mlx);
}
