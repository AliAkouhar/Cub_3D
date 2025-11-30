/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:27:27 by fbazaz            #+#    #+#             */
/*   Updated: 2025/01/13 13:27:28 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

float	radian_to_degree(float corner)
{
	return (corner * (180 / PI));
}

int	get_right_texture(t_cub *cub, t_point endPoint)
{
	if (endPoint.ver_inter)
	{
		if (cub->player.current_ray_angle > 3 * PI / 2
			|| cub->player.current_ray_angle < PI / 2)
			return (EAST);
		else
			return (WEST);
	}
	else
	{
		if (cub->player.current_ray_angle > 0
			&& cub->player.current_ray_angle < PI)
			return (SOUTH);
		else
			return (NORTH);
	}
}
