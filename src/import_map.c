/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:49:29 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/08 09:41:30 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	import_cub(t_var *var, char *argv, char *type)
{
	char	*line;

	(void)line;
	if (!ft_open_file(&var->fd1, argv, O_RDONLY) \
		|| !ft_check_fileext(argv, type))
		return (0);
	line = get_next_line(var->fd1);
	free(line);
	close(var->fd1);
	return (1);
	// printf("access: %d\n", access(argv[1], R_OK));
}
