/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:57:49 by fbazaz            #+#    #+#             */
/*   Updated: 2024/09/10 14:29:48 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	check_char(char c)
{
	if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'E' && c != 'W'
		&& c != ' ')
		return (0);
	return (1);
}

void	check_other_char(char **map)
{
	int	i;
	int x;

	x = -1;
	while (map[++x])
	{
		i = -1;
		while (map[x][++i])
		{
			if (!check_char(map[x][i]))
			{
				// free dakchi
				printf("Error\nInvalid char \"%c\" in the configuration file\n",
					map[x][i]);
				exit(1);
			}
		}
	}
}

void	check_side_borders(t_cub *cub)
{
	int	i;

	i = 0;
	while (cub->map_content[i])
	{
		if (cub->map_content[i][0] != '1' || cub->map_content[i][ft_strlen(cub->map_content[i])
			- 1] != '1')
		{
			printf("Error\n");
			printf("The map isn't closed by walls (side border)\n");
			exit(1);
		}
		i++;
	}
}

void	is_valid_map(t_cub *cub)
{
	int		i;
	int		j;
	char	*tmp;

	i = -1;
	check_other_char(cub->map_content);
	while (cub->map_content[++i])
	{
		tmp = cub->map_content[i];
		cub->map_content[i] = ft_strtrim(cub->map_content[i], " \t");
		free(tmp);
	}
	j = -1;
	i = 0;
	while (cub->map_content[i][++j])
		if (cub->map_content[i][j] != '1')
			exit(printf("Error\nMap isn't closed by walls (T)\n"));
	while (cub->map_content[++i])
		;
	j = -1;
	while (cub->map_content[i - 1][++j])
		if (cub->map_content[i - 1][j] != '1' && cub->map_content[i - 1][j] != ' ')
			exit(printf("Error\nMap isn't closed by walls (B)\n"));
	check_side_borders(cub);
	check_player_position(cub);
}
