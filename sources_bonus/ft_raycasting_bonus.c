/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:23:38 by lucocozz          #+#    #+#             */
/*   Updated: 2020/06/04 21:32:03 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static t_raycast	ft_init_ray(t_camera cam, t_parsing parse, int col)
{
	t_raycast	ray;

	ray.col = col;
	ray.hit = 0;
	ray.cam.y = 0;
	ray.sDist.x = 0;
	ray.sDist.y = 0;
	ray.cam.x = 2 * ray.col / (float)parse.size.x - 1;
	ray.dir.x = cam.dir.x + cam.plane.x * ray.cam.x;
	ray.dir.y = cam.dir.y + cam.plane.y * ray.cam.x;
	ray.map.x = (int)cam.pos.x;
	ray.map.y = (int)cam.pos.y;
	ray.dDist.x = fabsf(1 / ray.dir.x);
	ray.dDist.y = fabsf(1 / ray.dir.y);
	return (ray);
}

static void			ft_ray_hit(t_parsing parse, t_raycast *ray)
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
		if (ft_strchri(WALLS, parse.map.array[ray->map.y][ray->map.x]) > -1)
			ray->hit = 1;
	}
}

static void			ft_ray_step(t_camera cam, t_raycast *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->sDist.x = (cam.pos.x - ray->map.x) * ray->dDist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sDist.x = (ray->map.x + 1.0 - cam.pos.x) * ray->dDist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->sDist.y = (cam.pos.y - ray->map.y) * ray->dDist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sDist.y = (ray->map.y + 1.0 - cam.pos.y)
		* ray->dDist.y;
	}
}

static void			ft_p_h_ray(t_parsing parse, t_raycast *ray, t_camera cam)
{
	if (ray->side == EAST || ray->side == WEST)
		ray->PWDist = (ray->map.x - cam.pos.x
		+ (1 - ray->step.x) / 2) / ray->dir.x;
	else
		ray->PWDist = (ray->map.y - cam.pos.y
		+ (1 - ray->step.y) / 2) / ray->dir.y;
	ray->line_h = (int)(parse.size.y / ray->PWDist);
	ray->start = -ray->line_h / 2 + parse.size.y / 2;
	if (ray->start < 0)
		ray->start = 0;
	ray->end = ray->line_h / 2 + parse.size.y / 2;
	if (ray->end >= parse.size.y)
		ray->end = parse.size.y - 1;
}

t_raycast			ft_ray(t_camera cam, t_parsing parse, int x)
{
	t_raycast ray;

	ray = ft_init_ray(cam, parse, x);
	ft_ray_step(cam, &ray);
	ft_ray_hit(parse, &ray);
	ft_p_h_ray(parse, &ray, cam);
	return (ray);
}
