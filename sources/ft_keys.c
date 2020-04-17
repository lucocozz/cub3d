/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:20:41 by lucocozz          #+#    #+#             */
/*   Updated: 2020/04/14 21:18:27 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_w_key(t_garbage *garb)
{
	t_mlx		*mlx;
	t_parsing	*parse;
	t_engine	*eng;

	mlx = garb->mlx;
	eng = garb->engine;
	parse = garb->parse;
	if (eng->map.array[(int)(eng->cam.pos.y + eng->cam.dir.y * eng->moveS)]
	[(int)eng->cam.pos.x] == 0)
		eng->cam.pos.y += eng->cam.dir.y * eng->moveS;
	if (eng->map.array[(int)eng->cam.pos.y]
	[(int)(eng->cam.pos.x + eng->cam.dir.x * eng->moveS)] == 0)
		eng->cam.pos.x += eng->cam.dir.x * eng->moveS;
	ft_display_img(eng, parse, mlx);
	return (1);
}

int	ft_s_key(t_garbage *garb)
{
	t_mlx		*mlx;
	t_parsing	*parse;
	t_engine	*eng;

	mlx = garb->mlx;
	eng = garb->engine;
	parse = garb->parse;
	if (eng->map.array[(int)(eng->cam.pos.y - eng->cam.dir.y * eng->moveS)]
	[(int)eng->cam.pos.x] == 0)
		eng->cam.pos.y -= eng->cam.dir.y * eng->moveS;
	if (eng->map.array[(int)eng->cam.pos.y]
	[(int)(eng->cam.pos.x - eng->cam.dir.x * eng->moveS)] == 0)
		eng->cam.pos.x -= eng->cam.dir.x * eng->moveS;
	ft_display_img(eng, parse, mlx);
	return (1);
}

int	ft_a_key(t_garbage *garb)
{
	t_mlx		*mlx;
	t_parsing	*parse;
	t_engine	*eng;

	mlx = garb->mlx;
	eng = garb->engine;
	parse = garb->parse;
	if (eng->map.array[(int)(eng->cam.pos.y - eng->cam.plane.y * eng->moveS)]
	[(int)eng->cam.pos.x] == 0)
		eng->cam.pos.y -= eng->cam.plane.y * eng->moveS;
	if (eng->map.array[(int)eng->cam.pos.y]
	[(int)(eng->cam.pos.x - eng->cam.plane.x * eng->moveS)] == 0)
		eng->cam.pos.x -= eng->cam.plane.x * eng->moveS;
	ft_display_img(eng, parse, mlx);
	return (1);
}

int	ft_d_key(t_garbage *garb)
{
	t_mlx		*mlx;
	t_parsing	*parse;
	t_engine	*eng;

	mlx = garb->mlx;
	eng = garb->engine;
	parse = garb->parse;
	if (eng->map.array[(int)(eng->cam.pos.y + eng->cam.plane.y * eng->moveS)]
	[(int)eng->cam.pos.x] == 0)
		eng->cam.pos.y += eng->cam.plane.y * eng->moveS;
	if (eng->map.array[(int)eng->cam.pos.y]
	[(int)(eng->cam.pos.x + eng->cam.plane.x * eng->moveS)] == 0)
		eng->cam.pos.x += eng->cam.plane.x * eng->moveS;
	ft_display_img(eng, parse, mlx);
	return (1);
}
