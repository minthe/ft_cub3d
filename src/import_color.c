/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:04:17 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/08 15:20:57 by vfuhlenb         ###   ########.fr       */
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
	// TODO check if there are only 3 color values present
	*trgb = create_trgb(255, atoi_cub(var, color_temp[0]), \
	atoi_cub(var, color_temp[1]), atoi_cub(var, color_temp[2]));
	printf("$%s$\n", color_temp[0]);
	printf("%x\n", *trgb);
	printf("err_color: %d\n", var->data->err_color);
	var->data->f_set = 1;
	ft_free_doublepoint(color_temp);
}
