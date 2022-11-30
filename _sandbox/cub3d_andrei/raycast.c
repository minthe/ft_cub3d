/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:37:57 by lorfanu           #+#    #+#             */
/*   Updated: 2022/11/17 17:38:16 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** function to calculate the steps taken by the player and initial side_dist
** DeltaDistX and deltaDistY are the distance the ray has to travel to go from 
** 1 x-side to the next x-side, or from 1 y-side to the next y-side;
** LEFT - WEST
** RIGHT - EAST
** DOWN - SOUTH
** UP - NORTH
** SideDistX and sideDistY are initially the distance the ray has to travel
** from its start position to the first x-side and the first y-side
** Later in the code they will be incremented while steps are taken.
*/
void	set_player_steps(t_raycast *ray, t_player *p)
{
	ray->delta_dist_x = ((float)(sqrt(1 + (ray->ray_dir_y * \
		ray->ray_dir_y) / (ray->ray_dir_x * ray->ray_dir_x))));
	ray->delta_dist_y = ((float)(sqrt(1 + (ray->ray_dir_x * \
		ray->ray_dir_x) / (ray->ray_dir_y * ray->ray_dir_y))));
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = LEFT;
		ray->side_dist_x = (p->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = RIGHT;
		ray->side_dist_x = (ray->map_x + 1.0 - p->pos_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = DOWN;
		ray->side_dist_y = (p->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = UP;
		ray->side_dist_y = (ray->map_y + 1.0 - p->pos_y) * ray->delta_dist_y;
	}
}

/*
** Calculating: 
** Distance of perpendicular ray;
** Lowest (draw_start) and highest (draw_end) pixel to fill in current stripe
** by using the height of line to draw on screen(=S_HEIGHT / perp_wall_dist);
** The value of wallx - where exactly the wall was hit
** Tex_x is the x coordinate on texture
*/
void	calculate_draw_parameters(t_raycast *ray, t_gamedata *game)
{
	if (ray->side == 0)
		ray->perp_wall_dist = \
			(ray->map_x - game->player->pos_x + \
			(1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - game->player->pos_y + \
			(1 - ray->step_y) / 2) / ray->ray_dir_y;
	ray->draw_start = -(S_HEIGHT / ray->perp_wall_dist) / 2 + S_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (S_HEIGHT / ray->perp_wall_dist) / 2 + S_HEIGHT / 2;
	if (ray->draw_end >= S_HEIGHT)
		ray->draw_end = S_HEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = game->player->pos_y + \
			ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = game->player->pos_x + \
			ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)TX_WIDTH);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		ray->tex_x = TX_WIDTH - ray->tex_x - 1;
}

/*
** ray calculations & DDA (jumping to next square: in x or y direction:
** side 0 - EAST, WEST, side 1 - NORTH, SOUTH) until it hits a wall
** (finding in which square to move to when collision happens)
*/

void	raycast_dda(t_raycast *ray, t_gamedata *game)
{
	ray->hit = 0;
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (game->final_map[(int)ray->map_y][(int)ray->map_x] \
			&& game->final_map[(int)ray->map_y][(int)ray->map_x] == '1')
			ray->hit = 1;
	}
}

/*
** Casting the tx coord. to int and masking with (txHeight-1) in case of overflow
** Calculating texture position and rendering the pixels accordingly, by using
** the side variable & the coordinates of the player in relation to the map
*/
void	draw_image(int x, t_raycast *ray, t_gamedata *ptr)
{
	int	y;
	int	tex_y;

	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_y = (int)ray->tex_pos &(TX_HEIGHT - 1);
		ray->tex_pos += ray->step;
		if (ray->side == 0 && ray->ray_dir_x > 0)
			game_mlx_pixel_put(ptr->img, x, y, \
				ft_get_pix_colour(ptr->tex->img_west, ray->tex_x, tex_y));
		else if (ray->side == 0 && ray->ray_dir_x < 0)
			game_mlx_pixel_put(ptr->img, x, y, \
				ft_get_pix_colour(ptr->tex->img_east, ray->tex_x, tex_y));
		else if (ray->side == 1 && ray->ray_dir_y < 0)
			game_mlx_pixel_put(ptr->img, x, y, \
				ft_get_pix_colour(ptr->tex->img_north, ray->tex_x, tex_y));
		else if (ray->side == 1 && ray->ray_dir_y > 0)
			game_mlx_pixel_put(ptr->img, x, y, \
				ft_get_pix_colour(ptr->tex->img_south, ray->tex_x, tex_y));
		y++;
	}
}

/*
** The raycasting loop is going through every x (for every vertical stripe).
** The ray is starting at the position of the player (posX, posY)
** Calculating ray pos & dir
** mapX and mapY: the current square of the map the ray is in
** Setting the player steps, performing DDA algorithm, calculating draw param.
** Setting how much to increase the texture coordinate per screen pixel:
** step = 1.0 * texHeight / lineHeight, where lh= (int)(S_HEIGHT/perp_wall_dist)
** Starting tex coordinate: texPos = (drawStart - h / 2 + lineHeight / 2) * step
** Drawing the image
** Inspired from: https://lodev.org/cgtutor/raycasting.html
*/

void	raycast(t_gamedata *game)
{
	t_raycast	ray;
	int			x;

	x = 0;
	while (x < S_WIDTH)
	{
		ray.ray_dir_x = game->player->dir_x + game->player->plane_x * \
			(2 * x / (float)S_WIDTH - 1);
		ray.ray_dir_y = game->player->dir_y + game->player->plane_y * \
			(2 * x / (float)S_WIDTH - 1);
		ray.map_x = (int)game->player->pos_x;
		ray.map_y = (int)game->player->pos_y;
		set_player_steps(&ray, game->player);
		raycast_dda(&ray, game);
		calculate_draw_parameters(&ray, game);
		ray.step = 1.0 * TX_HEIGHT / \
			(int)(S_HEIGHT / ray.perp_wall_dist);
		ray.tex_pos = (ray.draw_start - S_HEIGHT / 2 + \
				(int)(S_HEIGHT / ray.perp_wall_dist) / 2) * ray.step;
		draw_image(x, &ray, game);
		x++;
	}
}
