/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:57:49 by fbazaz            #+#    #+#             */
/*   Updated: 2025/01/13 12:50:02 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d_bonus.h"

int	check_char(char c)
{
	if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'E' && c != 'W'
		&& c != ' ')
		return (0);
	return (1);
}

int	check_other_char(char **map)
{
	int	i;
	int	x;

	x = -1;
	while (map[++x])
	{
		i = -1;
		while (map[x][++i])
		{
			if (!check_char(map[x][i]) && map[x][i] != '\n')
				return (1);
		}
	}
	return (0);
}

void	check_side_borders(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map_content[i])
	{
		if ((cub->map_content[i][0] != '1' && cub->map_content[i][0] != ' ')
			|| (cub->map_content[i][ft_strlen(cub->map_content[i]) - 1] != '1'
				&& cub->map_content[i][ft_strlen(cub->map_content[i])
				- 1] != ' '))
		{
			free_all_map(cub);
			printf("Error\n");
			printf("The map isn't closed by walls (side border)\n");
			exit(1);
		}
		i++;
	}
}

void	check_top_buttom_borders(t_cub *cub)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (cub->map_content[i][++j])
	{
		if (cub->map_content[i][j] != '1' && cub->map_content[i][j] != ' ')
		{
			free_all_map(cub);
			exit(printf("Error\nMap isn't closed by walls (T)\n"));
		}
	}
	while (cub->map_content[++i])
		;
	j = -1;
	while (cub->map_content[i - 1][++j])
	{
		if (cub->map_content[i - 1][j] != '1' && cub->map_content[i
			- 1][j] != ' ')
		{
			free_all_map(cub);
			exit(printf("Error\nMap isn't closed by walls (B)\n"));
		}
	}
}

void	is_valid_map(t_cub *cub)
{
	check_top_buttom_borders(cub);
	check_side_borders(cub);
	switch_spaces(cub);
	check_player_position(cub);
	adjust_length(cub);
	check_player_spaces_position(cub);
}
