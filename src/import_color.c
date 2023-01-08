/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:04:17 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/08 14:31:07 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	cpy_color_to_struct(t_var *var, int i, int *trgb)
{
	char	**color_temp;

	i++;
	if (ft_is_whitespace_char(var->line[i]))
		i += ft_skip_whitespace(&var->line[i]);
	color_temp = ft_split(&var->line[i], ',');
	// NOTE check if split detected 2 commas and after that run tests if the strings contains only digits minus or plus sign and empty spaces. AFter that run a modified atoi that skips empty spaces to write the rgb values to the struct. after that use the create_trgb function to convert to int. but implement the limiters. all values get limited to the range of 0-255
	*trgb = create_trgb(255, 255, 255, 255);
	printf("$%s$\n", color_temp[0]);
	printf("%x\n", *trgb);
	var->data->f_set = 1;
	ft_free_doublepoint(color_temp);
}
