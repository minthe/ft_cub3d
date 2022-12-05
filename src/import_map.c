/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:49:29 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/05 17:02:46 by vfuhlenb         ###   ########.fr       */
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
	fd = ft_open_file(path, O_RDONLY);
	printf("%s", (line = get_next_line(fd)));
	free(line);
	printf("%s", (line = get_next_line(fd)));
	free(line);
	close(fd);
	fd = ft_open_file(path, O_RDONLY);
	printf("%s", (line = get_next_line(fd)));
	free(line);
}
