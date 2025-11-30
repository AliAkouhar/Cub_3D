/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbazaz <fbazaz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:50:51 by fbazaz            #+#    #+#             */
/*   Updated: 2025/01/17 17:50:52 by fbazaz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d_bonus.h"

void	init_weapon_textures(t_cub *cub)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (i < WEAPON_FRAME_NUMBER)
	{
		cub->weapon[i].img = NULL;
		cub->weapon[i].path = NULL;
		if (i <= 9)
			cub->weapon[i].path = ft_strdup("./textures/weapon/weapon_0");
		else
			cub->weapon[i].path = ft_strdup("./textures/weapon/weapon_");
		tmp = ft_itoa(i);
		cub->weapon[i].path = ft_strjoin2(cub->weapon[i].path, tmp);
		fre(tmp);
		cub->weapon[i].path = ft_strjoin2(cub->weapon[i].path, ".xpm");
		i++;
	}
}

void	init_door_textures(t_cub *cub)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (i < DOOR_FRAME_NUMBER)
	{
		cub->doors[i].img = NULL;
		cub->doors[i].img = NULL;
		if (i <= 9)
			cub->doors[i].path = ft_strdup("./textures/doors/door_0");
		else
			cub->doors[i].path = ft_strdup("./textures/doors/door_");
		tmp = ft_itoa(i);
		cub->doors[i].path = ft_strjoin2(cub->doors[i].path, tmp);
		fre(tmp);
		cub->doors[i].path = ft_strjoin2(cub->doors[i].path, ".xpm");
		i++;
	}
	cub->is_door_open = 0;
	cub->door_frame = 0;
}

void	free_textures(t_cub *cub)
{
	int	i;

	i = 0;
	if (cub->zoom.img)
		mlx_destroy_image(cub->mlx, cub->zoom.img);
	while (i < WEAPON_FRAME_NUMBER)
	{
		if (cub->weapon[i].img)
			mlx_destroy_image(cub->mlx, cub->weapon[i].img);
		if (cub->weapon[i].path)
			fre(cub->weapon[i].path);
		i++;
	}
	i = 0;
	while (i < DOOR_FRAME_NUMBER)
	{
		if (cub->doors[i].img)
			mlx_destroy_image(cub->mlx, cub->doors[i].img);
		if (cub->doors[i].path)
			fre(cub->doors[i].path);
		i++;
	}
}
