/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:45:08 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/11 19:36:22 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// checks if string has digits
int	hasdigits(const char *str)
{
	int	check;

	check = 0;
	while (*str)
	{
		if (*str >= 48 && *str <= 57)
			check = 1;
		str++;
	}
	if (check == 0)
	{
		write(2, "Error\ninvalid color characters\n", 31);
		exit (EXIT_FAILURE);
	}
	return (check);
}

// returns 1 if all textures are ok
// returns 2 if additionally all colors are set
// returns 3 if all parameters from cub are set
int	check_cub(t_data *cub)
{
	if (cub->no && cub->so && cub->we && cub->ea \
	&& !cub->f_set && !cub->c_set && !cub->map)
		return (1);
	if (cub->no && cub->so && cub->we && cub->ea \
		&& cub->f_set && cub->c_set && !cub->map)
		return (2);
	if (cub->no && cub->so && cub->we && cub->ea \
		&& cub->f_set && cub->c_set && cub->map && cub->p_set)
		return (3);
	return (0);
}
