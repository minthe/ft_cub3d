/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:12:17 by aionescu          #+#    #+#             */
/*   Updated: 2022/11/19 11:49:45 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <math.h>

# define S_HEIGHT 480
# define S_WIDTH 640
# define TX_HEIGHT 64
# define TX_WIDTH 64

# define MAP_FACTOR 1

# define UP 1
# define DOWN -1
# define RIGHT 1
# define LEFT -1

# define KEY_RIGHT_ARROW 0xFF51
# define KEY_LEFT_ARROW 0xFF53
# define KEY_ESCAPE 0xFF1B

# define MOVE_SPEED 0.1
# define ROT_SPEED 0.1

typedef struct s_player
{
	char	facing;
	double	pos_x;
	double	pos_y;
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_img {
	void	*imag;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_texture {
	t_img	*img_north;
	t_img	*img_south;
	t_img	*img_west;
	t_img	*img_east;
	int		floor;
	int		ceiling;
}	t_texture;

typedef struct s_raycast
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	float	perp_wall_dist;
	int		map_x;
	int		map_y;
	int		hit;
	int		side;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
	int		step_x;
	int		step_y;
}	t_raycast;

typedef struct s_gamedata
{
	void		*mlx;
	void		*win;
	char		map_layout[100][100];
	char		**final_map;
	char		*map_nsew[4];
	int			map_floorcolor[3];
	int			map_ceilingcolor[3];
	t_texture	*tex;
	t_img		*img;
	t_player	*player;
	t_raycast	*ray;
}	t_gamedata;

/* main.c */
int		main(int argc, char **argv);
void	initialize_gamedata(t_gamedata *gamedata);

/* parsing_utils.c */
char	first_nonspace_char(char *line);
int		check_white_spaces(char c);
char	*get_next_line(int fd);

/* file_structure_check.c */
int		check_layout(char *start);
int		check_clean_fc(char *start);
int		check_element_beginning(char *l);
int		check_lines(char *lines_as_str);
int		file_structure_check(char *filename);

/* missing_info_check.c */
void	update_counters(char *line_start, int *counters);
int		missing_info_check(char *start);

/* layout_logic_check.c */
int		check_player(t_gamedata *gamedata);
int		check_for_NSEW0(t_gamedata *gamedata, int row, int col);
int		check_walls_updown(t_gamedata *gamedata);
int		check_walls_leftright(t_gamedata *gamedata);
int		layout_logic_check(t_gamedata *gamedata);

/* extra_checks.c */
int		analyse_split(char **split);
int		fc_data_check(char *filename);
int		extra_checks(t_gamedata *gamedata, char *filename);

/* final_map.c */
void	free_final_map(char **final_map);
void	generate_p_square(char **final_map, t_gamedata *gamedata, int x, int y);
void	generate_square(char **final_map, t_gamedata *gamedata, int x, int y);
char	**allocate_final_map(t_gamedata *gamedata, int factor);
char	**generate_final_map(t_gamedata *gamedata);

/* process_gamedata.c */
char	*read_to_string(int fd);
char	first_nonspace_char(char *line);
char	process_valid_line(char *line, t_gamedata *gamedata);
int		populate_gamedata(char *source, t_gamedata *gamedata);
int		process_gamedata(char *map_file_path, t_gamedata *gamedata);

/* process_nsew.c */
char	process_north(char *line, t_gamedata *gamedata);
char	process_south(char *line, t_gamedata *gamedata);
char	process_east(char *line, t_gamedata *gamedata);
char	process_west(char *line, t_gamedata *gamedata);

/* process_floor_ceiling.c */
int		check_if_nums_before_nl(char *start_ptr);
int		go_to_next_colorcode(char *line, int start);
int		get_colorcode(char *start_ptr);
char	process_floor(char *line, t_gamedata *gamedata);
char	process_ceiling(char *line, t_gamedata *gamedata);

/* process_layout.c */
int		calculate_longest_line(t_gamedata *gamedata);
char	make_rect_and_replace_space(t_gamedata *gamedata);
int		empty_space_ahead(char *start_ptr, int *pos);
char	process_layout(char *start, t_gamedata *gamedata);

/* parse_and_report.c */
void	report_error_batch_one(int error_code);
void	report_error_batch_two(int error_code);
void	report_error_batch_three(int error_code);
int		parse_and_report(int argc, char **argv, t_gamedata *gamedata);

/* player_movement.c */
int		update_player_pos(t_gamedata *gamedata);
void	player_init(t_gamedata *game, t_player *player);

/* render_floor_ceiling.c */
void	game_mlx_pixel_put(t_img *img, int x, int y, int color);
int		create_trgb(int t, int r, int g, int b);
void	render_ceiling(t_gamedata *game, int y1, int y2, int x);
void	render_floor(t_gamedata *game, int y1, int y2, int x);
t_img	*put_floor_ceiling(t_gamedata *game);

/* init_and_render_img.c */

void	game_init(t_gamedata *game);
void	img_init(t_gamedata *game);
t_img	*img_xpm(t_gamedata *game, char *elem_path);
int		render_image(t_gamedata *game);
int		ft_get_pix_colour(t_img *tex, int x, int y);

/* keyboard.c */
int		handle_game_keys(int key, t_gamedata *game);
int		game_xbutton(t_gamedata *game);
void	rotate_left(t_gamedata *game);
void	rotate_right(t_gamedata *game);

/* keyboard_utils.c */
void	move_right_d(t_gamedata *game);
void	move_left_a(t_gamedata *game);
void	move_forward_w(t_gamedata *game);
void	move_backward_s(t_gamedata *game);

/* handle_game_exit.c */
void	free_parsed_gamedata(t_gamedata *game);
void	free_textures(t_texture *txt, t_img *image, t_gamedata *game);
void	mlx_cleanup(t_gamedata *game);
void	game_exit(t_gamedata *game, char *err_msg, int exit_status);

/* raycast.c */
void	raycast(t_gamedata *game);
void	set_player_steps(t_raycast *ray, t_player *p);
void	calculate_draw_parameters(t_raycast *ray, t_gamedata *game);
void	draw_image(int x, t_raycast *ray, t_gamedata *ptr);
void	raycast_dda(t_raycast *ray, t_gamedata *game);

#endif
