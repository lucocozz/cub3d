/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:26:25 by lucocozz          #+#    #+#             */
/*   Updated: 2020/03/09 09:10:58 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_sprites(t_engine *eng, t_parsing *parse)
{
	int	i;
	int j;

	i = 0;
	eng->sprite.nb = 0;
	while (i < parse->map.y)
	{
		j = 0;
		while (j < parse->map.x)
		{
			if (!ft_strchr(SPRITES, parse->map.array[i][j]))
				eng->sprite.nb += 1;
			j++;
		}
		i++;
	}
	eng->sprite.order = malloc(sizeof(int) * eng->sprite.nb);
	eng->sprite.dist = malloc(sizeof(int) * eng->sprite.nb);
	eng->sprite.data = malloc(sizeof(t_sprite_data) * eng->sprite.nb);
	i = 0;
	while (i < eng->sprite.nb)
	{
		//eng->sprite.data
		i++;
	}
}

void	ft_sprite(t_engine *eng, t_mlx *mlx, t_parsing *parse, t_raycast ray)
{
	int		i;
	static	bool = 0;

	i = 0;
	if (!bool++)
		ft_init_sprites(eng, parse);
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
