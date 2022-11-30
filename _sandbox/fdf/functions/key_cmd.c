/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 14:18:43 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/05/21 17:12:32 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	reset_values(t_fdf *data)
{
	data->scale = 70;
	data->offset_x = data->win_size_x / 5;
	data->offset_y = (data->win_size_y / 3) * -1;
	data->scale_h = 1;
}

int	key_cmd(int key, t_fdf *data)
{
	if (key == XK_Escape)
		close_fdf(data);
	else if (key == XK_i)
		data->scale += 10;
	else if (key == XK_o)
		data->scale -= 10;
	else if (key == XK_w)
		data->offset_y -= 100;
	else if (key == XK_s)
		data->offset_y += 100;
	else if (key == XK_a)
		data->offset_x -= 100;
	else if (key == XK_d)
		data->offset_x += 100;
	else if (key == XK_plus)
		data->scale_h += 1;
	else if (key == XK_minus)
		data->scale_h -= 1;
	else if (key == XK_r)
		reset_values(data);
	render_fdf(data);
	return (0);
}
