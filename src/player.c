# include "../headers/cub3d.h"

void    check_player_spaces_position(t_cub *cub)
{
    int i;
    int j;

    i = -1;
    while (cub->map_content[++i])
    {
        j = -1;
        while (cub->map_content[i][++j])
            if (cub->map_content[i][j] == '0' || cub->map_content[i][j] == 'N' || cub->map_content[i][j] == 'S' || cub->map_content[i][j] == 'E' || cub->map_content[i][j] == 'W')
            {
                if (cub->map_content[i][j + 1] == 'a' || cub->map_content[i][j - 1] == 'a' ||
                    cub->map_content[i + 1][j] == 'a' || cub->map_content[i - 1][j] == 'a')
                    {
                        printf("Error\nPlayer position %i-- %s\n", i + 1, cub->map_content[i]);
                        free_all_map(cub);
                        exit(1);
                    }
            }
    }
}
