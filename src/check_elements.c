/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:15:38 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/09 08:18:09 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_elements(t_data *data)
{
	if (!data->no)
		data->err = 1;
	else if (access(data->no, R_OK) != 0)
		data->err = 8;
	if (!data->so)
		data->err = 2;
	else if (access(data->so, R_OK) != 0)
		data->err = 9;
	if (!data->we)
		data->err = 3;
	else if (access(data->we, R_OK) != 0)
		data->err = 10;
	if (!data->ea)
		data->err = 4;
	else if (access(data->ea, R_OK) != 0)
		data->err = 11;
	if (!data->f_set)
		data->err = 5;
	if (!data->c_set)
		data->err = 6;
	if (!data->map)
		data->err = 7;
}
