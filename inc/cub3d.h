/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:27:58 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/04 10:57:54 by vfuhlenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include "libft/ft_printf/ft_printf.h"
# include <math.h>
# include <stdio.h>

typedef struct s_map
{
	char	*tex[3]; // N,E,S,W char *path_to_file.xmp
	int		*color[1]; // F,C (int *)(unsigned char [4]){r, g, b, a})
	char	**data;
}t_map;

typedef struct s_cub
{
	void		*mlx;
	s_struct	*s_map;
}t_cub;

// returns hex decoded rgba values as int pointer
int	*ft_itox_rgba(int r, int g, int b, int a);

#endif