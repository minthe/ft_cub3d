/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_cub.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:28:34 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/08 21:50:52 by vfuhlenb         ###   ########.fr       */
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
	13 map not last element
color:
	20 invalid characters
	21 too few color values
	22 too many color values
*/

void	err_color(t_data *data)
{
	if (data->err_color == 20)
		write(2, "Error\ncolor error: illegal characters\n", 38);
	else if (data->err_color == 21)
		write(2, "Error\ncolor error: less than 3 values\n", 38);
	else if (data->err_color == 22)
		write(2, "Error\ncolor error: more than 3 values\n", 38);
}

void	err_map(t_data *data)
{
	if (data->err_map == 12)
		write(2, "Error\nmap error: empty lines\n", 29);
	if (data->err_map == 13)
		write(2, "Error\nmap error: not last element\n", 34);
}

static void	err_elements3(t_data *data)
{
	if (!data->f_set)
	{
		data->err = 5;
		write(2, "Error\nmissing element: F\n", 25);
	}
	if (!data->c_set)
	{
		data->err = 6;
		write(2, "Error\nmissing element: C\n", 25);
	}
	if (!data->map)
	{
		data->err = 7;
		write(2, "Error\nmissing element: map\n", 27);
	}
}

static void	err_elements2(t_data *data)
{
	if (!data->we)
	{
		data->err = 3;
		write(2, "Error\nmissing element: WE\n", 26);
	}
	else if (access(data->we, R_OK) != 0)
	{
		data->err = 10;
		write(2, "Error\nWE -> ", 12);
		perror(data->we);
	}
	if (!data->ea)
	{
		data->err = 4;
		write(2, "Error\nmissing element: EA\n", 26);
	}
	else if (access(data->ea, R_OK) != 0)
	{
		data->err = 11;
		write(2, "Error\nEA -> ", 12);
		perror(data->ea);
	}
	err_elements3(data);
}

void	err_elements(t_data *data)
{
	if (!data->no)
	{
		data->err = 1;
		write(2, "Error\nmissing element: NO\n", 26);
	}
	else if (access(data->no, R_OK) != 0)
	{
		data->err = 8;
		write(2, "Error\nNO -> ", 12);
		perror(data->no);
	}
	if (!data->so)
	{
		data->err = 2;
		write(2, "Error\nmissing element: SO\n", 26);
	}
	else if (access(data->so, R_OK) != 0)
	{
		data->err = 9;
		write(2, "Error\nSO -> ", 12);
		perror(data->so);
	}
	err_elements2(data);
}
