/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:23:38 by lucocozz          #+#    #+#             */
/*   Updated: 2020/03/08 00:49:32 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_raycast	ft_init_ray(t_engine *eng, t_parsing *parse, int col)
{
	t_raycast	ray;

	ray.col = col;
	ray.hit = 0;
	ray.cam.y = 0;
	ray.sDist.x = 0;
	ray.sDist.y = 0;
	ray.cam.x = 2 * ray.col / (float)parse->size.x - 1;
	ray.dir.x = eng->cam.dir.x + eng->cam.plane.x * ray.cam.x;
	ray.dir.y = eng->cam.dir.y + eng->cam.plane.y * ray.cam.x;
	ray.map.x = (int)eng->cam.pos.x;
	ray.map.y = (int)eng->cam.pos.y;
	ray.dDist.x = fabsf(1 / ray.dir.x);
	ray.dDist.y = fabsf(1 / ray.dir.y);
	return (ray);
}

static void			ft_ray_hit(t_engine *eng, t_raycast *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sDist.x < ray->sDist.y)
		{
			ray->sDist.x += ray->dDist.x;
			ray->map.x += ray->step.x;
			ray->side = (ray->step.x == 1 ? EAST : WEST);
		}
		else
		{
			ray->sDist.y += ray->dDist.y;
			ray->map.y += ray->step.y;
			ray->side = (ray->step.y == 1 ? SOUTH : NORTH);
		}
		if (eng->map.array[ray->map.y][ray->map.x] > 0)
			ray->hit = 1;
	}
}

static void			ft_ray_step(t_engine *eng, t_raycast *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->sDist.x = (eng->cam.pos.x - ray->map.x) * ray->dDist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sDist.x = (ray->map.x + 1.0 - eng->cam.pos.x) * ray->dDist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->sDist.y = (eng->cam.pos.y - ray->map.y) * ray->dDist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sDist.y = (ray->map.y + 1.0 - eng->cam.pos.y)
		* ray->dDist.y;
	}
}

static void			ft_p_h_ray(t_parsing parse, t_raycast *ray, t_engine *eng)
{
	if (ray->side == EAST || ray->side == WEST)
		ray->PWDist = (ray->map.x - eng->cam.pos.x
		+ (1 - ray->step.x) / 2) / ray->dir.x;
	else
		ray->PWDist = (ray->map.y - eng->cam.pos.y
		+ (1 - ray->step.y) / 2) / ray->dir.y;
	ray->line_h = (int)(parse.size.y / ray->PWDist);
	ray->start = -ray->line_h / 2 + parse.size.y / 2;
	if (ray->start < 0)
		ray->start = 0;
	ray->end = ray->line_h / 2 + parse.size.y / 2;
	if (ray->end >= parse.size.y)
		ray->end = parse.size.y - 1;
}

void				ft_raycast(t_parsing *parse, t_engine *eng, t_mlx *mlx)
{
	t_raycast	ray;

	ray.col = 0;
	while (ray.col < parse->size.x)
	{
		ray = ft_init_ray(eng, parse, ray.col);
		ft_ray_step(eng, &ray);
		ft_ray_hit(eng, &ray);
		ft_p_h_ray(*parse, &ray, eng);
		ft_draw(eng, mlx, *parse, &ray);
		ray.col++;
	}
}
