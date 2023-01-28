/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_cub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:49:29 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/28 14:36:44 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

static void	check_access(t_var *var, char *str, char *element)
{
	int	fd_tex;

	fd_tex = open(str, O_RDONLY);
	if (fd_tex < 0)
	{
		write(2, "Error\n", 6);
		write(2, element, ft_strlen(element));
		write(2, " -> ", 4);
		perror(str);
		close(fd_tex);
		cleanup(var);
		ft_free_struct(var);
		free(var);
		exit (EXIT_FAILURE);
	}
	close(fd_tex);
}

static void	write_to_struct(t_var *var, int i, char c, char *nswe)
{
	if (var->line[i] == c)
	{
		i++;
		i += ft_skip_whitespace(&var->line[i]);
		if (ft_strncmp(nswe, "no", 2) == 0)
		{
			var->data->no = ft_strdup_cub(&var->line[i], 0, 0);
			check_access(var, var->data->no, "NO");
		}
		else if (ft_strncmp(nswe, "so", 2) == 0)
		{
			var->data->so = ft_strdup_cub(&var->line[i], 0, 0);
			check_access(var, var->data->so, "SO");
		}
		else if (ft_strncmp(nswe, "we", 2) == 0)
		{
			var->data->we = ft_strdup_cub(&var->line[i], 0, 0);
			check_access(var, var->data->we, "WE");
		}
		else if (ft_strncmp(nswe, "ea", 2) == 0)
		{
			var->data->ea = ft_strdup_cub(&var->line[i], 0, 0);
			check_access(var, var->data->ea, "EA");
		}
	}
}

static void	copy_element(t_var *var, int i)
{
	if (ft_strncmp(&var->line[i], "NO", 2) == 0 && !var->data->no)
		write_to_struct(var, ++i, 'O', "no");
	else if (ft_strncmp(&var->line[i], "SO", 2) == 0 && !var->data->so)
		write_to_struct(var, ++i, 'O', "so");
	else if (ft_strncmp(&var->line[i], "WE", 2) == 0 && !var->data->we)
		write_to_struct(var, ++i, 'E', "we");
	else if (ft_strncmp(&var->line[i], "EA", 2) == 0 && !var->data->ea)
		write_to_struct(var, ++i, 'A', "ea");
	else if (ft_strncmp(&var->line[i], "F", 1) == 0 && var->data->f_set == 0)
		cpy_color_to_struct(var, ++i, &var->data->f, 'F');
	else if (ft_strncmp(&var->line[i], "C", 1) == 0 && var->data->c_set == 0)
		cpy_color_to_struct(var, ++i, &var->data->c, 'C');
	else if (var->line[i] == '1')
		error_msg_exit(var, "map not last element");
	else if (unknown_key(&var->line[i]))
		error_msg_exit(var, "unknown key");
}

static void	import_cub2(t_var *var)
{
	if (var->line && ft_is_whitespace(var->line))
	{
		while (var->line && ft_is_whitespace(var->line))
		{
			free(var->line);
			var->line = get_next_line(var);
		}
	}
	while (var->line && !ft_is_whitespace(var->line))
	{
		if (var->line)
			copy_map_line(var);
		free(var->line);
		var->line = get_next_line(var);
	}
	while (var->line)
	{
		free(var->line);
		var->line = get_next_line(var);
		if (var->line && !ft_is_whitespace(var->line))
			error_msg_exit(var, "map error: empty lines");
		if (var->line && !ft_is_whitespace(var->line) && \
		!only_map_char(var->line))
			error_msg_exit(var, "map error: empty lines and \
				illegal characters");
	}
}

// imports all elements to struct
int	import_cub(t_var *var, char *argv, char *type)
{
	if (!ft_open_file(&var->fd1, argv, O_RDONLY) \
		|| !ft_check_fileext(argv, type))
		error_exit(var);
	var->line = get_next_line(var);
	while (var->line && (check_cub(var->data) != 2))
	{
		check_double_identifier(var);
		if (var->line && !ft_is_whitespace(var->line))
			copy_element(var, ft_skip_whitespace(var->line));
		free(var->line);
		var->line = get_next_line(var);
	}
	import_cub2(var);
	if (check_cub(var->data) == 2)
		import_map(var);
	check_elements(var);
	if (check_cub(var->data) == 3)
		check_map(var);
	close(var->fd1);
	return (1);
}
