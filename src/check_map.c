/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:24:03 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/11 16:56:03 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

//function that checks for valid map characters
static int	ft_is_map_char(char c)
{
	if (c == 32 || (c >= 48 && c <= 49) || \
		(c >= 78 && c <= 79) || c == 83 || c == 87)
		return (1);
	return (0);
}

static void	set_player(t_var *var, char c)
{
	if (var->data->p_set != 0 && ((c >= 78 && c <= 79) || c == 83 || c == 87))
	{
		write(2, "Error\nmap error: mupliple player detected\n", 42);
		exit (EXIT_FAILURE);
	}
	else if (c == 78)
		var->data->p_set = 1;
	else if (c == 79)
		var->data->p_set = 2;
	else if (c == 83)
		var->data->p_set = 3;
	else if (c == 87)
		var->data->p_set = 4;
}

// TODO check Map for valid characters and other tests
void	check_map(t_var *var, char c)
{
	if (!ft_is_map_char(c))
	{
		write(2, "Error\nmap error: invalid map character\n", 39);
		exit (EXIT_FAILURE);
	}
	set_player(var, c);
}
