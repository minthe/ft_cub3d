/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:13:11 by dimbrea           #+#    #+#             */
/*   Updated: 2022/12/13 11:07:42 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

// int ft_is_hit_wall(t_var *var, int height, int width, int x, int y)
// {
// 	int i;
// 	int j;

// 	i = height;
// 	while (i < (height + var->map->modul_h + 1))
// 	{
// 		j = width;
// 		while(j < (width + var->map->modul_w + 1))
// 		{
// 			if (i == y && j == x )
// 				return ();
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }
	

void	ft_write_ray(t_var *var, int x, int y, char	nswe)
{
	int ray;
	
	ray = -1;
	while (++ray < 15)
	{
		if (nswe == 'N')
			y--;
		if (nswe == 'S')
			y++;
		if (nswe == 'W')
			x--;
		if (nswe == 'E')
			x++;
		img_pix_put(var, x, y, 0xFFFFFF);
	}
}

void	ft_ray(t_var *var, char nswe)
{
	int x;
	int y;

	x = var->plr->pos_x;
	y = var->plr->pos_y;
	ft_write_ray(var, x, y, nswe);
}
