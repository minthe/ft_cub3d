/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_floor_ceiling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:53:30 by aionescu          #+#    #+#             */
/*   Updated: 2022/10/27 18:08:18 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// This function checks if there are any digits left in the current string
// before encountering a '\n' or a '\0'.
// Returns 0 if false, or 1 if true.
int	check_if_nums_before_nl(char *start_ptr)
{
	int	index;
	int	flag_num;

	flag_num = 0;
	index = 0;
	while (start_ptr[index] != '\n' && start_ptr[index] != '\0'
		&& flag_num == 0)
	{
		if (ft_isdigit(start_ptr[index]))
			flag_num++;
		index++;
	}
	return (flag_num);
}

// This function is used to navigate to the next color code in the line read
// from the input file. It goes past the current color code, past the comma
// and stops at the first digit of the next color code.
// Returns an int to be used as the index of the entire line being parsed.
int	go_to_next_colorcode(char *line, int start)
{
	int	index;

	index = start;
	while (ft_isdigit(line[index]))
		index++;
	if (check_if_nums_before_nl(line + index) == 0)
	{
		while (line[index] != '\n' && line[index] != '\0')
			index++;
		return (index);
	}
	while (line[index] != ',')
		index++;
	while (!ft_isdigit(line[index]))
		index++;
	return (index);
}

// This function takes as parameter a pointer to the beginning of the current
// color code to parse to an int value, which it then returns.
// If the parsed value is higher than 255, the function just returns 255.
int	get_colorcode(char *start_ptr)
{
	char	code_as_chars[5];
	int		index;

	index = 0;
	while (ft_isdigit(start_ptr[index]))
	{
		code_as_chars[index] = start_ptr[index];
		index++;
		if (index > 3)
			break ;
	}
	code_as_chars[index] = '\0';
	if (ft_atoi(code_as_chars) > 255)
		return (255);
	else
		return (ft_atoi(code_as_chars));
}

// This function gets called when the first non-space character in the
// line currently being parsed is 'F'.
// Returns 'F' if color codes were parsed ok, or 'f' if parsing failed.
char	process_floor(char *line, t_gamedata *gamedata)
{
	int	index;
	int	index_rgb;

	index = 0;
	while (line[index] != 'F')
		index++;
	if (line[index + 1] == ' ' || line[index + 1] == '\t')
	{
		index++;
		while (line[index] == ' ' || line[index] == '\t')
			index++;
		index_rgb = 0;
		while (index_rgb < 3 && check_if_nums_before_nl(line + index) == 1)
		{
			gamedata->map_floorcolor[index_rgb] = get_colorcode(line + index);
			index_rgb++;
			if (index_rgb < 3)
				index = go_to_next_colorcode(line, index);
		}
	}
	else
		return ('f');
	return ('F');
}

// Analogous to process_floor()
char	process_ceiling(char *line, t_gamedata *gamedata)
{
	int	index;
	int	index_rgb;

	index = 0;
	while (line[index] != 'C')
		index++;
	if (line[index + 1] == ' ' || line[index + 1] == '\t')
	{
		index++;
		while (line[index] == ' ' || line[index] == '\t')
			index++;
		index_rgb = 0;
		while (index_rgb < 3 && check_if_nums_before_nl(line + index) == 1)
		{
			gamedata->map_ceilingcolor[index_rgb] = get_colorcode(line + index);
			index_rgb++;
			if (index_rgb < 3)
				index = go_to_next_colorcode(line, index);
		}
	}
	else
		return ('c');
	return ('C');
}
