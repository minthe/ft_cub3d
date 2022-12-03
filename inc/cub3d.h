/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:27:58 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/03 17:43:10 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define S_HEIGTH 1440
# define S_WIDTH 2160
# define W 25
# define A 38
# define S 39
# define D 40
# define R_ARROW 113
# define L_ARROW 114
# define ESC 9
# include "mlx/mlx.h"
# include "math.h"
# include "libft/libft.h"

typedef struct s_mlx
{
	void	*ptr;
	void	*window;
	void	*img;
}t_mlx;

typedef struct s_var
{
	int		posx;
	int		posy;
	int		player_pos[2];
	t_mlx	*mlx;
}t_var;



#endif