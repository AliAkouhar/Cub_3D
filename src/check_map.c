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

#include "../headers/cub3d.h"

int	check_char(char c)
{
	if (c != '1' && c != '0' && c != 'N' && c != 'S' && c != 'E' && c != 'W'
		&& c != ' ')
		return (0);
	return (1);
}

void	check_other_char(char **map, int x)
{
	int	i;

	x--;
	while (map[++x])
	{
		i = -1;
		while (map[x][++i])
		{
			if (!check_char(map[x][i]))
			{
				printf("Error\n");
				printf("Invalid char \"%c\" in the configuration file\n",
					map[x][i]);
				exit(1);
			}
		}
	}
}

void	check_side_borders(t_cub *cub, int x)
{
	int	i;

	i = x;
	while (cub->map[i])
	{
		if (cub->map[i][0] != '1' || cub->map[i][ft_strlen(cub->map[i])
			- 1] != '1')
		{
			printf("Error\n");
			printf("The map isn't closed by walls (side border)\n");
			exit(1);
		}
		i++;
	}
}

void	is_valid_map(t_cub *cub, int x)
{
	int		i;
	int		j;
	char	*tmp;

	i = x - 1;
	check_other_char(cub->map, x);
	while (cub->map[++i])
	{
		tmp = cub->map[i];
		cub->map[i] = ft_strtrim(cub->map[i], " \t");
		free(tmp);
	}
	j = -1;
	while (cub->map[x][++j])
		if (cub->map[x][j] != '1')
			exit(printf("Error\nMap isn't closed by walls (T)\n"));
	i = x - 1;
	while (cub->map[++i])
		;
	j = -1;
	while (cub->map[i - 1][++j])
		if (cub->map[i - 1][j] != '1' && cub->map[i - 1][j] != ' ')
			exit(printf("Error\nMap isn't closed by walls (B)\n"));
	check_side_borders(cub, x);
	check_player_position(cub, x);
}
