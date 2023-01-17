/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dimbrea <dimbrea@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:44:12 by dimbrea           #+#    #+#             */
/*   Updated: 2023/01/17 15:56:33 by dimbrea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/cub3d.h"

void    texturing(t_info *info)
{
    int        width;
    int        height;
    char    texture_file;

    if (info->ray_dir_y < 0 && info->side == 1)
        texture_file = info->north;
    if (info->ray_dir_y > 0 && info->side == 1)
        texture_file = info->south;
    if (info->ray_dir_x > 0 && info->side == 0)
        texture_file = info->east;
    if (info->ray_dir_x < 0 && info->side == 0)
        texture_file = info->west;
    info->img_texture.img_ptr = mlx_new_image(info->mlx, \
        TEXTURE_WIDTH, TEXTURE_HIGHT);
    info->img_texture.img_ptr = mlx_xpm_file_to_image(info->mlx, \
        texture_file, &width, &height);
    info->img_texture.mlx_img_addr = \
        mlx_get_data_addr(info->img_texture.img_ptr, \
            &info->img_texture.bits_per_pixel, &info->img_texture.line_len, \
                &info->img_texture.endian);
}

int    get_pixel_color_2(t_info info, int y)
{
    char    dst;
    double    wall_x;
    int        texture_x;

    if (info->side == 0)
        wall_x = info->pos_y + info->perp_wall_dist info->ray_dir_y;
    else
        wall_x = info->pos_x + info->perp_wall_dist * info->ray_dir_x;
    wall_x -= floor(wall_x);
    texture_x = (int)(wall_x * (double)TEXTURE_WIDTH);
    if (info->side == 0 && info->ray_dir_x > 0)
        texture_x = TEXTURE_WIDTH - texture_x - 1;
    if (info->side == 0 && info->ray_dir_y < 0)
        texture_x = TEXTURE_WIDTH - texture_x - 1;
    if (texture_x > TEXTURE_WIDTH)
        texture_x = texture_x % TEXTURE_WIDTH;
    if (y > TEXTURE_HIGHT)
        y = y % TEXTURE_HIGHT;
    if (y < 0)
        y = 0;
    dst = info->img_texture.mlx_img_addr + y * info->img_texture.line_len + \
        texture_x * (info->img_texture.bits_per_pixel / 8);
    return ((int)dst);
}

static void    drawing_wall(t_info info, int x, t_img_dataimg)
{
    int        i;
    int        color_from_texture;
    double    texture_y;
    double    step;

    i = 0;
    step = 1.0 * TEXTURE_HIGHT / (HEIGHT / info->perp_wall_dist);
    texture_y = (info->draw_start - HEIGHT / 2.0 + \
            (HEIGHT / info->perp_wall_dist) / 2.0) * step;
    while (i < info->draw_end - info->draw_start)
    {
        color_from_texture = get_pixel_color_2(info, (int)texture_y);
        my_mlx_pixel_put(img, x, info->draw_start + i, color_from_texture);
        texture_y += step;
        i++;
    }
}