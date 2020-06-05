/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 05:22:39 by lucocozz          #+#    #+#             */
/*   Updated: 2020/06/04 16:57:36 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int			ft_shading(int color, float dist, float multiplier)
{
	int shade;

	shade = 0;
	if (dist <= multiplier)
		return (color);
	shade += (int)(((RED & color) >> 16) / dist * multiplier) << 16;
	shade += (int)(((GREEN & color) >> 8) / dist * multiplier) << 8;
	shade += (int)((BLUE & color) / dist * multiplier);
	return (shade);
}

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
		if (ray->side == EAST || ray->side == WEST)
			ray->color = (ray->color >> 1) & 8355711;
		mlx->img.data[y * parse->size.x + ray->col] = ft_shading(ray->color,
		ray->PWDist, SHADE);
		y++;
	}
}

void		ft_texturing(t_garbage garb, t_texture_data *texture,
t_raycast *ray)
{
	t_engine	*eng;

	eng = garb.engine;
	if (ray->side == EAST || ray->side == WEST)
		texture->wall_x = eng->cam.pos.y + ray->PWDist * ray->dir.y;
	else
		texture->wall_x = eng->cam.pos.x + ray->PWDist * ray->dir.x;
	texture->wall_x -= floor(texture->wall_x);
	texture->coord.x = (int)(texture->wall_x * (float)texture->width);
	if ((ray->side == EAST || ray->side == WEST) && ray->dir.x > 0)
		texture->coord.x = texture->width - texture->coord.x - 1;
	if ((ray->side == SOUTH || ray->side == NORTH) && ray->dir.y < 0)
		texture->coord.x = texture->width - texture->coord.x - 1;
	ft_draw_texture(texture, ray, garb.parse, garb.mlx);
}
