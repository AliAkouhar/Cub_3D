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

int	print(int key, void *p)
{
	(void)p;

	printf("key --> %i\n", key);
	return 0;
}

int	main(int ac, char **av)
{
	t_cub	cub;

	init_cub(&cub);
	ft_parcing(&cub, ac, av);
	{ // just for testing 
		printf("no --> %s\n", cub.no_texture);
		printf("so --> %s\n", cub.so_texture);
		printf("ea --> %s\n", cub.ea_texture);
		printf("we --> %s\n", cub.we_texture);
		printf("floor r --> %i\n", cub.floor_color.r);
		printf("floor g --> %i\n", cub.floor_color.g);
		printf("floor b --> %i\n", cub.floor_color.b);
		printf("ceiling r --> %i\n", cub.ceiling_color.r);
		printf("ceiling g --> %i\n", cub.ceiling_color.g);
		printf("ceiling b --> %i\n", cub.ceiling_color.b);
	}
	void *mlx = mlx_init();
	void *win = mlx_new_window(mlx, HEIGHT, WIDTH, "CUB3D");
	mlx_key_hook(win, print, NULL);
	mlx_loop(mlx);
}
