/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_cub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:49:29 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/12 12:12:06 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	copy_element(t_var *var)
{
	int	i;

	i = ft_skip_whitespace(var->line);
	if (var->line[i] == 'N')
	{
		if (var->line[++i] == 'O')
			var->data->no = &var->line[++i];
	}
	else if (var->line[i] == 'S')
	{
		if (var->line[++i] == 'O')
			var->data->so = &var->line[++i];
	}
	else if (var->line[i] == 'W')
	{
		if (var->line[++i] == 'E')
			var->data->we = &var->line[++i];
	}
	else if (var->line[i] == 'E')
	{
		if (var->line[++i] == 'A')
			var->data->ea = &var->line[++i];
	}
	else if (var->line[i] == 'F')
		var->data->f = ft_calloc(1, sizeof(int));
	else if (var->line[i] == 'C')
		var->data->c = ft_calloc(1, sizeof(int));
	// printf("access: %d\n", access(var->line, R_OK));
}

int	import_cub(t_var *var, char *argv, char *type)
{
	if (!ft_open_file(&var->fd1, argv, O_RDONLY) \
		|| !ft_check_fileext(argv, type))
		return (0);
	var->line = get_next_line(var->fd1);
	while (var->line && (check_cub(var->data) != 2))
	{
		if (var->line && !ft_is_whitespace(var->line))
			copy_element(var);
		free(var->line);
		var->line = get_next_line(var->fd1);
	}
	close(var->fd1);
	if (check_cub(var->data) != 3)
	{
		err_elements(var->data);
		return (0);
	}
	return (1);
}
