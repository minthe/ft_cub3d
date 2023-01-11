/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:54:39 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/11 17:19:30 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	cleanup(t_var *var)
{
	if (var->data->no)
		free (var->data->no);
	if (var->data->so)
		free (var->data->so);
	if (var->data->we)
		free (var->data->we);
	if (var->data->ea)
		free (var->data->ea);
	if (var->line)
		free (var->line);
	delete_list(var->data->map_lst);
	if (var->data->map_lst)
		free (var->data->map_lst);
	if (var->data->map)
		ft_free_doublepoint(var->data->map);
}
