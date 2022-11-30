/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:56:25 by lorfanu           #+#    #+#             */
/*   Updated: 2022/11/14 18:32:22 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	handle_game_keys(int key, t_gamedata *game)
{
	if (key == 'w' || key == 'W')
		move_forward_w(game);
	else if (key == 's' || key == 'S')
		move_backward_s(game);
	else if (key == 'd' || key == 'D')
		move_right_d(game);
	else if (key == 'a' || key == 'A')
		move_left_a(game);
	else if (key == KEY_RIGHT_ARROW)
		rotate_right(game);
	else if (key == KEY_LEFT_ARROW)
		rotate_left(game);
	if (key == KEY_ESCAPE)
		game_exit(game, "\nThanks for playing\n\n", EXIT_SUCCESS);
	return (0);
}

int	game_xbutton(t_gamedata *game)
{
	game_exit(game, "\nThanks for playing\n\n", EXIT_SUCCESS);
	return (0);
}

void	rotate_right(t_gamedata *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player->dir_x;
	game->player->dir_x = game->player->dir_x * cos(ROT_SPEED) \
		- game->player->dir_y * sin(ROT_SPEED);
	game->player->dir_y = old_dir_x * sin(ROT_SPEED) \
		+ game->player->dir_y * cos(ROT_SPEED);
	old_plane_x = game->player->plane_x;
	game->player->plane_x = game->player->plane_x * cos(ROT_SPEED) \
		- game->player->plane_y * sin(ROT_SPEED);
	game->player->plane_y = old_plane_x * sin(ROT_SPEED) + \
		game->player->plane_y * cos(ROT_SPEED);
}

void	rotate_left(t_gamedata *game)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = game->player->dir_x;
	game->player->dir_x = game->player->dir_x * \
		cos(-ROT_SPEED) - game->player->dir_y * sin(-ROT_SPEED);
	game->player->dir_y = old_dir_x * \
		sin(-ROT_SPEED) + game->player->dir_y * cos(-ROT_SPEED);
	old_plane_x = game->player->plane_x;
	game->player->plane_x = game->player->plane_x * \
		cos(-ROT_SPEED) - game->player->plane_y * sin(-ROT_SPEED);
	game->player->plane_y = old_plane_x * \
		sin(-ROT_SPEED) + game->player->plane_y * cos(-ROT_SPEED);
}
