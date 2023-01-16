/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_cub2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 18:35:20 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/16 19:08:17 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	check_double_identifier2(t_var *var)
{
	if ((check_cub(var->data) == 2))
	{
		if (!ft_is_whitespace(var->line) && !only_map_char(var->line))
			error_msg_exit("map error: invalid map character");
	}
}

void	check_double_identifier(t_var *var, int i)
{
	if ((check_cub(var->data) == 0) && !is_ident_char(var->line[i]) \
		&& only_map_char(var->line))
		error_msg_exit("map error: not last element");
	if (var->line[i] == 'N' && var->line[i + 1] && var->line[i + 1] == 'O' \
		&& var->data->no)
		error_msg_exit("NO duplicate");
	if (var->line[i] == 'S' && var->line[i + 1] && var->line[i + 1] == 'O' \
		&& var->data->so)
		error_msg_exit("SO duplicate");
	if (var->line[i] == 'W' && var->line[i + 1] && var->line[i + 1] == 'E' \
		&& var->data->we)
		error_msg_exit("WE duplicate");
	if (var->line[i] == 'E' && var->line[i + 1] && var->line[i + 1] == 'A' \
		&& var->data->ea)
		error_msg_exit("EA duplicate");
	if (var->line[i] == 'F' && var->line[i + 1] && \
		is_cf_char(var->line[i + 1]) && var->data->f_set)
		error_msg_exit("F duplicate");
	if (var->line[i] == 'C' && var->line[i + 1] && \
		is_cf_char(var->line[i + 1]) && var->data->c_set)
		error_msg_exit("C duplicate");
	check_double_identifier2(var);
}
