/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:20:41 by lucocozz          #+#    #+#             */
/*   Updated: 2021/01/14 16:54:03 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int			ft_w_key(t_garbage *garb)
{
	float		next;
	t_parsing	*parse;
	t_engine	*eng;

	eng = garb->engine;
	parse = garb->parse;
	next = eng->cam.pos.y + eng->cam.dir.y * eng->move_s;
	if (ft_strchri(COLLISION, parse->map.array[(int)next][(int)eng->cam.pos.x])
	== -1)
		eng->cam.pos.y = next;
	next = eng->cam.pos.x + eng->cam.dir.x * eng->move_s;
	if (ft_strchri(COLLISION, parse->map.array[(int)eng->cam.pos.y][(int)next])
	== -1)
		eng->cam.pos.x = next;
	return (1);
}

int			ft_s_key(t_garbage *garb)
{
	float		next;
	t_parsing	*parse;
	t_engine	*eng;

	eng = garb->engine;
	parse = garb->parse;
	next = eng->cam.pos.y - eng->cam.dir.y * eng->move_s;
	if (ft_strchri(COLLISION, parse->map.array[(int)next][(int)eng->cam.pos.x])
	== -1)
		eng->cam.pos.y = next;
	next = eng->cam.pos.x - eng->cam.dir.x * eng->move_s;
	if (ft_strchri(COLLISION, parse->map.array[(int)eng->cam.pos.y][(int)next])
	== -1)
		eng->cam.pos.x = next;
	return (1);
}

int			ft_a_key(t_garbage *garb)
{
	float		next;
	t_parsing	*parse;
	t_engine	*eng;

	eng = garb->engine;
	parse = garb->parse;
	next = eng->cam.pos.y - eng->cam.plane.y * eng->move_s;
	if (ft_strchri(COLLISION, parse->map.array[(int)next][(int)eng->cam.pos.x])
	== -1)
		eng->cam.pos.y = next;
	next = eng->cam.pos.x - eng->cam.plane.x * eng->move_s;
	if (ft_strchri(COLLISION, parse->map.array[(int)eng->cam.pos.y][(int)next])
	== -1)
		eng->cam.pos.x = next;
	return (1);
}

int			ft_d_key(t_garbage *garb)
{
	float		next;
	t_parsing	*parse;
	t_engine	*eng;

	eng = garb->engine;
	parse = garb->parse;
	next = eng->cam.pos.y + eng->cam.plane.y * eng->move_s;
	if (ft_strchri(COLLISION, parse->map.array[(int)next][(int)eng->cam.pos.x])
	== -1)
		eng->cam.pos.y = next;
	next = eng->cam.pos.x + eng->cam.plane.x * eng->move_s;
	if (ft_strchri(COLLISION, parse->map.array[(int)eng->cam.pos.y][(int)next])
	== -1)
		eng->cam.pos.x = next;
	return (1);
}
