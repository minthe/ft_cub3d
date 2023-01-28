/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_cub2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:54:47 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/28 12:18:02 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

int	check_double_identifier(t_var *var)
{
	if (ft_strncmp(var->line, "NO", 2) == 0 && var->data->no)
		error_msg_exit(var, "NO duplicate");
	if (ft_strncmp(var->line, "SO", 2) == 0 && var->data->so)
		error_msg_exit(var, "SO duplicate");
	if (ft_strncmp(var->line, "WE", 2) == 0 && var->data->we)
		error_msg_exit(var, "WE duplicate");
	if (ft_strncmp(var->line, "EA", 2) == 0 && var->data->ea)
		error_msg_exit(var, "EA duplicate");
	if (ft_strncmp(var->line, "F", 1) == 0 && var->data->f_set != 0)
		error_msg_exit(var, "F duplicate");
	if (ft_strncmp(var->line, "C", 1) == 0 && var->data->c_set != 0)
		error_msg_exit(var, "C duplicate");
	return (1);
}

int	unknown_key(char *line)
{
	int	check;

	check = 1;
	if (ft_strncmp(line, "NO", 2) == 0)
		check = 0;
	else if (ft_strncmp(line, "SO", 2) == 0)
		check = 0;
	else if (ft_strncmp(line, "WE", 2) == 0)
		check = 0;
	else if (ft_strncmp(line, "EA", 2) == 0)
		check = 0;
	else if (ft_strncmp(line, "F", 1) == 0)
		check = 0;
	else if (ft_strncmp(line, "C", 1) == 0)
		check = 0;
	return (check);
}

void	copy_map_line(t_var *var)
{
	if ((check_cub(var->data) == 2))
	{
		if (!ft_is_whitespace(var->line) && !only_map_char(var->line))
			error_msg_exit(var, "map error: invalid map character");
		check_map_player(var);
		add_tail(var->data->map_lst, ft_strdup_map(var, 0, NULL));
	}
}
