#include "../../headers/cub3d.h"

void	error_textures(t_cub *cub, int j)
{
	int	i;
	int	fd;

	if (!cub->textures[NORTH].path || !cub->textures[SOUTH].path
		|| !cub->textures[EAST].path || !cub->textures[WEST].path || j != 4)
	{
		free_all_map(cub);
		exit(printf("Error\nWrong Number of textures\n"));
	}
	i = 0;
	while (i < 4)
	{
		fd = open(cub->textures[i].path, O_RDONLY);
		if (fd < 0)
		{
			free_all_map(cub);
			exit(printf("Error\nInvalid texture path\n"));
		}
		close(fd);
		i++;
	}
}

void	ft_norm_25(char *trim, t_cub *cub, int i)
{
	if (!ft_strncmp(trim, "NO ", 3) && !cub->textures[NORTH].path)
	{
		cub->textures[NORTH].path = ft_strtrim(trim + 3, " \t");
		fre(cub->map_content[i]);
		cub->map_content[i] = ft_strdup("");
	}
	else if (!ft_strncmp(trim, "SO ", 3) && !cub->textures[SOUTH].path)
	{
		cub->textures[SOUTH].path = ft_strtrim(trim + 3, " \t");
		fre(cub->map_content[i]);
		cub->map_content[i] = ft_strdup("");
	}
	else if (!ft_strncmp(trim, "EA ", 3) && !cub->textures[EAST].path)
	{
		cub->textures[EAST].path = ft_strtrim(trim + 3, " \t");
		fre(cub->map_content[i]);
		cub->map_content[i] = ft_strdup("");
	}
	else if (!ft_strncmp(trim, "WE ", 3) && !cub->textures[WEST].path)
	{
		cub->textures[WEST].path = ft_strtrim(trim + 3, " \t");
		fre(cub->map_content[i]);
		cub->map_content[i] = ft_strdup("");
	}
}

void	check_textures(t_cub *cub)
{
	int		i;
	int		j;
	char	*trim;

	i = -1;
	j = 0;
	while (cub->map_content[++i])
	{
		trim = ft_strtrim(cub->map_content[i], " \t\n");
		if (ft_isdigit(trim[0]))
			break ;
		if (!ft_strncmp(trim, "NO ", 3) || !ft_strncmp(trim, "SO ", 3)
			|| !ft_strncmp(trim, "EA ", 3) || !ft_strncmp(trim, "WE ", 3))
			j++;
		ft_norm_25(trim, cub, i);
		fre(trim);
		trim = NULL;
	}
	if (trim)
		fre(trim);
	error_textures(cub, j);
}
