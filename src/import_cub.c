/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_cub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:49:29 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/08 18:26:33 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	write_to_struct(t_var *var, int i, char c, char *nswe)
{
	i++;
	if (var->line[i] == c)
	{
		i++;
		i += ft_skip_whitespace(&var->line[i]);
		if (ft_strncmp(nswe, "no", 2) == 0)
			var->data->no = ft_strdup_cub(&var->line[i]);
		else if (ft_strncmp(nswe, "so", 2) == 0)
			var->data->so = ft_strdup_cub(&var->line[i]);
		else if (ft_strncmp(nswe, "we", 2) == 0)
			var->data->we = ft_strdup_cub(&var->line[i]);
		else if (ft_strncmp(nswe, "ea", 2) == 0)
			var->data->ea = ft_strdup_cub(&var->line[i]);
	}
}

static void	copy_element(t_var *var)
{
	int	i;

	i = ft_skip_whitespace(var->line);
	if (var->line[i] == 'N')
		write_to_struct(var, i, 'O', "no");
	else if (var->line[i] == 'S')
		write_to_struct(var, i, 'O', "so");
	else if (var->line[i] == 'W')
		write_to_struct(var, i, 'E', "we");
	else if (var->line[i] == 'E')
		write_to_struct(var, i, 'A', "ea");
	else if (var->line[i] == 'F')
		cpy_color_to_struct(var, ++i, &var->data->f, &var->data->f_set);
	else if (var->line[i] == 'C')
		cpy_color_to_struct(var, ++i, &var->data->c, &var->data->c_set);
	else if ((check_cub(var->data) == 2))
		add_tail(var->data->map_lst, ft_strdup_map(var->line));
}

static void	import_cub2(t_var *var)
{
	if (var->line && ft_is_whitespace(var->line))
	{
		while (var->line && ft_is_whitespace(var->line))
		{
			free(var->line);
			var->line = get_next_line(var->fd1);
		}
	}
	while (var->line && !ft_is_whitespace(var->line))
	{
		if (var->line)
			copy_element(var);
		free(var->line);
		var->line = get_next_line(var->fd1);
	}
	while (var->line)
	{
		free(var->line);
		var->line = get_next_line(var->fd1);
		if (var->line && !ft_is_whitespace(var->line))
			var->data->err_map = 12;
	}
}

int	import_cub(t_var *var, char *argv, char *type)
{
	if (!ft_open_file(&var->fd1, argv, O_RDONLY) \
		|| !ft_check_fileext(argv, type))
		return (0);
	var->line = get_next_line(var->fd1);
	while (var->line && (check_cub(var->data) != 2))
	{
		if (var->line && !ft_is_whitespace(var->line))
			copy_element(var);
		free(var->line);
		var->line = get_next_line(var->fd1);
	}
	import_cub2(var);
	close(var->fd1);
	err_elements(var->data);
	err_map(var->data);
	err_color(var->data);
	printf("\n\ndata->f: %x\n", var->data->f);
	printf("data->c: %x\n\n", var->data->c);
	display_linked_list(var->data->map_lst);
	if (var->data->err != 0 || var->data->err_map != 0 || \
		var->data->err_color != 0)
		return (0);
	return (1);
}
