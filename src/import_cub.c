/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_cub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:49:29 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/11 18:34:19 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static void	check_access(char *str, char *element)
{
	if (access(str, R_OK) != 0)
	{
		write(2, "Error\n", 6);
		write(2, element, ft_strlen(element));
		write(2, " -> ", 4);
		perror(str);
		exit (EXIT_FAILURE);
	}
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
			check_access(var->data->no, "NO");
		}
		else if (ft_strncmp(nswe, "so", 2) == 0)
		{
			var->data->so = ft_strdup_cub(&var->line[i], 0, 0);
			check_access(var->data->so, "SO");
		}
		else if (ft_strncmp(nswe, "we", 2) == 0)
		{
			var->data->we = ft_strdup_cub(&var->line[i], 0, 0);
			check_access(var->data->we, "WE");
		}
		else if (ft_strncmp(nswe, "ea", 2) == 0)
		{
			var->data->ea = ft_strdup_cub(&var->line[i], 0, 0);
			check_access(var->data->ea, "EA");
		}
	}
}

static void	copy_element(t_var *var, int i)
{
	if (var->line[i] == 'N')
		write_to_struct(var, ++i, 'O', "no");
	else if (var->line[i] == 'S')
		write_to_struct(var, ++i, 'O', "so");
	else if (var->line[i] == 'W')
		write_to_struct(var, ++i, 'E', "we");
	else if (var->line[i] == 'E')
		write_to_struct(var, ++i, 'A', "ea");
	else if (var->line[i] == 'F')
		cpy_color_to_struct(var, ++i, &var->data->f, &var->data->f_set);
	else if (var->line[i] == 'C')
		cpy_color_to_struct(var, ++i, &var->data->c, &var->data->c_set);
	else if ((check_cub(var->data) == 0))
	{
		write(2, "Error\nmap error: not last element\n", 34);
		exit (EXIT_FAILURE);
	}
	else if ((check_cub(var->data) == 2))
		add_tail(var->data->map_lst, ft_strdup_map(var, 0, NULL));
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
			copy_element(var, ft_skip_whitespace(var->line));
		free(var->line);
		var->line = get_next_line(var->fd1);
	}
	while (var->line)
	{
		free(var->line);
		var->line = get_next_line(var->fd1);
		if (var->line && !ft_is_whitespace(var->line))
		{
			write(2, "Error\nmap error: empty lines\n", 29);
			exit (EXIT_FAILURE);
		}
	}
}

int	import_cub(t_var *var, char *argv, char *type)
{
	if (!ft_open_file(&var->fd1, argv, O_RDONLY) \
		|| !ft_check_fileext(argv, type))
		exit (EXIT_FAILURE);
	var->line = get_next_line(var->fd1);
	while (var->line && (check_cub(var->data) != 2))
	{
		if (var->line && !ft_is_whitespace(var->line))
			copy_element(var, ft_skip_whitespace(var->line));
		free(var->line);
		var->line = get_next_line(var->fd1);
	}
	import_cub2(var);
	import_map(var);
	check_elements(var->data);
	close(var->fd1);
	return (1);
}
