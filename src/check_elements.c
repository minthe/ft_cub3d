/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 08:15:38 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/28 12:32:48 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

static void	write_error_and_exit(t_var *var, char *element)
{
	write(2, "Error\nmissing element: ", 23);
	write(2, element, ft_strlen(element));
	write(2, "\n", 1);
	cleanup(var);
	exit (EXIT_FAILURE);
}

// checks for missing elements
void	check_elements(t_var *var)
{
	if (!var->data->no)
		write_error_and_exit(var, "NO");
	if (!var->data->so)
		write_error_and_exit(var, "SO");
	if (!var->data->we)
		write_error_and_exit(var, "WE");
	if (!var->data->ea)
		write_error_and_exit(var, "EA");
	if (!var->data->f_set)
		write_error_and_exit(var, "F");
	if (!var->data->c_set)
		write_error_and_exit(var, "C");
	if (!var->data->map || var->data->map_lines < 1)
		write_error_and_exit(var, "map");
}
