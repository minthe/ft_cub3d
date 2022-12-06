/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:49:29 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/05 23:32:31 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Returns 
void	import_map(t_var *var, char *path, char *type)
{
	char	*line;
	int		fd;

	(void)var;
	(void)type;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror("map");
		return ;
	}
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
