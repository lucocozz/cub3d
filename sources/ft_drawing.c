/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:21:14 by lucocozz          #+#    #+#             */
/*   Updated: 2021/02/09 17:21:54 by lucocozz         ###   ########.fr       */
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
	if (eng->map.array[ray->map.y][ray->map.x] == 1 && ray->side == NORTH)
		texture = &eng->texture.north;
	else if (eng->map.array[ray->map.y][ray->map.x] == 1 && ray->side == SOUTH)
		texture = &eng->texture.south;
	else if (eng->map.array[ray->map.y][ray->map.x] == 1 && ray->side == EAST)
		texture = &eng->texture.east;
	else if (eng->map.array[ray->map.y][ray->map.x] == 1 && ray->side == WEST)
		texture = &eng->texture.west;
	ft_texturing((t_garbage){&parse, mlx, eng}, texture, ray);
}
