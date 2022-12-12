/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vfuhlenb <vfuhlenb@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:27:58 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/12 11:53:44 by vfuhlenb         ###   ########.fr       */
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

typedef struct s_data
{
	char	*no; // N,E,S,W char *path_to_file.xmp
	char	*so;
	char	*we;
	char	*ea;
	int		*f; // F,C (int *)(unsigned char [4]){r, g, b, a})
	int		*c;
	char	**map; // valid map data
}t_data;

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
	t_data		*data;
	t_mlx		*mlx;
	char		*line;
	int			fd1;
}t_var;

// SRC
int		import_cub(t_var *var, char *argv, char *type);
int		check_cub(t_data *data);
void	err_elements(t_data *data);
void	copy_element(t_var *var);

// UTILS
int		ft_open_file(int *fd, char *path, int opt);
int		*ft_itox_rgba(int r, int g, int b, int a);
int		init_struct(t_var *var);
int		ft_check_fileext(char *path, char *ext);
int		ft_is_whitespace(char *line);
char	ft_skip_whitespace(char *line);
// skip whitespace

#endif