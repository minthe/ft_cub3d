/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:34:10 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/05 15:53:52 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int	ft_open_file(char *path, int opt)
{
	int	fd;

	fd = open(path, opt);
	if (fd <= 0)
		perror("ft_open_file");
	return (fd);
}
