/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:04:30 by fbazaz            #+#    #+#             */
/*   Updated: 2025/01/17 17:33:53 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d_bonus.h"

void	assign_color(t_cub *cub, char **split, char c)
{
	if (c == 'F')
	{
		cub->floor_color.r = ft_atoi(split[0]);
		cub->floor_color.g = ft_atoi(split[1]);
		cub->floor_color.b = ft_atoi(split[2]);
	}
	else if (c == 'C')
	{
		cub->ceiling_color.r = ft_atoi(split[0]);
		cub->ceiling_color.g = ft_atoi(split[1]);
		cub->ceiling_color.b = ft_atoi(split[2]);
	}
}

void	ft_norm_25_2(char *trim, t_cub *cub, int i, int *j)
{
	if (!ft_strncmp(trim, "F ", 2) && cub->floor_color.r == -1)
	{
		cub->c = 'F';
		check_rgb(j, trim + 2, cub, trim);
		fre(cub->map_content[i]);
		cub->map_content[i] = ft_strdup("");
	}
	if (!ft_strncmp(trim, "C ", 2) && cub->ceiling_color.r == -1)
	{
		cub->c = 'C';
		check_rgb(j, trim + 2, cub, trim);
		fre(cub->map_content[i]);
		cub->map_content[i] = ft_strdup("");
	}
}

void	check_door_borders(t_cub *cub, int i, int j)
{
	if ((cub->map_content[i][j + 1] != '1' || cub->map_content[i][j - 1] != '1')
		&& (cub->map_content[i - 1][j] != '1' || cub->map_content[i
			+ 1][j] != '1'))
	{
		free_all_map(cub);
		printf("Error\nInvalid door position\n");
		exit(1);
	}
}

void	check_player_norm(t_cub *cub, int i, int j)
{
	if (cub->map_content[i][j] == 'D')
		check_door_borders(cub, i, j);
	if (cub->map_content[i][j] == '0' || cub->map_content[i][j] == 'N'
		|| cub->map_content[i][j] == 'S' || cub->map_content[i][j] == 'E'
		|| cub->map_content[i][j] == 'W')
	{
		if (cub->map_content[i][j + 1] == 'a' || cub->map_content[i][j
			- 1] == 'a' || cub->map_content[i + 1][j] == 'a'
			|| cub->map_content[i - 1][j] == 'a')
		{
			free_all_map(cub);
			exit(printf("Error\nPlayer position\n"));
		}
	}
}

void	check_player_spaces_position(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub->map_content[++i])
	{
		j = -1;
		while (cub->map_content[i][++j])
			check_player_norm(cub, i, j);
	}
}
