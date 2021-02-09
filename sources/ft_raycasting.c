/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 17:23:38 by lucocozz          #+#    #+#             */
/*   Updated: 2021/02/09 18:34:27 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static t_raycast	ft_init_ray(t_camera cam, t_parsing parse, int col)
{
	t_raycast	ray;

	ray.col = col;
	ray.hit = 0;
	ray.cam.y = 0;
	ray.s_dist.x = 0;
	ray.s_dist.y = 0;
	ray.cam.x = 2 * ray.col / (float)parse.size.x - 1;
	ray.dir.x = cam.dir.x + cam.plane.x * ray.cam.x;
	ray.dir.y = cam.dir.y + cam.plane.y * ray.cam.x;
	ray.map.x = (int)cam.pos.x;
	ray.map.y = (int)cam.pos.y;
	ray.d_dist.x = fabsf(1 / ray.dir.x);
	ray.d_dist.y = fabsf(1 / ray.dir.y);
	return (ray);
}

static void			ft_ray_hit(t_parsing parse, t_raycast *ray)
{
	while (ray->hit == 0)
	{
		if (ray->s_dist.x < ray->s_dist.y)
		{
			ray->s_dist.x += ray->d_dist.x;
			ray->map.x += ray->step.x;
			ray->side = (ray->step.x == 1 ? EAST : WEST);
		}
		else
		{
			ray->s_dist.y += ray->d_dist.y;
			ray->map.y += ray->step.y;
			ray->side = (ray->step.y == 1 ? SOUTH : NORTH);
		}
		if (parse.map.array[ray->map.y][ray->map.x] == '1')
			ray->hit = 1;
	}
}

static void			ft_ray_step(t_camera cam, t_raycast *ray)
{
	if (ray->dir.x < 0)
	{
		ray->step.x = -1;
		ray->s_dist.x = (cam.pos.x - ray->map.x) * ray->d_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->s_dist.x = (ray->map.x + 1.0 - cam.pos.x) * ray->d_dist.x;
	}
	if (ray->dir.y < 0)
	{
		ray->step.y = -1;
		ray->s_dist.y = (cam.pos.y - ray->map.y) * ray->d_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->s_dist.y = (ray->map.y + 1.0 - cam.pos.y)
		* ray->d_dist.y;
	}
}

static void			ft_p_h_ray(t_parsing parse, t_raycast *ray, t_camera cam)
{
	if (ray->side == EAST || ray->side == WEST)
		ray->pw_dist = (ray->map.x - cam.pos.x
		+ (1 - ray->step.x) / 2) / ray->dir.x;
	else
		ray->pw_dist = (ray->map.y - cam.pos.y
		+ (1 - ray->step.y) / 2) / ray->dir.y;
	ray->line_h = (int)(parse.size.y / ray->pw_dist);
	ray->start = -ray->line_h / 2 + parse.size.y / 2;
	if (ray->start < 0)
		ray->start = 0;
	ray->end = ray->line_h / 2 + parse.size.y / 2;
	if (ray->end >= parse.size.y)
		ray->end = parse.size.y - 1;
}

t_raycast			ft_ray(t_camera cam, t_parsing parse, int x)
{
	t_raycast	ray;

	ray = ft_init_ray(cam, parse, x);
	ft_ray_step(cam, &ray);
	ft_ray_hit(parse, &ray);
	ft_p_h_ray(parse, &ray, cam);
	return (ray);
}
