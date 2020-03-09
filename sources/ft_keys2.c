/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 22:42:00 by lucocozz          #+#    #+#             */
/*   Updated: 2020/03/06 01:12:24 by lucocozz         ###   ########.fr       */
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
	eng->cam.dir.x = eng->cam.dir.x * cos(eng->rotS) - eng->cam.dir.y
	* sin(eng->rotS);
	eng->cam.dir.y = old_dir * sin(eng->rotS) + eng->cam.dir.y * cos(eng->rotS);
	old_plane = eng->cam.plane.x;
	eng->cam.plane.x = eng->cam.plane.x * cos(eng->rotS) - eng->cam.plane.y
	* sin(eng->rotS);
	eng->cam.plane.y = old_plane * sin(eng->rotS) + eng->cam.plane.y
	* cos(eng->rotS);
	ft_display_img(eng, garb->parse, garb->mlx);
	return (1);
}

int		ft_left_key(t_garbage *garb)
{
	float		old_dir;
	float		old_plane;
	t_engine	*eng;

	eng = garb->engine;
	old_dir = eng->cam.dir.x;
	eng->cam.dir.x = eng->cam.dir.x * cos(-eng->rotS) - eng->cam.dir.y
	* sin(-eng->rotS);
	eng->cam.dir.y = old_dir * sin(-eng->rotS) + eng->cam.dir.y
	* cos(-eng->rotS);
	old_plane = eng->cam.plane.x;
	eng->cam.plane.x = eng->cam.plane.x * cos(-eng->rotS) - eng->cam.plane.y
	* sin(-eng->rotS);
	eng->cam.plane.y = old_plane * sin(-eng->rotS) + eng->cam.plane.y
	* cos(-eng->rotS);
	ft_display_img(eng, garb->parse, garb->mlx);
	return (1);
}
