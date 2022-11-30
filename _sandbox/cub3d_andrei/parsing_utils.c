/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:11:04 by aionescu          #+#    #+#             */
/*   Updated: 2022/10/24 19:54:33 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// This function returns the first non-space character it finds in a string,
// starting from the position that gets passed as a parameter.
char	first_nonspace_char(char *line)
{
	int	index;

	index = 0;
	while (line[index] != '\0')
	{
		if (line[index] == '\n')
			return ('\n');
		else if (line[index] != ' ' && line[index] != '\t')
			return (line[index]);
		index++;
	}
	return ('\0');
}

// This function checks if the passed character c is a whitespace character.
int	check_white_spaces(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}
