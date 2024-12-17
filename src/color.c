/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:23:39 by fbazaz            #+#    #+#             */
/*   Updated: 2024/09/10 14:37:34 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	array_size(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return (1);
	while (arr[i])
		i++;
	return (i);
}

int	check_color(t_cub *cub)
{
	if (cub->ceiling_color.r == -1 || cub->ceiling_color.g == -1
		|| cub->ceiling_color.b == -1 || cub->floor_color.r == -1
		|| cub->floor_color.g == -1 || cub->floor_color.b == -1)
		return (1);
	return (0);
}

void	parse_color(char *line, t_color *color)
{
	char	**rgb;

	rgb = ft_split(line, ',');
	if (!rgb || array_size(rgb) != 3)
	{
		printf("Error\nInvalid color format\n");
		exit(1);
	}
	color->r = ft_atoi(rgb[0]);
	color->g = ft_atoi(rgb[1]);
	color->b = ft_atoi(rgb[2]);
	free_2d(rgb);
	if (color->r < 0 || color->r > 255 || color->g < 0 || color->g > 255
		|| color->b < 0 || color->b > 255)
	{
		printf("Error\nInvalid RGB values range [0-255]\n");
		exit(1);
	}
}
