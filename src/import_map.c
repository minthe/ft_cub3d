/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:23:47 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/28 12:17:28 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

static void	copy_linked_list(t_var *var, t_linked_list *list, char **map)
{
	t_node	*current;
	int		row;
	int		col;
	int		len;

	row = 0;
	current = list->head;
	while (current != NULL)
	{
		len = ft_strlen(current->data);
		map[row] = ft_calloc(var->data->map_col + 1, sizeof(char));
		col = 0;
		while (col < var->data->map_col)
		{
			if (col < len)
				map[row][col] = current->data[col];
			else
				map[row][col] = 32;
			col++;
		}
		current = current->next;
		row++;
	}
}

// copies map from linked list to **map, normalize col-size
void	import_map(t_var *var)
{
	var->data->map_lines = count_linked_list(var->data->map_lst);
	if (var->data->map_lines < 3)
		error_msg_exit(var, "map error: invalid layout");
	var->data->map = ft_calloc(var->data->map_lines + 1, \
		sizeof(char *));
	var->data->map_col = max_col(var->data->map_lst);
	copy_linked_list(var, var->data->map_lst, var->data->map);
}
