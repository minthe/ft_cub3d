/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:04:17 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/06 17:33:57 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	cpy_color_to_struct(t_var *var, int i, int *trgb)
{
	i++;
	if (ft_is_whitespace_char(var->line[i]))
		i += ft_skip_whitespace(&var->line[i]);
	*trgb = create_trgb(255, 255, 255, 255);
	printf("$%s$\n", &var->line[i]);
	printf("%x\n", *trgb);
	var->data->f_set = 1;
}
