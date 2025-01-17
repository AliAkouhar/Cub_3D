/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:50:45 by fbazaz            #+#    #+#             */
/*   Updated: 2025/01/17 17:50:46 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

int	ft_close(t_cub *cub)
{
	printf("Closing the window..\n");
	free_all_map(cub);
	mlx_destroy_image(cub->mlx, cub->img);
	mlx_destroy_window(cub->mlx, cub->win);
	mlx_destroy_display(cub->mlx);
	free(cub->mlx);
	exit(0);
}

int	key_press(int key, t_cub *cub)
{
	if (key == ESC)
		ft_close(cub);
	if (key == W)
		cub->player.walk_direction = 2;
	else if (key == S)
		cub->player.walk_direction = -2;
	else if (key == A)
		cub->player.left_right = -2;
	else if (key == D)
		cub->player.left_right = 2;
	else if (key == RIGHT)
		cub->player.turn_direction = +1;
	else if (key == LEFT)
		cub->player.turn_direction = -1;
	else if (key == SPACE)
	{
		cub->weapon_shooting = 1;
		cub->weapon_frame = 0;
	}
	return (0);
}

int	key_release(int key, t_cub *cub)
{
	if (key == W)
		cub->player.walk_direction = 0;
	else if (key == S)
		cub->player.walk_direction = 0;
	else if (key == A)
		cub->player.left_right = 0;
	else if (key == D)
		cub->player.left_right = 0;
	else if (key == RIGHT)
		cub->player.turn_direction = 0;
	else if (key == LEFT)
		cub->player.turn_direction = 0;
	else if (key == SPACE)
	{
		cub->weapon_shooting = 0;
		cub->weapon_frame = 0;
	}
	return (0);
}
