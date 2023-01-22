/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:14:40 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/22 18:34:50 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

// sets nodes from linked-list to NULL
void	initialize_list(t_linked_list *list)
{
	list->head = NULL;
	list->tail = NULL;
	list->current = NULL;
}

// adds a node at the tail
void	add_tail(t_linked_list *list, void *data)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	node->data = data;
	node->next = NULL;
	if (list->head == NULL)
		list->head = node;
	else
		list->tail->next = node;
	list->tail = node;
}

// prints the list
int	count_linked_list(t_linked_list *list)
{
	int		i;
	t_node	*current;

	current = list->head;
	i = 0;
	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}

// deletes and frees nodes from linked-list 
void	delete_list(t_linked_list *list)
{
	t_node	*temp;

	while (list->head != NULL)
	{
		temp = list->head;
		list->head = list->head->next;
		free(temp->data);
		free(temp);
	}
}

// displays nodes from linked_list
void	display_linked_list(t_linked_list *list)
{
	t_node	*current;

	current = list->head;
	while (current != NULL)
	{
		if (ft_is_whitespace(current->data) && current->next)
			printf("invalid empty line\n");
		else
		{
			ft_putstr_fd(current->data, 1);
			ft_putchar_fd('$', 1);
			ft_putchar_fd('\n', 1);
		}
		current = current->next;
	}
}
