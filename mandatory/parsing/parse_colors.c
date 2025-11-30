/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_colors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:04:43 by fbazaz            #+#    #+#             */
/*   Updated: 2025/01/17 17:31:03 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	check_digit(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (ft_atoi(str[i]) < 0 || ft_atoi(str[i]) > 255)
			return (-1);
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) && str[i][j] != ' ' && (str[i][j] > 13
					|| str[i][j] < 9))
				return (-1);
			j++;
		}
		i++;
	}
	if (i != 3)
		return (-1);
	return (0);
}

void	check_rgb(int *j, char *str, t_cub *cub, char *to_free)
{
	char	**split;
	char	*trim;

	split = NULL;
	trim = ft_strtrim(str, " \t");
	split = ft_split(trim, ',');
	if (!split || check_digit(split) == -1 || trim[0] == ','
		|| trim[ft_strlen(trim) - 1] == ',')
	{
		fre(trim);
		free_2d(split);
		free_all_map(cub);
		fre(to_free);
		exit(printf("Error\nInvalid color format\n"));
	}
	fre(trim);
	assign_color(cub, split, cub->c);
	(*j)++;
	free_2d(split);
}

void	check_color_num(int j, t_cub *cub)
{
	if (j != 2)
	{
		free_all_map(cub);
		exit(printf("Error\nWrong number of color\n"));
	}
}

void	check_colors(t_cub *cub)
{
	char	*trim;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (cub->map_content[++i])
	{
		trim = ft_strtrim(cub->map_content[i], " \t\n");
		if (ft_isdigit(trim[0]))
			break ;
		ft_norm_25_2(trim, cub, i, &j);
		fre(trim);
		trim = NULL;
	}
	if (trim)
		fre(trim);
	check_color_num(j, cub);
}
