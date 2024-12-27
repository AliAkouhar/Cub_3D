/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:41:52 by fbazaz            #+#    #+#             */
/*   Updated: 2024/12/27 15:03:27 by fbazaz           ###   ########.fr       */
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
	cub->player.turnDirection = 0;
	cub->player.walkDirection = 0;
	cub->player.leftRight = 0;
	cub->player.speed = 2.0;
	cub->player.FOV_angle = 60 * (PI / 180);
	cub->player.rotationAngle = PI / 2;
	cub->player.rotationSpeed = 2 * (PI / 180);
}

int	main(int ac, char **av)
{
	t_cub	cub;

	init_cub(&cub);
	ft_parsing(&cub, ac, av);
	cub.player.player_x = (cub.player.player_x * TILE) + TILE / 2;
	cub.player.player_y = (cub.player.player_y * TILE) + TILE / 2;
	init_mlx(&cub);
	draw_big_map(&cub);
	mlx_mouse_hook(cub.win, print2, &cub);
	mlx_hook(cub.win, 17, (1L<<0), ft_close, &cub); // also to search
	mlx_hook(cub.win, 2, 1L << 0, key_press, &cub); // to search
	mlx_hook(cub.win, 3, 1L << 1, key_release, &cub);
	mlx_loop(cub.mlx);
}
