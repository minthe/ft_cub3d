/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:01:17 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/08 21:52:51 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*ft_strdup_map(const char *s1, size_t i, char *str)
{
	str = ft_calloc((ft_strlen_gnl(s1) + 1), sizeof(const char));
	if (str)
	{
		while (i < ft_strlen_gnl(s1))
		{
			if (s1[i] == '\n')
				break ;
			// TODO check Map for valid characters and other tests
			str[i] = s1[i];
			i++;
		}
	}
	return (str);
}

char	*ft_strdup_cub(const char *s1, size_t i, size_t j)
{
	char	*str;

	str = ft_calloc((ft_strlen_gnl(s1) + 1), sizeof(const char));
	if (str)
	{
		while (i < ft_strlen_gnl(s1))
		{
			if (s1[i] == '\n')
				break ;
			if (!ft_is_whitespace_char(s1[i]))
			{
				str[j] = s1[i];
				j++;
			}
			i++;
		}
	}
	return (str);
}
