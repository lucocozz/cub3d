/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:26:25 by lucocozz          #+#    #+#             */
/*   Updated: 2020/04/16 18:52:40 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_sprite(t_engine *eng, t_mlx *mlx, t_parsing *parse, t_raycast ray)
{
	int		i;
	static	bool = 0;

	i = 0;
	if (!bool++)
		ft_init_sprites(mlx, eng, parse);
	while (i < eng->sprite.nb)
	{
		eng->sprite.order[i] = i;
		eng->sprite.dist[i] = ((eng->cam.pos.x - eng->sprite.data[i].coord.x)
		* (eng->cam.pos.x - eng->sprite.data[i].coord.x) + (eng->cam.pos.y
		- eng->sprite.data[i].coord.y) * (eng->cam.pos.y
		- eng->sprite.data[i].coord.y));
		i++;
	}
}
