/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:27:58 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/20 16:07:59 by dimbrea          ###   ########.fr       */
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
# define ROT_SPEED 0.02
# define TXT_W 	256
# define FOV 60

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

typedef struct s_node
{
	char			*data;
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

typedef struct s_linked_list {
	t_node	*head;
	t_node	*tail;
	t_node	*current;
}	t_linked_list;

typedef struct s_data
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				f;
	int				c;
	int				f_set;
	int				c_set;
	int				p_set;
	char			**map;
	t_linked_list	*map_lst;
	int				map_lines;
	int				map_col;
	int				err;
}t_data;

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
	double	c_angle;
	double	c_x;
	double	c_y;	
	double	camera_len;
	int		pos_x;
	int		pos_y;
	double	mid_ray;
	double	real_wall_height;
}t_player;

typedef struct s_map
{
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

typedef struct s_txt
{
	char	*tex_addr;
	void	*img_ptr;
	int		txt_width;
	int		txt_height;
	int		bpp_txt;
	int		sz_ln;
	int		endian_txt;
}t_txt;

typedef struct s_var
{
	t_img		*img;
	t_mlx		*mlx;
	t_player	*plr;
	t_map		*map;
	t_node		*node;
	t_data		*data;
	t_txt		*txt;
	char		*line;
	int			fd1;
}t_var;

// SRC
int		import_cub(t_var *var, char *argv, char *type);
void	import_map(t_var *var);
int		check_cub(t_data *data);
void	check_elements(t_data *data);
void	cleanup(t_var *var);
void	cpy_color_to_struct(t_var *var, int i, int *trgb, int *color_set);
int		atoi_cub(const char *str, int sign, int ret);
int		hasdigits(const char *str);

// SRC/LIST-UTILS
void	initialize_list(t_linked_list *list);
void	add_tail(t_linked_list *list, void *data);
int		count_linked_list(t_linked_list *list);
void	delete_list(t_linked_list *list);
void	display_linked_list(t_linked_list *list);
// keys.c
int		x_window(t_var *var);
void	ft_w(t_var *var);
void	ft_a(t_var *var);
void	ft_s(t_var *var);
void	ft_d(t_var *var);
void	ft_lr_arrows(t_var *var, int arrow);
// UTILS
void	error_msg_exit(char *str);
int		ft_open_file(int *fd, char *path, int opt);
int		init_struct(t_var *var);
int		ft_check_fileext(char *path, char *ext);
int		ft_is_whitespace(char *line);
char	ft_skip_whitespace(char *line);
int		ft_is_whitespace_char(char c);
char	*ft_strdup_cub(const char *s1, size_t i, size_t j);
char	*ft_strdup_map(t_var *var, size_t i, char *str);
void	ft_free_doublepoint(char **to_free);
int		is_ident_char(char c);
int		is_cf_char(char c);

// map utils
int		is_map_char(char c);
int		is_mchar(char c);
int		only_map_char(const char *str);
void	set_player(t_var *var, char c);
void	check_map_char(t_var *var, char c);
void	check_map(t_data *data);
int		max_col(t_linked_list *list);

//main.c
void	ft_set_walls(t_var *var);
void	img_pix_put(t_var *var, int x, int y, int color);
// void	render_background(t_var *var);
void	ft_player(t_var *var);
int		render(t_var *var);
int		ft_is_wall(t_var *var, int x, int y);
void	ft_put_player(t_var *var);
void	ft_ray(t_var *var, char nswe);
// void	draw_ln(t_var *var);// not needded
void	ft_cast_rayz(t_var *var);
void	ft_draw_wall(t_var *var, int distance, int x_ing, int coo_x);
void	ft_textures(t_var *var);
void	img_pix_put2(t_var *var, int x, int y, int color);

#endif
