/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:18:44 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/28 12:53:11 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

static void	init_cub(t_data *data)
{
	data->no = NULL;
	data->so = NULL;
	data->we = NULL;
	data->ea = NULL;
	data->f = 0x00000000;
	data->c = 0x00000000;
	data->f_set = 0;
	data->c_set = 0;
	data->p_set = 0;
	data->map = NULL;
	data->map_lines = 0;
	data->map_col = 0;
	data->map_lst = ft_calloc(1, sizeof(t_linked_list));
	initialize_list(data->map_lst);
	data->err = 0;
}

// inits the data struct
int	init_struct(t_var *var)
{
	var->data = malloc(sizeof(t_data));
	var->fd1 = 0;
	var->line = NULL;
	init_cub(var->data);
	return (1);
}
