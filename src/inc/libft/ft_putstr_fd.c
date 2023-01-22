/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:23:10 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/06/03 17:14:19 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// prints string to specified fd
void	ft_putstr_fd(char *s, int fd)
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
}
