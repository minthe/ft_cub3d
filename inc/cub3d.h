/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:27:58 by vfuhlenb          #+#    #+#             */
/*   Updated: 2022/12/13 10:38:15 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 600
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
	void	*structure;
	char	*addr;
	void	*img_xpm;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	int		color;
	int		begin_x;
	int		begin_y;
}t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*window;
	int		cur_img;
}t_mlx;

typedef struct s_player
{
	char	orient;
	double	pos_x;
	double	pos_y;
	
}t_player;

typedef struct s_ray
{
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
	double	frametime;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		lineHeight;
	int		drawStart;
	int		drawEnd;
}t_ray;

typedef struct s_map
{
	char	*d_map[100];
	int		map_w;
	int		map_h;
	int		modul_w;
	int		modul_h;
}t_map;

typedef struct s_var
{
	t_img		*img;
	t_ray		*ray;
	t_mlx		*mlx;
	t_player	*plr;
	t_map		*map;
}t_var;

// keys.c
int		x_window(t_var *var);
void	ft_w(t_var *var);
void	ft_a(t_var *var);
void	ft_s(t_var *var);
void	ft_d(t_var *var);

//main.c
void	ft_set_walls(t_var *var);
void	img_pix_put(t_var *var, int x, int y, int color);
void	render_background(t_var *var);
void	ft_player(t_var *var);
int		render(t_var *var);
int		ft_is_wall(t_var *var, int x, int y);
void	ft_put_player(t_var *var);
void	ft_ray(t_var *var, char nswe);

#endif