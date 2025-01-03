# include "../../headers/cub3d.h"

void    assign_color(t_cub *cub, char **split, char c)
{
    if (c == 'F')
    {
        cub->floor_color.r = ft_atoi(split[0]);
        cub->floor_color.g = ft_atoi(split[1]);
        cub->floor_color.b = ft_atoi(split[2]);
    }
    else if (c == 'C')
    {
        cub->ceiling_color.r = ft_atoi(split[0]);
        cub->ceiling_color.g = ft_atoi(split[1]);
        cub->ceiling_color.b = ft_atoi(split[2]);
    }
}

void    ft_norm_25_2(char *trim, t_cub *cub, int i, int *j)
{
    if (!ft_strncmp(trim, "F ", 2) && cub->floor_color.r == -1)
    {
        check_rgb(j, trim + 2, cub, 'F', trim);
        fre(cub->map_content[i]);
        cub->map_content[i] = ft_strdup("");
    }
    if (!ft_strncmp(trim, "C ", 2) && cub->ceiling_color.r == -1)
    {
        check_rgb(j, trim + 2, cub, 'C', trim);
        fre(cub->map_content[i]);
        cub->map_content[i] = ft_strdup("");
    }
}
