/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:27:58 by vfuhlenb          #+#    #+#             */
/*   Updated: 2023/01/28 17:02:47 by dimbrea          ###   ########.fr       */
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
# define M 109
# define R_ARROW 65363
# define L_ARROW 65361
# define ESC 65307
# define TXT_W 64
# define FOV 60

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <limits.h>
# include <math.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

typedef struct s_node
{
	char			*data;
	struct s_node	*next;
}t_node;

typedef struct s_img
{
	void	*structure;
	char	*addr;
	void	*img_xpm;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
	int		color;
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
	char			color_c;
	char			*buffer;
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
	double	p_angle;
	double	radians;
	double	ray_pos;
	int		pos_x;
	int		pos_y;
	int		mini_x;
	int		mini_y;
}t_player;

typedef struct s_map
{
	int		map_w;
	int		map_h;
	int		wall_height;
	int		modul_w;
	int		modul_h;
	int		minimap;
	int		is_w_or_e;
}t_map;

typedef struct s_txt
{
	char	*tex_addr;
	int		txt_width;
	int		txt_height;
	int		bpp_txt;
	int		sz_ln;
	int		endian_txt;
	void	*texture_no;
	void	*texture_so;
	void	*texture_ea;
	void	*texture_we;
	double	ray_pos;
	double	ray_angle;
	double	ray_distance;
	double	ray_x;
	double	ray_y;
	double	ray_dx;
	double	ray_dy;
	int		ray_x_ing;
	double	dist_pos;
	double	dist_angle;
	double	dist_distance;
	double	dist_x;
	double	dist_y;
	double	dist_dx;
	double	dist_dy;
	int		dist_x_ing;
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
	char		*buffer_static;
	char		*line;
	int			fd1;
	int			wall_td;
	int			wall_ty;
	int			wall_c;
	double		wall_ph;
	int			wall_txt_y;
}t_var;

void	ft_get_wall_orient(t_var *var, double x, double y);
// SRC
int		import_cub(t_var *var, char *argv, char *type);
void	import_map(t_var *var);
int		check_cub(t_data *data);
void	check_elements(t_var *var);
void	cleanup(t_var *var);
void	cpy_color_to_struct(t_var *var, int i, int *trgb, char c);
int		atoi_cub(const char *str, int sign, int ret, t_var *var);
int		hasdigits(t_var *var, const char *str, char c);
int		check_double_identifier(t_var *var);
int		unknown_key(char *line);
void	copy_map_line(t_var *var);

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
void	ft_m(t_var *var);
void	ft_lr_arrows(t_var *var, int arrow);
// UTILS
void	error_msg_exit(t_var *var, char *str);
void	error_msg(char *str);
void	error_exit(t_var *var);
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
void	check_map_player(t_var *var);
void	check_map(t_var *var);
int		max_col(t_linked_list *list);

// GetNextLine
char	*get_next_line(t_var *var);
int		read_file(int fd, char **buffer, char **buffer_static, char **line);
char	*get_line(char **line, char **buffer_static);
size_t	ft_strlen_gnl(const char *s);
char	*ft_strdup_gnl(const char *s1);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);

//main.c
void	ft_set_walls(t_var *var);
void	img_pix_put(t_var *var, int x, int y, int color);
void	ft_player(t_var *var);
int		render(t_var *var);
int		ft_is_wall(t_var *var, int x, int y);
void	ft_put_player(t_var *var);
void	ft_ray(t_var *var, char nswe);
void	ft_cast_rayz(t_var *var);
void	ft_textures(t_var *var);
//exec.c
int		keypress(int key, t_var *var);
void	ft_map_size(t_var *var);
void	ft_starting_angle(t_var *var, char nswe);
double	degree_to_radians(double degree);
int		ft_get_pxl_color(t_var *var, double x, double y);
void	ft_get_dist(t_var *var);
void	ft_draw_wall(t_var *var, int distance, int x_ing, int coo_x);
void	ft_free_struct(t_var *var);

#endif
