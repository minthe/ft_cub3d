/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_cub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:49:29 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/28 20:26:36 by vfuhlenb         ###   ########.fr       */
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
		var->data->f = ft_calloc(1, sizeof(int));
	else if (var->line[i] == 'C')
		var->data->c = ft_calloc(1, sizeof(int));
	else if ((check_cub(var->data) == 2)) // TODO insert primary check for map: allowed characters, check if player is set and if another player character appears then mark as invalid
	{
		// var->data->map[0] = calloc(ft_strlen(var->line), sizeof(char));
		// var->data->map[0] = ft_strdup_cub(var->line);
		printf("%s", var->line);
	}
}

int	import_cub(t_var *var, char *argv, char *type)
{
	if (!ft_open_file(&var->fd1, argv, O_RDONLY) \
		|| !ft_check_fileext(argv, type))
		return (0);
	var->line = get_next_line(var->fd1);
	while (var->line && (check_cub(var->data) != 3))
	{
		if (var->line && !ft_is_whitespace(var->line)) // TODO check if map lines are written, if so and if empty lines appear then invalid
			copy_element(var);
		free(var->line);
		var->line = get_next_line(var->fd1);
	}
	close(var->fd1);
	err_elements(var->data);
	if (var->data->err != 0)
		return (0);
	return (1);
}
