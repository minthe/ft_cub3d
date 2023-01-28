/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:08:43 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/28 17:06:44 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

char	*get_line(char **line, char **buffer_static)
{
	char	*buffer_temp;
	int		xline;

	buffer_temp = *buffer_static;
	xline = 0;
	while ((*buffer_static)[xline] != '\n' && (*buffer_static)[xline] != '\0')
		xline++;
	if (ft_strchr_gnl(*buffer_static, '\n'))
	{
		*line = ft_substr_gnl(*buffer_static, 0, xline + 1);
		*buffer_static = ft_strdup_gnl(*buffer_static + xline + 1);
	}
	else
	{
		*line = ft_strdup_gnl(buffer_temp);
		*buffer_static = NULL;
	}
	free(buffer_temp);
	return (*line);
}

int	read_file(int fd, char **buffer, char **buffer_static, char **line)
{
	int		i;
	char	*temp;

	i = 1;
	while (!ft_strchr_gnl(*buffer_static, '\n') && i)
	{
		i = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[i] = '\0';
		temp = *buffer_static;
		*buffer_static = ft_strjoin_gnl(*buffer_static, *buffer);
		free(temp);
	}
	free(*buffer);
	get_line(line, buffer_static);
	return (i);
}

char	*get_next_line(t_var *var)
{
	char		*line;

	if (var->fd1 < 0 || BUFFER_SIZE <= 0 || var->fd1 > OPEN_MAX)
		return (NULL);
	var->data->buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!var->data->buffer || read(var->fd1, var->data->buffer, 0) < 0)
	{
		free(var->data->buffer);
		return (NULL);
	}
	if (!var->buffer_static)
		var->buffer_static = ft_strdup_gnl("");
	if (read_file(var->fd1, &var->data->buffer, &var->buffer_static, \
	&line) == 0 && *line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
