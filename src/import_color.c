/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:04:17 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/22 18:35:11 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	count_values(char **color_temp)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (color_temp[i] != NULL)
	{
		if (!ft_is_whitespace(color_temp[i]))
			count++;
		i++;
	}
	return (count);
}

static void	del_newline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (ft_strncmp(&line[i], "\n", 1) == 0)
			line[i] = '\0';
		i++;
	}
}

// imports color values to struct
void	cpy_color_to_struct(t_var *var, int i, int *trgb, int *color_set)
{
	char	**color_temp;

	del_newline(var->line);
	if (ft_is_whitespace_char(var->line[i]))
		i += ft_skip_whitespace(&var->line[i]);
	color_temp = ft_split(&var->line[i], ',');
	if (count_values(color_temp) == 3)
	{
		*trgb = create_trgb(255, atoi_cub(color_temp[0], 1, 0), \
		atoi_cub(color_temp[1], 1, 0), \
		atoi_cub(color_temp[2], 1, 0));
	}
	else if (count_values(color_temp) < 3)
		error_msg_exit("F/C: less than 3 color values");
	else if (count_values(color_temp) > 3)
		error_msg_exit("F/C: more than 3 color values");
	if (color_temp)
		ft_free_doublepoint(color_temp);
	*color_set = 1;
}
