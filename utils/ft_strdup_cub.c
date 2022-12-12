/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_cub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:01:17 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/12 18:59:44 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*ft_strdup_map(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	i = 0;
	len = ft_strlen_gnl(s1);
	ptr = ft_calloc((len + 1), sizeof(const char));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		if (s1[i] == '\n')
		{
			ptr[i] = '\0';
			i++;
			break ;
		}
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strdup_cub(const char *s1)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*ptr;

	i = 0;
	j = 0;
	len = ft_strlen_gnl(s1);
	ptr = ft_calloc((len + 1), sizeof(const char));
	if (!ptr)
		return (NULL);
	while (i < len)
	{
		if (s1[i] == '\n')
		{
			ptr[i] = '\0';
			i++;
			break ;
		}
		if (!ft_is_whitespace_char(s1[i]))
		{
			ptr[j] = s1[i];
			j++;
		}
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}