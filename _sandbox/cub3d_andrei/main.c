/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:09:18 by aionescu          #+#    #+#             */
/*   Updated: 2022/11/19 11:49:54 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_gamedata(t_gamedata *gamedata)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < 100)
	{
		while (j++ < 100)
			gamedata->map_layout[i - 1][j - 1] = '\0';
		j = 0;
	}
	while (j++ < 4)
		gamedata->map_nsew[j - 1] = NULL;
	j = 0;
	while (j++ < 3)
		gamedata->map_floorcolor[j - 1] = 666;
	j = 0;
	while (j++ < 3)
		gamedata->map_ceilingcolor[j - 1] = 666;
}

int	main(int argc, char **argv)
{
	t_gamedata	gamedata;
	t_player	player;

	gamedata.player = &player;
	initialize_gamedata(&gamedata);
	if (parse_and_report(argc, argv, &gamedata) != 0)
	{
		free_parsed_gamedata(&gamedata);
		return (1);
	}
	gamedata.final_map = generate_final_map(&gamedata);
	player_init(&gamedata, &player);
	game_init(&gamedata);
	mlx_loop_hook(gamedata.mlx, render_image, &gamedata);
	mlx_hook(gamedata.win, 17, 1L << 0, game_xbutton, &gamedata);
	mlx_hook(gamedata.win, 2, 1L << 0, handle_game_keys, &gamedata);
	mlx_loop(gamedata.mlx);
	return (0);
}
