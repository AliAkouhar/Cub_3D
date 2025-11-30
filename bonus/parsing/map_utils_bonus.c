/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:04:39 by fbazaz            #+#    #+#             */
/*   Updated: 2025/01/13 13:04:40 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d_bonus.h"

int	size_map(char **map)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (check_char(map[i][j]) && !flag)
			{
				flag = 1;
				break ;
			}
		}
		if (flag)
			break ;
	}
	return (array_size(map) - i + 1);
}

void	refill_map(char **map2, t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (cub->map_content[++i])
	{
		if (check_char(cub->map_content[i][0]))
		{
			while (cub->map_content[i])
			{
				map2[++j] = ft_strdup(cub->map_content[i]);
				i++;
			}
			break ;
		}
	}
	map2[++j] = NULL;
}

void	switch_spaces(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub->map_content[++i])
	{
		j = -1;
		while (cub->map_content[i][++j])
		{
			if (cub->map_content[i][j] == ' ')
				cub->map_content[i][j] = 'a';
		}
	}
}

void	adjust_map(t_cub *cub)
{
	char	**map2;

	map2 = malloc(sizeof(char *) * size_map(cub->map_content));
	if (!map2)
	{
		free_all_map(cub);
		exit(printf("Error\nAllocation issue\n"));
	}
	if (check_other_char(cub->map_content))
	{
		printf("Error\nInvalid char in the configuration file\n");
		free(map2);
		free_all_map(cub);
		exit(1);
	}
	refill_map(map2, cub);
	free_2d(cub->map_content);
	cub->map_content = map2;
}

void	adjust_length(t_cub *cub)
{
	int		i;
	int		max;
	char	*tmp;
	char	*new_str;

	i = -1;
	max = 0;
	new_str = NULL;
	while (cub->map_content[++i])
		if (max < (int)ft_strlen(cub->map_content[i]))
			max = ft_strlen(cub->map_content[i]);
	i = -1;
	while (cub->map_content[++i])
	{
		if ((int)ft_strlen(cub->map_content[i]) < max)
		{
			tmp = cub->map_content[i];
			new_str = new_string('a', max - ft_strlen(cub->map_content[i]));
			cub->map_content[i] = ft_strjoin(cub->map_content[i], new_str);
			fre(tmp);
			fre(new_str);
		}
	}
}
