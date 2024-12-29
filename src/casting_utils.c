# include "../headers/cub3d.h"

void    normalizing(float *rayAngle)
{
    *rayAngle = fmod(*rayAngle, 2 * PI);
    if (*rayAngle < 0)
        *rayAngle += 2 * PI;
} 