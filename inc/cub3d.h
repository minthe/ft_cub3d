/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:27:58 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/06 21:19:35 by vfuhlenb         ###   ########.fr       */
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
# include "get_next_line/get_next_line.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>

typedef struct s_map
{
	char	*tex_n; // N,E,S,W char *path_to_file.xmp
	char	*tex_e;
	char	*tex_s;
	char	*tex_w;
	char	**infos; // alloziiere 6 pointer für alle infos und setze sie auf -1 und iteriere sie durch. beginnend bei den texturen, die übrigen 2 sind dann die farben
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
	t_map		*map;
	t_mlx		*mlx;
}t_var;

// SRC
void	import_map(t_var *var, char *path, char *type);

// UTILS
int		*ft_itox_rgba(int r, int g, int b, int a);
void	init_struct(t_var *var);
// skip whitespace

#endif