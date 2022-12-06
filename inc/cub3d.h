/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:27:58 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/06 16:14:33 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define MAP_HEIGTH 24
# define MAP_WIDTH 24
# define SCREEN_WIDTH 640
# define SCREEN_HEIGHT 480
# define W 119
# define A 97
# define S 115
# define D 100
# define R_ARROW 65363
# define L_ARROW 65361
# define ESC 65307
# include "mlx/mlx.h"
# include "math.h"
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	void	*img_xpm;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
}t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*window;
	int 	cur_img;
}t_mlx;

typedef struct s_ray
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	time;
	double	pv_time;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	double	deltadist_x;
	double	deltadist_y;
	double	sidedist_x;
	double	sidedist_y;
	double	perpWallDist;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		lineHeight;
	int drawStart;
	int drawEnd;
}t_ray;

typedef struct s_var
{
	t_img	*img;
	t_ray	*ray;
	t_mlx	*mlx;
}t_var;

// keys.c
// int		x_window(t_mlx *mlx);
// void	ft_w(t_var *var);
// void	mlx_pixl_put(t_var *var, int x, int y, int color);

#endif