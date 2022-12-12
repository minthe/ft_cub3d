/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_cub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:49:29 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/12 14:27:33 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static	count_len(char *line)
{
	int	i;

	i = 0;
	while (line[i] && !ft_is_whitespace_char(line[i]))
		i++;
	return (i);
}

static copy_str()

void	copy_element(t_var *var)
{
	int	i;

	i = ft_skip_whitespace(var->line);
	if (var->line[i] == 'N')
	{
		i++;
		if (var->line[i] == 'O')
		{
			i++;
			i += ft_skip_whitespace(&var->line[i]);
			var->data->no = ft_strdup(&var->line[i]);
		}
	}
	else if (var->line[i] == 'S')
	{
		i++;
		if (var->line[i] == 'O')
		{
			i++;
			i += ft_skip_whitespace(&var->line[i]);
			var->data->so = ft_strdup(&var->line[i]);
		}
	}
	else if (var->line[i] == 'W')
	{
		i++;
		if (var->line[i] == 'E')
			var->data->we = ft_strdup(&var->line[++i]);
	}
	else if (var->line[i] == 'E')
	{
		i++;
		if (var->line[i] == 'A')
			var->data->ea = ft_strdup(&var->line[++i]);
	}
	else if (var->line[i] == 'F')
		var->data->f = ft_calloc(1, sizeof(int));
	else if (var->line[i] == 'C')
		var->data->c = ft_calloc(1, sizeof(int));
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
	close(var->fd1);
	printf("$%s$", var->data->no);
	printf("$%s$", var->data->so);
	printf("access: %d\n", access(var->data->no, R_OK));
	printf("access: %d\n", access(var->data->so, R_OK));
	if (check_cub(var->data) != 3)
	{
		err_elements(var->data);
		return (0);
	}
	return (1);
}
