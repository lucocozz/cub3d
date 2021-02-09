/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 05:22:39 by lucocozz          #+#    #+#             */
/*   Updated: 2021/02/09 18:06:20 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_get_textures_img(t_engine *eng, t_mlx *mlx, t_parsing parse)
{
	int				i;
	t_texture_data	*tmp;

	i = 0;
	while (i < N_TEXTURES)
	{
		tmp = &((t_texture_data *)(&eng->texture))[i];
		tmp->ptr = mlx_xpm_file_to_image(mlx->ptr,
		((char **)(&parse.texture))[i], &tmp->width, &tmp->height);
		tmp->img = (int*)mlx_get_data_addr(tmp->ptr, &mlx->img.bpp,
		&mlx->img.size, &mlx->img.endian);
		i++;
	}
}

static void	ft_draw_texture(t_texture_data *texture, t_raycast *ray,
t_parsing *parse, t_mlx *mlx)
{
	int	y;

	y = ray->start;
	texture->step = 1.0 * texture->height / ray->line_h;
	texture->pos = (y - parse->size.y / 2 + ray->line_h / 2) * texture->step;
	while (y < ray->end)
	{
		texture->coord.y = (int)texture->pos & (texture->height - 1);
		texture->pos += texture->step;
		ray->color = texture->img[texture->coord.y * texture->height
		+ texture->coord.x];
		mlx->img.data[y * parse->size.x + ray->col] = ray->color;
		y++;
	}
}

void		ft_texturing(t_garbage garb, t_texture_data *texture,
t_raycast *ray)
{
	t_engine	*eng;

	eng = garb.engine;
	texture->num = eng->map.array[ray->map.y][ray->map.x] - 1;
	if (ray->side == EAST || ray->side == WEST)
		texture->wall_x = eng->cam.pos.y + ray->pw_dist * ray->dir.y;
	else
		texture->wall_x = eng->cam.pos.x + ray->pw_dist * ray->dir.x;
	texture->wall_x -= floor(texture->wall_x);
	texture->coord.x = (int)(texture->wall_x * (float)texture->width);
	if ((ray->side == EAST || ray->side == WEST) && ray->dir.x > 0)
		texture->coord.x = texture->width - texture->coord.x - 1;
	if ((ray->side == SOUTH || ray->side == NORTH) && ray->dir.y < 0)
		texture->coord.x = texture->width - texture->coord.x - 1;
	ft_draw_texture(texture, ray, garb.parse, garb.mlx);
}
