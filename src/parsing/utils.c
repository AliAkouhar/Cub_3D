/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:23:56 by fbazaz            #+#    #+#             */
/*   Updated: 2024/09/09 18:28:40 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

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
	// if (cub->content)
	// 	fre(cub->content);
	if (cub->map_content)
		free_2d(cub->map_content);
	if (cub->textures_path[NORTH])
		fre(cub->textures_path[NORTH]);
	if (cub->textures_path[SOUTH])
		fre(cub->textures_path[SOUTH]);
	if (cub->textures_path[EAST])
		fre(cub->textures_path[EAST]);
	if (cub->textures_path[WEST])
		fre(cub->textures_path[WEST]);
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
