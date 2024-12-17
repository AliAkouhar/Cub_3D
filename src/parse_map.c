/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:47:59 by fbazaz            #+#    #+#             */
/*   Updated: 2024/09/10 14:29:39 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

char	*parse_texture(char *line)
{
	int	fd;

	fd = open(line, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nInvalid texture path\n");
		exit(1);
	}
	close(fd);
	return (line);
}

void	ft_norm(char *line, t_cub *cub)
{
	if (!ft_strncmp(line, "EA ", 3))
	{
		if (cub->ea_texture)
			exit(printf("Error\nDuplicate identifier EA\n"));
		cub->ea_texture = ft_strdup(parse_texture(line + 3));
	}
	else if (line[0] == 'F')
		parse_color(line + 2, &cub->floor_color);
	else if (line[0] == 'C')
		parse_color(line + 2, &cub->ceiling_color);
	else
	{
		printf("Error\nInvalid identifier in the configuration file\n");
		exit(1);
	}
}

void	parse_line(char *line, t_cub *cub)
{
	if (!ft_strncmp(line, "NO ", 3))
	{
		if (cub->no_texture)
			exit(printf("Error\nDuplicate identifier NO\n"));
		cub->no_texture = ft_strdup(parse_texture(line + 3));
	}
	else if (!ft_strncmp(line, "SO ", 3))
	{
		if (cub->so_texture)
			exit(printf("Error\nDuplicate identifier SO\n"));
		cub->so_texture = ft_strdup(parse_texture(line + 3));
	}
	else if (!ft_strncmp(line, "WE ", 3))
	{
		if (cub->we_texture)
			exit(printf("Error\nDuplicate identifier WE\n"));
		cub->we_texture = ft_strdup(parse_texture(line + 3));
	}
	else
		ft_norm(line, cub);
}

void	check_player_position(t_cub *cub, int x)
{
	int	i;
	int	j;
	int	pos_count;

	i = x--;
	pos_count = 0;
	while (cub->map[++i])
	{
		j = -1;
		while (cub->map[i][++j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S'
				|| cub->map[i][j] == 'E' || cub->map[i][j] == 'W')
			{
				pos_count++;
				cub->player_x = j;
				cub->player_y = i;
			}
		}
	}
	if (!pos_count)
		exit(printf("Error\nNo player spawn point found (N, E, W, S)\n"));
	if (pos_count > 1)
		exit(printf("Error\nMultiple player spawn points found\n"));
}

void	parse_map(t_cub *cub)
{
	int	i;

	i = -1;
	while (ft_isalpha(cub->map[++i][0]))
		parse_line(cub->map[i], cub);
	if (!cub->no_texture || !cub->ea_texture || !cub->so_texture
		|| !cub->we_texture || check_color(cub))
	{
		printf("Error\nMissing identifier in the configuration file\n");
		exit(1);
	}
	is_valid_map(cub, i);
}
