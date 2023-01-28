/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:00:39 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/28 12:29:43 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// checks if player exist and if not set the variable in struct.
// Detects error of multiple players
void	set_player(t_var *var, char c)
{
	if (var->data->p_set != 0 && (c == 'N' || c == 'E' || c == 'S' || c == 'W'))
		error_msg_exit(var, "map error: mupliple player detected");
	else if (c == 'N')
		var->data->p_set = 1;
	else if (c == 'E')
		var->data->p_set = 2;
	else if (c == 'S')
		var->data->p_set = 3;
	else if (c == 'W')
		var->data->p_set = 4;
}

// checks map player
void	check_map_player(t_var *var)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen_gnl(var->line))
	{
		if (var->line[i] == '\n')
			break ;
		if (!is_map_char(var->line[i]))
			error_msg_exit(var, "map error: invalid map character");
		set_player(var, var->line[i]);
		i++;
	}
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
