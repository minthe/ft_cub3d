/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 09:57:38 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/13 11:16:02 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// allocates the requested memory, sets it to zero and returns a pointer to it
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;

	p = malloc(nmemb * size);
	if (!p)
		return (NULL);
	ft_bzero(p, nmemb * size);
	return (p);
}
