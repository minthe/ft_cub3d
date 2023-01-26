/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_cub2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:11:55 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/26 17:03:53 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

static void	check_double_identifier2(t_var *var)
{
	if ((var->line[i] == 'F' && var->line[i + 1] && \
		is_cf_char(var->line[i + 1]) && var->data->f_set) \
		|| (var->line[i] == 'F' && ft_strlen(var->line) == 2))
		error_msg_exit("F duplicate");
	if ((var->line[i] == 'C' && var->line[i + 1] && \
		is_cf_char(var->line[i + 1]) && var->data->c_set) \
		|| (var->line[i] == 'C' && ft_strlen(var->line) == 2))
		error_msg_exit("C duplicate");
}

int	check_double_identifier(t_var *var, int i)
{
	if ((var->line[i] == 'N' && var->line[i + 1] && var->line[i + 1] \
	== 'O' && var->data->no) || (var->line[i] == 'N' && var->line[i + 1] \
	== 'O' && ft_strlen(var->line) == 3))
		error_msg_exit("NO duplicate");
	if ((var->line[i] == 'S' && var->line[i + 1] && var->line[i + 1] \
	== 'O' && var->data->so) || (var->line[i] == 'S' && var->line[i + 1] \
	== 'O' && ft_strlen(var->line) == 3))
		error_msg_exit("SO duplicate");
	if ((var->line[i] == 'W' && var->line[i + 1] && var->line[i + 1] == 'E' \
	&& var->data->we) || (var->line[i] == 'W' && var->line[i + 1] == 'E' \
	&& ft_strlen(var->line) == 3))
		error_msg_exit("WE duplicate");
	if ((var->line[i] == 'E' && var->line[i + 1] && var->line[i + 1] \
	== 'A' && var->data->ea) || (var->line[i] == 'E' && var->line[i + 1] \
	== 'A' && ft_strlen(var->line) == 3))
		error_msg_exit("EA duplicate");
	check_double_identifier2(var);
	return (1);
}
