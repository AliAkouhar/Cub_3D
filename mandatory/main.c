/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:41:52 by fbazaz            #+#    #+#             */
/*   Updated: 2025/01/17 17:03:29 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	main(int ac, char **av)
{
	t_cub	cub;

	if (ac != 2)
		exit(printf("USAGE ERROR:\n./cub3D <map>.cub\n"));
	if (SCREEN_WIDTH < 0 || SCREEN_WIDTH > 2000 || SCREEN_HEIGHT < 0
		|| SCREEN_HEIGHT > 1000)
		return (printf("Error\nIvalid SCREEN_WIDTH or SCREEN_HEIGHT\n"), 1);
	init_cub(&cub);
	ft_parsing(&cub, av);
	init_mlx(&cub);
	mlx_loop_hook(cub.mlx, draw, &cub);
	mlx_hook(cub.win, 17, 1L << 0, ft_close, &cub);
	mlx_hook(cub.win, 2, 1L << 0, key_press, &cub);
	mlx_hook(cub.win, 3, 1L << 1, key_release, &cub);
	mlx_loop(cub.mlx);
}
