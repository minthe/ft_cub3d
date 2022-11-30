/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_gamedata.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:16:21 by aionescu          #+#    #+#             */
/*   Updated: 2022/11/19 11:49:07 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// This function reads the contents of the input file into a string
// one character at a time and then returns the string.
char	*read_to_string(int fd)
{
	char	*final_str;
	char	*temp_str;
	int		index;

	temp_str = ft_calloc(1000000, sizeof(char));
	index = 0;
	while (read(fd, &(temp_str[index]), 1) > 0)
		index++;
	final_str = ft_strdup(temp_str);
	free(temp_str);
	return (final_str);
}

// This function calls the appropriate sub-function to process a line
// from the input file, based on the first non-space character it encounters.
// The return value is a character that represents what kind of information
// was detected and whether it has been processed successfully or not.
// Upper-case letter means success. Lower-case letter means failure.
char	process_valid_line(char *line, t_gamedata *gamedata)
{
	char	processed_type;

	if (first_nonspace_char(line) == 'N')
		processed_type = process_north(line, gamedata);
	else if (first_nonspace_char(line) == 'S')
		processed_type = process_south(line, gamedata);
	else if (first_nonspace_char(line) == 'E')
		processed_type = process_east(line, gamedata);
	else if (first_nonspace_char(line) == 'W')
		processed_type = process_west(line, gamedata);
	else if (first_nonspace_char(line) == 'F')
		processed_type = process_floor(line, gamedata);
	else if (first_nonspace_char(line) == 'C')
		processed_type = process_ceiling(line, gamedata);
	else if (first_nonspace_char(line) == '1')
		processed_type = process_layout(line, gamedata);
	else if (first_nonspace_char(line) == '\n')
		processed_type = '\n';
	else
		processed_type = '\0';
	return (processed_type);
}

// This function goes to the beginning of every line of the input file
// and attempts to gather game information from it.
// If any non-empty line fails to provide useful information,
// input processing stops and the value 1 gets returned.
int	populate_gamedata(char *source, t_gamedata *gamedata)
{
	char	processed_line_result;
	char	*position;

	position = source;
	while (*position != '\0')
	{
		processed_line_result = process_valid_line(position, gamedata);
		if (('A' <= processed_line_result && processed_line_result <= 'Z')
			|| processed_line_result == '\n')
		{
			if (processed_line_result == 'L')
				break ;
			while (*position != '\n' && *position != '\0')
				position++;
			if (*position != '\0')
				while (*position == '\n')
					position++;
		}
		else if (processed_line_result == 'm')
			return (layout_logic_check(gamedata));
		else
			return (38);
	}
	return (0);
}

// This function goes through the whole .cub file and populates the
// 'gamedata' variable that was passed as a parameter.
// If at any point one of the subsequently called functions
// considers a piece of data in the file invalid, then this function
// stops parsing the file and returns 1 to signal the error.
int	process_gamedata(char *map_file_path, t_gamedata *gamedata)
{
	int		fd;
	char	*input_file;
	char	*temp_filedata;
	int		processing_status;

	input_file = ft_strnstr(map_file_path, ".cub", ft_strlen(map_file_path));
	if (input_file != NULL && ft_strlen(input_file) == 4)
		fd = open(map_file_path, O_RDONLY);
	else
		return (1);
	if (fd == -1)
		return (2);
	temp_filedata = read_to_string(fd);
	processing_status = populate_gamedata(temp_filedata, gamedata);
	free(temp_filedata);
	close(fd);
	return (processing_status);
}
