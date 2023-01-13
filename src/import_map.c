/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:23:47 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/12 14:54:47 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	copy_linked_list(t_linked_list *list, char **map)
{
	t_node	*current;

	current = list->head;
	while (current != NULL)
	{
		*map = ft_strdup(current->data);
		current = current->next;
		map++;
	}
}

void	import_map(t_var *var)
{
	var->data->map_lines = count_linked_list(var->data->map_lst);
	if (var->data->map_lines < 3)
		error_msg_exit("map error: invalid layout");
	var->data->map = ft_calloc(var->data->map_lines + 1, \
		sizeof(char *));
	copy_linked_list(var->data->map_lst, var->data->map);
}
