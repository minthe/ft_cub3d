/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 13:54:39 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/29 13:21:24 by vfuhlenb         ###   ########.fr       */
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
	if (var->data->f)
		free (var->data->f);
	if (var->data->c)
		free (var->data->c);
	if (var->data->map)
		free (var->data->map);
	if (var->line)
		free (var->line);
	delete_list(var->data->map_lst);
	if (var->data->map_lst)
		free (var->data->map_lst);
}
