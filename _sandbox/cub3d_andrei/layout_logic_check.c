/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_logic_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 16:54:27 by aionescu          #+#    #+#             */
/*   Updated: 2022/11/18 22:29:43 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// This function checks if the number of player starting positions
// is greater than 1.
// Returns 0 in case there is only one, or 35 in case of multiple entries.
int	check_player(t_gamedata *gamedata)
{
	int	row;
	int	col;
	int	count;

	count = 0;
	row = 0;
	col = 0;
	while (gamedata->map_layout[row][col] != '\0')
	{
		while (gamedata->map_layout[row][col] != '\0')
		{
			if (gamedata->map_layout[row][col] == 'N'
				|| gamedata->map_layout[row][col] == 'S'
				|| gamedata->map_layout[row][col] == 'E'
				|| gamedata->map_layout[row][col] == 'W')
				count++;
			col++;
		}
		col = 0;
		row++;
	}
	if (count != 1)
		return (35);
	return (0);
}

// This function checks if an accessible square in the game is
// adjacent either to a wall or to another accessible square.
// Returns 0 if everything is correct, or 1 if incorrect.
int	check_for_nsewzero(t_gamedata *gamedata, int row, int col)
{
	if (gamedata->map_layout[row - 1][col] == ' '
		|| gamedata->map_layout[row][col - 1] == ' '
		|| gamedata->map_layout[row][col + 1] == ' '
		|| gamedata->map_layout[row + 1][col] == ' '
		|| gamedata->map_layout[row - 1][col] == '\0'
		|| gamedata->map_layout[row][col - 1] == '\0'
		|| gamedata->map_layout[row][col + 1] == '\0'
		|| gamedata->map_layout[row + 1][col] == '\0')
		return (25);
	else
		return (0);
}

// This function checks if the upper and lower edges of the game map are walls.
// Returns 0 if everything is correct, or 1 if incorrect.
int	check_walls_updown(t_gamedata *gamedata)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (gamedata->map_layout[0][col] != '\0')
	{
		if (gamedata->map_layout[row][col] != '1')
			return (23);
		row = 0;
		while (gamedata->map_layout[row][col] != '\0')
			row++;
		while (gamedata->map_layout[row - 1][col] == ' ')
			row--;
		if (gamedata->map_layout[row - 1][col] != '1')
			return (24);
		row = 0;
		col++;
	}
	return (0);
}

// This function checks if the left and right edges of the game map are walls.
// Returns 0 if everything is correct, or 1 if incorrect.
int	check_walls_leftright(t_gamedata *gamedata)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (gamedata->map_layout[row][0] != '\0')
	{
		while (gamedata->map_layout[row][col] == ' ')
			col++;
		if (gamedata->map_layout[row][col] != '1')
			return (21);
		col = 0;
		while (gamedata->map_layout[row][col] != '\0')
			col++;
		if (gamedata->map_layout[row][col - 1] != '1')
			return (22);
		col = 0;
		row++;
	}
	return (0);
}

// This function checks if all the rules for the map design are respected.
// Returns 0 if everything is correct, or 1 if incorrect.
int	layout_logic_check(t_gamedata *gamedata)
{
	int	row;
	int	col;
	int	verdict;

	row = 0;
	col = 0;
	verdict = check_walls_leftright(gamedata);
	if (verdict == 0)
		verdict = check_walls_updown(gamedata);
	while (gamedata->map_layout[row][col] != '\0' && verdict == 0)
	{
		if (ft_strchr("NSEW0", gamedata->map_layout[row][col]) != NULL)
			verdict = check_for_nsewzero(gamedata, row, col);
		if (verdict != 0)
			return (verdict);
		col++;
		if (gamedata->map_layout[row][col] == '\0')
		{
			row++;
			col = 0;
		}
	}
	if (verdict == 0)
		verdict = check_player(gamedata);
	return (verdict);
}
