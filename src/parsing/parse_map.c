/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:47:59 by fbazaz            #+#    #+#             */
/*   Updated: 2024/12/27 11:09:19 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int is_all_whitespaces(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
            return (0);
        i++;
    }
    return (1);
}

void    fill_map(t_cub *cub)
{
    int     i;
    char    *tmp;

    i = -1;
    while (cub->map_content[++i])
        cub->content = ft_strjoin2(cub->content, cub->map_content[i]);
    free_2d(cub->map_content);
    cub->map_content = NULL;
    tmp = cub->content;
    cub->content = ft_strtrim(cub->content, "\t\n");
    fre(tmp);
    if (!cub->content || cub->content[0] == '\0' || is_all_whitespaces(cub->content))
    {
        fre(cub->content);
        free_all_map(cub);
        exit(printf("Error\nEmpty map\n"));
    }
    if (!check_char(cub->content[0]) || (!check_char(cub->content[ft_strlen(cub->content) - 1]) && cub->content[ft_strlen(cub->content) - 1] != '\n'))
    {
        fre(cub->content);
        free_all_map(cub);
        exit(printf("Error\nInvalid configuration\n"));
    }
}

void	check_empty_line(t_cub *cub, char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
            fre(str);
            free_all_map(cub);
			exit(printf("Error\nFound an empty line inside the map\n"));
		}
	cub->map_content = ft_split(str, '\n');
	fre(str);
}

void	check_player_position(t_cub *cub)
{
	int	i;
	int	j;
	int	pos_count;

	i = -1;
	pos_count = 0;
	while (cub->map_content[++i])
	{
		j = -1;
		while (cub->map_content[i][++j])
		{
			if (cub->map_content[i][j] == 'N' || cub->map_content[i][j] == 'S'
				|| cub->map_content[i][j] == 'E' || cub->map_content[i][j] == 'W')
			{
				pos_count++;
				cub->player.player_x = j;
				cub->player.player_y = i;
			}
		}
	}
	if (pos_count != 1)
    {
        free_all_map(cub);
        exit(printf("Error\nInvalid number of player position\n"));
    }
}

void	check_map(t_cub*cub)
{
    fill_map(cub); //done
    check_empty_line(cub, cub->content); //done
    is_valid_map(cub);
}
