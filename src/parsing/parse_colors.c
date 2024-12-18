# include "../../headers/cub3d.h"

int check_digit(char **str)
{
    int i;
    int j;

    i = 0;
    while (str[i])
    {
        if (ft_atoi(str[i]) < 0 || ft_atoi(str[i]) > 255)
        return (-1);
        j = 0;
        while (str[i][j])
        {
            if (!ft_isdigit(str[i][j]) && str[i][j] != ' ' && (str[i][j] > 13 || str[i][j] < 9))
                return (-1);
            j++;
        }
        i++;
    }
    if (i != 3)
        return (-1);
    return (0);
}

void    check_rgb(int *j, char *str, t_cub *cub, char c)
{
    char    **split;
    char    *trim;

    trim = ft_strtrim(str, " \t");
    split = ft_split(trim, ',');
    free(trim);
    if (!split || check_digit(split) == -1)
    {
        //free dakchi
        exit(printf("Error\nInvalid color format\n"));
    }
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
    (*j)++;
    free_2d(split);
}

void    check_color_num(int j, t_cub *cub)
{
    (void)cub;
    if (j != 2)
    {
        //free the map and textures
        exit(printf("Error\nWrong number of color\n"));
    }
}

void    check_colors(t_cub *cub)
{
    char    *trim;
    int     i;
    int     j;

    i = -1;
    j = 0;
    while (cub->map_content[++i])
    {
        trim = ft_strtrim(cub->map_content[i], " \t\n");
        if (ft_isdigit(trim[0]))
            break;
        if (!ft_strncmp(trim, "F ", 2))
        {
            check_rgb(&j, trim + 2, cub, 'F');
            free(cub->map_content[i]);
            cub->map_content[i] = ft_strdup("");
        }
        if (!ft_strncmp(trim, "C ", 2))
        {
            check_rgb(&j, trim + 2, cub, 'C');
            free(cub->map_content[i]);
            cub->map_content[i] = ft_strdup("");
        }
        free(trim);
    }
    check_color_num(j, cub);
}
