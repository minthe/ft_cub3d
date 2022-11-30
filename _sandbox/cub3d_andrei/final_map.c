/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:45:55 by aionescu          #+#    #+#             */
/*   Updated: 2022/11/13 16:35:36 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// This function iterates through all the *chars contained in **final_map,
// freeing them, and finally frees **final_map itself.
void	free_final_map(char **final_map)
{
	int	index;

	index = 0;
	while (final_map[index] != NULL)
	{
		free(final_map[index]);
		index++;
	}
	free(final_map[index]);
	free(final_map);
}

// This function generates a square of '0's in the final map, but with one
// special char in the center describing the position and facing of the player.
void	generate_p_square(char **final_map, t_gamedata *gamedata, int x, int y)
{
	int	row;
	int	col;

	row = y * MAP_FACTOR;
	col = x * MAP_FACTOR;
	while (row < y * MAP_FACTOR + MAP_FACTOR)
	{
		while (col < x * MAP_FACTOR + MAP_FACTOR)
		{
			if (col == x * MAP_FACTOR + MAP_FACTOR / 2
				&& row == y * MAP_FACTOR + MAP_FACTOR / 2)
				final_map[row][col] = gamedata->map_layout[y][x];
			else
				final_map[row][col] = '0';
			col++;
		}
		col = x * MAP_FACTOR;
		row++;
	}
}

// This function generates a MAP_FACTOR * MAP_FACTOR square in the final map
// formed out of the char from the initial map at that position.
void	generate_square(char **final_map, t_gamedata *gamedata, int x, int y)
{
	int	row;
	int	col;

	row = y * MAP_FACTOR;
	col = x * MAP_FACTOR;
	while (row < y * MAP_FACTOR + MAP_FACTOR)
	{
		while (col < x * MAP_FACTOR + MAP_FACTOR)
		{
			final_map[row][col] = gamedata->map_layout[y][x];
			col++;
		}
		col = x * MAP_FACTOR;
		row++;
	}
}

// This function calculates the exact number of bytes necessary
// for the final map and allocates and assembles it in a **char.
char	**allocate_final_map(t_gamedata *gamedata, int factor)
{
	char	**allocated_map;
	int		x;
	int		y;
	int		side_size;

	x = 0;
	y = 0;
	while (gamedata->map_layout[0][x] != '\0')
		x++;
	while (gamedata->map_layout[y][0] != '\0')
		y++;
	side_size = y * factor;
	allocated_map = ft_calloc(y * factor + 1 + 1, sizeof(char *));
	y = 0;
	while (y < side_size)
	{
		allocated_map[y] = ft_calloc(x * factor + 1, sizeof(char));
		y++;
	}
	allocated_map[y] = ft_calloc(x * factor + 1, sizeof(char));
	allocated_map[y + 1] = NULL;
	return (allocated_map);
}

// This chain of functions generates a memory-efficient version
// of the initial map that has a higher "resolution" defined by MAP_FACTOR.
char	**generate_final_map(t_gamedata *gamedata)
{
	char	**final_map;
	int		x;
	int		y;

	final_map = allocate_final_map(gamedata, MAP_FACTOR);
	x = 0;
	y = 0;
	while (gamedata->map_layout[y][x] != '\0')
	{
		while (gamedata->map_layout[y][x] != '\0')
		{
			if (gamedata->map_layout[y][x] == 'N'
				|| gamedata->map_layout[y][x] == 'S'
				|| gamedata->map_layout[y][x] == 'E'
				|| gamedata->map_layout[y][x] == 'W')
				generate_p_square(final_map, gamedata, x, y);
			else
				generate_square(final_map, gamedata, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (final_map);
}
