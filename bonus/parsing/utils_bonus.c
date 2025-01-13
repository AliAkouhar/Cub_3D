/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:23:56 by fbazaz            #+#    #+#             */
/*   Updated: 2025/01/13 07:58:16 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d_bonus.h"

void	fre(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
}

void	free_all_map(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (cub->textures[i].path)
		{
			if (cub->textures[i].img)
				mlx_destroy_image(cub->mlx, cub->textures[i].img);
			fre(cub->textures[i].path);
		}
		i++;
	}
	if (cub->zoom.img)
		mlx_destroy_image(cub->mlx, cub->zoom.img);
	if (cub->map_content)
		free_2d(cub->map_content);
}

void	free_2d(char **str)
{
	int	i;

	i = -1;
	if (str)
	{
		while (str[++i])
			fre(str[i]);
		free(str);
		str = NULL;
	}
}

int	array_size(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

char	*new_string(char a, int size)
{
	char	*str;
	int		i;

	if (size <= 0)
		size = 1;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		exit(printf("Allocation issue\n"));
	i = 0;
	while (i < size)
	{
		str[i] = a;
		i++;
	}
	str[i] = '\0';
	return (str);
}
