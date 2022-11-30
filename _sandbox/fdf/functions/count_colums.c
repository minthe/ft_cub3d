/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_colums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 15:28:50 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/05/19 18:37:11 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

// returns colums
int	count_colums(t_fdf *data)
{
	char	*line;
	int		fd;
	char	**colums;

	fd = open(data->map, O_RDONLY);
	data->colums = 0;
	line = get_next_line(fd);
	colums = ft_split(line, ' ');
	while (colums[data->colums])
		data->colums++;
	free(line);
	free_array(colums);
	close(fd);
	return (data->colums);
}
