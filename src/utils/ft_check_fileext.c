/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fileext.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 09:01:15 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/28 14:33:37 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (n)
	{
		if (*us1 != *us2)
			return (*us1 - *us2);
		if (!*us1 || !*us2)
			break ;
		us1++;
		us2++;
		n--;
	}
	return (0);
}

static size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter])
	{
		counter ++;
	}
	return (counter);
}

// checks if given fileextension equals
int	ft_check_fileext(char *path, char *ext)
{
	if ((ft_strncmp(&path[(ft_strlen(path) - ft_strlen(ext))], \
		ext, ft_strlen(ext))) == 0)
		return (1);
	write(2, "Error\n", 6);
	write(2, path, ft_strlen(path));
	write(2, ": not a valid \n", 14);
	write(2, ext, ft_strlen(ext));
	write(2, " file\n", 6);
	return (0);
}
