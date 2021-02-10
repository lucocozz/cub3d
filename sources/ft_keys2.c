/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 22:42:00 by lucocozz          #+#    #+#             */
/*   Updated: 2021/02/10 15:56:02 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_right_key(t_garbage *garb)
{
	float		old_dir;
	float		old_plane;
	t_engine	*eng;

	eng = garb->engine;
	old_dir = eng->cam.dir.x;
	eng->cam.dir.x = eng->cam.dir.x * cos(eng->rot_s) - eng->cam.dir.y
	* sin(eng->rot_s);
	eng->cam.dir.y = old_dir * sin(eng->rot_s) + eng->cam.dir.y
	* cos(eng->rot_s);
	old_plane = eng->cam.plane.x;
	eng->cam.plane.x = eng->cam.plane.x * cos(eng->rot_s) - eng->cam.plane.y
	* sin(eng->rot_s);
	eng->cam.plane.y = old_plane * sin(eng->rot_s) + eng->cam.plane.y
	* cos(eng->rot_s);
	return (1);
}

int		ft_left_key(t_garbage *garb)
{
	float		old_dir;
	float		old_plane;
	t_engine	*eng;

	eng = garb->engine;
	old_dir = eng->cam.dir.x;
	eng->cam.dir.x = eng->cam.dir.x * cos(-eng->rot_s) - eng->cam.dir.y
	* sin(-eng->rot_s);
	eng->cam.dir.y = old_dir * sin(-eng->rot_s) + eng->cam.dir.y
	* cos(-eng->rot_s);
	old_plane = eng->cam.plane.x;
	eng->cam.plane.x = eng->cam.plane.x * cos(-eng->rot_s) - eng->cam.plane.y
	* sin(-eng->rot_s);
	eng->cam.plane.y = old_plane * sin(-eng->rot_s) + eng->cam.plane.y
	* cos(-eng->rot_s);
	return (1);
}
