/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_nsew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:09:49 by aionescu          #+#    #+#             */
/*   Updated: 2022/10/14 19:46:53 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// This function checks if the line passed as a parameter starts with 'NO ',
// preallocates a string of size 1000 for the address of the wall texture,
// copies the text from the line into it and assigns it to gamedata->map_nsew[0]
// Returns 'N' in case of success, or 'n' in case of failure.
char	process_north(char *line, t_gamedata *gamedata)
{
	int		index;
	int		index_map_north;

	index = 0;
	while (line[index] != 'N')
		index++;
	if (line[index + 1] == 'O' && line[index + 2] == ' ')
	{
		index = index + 2;
		while (line[index] == ' ' || line[index] == '\t')
			index++;
		gamedata->map_nsew[0] = ft_calloc(1000, sizeof(char));
		index_map_north = 0;
		while (line[index] != ' ' && line[index] != '\t' && line[index] != '\n')
		{
			gamedata->map_nsew[0][index_map_north] = line[index];
			index_map_north++;
			index++;
		}
	}
	else
		return ('n');
	return ('N');
}

// Analogous to process_north()
char	process_south(char *line, t_gamedata *gamedata)
{
	int	index;
	int	index_map_south;

	index = 0;
	while (line[index] != 'S')
		index++;
	if (line[index + 1] == 'O' && line[index + 2] == ' ')
	{
		index = index + 2;
		while (line[index] == ' ' || line[index] == '\t')
			index++;
		gamedata->map_nsew[1] = ft_calloc(1000, sizeof(char));
		index_map_south = 0;
		while (line[index] != ' ' && line[index] != '\t' && line[index] != '\n')
		{
			gamedata->map_nsew[1][index_map_south] = line[index];
			index_map_south++;
			index++;
		}
	}
	else
		return ('s');
	return ('S');
}

// Analogous to process_north()
char	process_east(char *line, t_gamedata *gamedata)
{
	int	index;
	int	index_map_east;

	index = 0;
	while (line[index] != 'E')
		index++;
	if (line[index + 1] == 'A' && line[index + 2] == ' ')
	{
		index = index + 2;
		while (line[index] == ' ' || line[index] == '\t')
			index++;
		gamedata->map_nsew[2] = ft_calloc(1000, sizeof(char));
		index_map_east = 0;
		while (line[index] != ' ' && line[index] != '\t' && line[index] != '\n')
		{
			gamedata->map_nsew[2][index_map_east] = line[index];
			index_map_east++;
			index++;
		}
	}
	else
		return ('e');
	return ('E');
}

// Analogous to process_north()
char	process_west(char *line, t_gamedata *gamedata)
{
	int	index;
	int	index_map_west;

	index = 0;
	while (line[index] != 'W')
		index++;
	if (line[index + 1] == 'E' && line[index + 2] == ' ')
	{
		index = index + 2;
		while (line[index] == ' ' || line[index] == '\t')
			index++;
		gamedata->map_nsew[3] = ft_calloc(1000, sizeof(char));
		index_map_west = 0;
		while (line[index] != ' ' && line[index] != '\t' && line[index] != '\n')
		{
			gamedata->map_nsew[3][index_map_west] = line[index];
			index_map_west++;
			index++;
		}
	}
	else
		return ('w');
	return ('W');
}
