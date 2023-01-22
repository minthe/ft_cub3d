/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whitespace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 11:15:10 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/12 14:22:08 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//function that checks for whitespace characters
int	ft_is_whitespace(char *line)
{
	while (*line)
	{
		if (*line != 32 && !(*line >= 9 && *line <= 13))
			return (0);
		line++;
	}
	return (1);
}

//function that checks for whitespace character
int	ft_is_whitespace_char(char c)
{
	if (c != 32 && !(c >= 9 && c <= 13))
		return (0);
	return (1);
}

//function that skips whitespace and returns the position with
//first non whitespace character.
int	ft_skip_whitespace(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 32 && !(line[i] >= 9 && line[i] <= 13))
			return (i);
		i++;
	}
	return (0);
}
