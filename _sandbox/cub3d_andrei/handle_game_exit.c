/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_game_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 16:49:04 by lorfanu           #+#    #+#             */
/*   Updated: 2022/11/14 20:16:43 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_parsed_gamedata(t_gamedata *game)
{
	if (game->map_nsew[0])
		free(game->map_nsew[0]);
	if (game->map_nsew[1])
		free(game->map_nsew[1]);
	if (game->map_nsew[2])
		free(game->map_nsew[2]);
	if (game->map_nsew[3])
		free(game->map_nsew[3]);
	if (game->final_map)
		free_final_map(game->final_map);
}

void	free_textures(t_texture *txt, t_img *image, t_gamedata *game)
{
	if (txt->img_north)
		mlx_destroy_image(game->mlx, txt->img_north->imag);
	if (txt->img_south)
		mlx_destroy_image(game->mlx, txt->img_south->imag);
	if (txt->img_east)
		mlx_destroy_image(game->mlx, txt->img_east->imag);
	if (txt->img_west)
		mlx_destroy_image(game->mlx, txt->img_west->imag);
	if (image->imag)
		mlx_destroy_image(game->mlx, image->imag);
	if (txt->img_north)
		free(txt->img_north);
	if (txt->img_south)
		free(txt->img_south);
	if (txt->img_east)
		free(txt->img_east);
	if (txt->img_west)
		free(txt->img_west);
	free(game->tex);
}

void	mlx_cleanup(t_gamedata *game)
{
	if (game->tex)
		free_textures(game->tex, game->img, game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
}

void	game_exit(t_gamedata *game, char *err_msg, int exit_status)
{
	if (game)
		mlx_cleanup(game);
	if (err_msg)
		ft_putstr_fd(err_msg, 1);
	free_parsed_gamedata(game);
	if (game->mlx)
		free(game->mlx);
	if (game->img)
		free(game->img);
	exit(exit_status);
}
