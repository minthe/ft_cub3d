/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 21:27:02 by aionescu          #+#    #+#             */
/*   Updated: 2022/11/13 17:40:43 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*new_str;
	long long	length;
	long long	index;

	new_str = NULL;
	length = 0;
	index = 0;
	while (s[length] != '\0')
	{
		length++;
	}
	new_str = ft_calloc(length + 1 + 1, sizeof(char));
	while (index < length)
	{
		new_str[index] = s[index];
		index++;
	}
	return (new_str);
}
