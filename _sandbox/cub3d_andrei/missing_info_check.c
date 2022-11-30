/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   missing_info_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 18:37:55 by aionescu          #+#    #+#             */
/*   Updated: 2022/11/13 16:41:04 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// This function is used to increment the counter for each type of
// line of information necessary to render the game area.
void	update_counters(char *line_start, int *counters)
{
	if (first_nonspace_char(line_start) == 'N')
		counters[0]++;
	else if (first_nonspace_char(line_start) == 'S')
		counters[1]++;
	else if (first_nonspace_char(line_start) == 'E')
		counters[2]++;
	else if (first_nonspace_char(line_start) == 'W')
		counters[3]++;
	else if (first_nonspace_char(line_start) == 'F')
		counters[4]++;
	else if (first_nonspace_char(line_start) == 'C')
		counters[5]++;
	else if (first_nonspace_char(line_start) == '1')
		counters[6]++;
}

// This function checks if there is any line of information missing
// from the input file, that would make it impossible to render the game area.
// Returns 0 if there is nothing missing, or
// returns 1 - 7 depending on the first identified missing line of information.
int	missing_info_check(char *start)
{
	int	index;
	int	elements[7];

	index = 0;
	while (index < 7)
	{
		elements[index] = 0;
		index++;
	}
	index = 0;
	while (first_nonspace_char(start + index) != '\0')
	{
		update_counters(start + index, elements);
		while (start[index] != '\n' && start[index] != '\0')
			index++;
		index++;
	}
	index = 0;
	while (index < 7)
	{
		if (elements[index] == 0)
			return (index + 3);
		index++;
	}
	return (0);
}
