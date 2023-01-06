/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:28:34 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/06 17:25:50 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*
Error Codes
missing element:
	1 NO
	2 SO
	3 WE
	4 EA
	5 F
	6 C
	7 map
no access:
	8 NO
	9 SO
	10 WE
	11 EA
map:
	12 invalid line after map
	
*/

void	err_map(t_data *data)
{
	if (data->err_map == 12)
		write(2, "map error: empty lines\n", 23);
	
}

static void	err_elements3(t_data *data)
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

static void	err_elements2(t_data *data)
{
	if (!data->we)
	{
		data->err = 3;
		write(2, "missing element: WE\n", 20);
	}
	else if (access(data->we, R_OK) != 0)
	{
		data->err = 10;
		write(2, "WE -> ", 6);
		perror(data->we);
	}
	if (!data->ea)
	{
		data->err = 4;
		write(2, "missing element: EA\n", 20);
	}
	else if (access(data->ea, R_OK) != 0)
	{
		data->err = 11;
		write(2, "EA -> ", 6);
		perror(data->ea);
	}
	err_elements3(data);
}

void	err_elements(t_data *data)
{
	if (!data->no)
	{
		data->err = 1;
		write(2, "missing element: NO\n", 20);
	}
	else if (access(data->no, R_OK) != 0)
	{
		data->err = 8;
		write(2, "NO -> ", 6);
		perror(data->no);
	}
	if (!data->so)
	{
		data->err = 2;
		write(2, "missing element: SO\n", 20);
	}
	else if (access(data->so, R_OK) != 0)
	{
		data->err = 9;
		write(2, "SO -> ", 6);
		perror(data->so);
	}
	err_elements2(data);
}
