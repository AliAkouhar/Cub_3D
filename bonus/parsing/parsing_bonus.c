/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:44:29 by fbazaz            #+#    #+#             */
/*   Updated: 2025/01/17 16:24:03 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d_bonus.h"

void	is_extension(char *str, t_cub *cub)
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
	{
		free_all_map(cub);
		exit(printf("Error\nYour filename should end by <.cub>\n"));
	}
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
		free_to_exit(cub);
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

void	ft_parsing(t_cub *cub, char **av)
{
	is_extension(av[1], cub);
	get_map(cub, av[1]);
	check_textures(cub);
	check_colors(cub);
	adjust_map(cub);
	check_map(cub);
	cub->height = array_size(cub->map_content);
	cub->width = ft_strlen(cub->map_content[0]);
	cub->tile_map = 64;
	cub->player.tile = cub->tile_map / 3;
	cub->player.point.x = (cub->player.point.x * cub->tile_map) + (cub->tile_map
			/ 2);
	cub->player.point.y = (cub->player.point.y * cub->tile_map) + (cub->tile_map
			/ 2);
}
