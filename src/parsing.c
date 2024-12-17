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

#include "../headers/cub3d.h"

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

void	open_map(t_cub *cub, char *str)
{
	int		fd;
	char	*content;
	char	*helper;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		printf("File doesn't exist or can't be opened for reading.\n");
		exit(1);
	}
	content = NULL;
	while (1)
	{
		helper = get_next_line(fd);
		if (!helper)
			break ;
		content = ft_strjoin2(content, helper);
		free(helper);
	}
	if (!content || *content == '\0')
		exit(printf("Error\nThe map is empty\n"));
	cub->map = ft_split(content, '\n');
	free(content);
}

void	ft_parsing(t_cub *cub, int ac, char **av)
{
	if (ac != 2)
	{
		printf("ERROR\nEnter just one argument\n");
		exit(1);
	}
	is_extension(av[1]);
	open_map(cub, av[1]);
	parse_map(cub);
}
