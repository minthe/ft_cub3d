/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:13:55 by aionescu          #+#    #+#             */
/*   Updated: 2022/11/30 23:06:18 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// This function checks if there are too many or too few
// commas in the input file or if there is a color code missing.
int	analyse_split(char **split)
{
	int	index;
	int	error_code;

	error_code = 0;
	index = 0;
	while (split[index] != NULL)
		index++;
	if (index > 5)
		error_code = 36;
	else if (index < 5)
		error_code = 37;
	index = 0;
	while (split[index] != NULL)
	{
		if (ft_strlen(split[index]) == 0)
			error_code = 37;
		free(split[index]);
		index++;
	}
	free(split[index]);
	return (error_code);
}

// This function checks the validity of the floor and ceiling information
// based on the number and positioning of the commas in the input file.
int	fc_data_check(char *filename)
{
	int		fd;
	char	*temp_filedata;
	char	**split;
	int		error_code;

	fd = open(filename, O_RDONLY);
	temp_filedata = read_to_string(fd);
	split = ft_split(temp_filedata, ',');
	error_code = analyse_split(split);
	free(temp_filedata);
	free(split);
	close(fd);
	return (error_code);
}

// This function checks if the provided texture paths are accessible.
int	extra_checks(t_gamedata *gamedata, char *filename)
{
	int	index;
	int	fd;

	fd = 0;
	index = 0;
	while (index < 4)
	{
		fd = open(gamedata->map_nsew[index], O_RDONLY);
		if (fd == -1)
			return (31 + index);
		close(fd);
		index++;
	}
	if (fc_data_check(filename) != 0)
		return (fc_data_check(filename));
	index = 0;
	while (index < 3)
	{
		if (gamedata->map_floorcolor[index] == 666
			|| gamedata->map_ceilingcolor[index] == 666)
			return (37);
		index++;
	}
	return (0);
}
