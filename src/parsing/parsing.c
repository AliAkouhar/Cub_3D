/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:44:29 by fbazaz            #+#    #+#             */
/*   Updated: 2024/09/10 14:22:03 by fbazaz           ###   ########.fr       */
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
		printf("Error\nThe PATH is a directory\n");
		exit(1);
	}
	s = ft_strchr(str, '.');
	if (!s || ft_strcmp(s, ".cub"))
	{
		printf("Error\nYour filename should end by <.cub>\n");
		exit(1);
	}
}

int	ft_get_size(char *str)
{
	int fd;
	int	i;
	char *helper;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		exit(printf("Error\nConnot open the Map\n"));
	helper = get_next_line(fd);
	while (helper)
	{
		free(helper);
		helper = get_next_line(fd);
		i++;
	}
	close(fd);
	return (i);
}

void	get_map(t_cub *cub, char *str)
{
	int fd;
	int	i;
	char *helper;

	cub->map_content = malloc(sizeof(char *) * (ft_get_size(str) + 1));
	if (!cub->map_content)
		exit(printf("Error\nAllocation issue\n"));
	i = 0;
	fd = open(str, O_RDONLY);
	helper = get_next_line(fd);
	while (helper)
	{
		cub->map_content[i++] = ft_strdup(helper);
		free(helper);
		helper = get_next_line(fd);
	}
	cub->map_content[i] = NULL;
	close(fd);
	if (!cub->map_content)
		exit(printf("Error\nThe file is empty\n"));
}

void	ft_parsing(t_cub *cub, int ac, char **av)
{
	if (ac != 2)
	{
		printf("ERROR\nEnter one argument\n");
		exit(1);
	}
	is_extension(av[1]);
	get_map(cub, av[1]);
	check_textures(cub);
	check_colors(cub);
	check_map(cub);
}
