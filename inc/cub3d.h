/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:27:58 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/14 22:47:37 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# define SCREEN_WIDTH 800
# define SCREEN_HEIGHT 640
# define W 119
# define A 97
# define S 115
# define D 100
# define R_ARROW 65363
# define L_ARROW 65361
# define ESC 65307
# define ROT_SPEED 0.02
# define FOV 90
# include "mlx/mlx.h"
# include "math.h"
# include "libft/libft.h"
# include <stdio.h>

//trying to make wall reading more efficient

typedef struct s_node
{
	int		x;
	int		y;
	char	is_wall;
	struct s_node	*next;
	
}t_node;

typedef struct s_img
{
	void	*img_ptr;
	void	*img_2ptr;
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
	void	*window2;
	int		cur_img;
}t_mlx;

typedef struct s_player
{
	char	orient;
	double	p_height;
	double	p_angle;
	double	radians;
	double	begin_x;
	double	begin_y;
	double	ray_pos;
	double	end_x;
	double	end_y;
	int		pos_x;
	int		pos_y;	
}t_player;

typedef struct s_map
{
	char	*d_map[100];
	int		**grid_dims;
	int		map_w;
	int		map_h;
	int		wall_sx;
	int		wall_sy;
	int		wall_ex;
	int		wall_ey;
	int		wall_height;
	int		modul_w;
	int		modul_h;
}t_map;

typedef struct s_var
{
	t_img		*img;
	t_mlx		*mlx;
	t_player	*plr;
	t_map		*map;
	t_node		*node;
}t_var;

// keys.c
int		x_window(t_var *var);
void	ft_w(t_var *var);
void	ft_a(t_var *var);
void	ft_s(t_var *var);
void	ft_d(t_var *var);
void	ft_lr_arrows(t_var *var, int arrow);

//main.c
void	ft_set_walls(t_var *var);
void	img_pix_put(t_var *var, int x, int y, int color);
void	render_background(t_var *var);
void	ft_player(t_var *var);
int		render(t_var *var);
int		ft_is_wall(t_var *var, int x, int y);
void	ft_put_player(t_var *var);
void	ft_ray(t_var *var, char nswe);

// ray.c
void	ft_draw_wall(t_var *var, int distance, int x_ing);
void	ft_cast_rayz(t_var *var, double radians);
#endif