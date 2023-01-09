/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:45:08 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/09 15:54:32 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
