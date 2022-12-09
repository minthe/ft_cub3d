/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:28:34 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/08 15:51:16 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	err_elements(t_cub *cub)
{
	if (!cub->c)
		write(2, "missing element: C\n", 19);
	if (!cub->f)
		write(2, "missing element: F\n", 19);
	if (!cub->no)
		write(2, "missing element: NO\n", 20);
	if (!cub->so)
		write(2, "missing element: SO\n", 20);
	if (!cub->we)
		write(2, "missing element: WE\n", 20);
	if (!cub->ea)
		write(2, "missing element: EA\n", 20);
	if (!cub->map)
		write(2, "missing element: map\n", 21);
	exit (1);
}
