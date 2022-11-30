/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 19:08:43 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/05/21 17:30:00 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char **line, char **buffer_static)
{
	char	*buffer_temp;
	int		xline;

	buffer_temp = *buffer_static;
	xline = 0;
	while ((*buffer_static)[xline] != '\n' && (*buffer_static)[xline] != '\0')
		xline++;
	if (ft_strchr(*buffer_static, '\n'))
	{
		*line = ft_substr(*buffer_static, 0, xline + 1);
		if (ft_strlen(*buffer_static + xline + 1))
			*buffer_static = ft_strdup(*buffer_static + xline + 1);
		else
			*buffer_static = NULL;
	}
	else
	{
		*line = ft_strdup(buffer_temp);
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
	while (!ft_strchr(*buffer_static, '\n') && i)
	{
		i = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[i] = '\0';
		temp = *buffer_static;
		*buffer_static = ft_strjoin(*buffer_static, *buffer);
		free(temp);
	}
	free(*buffer);
	get_line(line, buffer_static);
	return (i);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*buffer_static[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > OPEN_MAX)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer || read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!buffer_static[fd])
		buffer_static[fd] = ft_strdup("");
	if (read_file(fd, &buffer, &buffer_static[fd], &line) == 0 && *line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
