/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:27:58 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/05 09:13:22 by vfuhlenb         ###   ########.fr       */
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

# include <math.h>
# include <stdio.h>

typedef struct s_map
{
	char	*tex_n; // N,E,S,W char *path_to_file.xmp
	char	*tex_e;
	char	*tex_s;
	char	*tex_w;
	int		*color_f; // F,C (int *)(unsigned char [4]){r, g, b, a})
	int		*color_c;
	char	**data; // valid map data
}t_map;

typedef struct s_mlx
{
	void	*ptr;
	void	*window;
	void	*img;
}t_mlx;

typedef struct s_var
{
	int			posx;
	int			posy;
	int			player_pos[2];
	s_struct	*s_map;
	t_mlx		*mlx;
}t_var;

// returns hex decoded rgba values as int pointer
int	*ft_itox_rgba(int r, int g, int b, int a);

#endif