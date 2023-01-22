/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:50:25 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/03 17:16:15 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// prints string to specified fd and prints a new line
void	ft_putendl_fd(char *s, int fd)
{
	int	counter;

	if (!s)
		return ;
	counter = 0;
	while (s[counter])
	{
		ft_putchar_fd(s[counter], fd);
		counter++;
	}
	write(fd, "\n", 1);
}
