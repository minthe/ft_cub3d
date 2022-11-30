/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_layout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:54:53 by aionescu          #+#    #+#             */
/*   Updated: 2022/11/19 11:25:46 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// This is a helper function used to determine
// the length of the longest line in the map.
int	calculate_longest_line(t_gamedata *gamedata)
{
	int	col_max;
	int	row;
	int	col;

	col_max = 0;
	row = 0;
	col = 0;
	while (gamedata->map_layout[row][0] != '\0')
	{
		while (gamedata->map_layout[row][col] != '\0')
		{
			if (col > col_max)
				col_max = col;
			col++;
		}
		col = 0;
		row++;
	}
	col_max++;
	return (col_max);
}

// This function refines the map layout into a rectangle and
// replaces all the whitespaces with the character '1'.
char	make_rect_and_replace_space(t_gamedata *gamedata)
{
	int	longest_line;
	int	row;
	int	col;

	if (layout_logic_check(gamedata) != 0)
		return ('m');
	longest_line = calculate_longest_line(gamedata);
	row = 0;
	col = 0;
	while (gamedata->map_layout[row][0] != '\0')
	{
		while (col < longest_line)
		{
			if (gamedata->map_layout[row][col] == ' '
				|| gamedata->map_layout[row][col] == '\0')
				gamedata->map_layout[row][col] = '1';
			col++;
		}
		col = 0;
		row++;
	}
	return ('L');
}

// This function is used to check if there is any non-space character before
// the end of the current line, starting from the passed pointer.
// Returns 0 if false, or 1 if true and additionally increases *pos as needed.
int	empty_space_ahead(char *start_ptr, int *pos)
{
	int	flag_empty;
	int	index;

	flag_empty = 1;
	index = 0;
	while (start_ptr[index] != '\n' && start_ptr[index] != '\0')
	{
		if (start_ptr[index] != ' ' && start_ptr[index] != '\t')
		{
			flag_empty = 0;
			break ;
		}
		index++;
	}
	if (flag_empty == 1)
		*pos = *pos + index;
	return (flag_empty);
}

// This function copies every character that represents the layout of the
// playable area into the the gamedata->map_layout[][] variable.
// The return value 'L' means success and the return value 'l' means error.
char	process_layout(char *p, t_gamedata *gamedata)
{
	int	pos;
	int	row;
	int	col;

	pos = 0;
	row = 0;
	col = 0;
	while (p[pos] != '\0')
	{
		if (p[pos] == '\n' || empty_space_ahead(p + pos, &pos))
		{
			gamedata->map_layout[row][col] = '\0';
			row++;
			col = 0;
		}
		else if (ft_strchr("NSEW01 ", p[pos]) != NULL)
		{
			gamedata->map_layout[row][col] = p[pos];
			col++;
		}
		else
			return ('l');
		pos++;
	}
	return (make_rect_and_replace_space(gamedata));
}
