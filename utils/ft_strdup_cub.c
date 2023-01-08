/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:01:17 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/08 18:34:54 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*ft_strdup_map(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*str;

	i = 0;
	len = ft_strlen_gnl(s1);
	str = ft_calloc((len + 1), sizeof(const char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		if (s1[i] == '\n')
		{
			str[i] = '\0';
			i++;
			break ;
		}
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strdup_cub(const char *s1)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*str;

	i = 0;
	j = 0;
	len = ft_strlen_gnl(s1);
	str = ft_calloc((len + 1), sizeof(const char));
	if (!str)
		return (NULL);
	while (i < len)
	{
		if (s1[i] == '\n')
		{
			str[i] = '\0';
			i++;
			break ;
		}
		if (!ft_is_whitespace_char(s1[i]))
		{
			str[j] = s1[i];
			j++;
		}
		i++;
	}
	str[i] = '\0';
	return (str);
}
