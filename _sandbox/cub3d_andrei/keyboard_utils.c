/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:35:49 by lorfanu           #+#    #+#             */
/*   Updated: 2022/11/14 18:32:14 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** Player moves bacward if has no wall behind
*/
void	move_backward_s(t_gamedata *game)
{
	if (game->final_map[(int)game->player->pos_y][(int) \
		(game->player->pos_x - game->player->dir_x * MOVE_SPEED)] != '1')
		game->player->pos_x -= game->player->dir_x * MOVE_SPEED;
	if (game->final_map[(int)(game->player->pos_y - game->player->dir_y \
		* MOVE_SPEED)][(int)(game->player->pos_x)] != '1')
		game->player->pos_y -= game->player->dir_y * MOVE_SPEED;
}

/*
** Player moves forward if has no wall in front
*/
void	move_forward_w(t_gamedata *game)
{
	if (game->final_map[(int)game->player->pos_y][(int) \
		(game->player->pos_x + game->player->dir_x * MOVE_SPEED)] != '1')
		game->player->pos_x += game->player->dir_x * MOVE_SPEED;
	if (game->final_map[(int)(game->player->pos_y + game->player->dir_y \
		* MOVE_SPEED)][(int)(game->player->pos_x)] != '1')
		game->player->pos_y += game->player->dir_y * MOVE_SPEED;
}

/*
** Player moves to the left if has no wall to the left
*/
void	move_left_a(t_gamedata *game)
{
	if (game->final_map[(int)game->player->pos_y][(int) \
		(game->player->pos_x - game->player->plane_x * MOVE_SPEED)] != '1')
		game->player->pos_x -= game->player->plane_x * MOVE_SPEED;
	if (game->final_map[(int)(game->player->pos_y - \
		game->player->plane_y * MOVE_SPEED)][(int)(game->player->pos_x)] != '1')
		game->player->pos_y -= game->player->plane_y * MOVE_SPEED;
}

/*
** Player moves to the right if has no wall to the right
*/
void	move_right_d(t_gamedata *game)
{
	if (game->final_map[(int)game->player->pos_y][(int) \
		(game->player->pos_x + game->player->plane_x * MOVE_SPEED)] != '1')
		game->player->pos_x += game->player->plane_x * MOVE_SPEED;
	if (game->final_map[(int)(game->player->pos_y + \
		game->player->plane_y * MOVE_SPEED)][(int)(game->player->pos_x)] != '1')
		game->player->pos_y += game->player->plane_y * MOVE_SPEED;
}
