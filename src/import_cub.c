/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_cub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:49:29 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/08 15:57:15 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	copy_element(t_var *var)
{
	printf("access: %d\n", access(var->line, R_OK));
}

int	import_cub(t_var *var, char *argv, char *type)
{
	if (!ft_open_file(&var->fd1, argv, O_RDONLY) \
		|| !ft_check_fileext(argv, type))
		return (0);
	var->line = get_next_line(var->fd1);
	while (var->line && (check_cub(var->cub) != 2))
	{
		copy_element(var);
		free(var->line);
		var->line = get_next_line(var->fd1);
	}
	close(var->fd1);
	if (check_cub(var->cub) != 3)
	{
		err_elements(var->cub);
		return (0);
	}
	return (1);
}
