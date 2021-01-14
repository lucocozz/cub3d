/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_engine_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:55:13 by lucocozz          #+#    #+#             */
/*   Updated: 2021/01/14 16:53:43 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	ft_pos_cam(t_camera *cam, t_coord dir, t_fcoord plane)
{
	cam->dir.x = dir.x;
	cam->dir.y = dir.y;
	cam->plane.x = plane.x;
	cam->plane.y = plane.y;
}

static void	ft_set_cam(t_map_parse *map, t_camera *cam, int x, int y)
{
	if (map->array[y][x] == 'N')
		ft_pos_cam(cam, (t_coord){0, -1}, (t_fcoord){0.66, 0.0});
	else if (map->array[y][x] == 'E')
		ft_pos_cam(cam, (t_coord){1, 0}, (t_fcoord){0.0, 0.66});
	else if (map->array[y][x] == 'W')
		ft_pos_cam(cam, (t_coord){-1, 0}, (t_fcoord){0.0, -0.66});
	else if (map->array[y][x] == 'S')
		ft_pos_cam(cam, (t_coord){0, 1}, (t_fcoord){-0.66, 0.0});
	cam->pos.x = x + 0.5;
	cam->pos.y = y + 0.5;
	map->array[y][x] = '0';
}

t_engine	ft_init_engine(t_parsing *parse)
{
	t_coord		axe;
	t_engine	engine;

	axe.y = 0;
	while (axe.y < parse->map.y)
	{
		axe.x = 0;
		while (axe.x < parse->map.x)
		{
			if (ft_strchr(PLAYER, parse->map.array[axe.y][axe.x]))
				ft_set_cam(&parse->map, &engine.cam, axe.x, axe.y);
			axe.x++;
		}
		axe.y++;
	}
	engine.sprite.data = NULL;
	engine.move_s = SPEED;
	engine.rot_s = ROT;
	engine.key = 0;
	if ((engine.z_buff = malloc(sizeof(float) * parse->size.x)) == NULL)
		ft_exit_parsing(parse, "Init engine error\n");
	return (engine);
}
