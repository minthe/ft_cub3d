/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_structure_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 15:36:28 by aionescu          #+#    #+#             */
/*   Updated: 2022/11/13 15:38:59 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// This function checks that the lines in the input file describing the layout
// of the map are unseparated and that they are the last ones in the file.
int	check_layout(char *start)
{
	int	index;

	index = 0;
	while (first_nonspace_char(start + index) != '\n'
		&& first_nonspace_char(start + index) != '\0')
	{
		if (first_nonspace_char(start + index) != '1')
			return (11);
		while (start[index] != '\n' && start[index] != '\0')
			index++;
		index++;
	}
	while (start[index] != '\0')
	{
		if (start[index] != ' ' && start[index] != '\t' && start[index] != '\n')
			return (12);
		index++;
	}
	return (0);
}

// This function checks if there are any characters other than digits,
// whitespaces and commas present in the lines describing the floor and ceiling.
int	check_clean_fc(char *start)
{
	int	index;

	index = 0;
	while (start[index] != '\n' && start[index] != '\0')
	{
		if (ft_isdigit(start[index]) == 0 && start[index] != ' '
			&& start[index] != '\t' && start[index] != ',')
			return (13);
		index++;
	}
	return (0);
}

// This function checks if the first non-space characters in every
// non-empty line in the input file match valid information type identifiers.
int	check_element_beginning(char *l)
{
	int	i;

	if (first_nonspace_char(l) == '\n'
		|| first_nonspace_char(l) == '\0')
		return (0);
	if (first_nonspace_char(l) == '1')
		return (check_layout(l));
	i = 0;
	while (l[i] == ' ' || l[i] == '\t')
		i++;
	if (ft_strncmp(l + i, "NO ", 3) != 0 && ft_strncmp(l + i, "NO\t", 3) != 0
		&& ft_strncmp(l + i, "SO ", 3) != 0 && ft_strncmp(l + i, "SO\t", 3) != 0
		&& ft_strncmp(l + i, "EA ", 3) != 0 && ft_strncmp(l + i, "EA\t", 3) != 0
		&& ft_strncmp(l + i, "WE ", 3) != 0 && ft_strncmp(l + i, "WE\t", 3) != 0
		&& ft_strncmp(l + i, "F ", 2) != 0 && ft_strncmp(l + i, "F\t", 2) != 0
		&& ft_strncmp(l + i, "C ", 2) != 0 && ft_strncmp(l + i, "C\t", 2) != 0)
		return (13);
	if (ft_strncmp(l + i, "F", 1) == 0 || ft_strncmp(l + i, "C", 1) == 0)
		return (check_clean_fc(l + i + 1));
	return (0);
}

// This function is basically the upper level of check_element_beginning()
int	check_lines(char *lines_as_str)
{
	int	index;

	index = 0;
	while (lines_as_str[index] != '\0')
	{
		if (first_nonspace_char(lines_as_str + index) != '\n'
			&& first_nonspace_char(lines_as_str + index) != '\0'
			&& first_nonspace_char(lines_as_str + index) != 'N'
			&& first_nonspace_char(lines_as_str + index) != 'S'
			&& first_nonspace_char(lines_as_str + index) != 'E'
			&& first_nonspace_char(lines_as_str + index) != 'W'
			&& first_nonspace_char(lines_as_str + index) != 'F'
			&& first_nonspace_char(lines_as_str + index) != 'C'
			&& first_nonspace_char(lines_as_str + index) != '1')
			return (10);
		if (check_element_beginning(lines_as_str + index) != 0)
			return (check_element_beginning(lines_as_str + index));
		while (lines_as_str[index] != '\n' && lines_as_str[index] != '\0')
			index++;
		index++;
	}
	return (0);
}

// This function checks the most basic requirements of the input file format.
// Returns an error code depending on what error was found first (0 = OK).
int	file_structure_check(char *filename)
{
	int		fd;
	char	*input_file;
	char	*temp_filedata;
	int		error_code;

	input_file = ft_strnstr(filename, ".cub", ft_strlen(filename));
	if (input_file != NULL && ft_strlen(input_file) == 4)
		fd = open(filename, O_RDONLY);
	else
		return (1);
	if (fd == -1)
		return (2);
	temp_filedata = read_to_string(fd);
	error_code = missing_info_check(temp_filedata);
	if (error_code == 0)
		error_code = check_lines(temp_filedata);
	free(temp_filedata);
	close(fd);
	return (error_code);
}
