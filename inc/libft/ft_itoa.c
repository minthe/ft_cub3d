/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 20:11:30 by vfuhlenb          #+#    #+#             */
/*   Updated: 2021/08/22 20:16:39 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countd(int n)
{
	size_t	x;

	x = 0;
	if (n < 0)
	{
		n *= -1;
		++x;
	}
	while (n >= 10)
	{
		n /= 10;
		++x;
	}
	return (++x);
}

char	*ft_itoa(int n)
{
	char	*d;
	char	*r;
	size_t	dc;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	dc = ft_countd(n);
	d = ft_calloc(sizeof(char), (dc + 1));
	if (!d)
		return (NULL);
	r = d;
	if (n < 0)
	{
		*d = '-';
		n *= -1;
	}
	d += dc;
	while (n >= 10)
	{
		d--;
		*d = ((n % 10) + '0');
		n /= 10;
	}
	*(--d) = (n % 10) + '0';
	return (r);
}
