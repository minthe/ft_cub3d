/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:28:34 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/11 18:08:34 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	err_elements2(t_data *data)
{
	if (!data->f_set)
	{
		data->err = 5;
		write(2, "missing element: F\n", 19);
	}
	if (!data->c_set)
	{
		data->err = 6;
		write(2, "missing element: C\n", 19);
	}
	if (!data->map)
	{
		data->err = 7;
		write(2, "missing element: map\n", 21);
	}
}

void	err_elements(t_data *data)
{
	write(2, "Error\n", 6);
	if (!data->no)
	{
		data->err = 1;
		write(2, "missing element: NO\n", 20);
	}
	if (!data->so)
	{
		data->err = 2;
		write(2, "missing element: SO\n", 20);
	}
	if (!data->we)
	{
		data->err = 3;
		write(2, "missing element: WE\n", 20);
	}
	if (!data->ea)
	{
		data->err = 4;
		write(2, "missing element: EA\n", 20);
	}
	err_elements2(data);
}
