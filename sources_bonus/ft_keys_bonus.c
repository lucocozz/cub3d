/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:20:41 by lucocozz          #+#    #+#             */
/*   Updated: 2020/06/02 16:45:36 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	ft_collision(const int nb, const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		if (nb == str[i] - '0' && ft_isdigit(str[i]))
			return (1);
		else if (nb == (int)str[i])
			return (1);
		i++;
	}
	return (0);
}

int			ft_w_key(t_garbage *garb)
{
	t_mlx		*mlx;
	t_parsing	*parse;
	t_engine	*eng;

	mlx = garb->mlx;
	eng = garb->engine;
	parse = garb->parse;
	if (ft_collision(eng->map.array[(int)(eng->cam.pos.y + eng->cam.dir.y
	* eng->moveS)][(int)eng->cam.pos.x], COLLISION) == 0)
		eng->cam.pos.y += eng->cam.dir.y * eng->moveS;
	if (ft_collision(eng->map.array[(int)eng->cam.pos.y]
	[(int)(eng->cam.pos.x + eng->cam.dir.x * eng->moveS)], COLLISION) == 0)
		eng->cam.pos.x += eng->cam.dir.x * eng->moveS;
	return (1);
}

int			ft_s_key(t_garbage *garb)
{
	t_mlx		*mlx;
	t_parsing	*parse;
	t_engine	*eng;

	mlx = garb->mlx;
	eng = garb->engine;
	parse = garb->parse;
	if (ft_collision(eng->map.array[(int)(eng->cam.pos.y - eng->cam.dir.y
	* eng->moveS)][(int)eng->cam.pos.x], COLLISION) == 0)
		eng->cam.pos.y -= eng->cam.dir.y * eng->moveS;
	if (ft_collision(eng->map.array[(int)eng->cam.pos.y]
	[(int)(eng->cam.pos.x - eng->cam.dir.x * eng->moveS)], COLLISION) == 0)
		eng->cam.pos.x -= eng->cam.dir.x * eng->moveS;
	return (1);
}

int			ft_a_key(t_garbage *garb)
{
	t_mlx		*mlx;
	t_parsing	*parse;
	t_engine	*eng;

	mlx = garb->mlx;
	eng = garb->engine;
	parse = garb->parse;
	if (ft_collision(eng->map.array[(int)(eng->cam.pos.y - eng->cam.plane.y
	* eng->moveS)][(int)eng->cam.pos.x], COLLISION) == 0)
		eng->cam.pos.y -= eng->cam.plane.y * eng->moveS;
	if (ft_collision(eng->map.array[(int)eng->cam.pos.y]
	[(int)(eng->cam.pos.x - eng->cam.plane.x * eng->moveS)], COLLISION) == 0)
		eng->cam.pos.x -= eng->cam.plane.x * eng->moveS;
	return (1);
}

int			ft_d_key(t_garbage *garb)
{
	t_mlx		*mlx;
	t_parsing	*parse;
	t_engine	*eng;

	mlx = garb->mlx;
	eng = garb->engine;
	parse = garb->parse;
	if (ft_collision(eng->map.array[(int)(eng->cam.pos.y + eng->cam.plane.y
	* eng->moveS)][(int)eng->cam.pos.x], COLLISION) == 0)
		eng->cam.pos.y += eng->cam.plane.y * eng->moveS;
	if (ft_collision(eng->map.array[(int)eng->cam.pos.y]
	[(int)(eng->cam.pos.x + eng->cam.plane.x * eng->moveS)], COLLISION) == 0)
		eng->cam.pos.x += eng->cam.plane.x * eng->moveS;
	return (1);
}
