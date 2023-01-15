/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:00:39 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/15 15:14:19 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// checks if player exist and if not set the variable in struct.
// Detects error of multiple players
void	set_player(t_var *var, char c)
{
	if (var->data->p_set != 0 && (c == 78 || c == 79 || c == 83 || c == 87))
		error_msg_exit("map error: mupliple player detected");
	else if (c == 78)
		var->data->p_set = 1;
	else if (c == 79)
		var->data->p_set = 2;
	else if (c == 83)
		var->data->p_set = 3;
	else if (c == 87)
		var->data->p_set = 4;
}

// checks map char
void	check_map_char(t_var *var, char c)
{
	if (!is_map_char(c))
		error_msg_exit("map error: invalid map character");
	set_player(var, c);
}

// gives back an int with the value of the longest str in **map
int	max_col(t_linked_list *list)
{
	t_node	*current;
	size_t	max_col;

	current = list->head;
	max_col = 0;
	while (current != NULL)
	{
		if (max_col < ft_strlen(current->data))
			max_col = ft_strlen(current->data);
		current = current->next;
	}
	return (max_col);
}