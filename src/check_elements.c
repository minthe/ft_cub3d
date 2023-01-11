/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:15:38 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/11 21:40:18 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	write_error_and_exit(char *element)
{
	write(2, "Error\nmissing element: ", 23);
	write(2, element, ft_strlen(element));
	write(2, "\n", 1);
	exit (EXIT_FAILURE);
}

// checks for missing elements
void	check_elements(t_data *data)
{
	if (!data->no)
		write_error_and_exit("NO");
	if (!data->so)
		write_error_and_exit("SO");
	if (!data->we)
		write_error_and_exit("WE");
	if (!data->ea)
		write_error_and_exit("EA");
	if (!data->f_set)
		write_error_and_exit("F");
	if (!data->c_set)
		write_error_and_exit("C");
	if (!data->map || data->map_lines < 1)
		write_error_and_exit("map");
}
