/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 21:24:03 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/14 22:01:06 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_map(t_var *var, char **map, int map_lines, int p_set)
{
	int	col;
	int	row;
	(void)map_lines;
	(void)p_set;

	if (!var->data->p_set)
		error_msg_exit("map error: no player found");
	row = 0;
	while(row < var->data->map_lines)
	{
		col = 0;
		while(col < var->data->map_col)
		{
			if (map[row][col] == '0')
				printf("0 at: %d,%d\n", row, col);
			col++;
		}
		row++;
	}
}
