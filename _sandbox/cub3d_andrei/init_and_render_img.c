/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_render_img.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 20:17:39 by lorfanu           #+#    #+#             */
/*   Updated: 2022/11/14 18:32:28 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_init(t_gamedata *game)
{
	t_texture	*txt;

	txt = ft_calloc(sizeof(t_texture), 1);
	game->tex = txt;
	game->mlx = mlx_init();
	if (!game->mlx)
		game_exit(game, "Error: Mlx initialisation failed\n", EXIT_FAILURE);
	game->win = mlx_new_window(game->mlx, S_WIDTH, S_HEIGHT, "cub3D");
	if (!game->win)
		game_exit(game, "Error: Mlx_new_window() init failed\n", EXIT_FAILURE);
	game->tex->img_north = NULL;
	game->tex->img_south = NULL;
	game->tex->img_west = NULL;
	game->tex->img_east = NULL;
	game->tex->floor = create_trgb(0x0, game->map_floorcolor[0],
			game->map_floorcolor[1], game->map_floorcolor[2]);
	game->tex->ceiling = create_trgb(0x0, game->map_ceilingcolor[0],
			game->map_ceilingcolor[1], game->map_ceilingcolor[2]);
	img_init(game);
}

void	img_init(t_gamedata *game)
{
	game->img = malloc(sizeof(t_gamedata));
	game->img->imag = mlx_new_image(game->mlx, S_WIDTH, S_HEIGHT);
	if (game->img->imag == NULL)
		game_exit(game, "Error: Init. of new img failed\n", EXIT_FAILURE);
	game->img->addr = mlx_get_data_addr(game->img->imag,
			&game->img->bpp, &game->img->line_length, &game->img->endian);
	game->tex->img_north = img_xpm(game, game->map_nsew[0]);
	game->tex->img_south = img_xpm(game, game->map_nsew[1]);
	game->tex->img_west = img_xpm(game, game->map_nsew[2]);
	game->tex->img_east = img_xpm(game, game->map_nsew[3]);
}

t_img	*img_xpm(t_gamedata *game, char *elem_path)
{
	t_img	*img;

	img = malloc(sizeof(*img));
	img->imag = mlx_xpm_file_to_image(game->mlx, elem_path,
			&img->width, &img->height);
	if (!(img->imag))
	{
		free(img);
		ft_putstr_fd("Error. Invalid wall texture path\n", 1);
	}
	img->addr = mlx_get_data_addr(img->imag, &img->bpp,
			&img->line_length, &img->endian);
	return (img);
}

int	ft_get_pix_colour(t_img *tex, int x, int y)
{
	unsigned int	*addr;
	int				colour;

	addr = (unsigned int *)tex->addr;
	colour = 0;
	if (x >= 0 && y >= 0 && x <= tex->width && y <= tex->height)
		colour = ((unsigned int *)addr)[64 * y + x];
	return (colour);
}

int	render_image(t_gamedata *game)
{
	t_img		*image;

	image = put_floor_ceiling(game);
	raycast(game);
	mlx_put_image_to_window(game->mlx, game->win, image->imag, 0, 0);
	game->img = image;
	return (0);
}
