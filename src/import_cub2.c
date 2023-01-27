/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_cub2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:54:47 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/27 11:01:44 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	check_double_identifier(t_var *var)
{
	if (ft_strncmp(var->line, "NO", 2) == 0 && var->data->no)
		error_msg_exit("NO duplicate");
	if (ft_strncmp(var->line, "SO", 2) == 0 && var->data->so)
		error_msg_exit("SO duplicate");
	if (ft_strncmp(var->line, "WE", 2) == 0 && var->data->we)
		error_msg_exit("WE duplicate");
	if (ft_strncmp(var->line, "EA", 2) == 0 && var->data->ea)
		error_msg_exit("EA duplicate");
	if (ft_strncmp(var->line, "F", 1) == 0 && var->data->f_set != 0)
		error_msg_exit("F duplicate");
	if (ft_strncmp(var->line, "C", 1) == 0 && var->data->c_set != 0)
		error_msg_exit("C duplicate");
	return (1);
}
