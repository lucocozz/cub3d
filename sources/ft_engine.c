/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:13:42 by lucocozz          #+#    #+#             */
/*   Updated: 2020/03/07 05:06:35 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_verline(t_mlx *mlx, t_parsing parse, t_raycast *ray)
{
	int	y;

	y = ray->start;
	while (y < ray->end)
	{
		mlx->img.data[y * parse.size.x + ray->col] = ray->color;
		y++;
	}
}

static void	ft_sky_floor(t_mlx *mlx, t_raycast *ray, t_parsing parse)
{
	t_raycast		tmp_ray;

	tmp_ray.col = ray->col;
	tmp_ray.start = 0;
	tmp_ray.end = parse.size.y / 2;
	tmp_ray.color = parse.color.top;
	ft_verline(mlx, parse, &tmp_ray);
	tmp_ray.start = parse.size.y / 2;
	tmp_ray.end = parse.size.y - 1;
	tmp_ray.color = parse.color.roof;
	ft_verline(mlx, parse, &tmp_ray);
}

void		ft_draw(t_engine *eng, t_mlx *mlx, t_parsing parse, t_raycast *ray)
{
	t_texture_data	*texture;

	texture = NULL;
	ft_sky_floor(mlx, ray, parse);
	if (eng->map.array[ray->map.y][ray->map.x] && ray->side == NORTH)
		texture = &eng->texture.north;
	else if (eng->map.array[ray->map.y][ray->map.x] && ray->side == SOUTH)
		texture = &eng->texture.south;
	else if (eng->map.array[ray->map.y][ray->map.x] && ray->side == EAST)
		texture = &eng->texture.east;
	else if (eng->map.array[ray->map.y][ray->map.x] && ray->side == WEST)
		texture = &eng->texture.west;
	ft_texturing((t_garbage){&parse, mlx, eng}, texture, ray);
}

void		ft_display_img(t_engine *eng, t_parsing *parse, t_mlx *mlx)
{
	int			x;
	int			y;
	void		*ptr;
	int			*img;

	y = 0;
	ptr = mlx_new_image(mlx->ptr, parse->size.x, parse->size.y);
	img = (int*)mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp,
	&mlx->img.size, &mlx->img.endian);
	while (y < parse->size.y)
	{
		x = 0;
		while (x < parse->size.x)
		{
			img[y * parse->size.x + x] = 0;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, ptr, 0, 0);
	mlx_destroy_image(mlx->ptr, ptr);
	ft_raycast(parse, eng, mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}