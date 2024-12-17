/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiima <tiima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:41:52 by fbazaz            #+#    #+#             */
/*   Updated: 2024/09/11 13:00:26 by tiima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	init_cub(t_cub *cub)
{
	cub->no_texture = NULL;
	cub->so_texture = NULL;
	cub->we_texture = NULL;
	cub->ea_texture = NULL;
	cub->floor_color.r = -1;
	cub->floor_color.g = -1;
	cub->floor_color.b = -1;
	cub->ceiling_color.r = -1;
	cub->ceiling_color.g = -1;
	cub->ceiling_color.b = -1;
}

int	main(int ac, char **av)
{
	t_cub	cub;

	init_cub(&cub);
	ft_parsing(&cub, ac, av);
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, 500, 500, "hhhhhh");
	(void)win;
	mlx_loop(mlx);
}
