/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:26:25 by lucocozz          #+#    #+#             */
/*   Updated: 2020/04/21 03:14:08 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_init_sprites(t_mlx *mlx, t_engine *eng, t_parsing *parse)
{
	int		i;
	t_coord	axe;

	axe.y = 0;
	eng->sprite.nb = 0;
	(void)mlx;
	while (axe.y < parse->map.y)
	{
		axe.x = 0;
		while (axe.x < parse->map.x)
		{
			if ((i = ft_strchri(SPRITES, parse->map.array[axe.y][axe.x])) > -1)
			{
				ft_push_sprite(&eng->sprite.data, &(t_garbage){parse, mlx, eng},
				axe, i);
				eng->sprite.nb++;
			}
			axe.x++;
		}
		axe.y++;
	}
}

void		ft_sprite(t_engine *eng, t_mlx *mlx, t_parsing *parse)
{
	int				i;
	int				y;
	t_sprite_lst	*sprite;
	static int		bool = 0;

	i = 0;
	if (!bool++)
		ft_init_sprites(mlx, eng, parse);
	sprite = eng->sprite.data;
	while (sprite)
	{
		sprite->dist = ((eng->cam.pos.x - sprite->coord.x) * (eng->cam.pos.x
		- sprite->coord.x) + (eng->cam.pos.y - sprite->coord.y)
		* (eng->cam.pos.y - sprite->coord.y));
		sprite = sprite->next;
	}
	ft_sort_sprite(&eng->sprite.data);
	sprite = eng->sprite.data;
	while (sprite)
	{
		eng->sprite.coord.x = sprite->coord.x - eng->cam.pos.x; // ok
		eng->sprite.coord.y = sprite->coord.y - eng->cam.pos.y; // ok

		eng->sprite.invDet = 1.0 / (eng->cam.plane.x * eng->cam.dir.y
		- eng->cam.dir.x * eng->cam.plane.y); // ok

		eng->sprite.transf.x = eng->sprite.invDet * (eng->cam.dir.y
		* eng->sprite.coord.x - eng->cam.dir.x * eng->sprite.coord.y); // ok
		eng->sprite.transf.y = eng->sprite.invDet * (-eng->cam.plane.y
		* eng->sprite.coord.x + eng->cam.plane.x * eng->sprite.coord.y); // ok

		eng->sprite.screenX = (int)((parse->size.x / 2) * (1
		+ eng->sprite.transf.x / eng->sprite.transf.y)); // ok

		eng->sprite.size.y = abs((int)(parse->size.y / (eng->sprite.transf.y))); // ok 

		eng->sprite.start.y = -eng->sprite.size.y / 2 + parse->size.y / 2; // ok
		if (eng->sprite.start.y < 0) // ok
			eng->sprite.start.y = 0; // ok

		eng->sprite.end.y = eng->sprite.size.y / 2 + parse->size.y / 2; // ok
		if (eng->sprite.end.y >= parse->size.y) // ok
			eng->sprite.end.y = parse->size.y - 1; // ok

		eng->sprite.size.x = abs((int)(parse->size.y / (eng->sprite.transf.y))); // ok

		eng->sprite.start.x = -eng->sprite.size.x / 2 + eng->sprite.screenX; // ok
		if (eng->sprite.start.x < 0) // ok
			eng->sprite.start.x = 0; // ok

		eng->sprite.end.x = eng->sprite.size.x / 2 + eng->sprite.screenX; // ok
		if (eng->sprite.end.x >= parse->size.x) // ok
			eng->sprite.end.x = parse->size.x - 1; // ok
		
		ft_printf("\nstrip=%d\nendX=%d\n", eng->sprite.stripe, eng->sprite.end.x);
		eng->sprite.stripe = eng->sprite.start.x; // ok
		while (eng->sprite.stripe < eng->sprite.end.x) // ok
		{
			ft_printf("BITE\n");
			eng->sprite.tex.x = (int)((256 * (eng->sprite.stripe
			- (-eng->sprite.size.x / 2 + eng->sprite.screenX))
			* sprite->size.x / eng->sprite.size.x)) / 256; // ok

			if (eng->sprite.transf.y > 0 && eng->sprite.stripe > 0
			&& eng->sprite.stripe < parse->size.x && eng->sprite.transf.y
			< eng->Zbuff[eng->sprite.stripe]) // ok
			{
				y = eng->sprite.start.y; // ok
				while (y < eng->sprite.end.y) // ok
				{
					eng->sprite.d = (y) * 256 - parse->size.x * 128
					+ eng->sprite.size.y * 128; // ok ? (neg value return)
					eng->sprite.tex.y = ((eng->sprite.d * sprite->size.y)
					/ eng->sprite.size.y) / 256; // ok
					eng->sprite.color = sprite->img.data[sprite->size.x * eng->sprite.tex.y + eng->sprite.tex.x]; // ok
					if ((eng->sprite.color & 0x00FFFFFF) != 0) // ok
						mlx->img.data[y * parse->size.x + eng->sprite.stripe] = eng->sprite.color; // ok
					y++; // ok
				}
			}
			eng->sprite.stripe++; // ok
		}
		sprite = sprite->next; // ok
	}
	
}
