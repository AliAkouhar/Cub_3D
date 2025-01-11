/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:44:29 by fbazaz            #+#    #+#             */
/*   Updated: 2025/01/06 08:41:36 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	is_extension(char *str)
{
	char	*s;
	int		fd;

	fd = open(str, O_DIRECTORY);
	if (fd != -1)
	{
		close(fd);
		exit(printf("Error\nThe PATH is a directory\n"));
	}
	s = ft_strchr(str, '.');
	if (!s || ft_strcmp(s, ".cub"))
		exit(printf("Error\nYour filename should end by <.cub>\n"));
}

int	ft_get_size(char *str)
{
	int		fd;
	int		i;
	char	*helper;

	i = 0;
	fd = open(str, O_RDONLY);
	helper = get_next_line(fd);
	while (helper)
	{
		fre(helper);
		helper = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

int	empty_file(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_all_whitespaces(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	get_map(t_cub *cub, char *str)
{
	int		fd;
	int		i;
	char	*helper;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		exit(printf("Error\nConnot open the Map for\n"));
	cub->map_content = malloc(sizeof(char *) * (ft_get_size(str) + 1));
	if (!cub->map_content)
		exit(printf("Error\nAllocation issue\n"));
	helper = get_next_line(fd);
	while (helper)
	{
		cub->map_content[i++] = ft_strdup(helper);
		fre(helper);
		helper = get_next_line(fd);
	}
	cub->map_content[i] = NULL;
	close(fd);
	if (!cub->map_content || empty_file(cub->map_content))
	{
		free_all_map(cub);
		exit(printf("Error\nThe file is empty\n"));
	}
}

void	ft_parsing(t_cub *cub, int ac, char **av)
{
	if (ac != 2)
		exit(printf("USAGE ERROR:\n./cub3D <map>.cub\n"));
	is_extension(av[1]); // done
	get_map(cub, av[1]); // done
	check_textures(cub); // done
	check_colors(cub);   // done
	adjust_map(cub);
	check_map(cub);
	cub->height = array_size(cub->map_content);
	cub->width = ft_strlen(cub->map_content[0]);
	cub->tile_map = 64;
	cub->player.tile = cub->tile_map / 3;
}
