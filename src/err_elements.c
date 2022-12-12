/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:28:34 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/12 20:56:36 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	err_elements2(t_data *data)
{
	if (!data->ea)
		data->err = write(2, "missing element: EA\n", 20);
	else if (access(data->ea, R_OK) != 0)
	{
		data->err = write(2, "EA -> ", 6);
		perror(data->ea);
	}
	if (!data->f)
		data->err = write(2, "missing element: F\n", 19);
	if (!data->c)
		data->err = write(2, "missing element: C\n", 19);
	if (!data->map)
		data->err = write(2, "missing element: map\n", 21);
}

void	err_elements(t_data *data)
{
	if (!data->no)
		data->err = write(2, "missing element: NO\n", 20);
	else if (access(data->no, R_OK) != 0)
	{
		data->err = write(2, "NO -> ", 6);
		perror(data->no);
	}
	if (!data->so)
		data->err = write(2, "missing element: SO\n", 20);
	else if (access(data->so, R_OK) != 0)
	{
		data->err = write(2, "SO -> ", 6);
		perror(data->so);
	}
	if (!data->we)
		data->err = write(2, "missing element: WE\n", 20);
	else if (access(data->we, R_OK) != 0)
	{
		data->err = write(2, "WE -> ", 6);
		perror(data->we);
	}
	err_elements2(data);
}
