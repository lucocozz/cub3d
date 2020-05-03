/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprites.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:26:25 by lucocozz          #+#    #+#             */
/*   Updated: 2020/05/02 18:53:18 by lucocozz         ###   ########.fr       */
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

static void	ft_draw_sprite(t_engine *eng, t_mlx *mlx, t_coord screen,
t_sprite_lst sprite)
{
	t_coord	axe;

	axe.x = eng->sprite.start.x - 1;
	while (++axe.x < eng->sprite.end.x)
	{
		eng->sprite.tex.x = (int)(256 * (axe.x - (-eng->sprite.size.x / 2
			+ eng->sprite.screenX)) * sprite.size.x / eng->sprite.size.x / 256);
		if (eng->sprite.transf.y > 0 && axe.x > 0 && axe.x < screen.x
		&& eng->sprite.transf.y < eng->Zbuff[axe.x])
		{
			axe.y = eng->sprite.start.y - 1;
			while (++axe.y < eng->sprite.end.y)
			{
				eng->sprite.d = axe.y * 256 - screen.y * 128
					+ eng->sprite.size.y * 128;
				eng->sprite.tex.y = ((eng->sprite.d * sprite.size.y)
					/ eng->sprite.size.y) / 256;
				eng->sprite.color = sprite.img.data[sprite.size.x
					* eng->sprite.tex.y + eng->sprite.tex.x];
				if ((eng->sprite.color & 0x00FFFFFF) != 0)
					mlx->img.data[axe.y * screen.x + axe.x] = eng->sprite.color;
			}
		}
	}
}

static void	ft_set_data_sprite(t_sprite *data, t_camera cam, t_coord screen,
t_sprite_lst *sprite)
{
	data->coord.x = sprite->coord.x - cam.pos.x;
	data->coord.y = sprite->coord.y - cam.pos.y;
	data->invDet = 1.0 / (cam.plane.x * cam.dir.y - cam.dir.x * cam.plane.y);
	data->transf.x = data->invDet * (cam.dir.y * data->coord.x - cam.dir.x
		* data->coord.y);
	data->transf.y = data->invDet * (-cam.plane.y * data->coord.x + cam.plane.x
		* data->coord.y);
	data->screenX = (int)((screen.x / 2) * (1 + data->transf.x
		/ data->transf.y));
	data->size.y = abs((int)(screen.y / (data->transf.y)));
	data->start.y = -data->size.y / 2 + screen.y / 2;
	if (data->start.y < 0)
		data->start.y = 0;
	data->end.y = data->size.y / 2 + screen.y / 2;
	if (data->end.y >= screen.y)
		data->end.y = screen.y - 1;
	data->size.x = abs((int)(screen.y / (data->transf.y)));
	data->start.x = -data->size.x / 2 + data->screenX;
	if (data->start.x < 0)
		data->start.x = 0;
	data->end.x = data->size.x / 2 + data->screenX;
	if (data->end.x >= screen.x)
		data->end.x = screen.x - 1;
}

void		ft_sprite(t_engine *eng, t_mlx *mlx, t_parsing *parse)
{
	t_sprite_lst	*sprite;
	static int		bool = 0;

	if (!bool++)
		ft_init_sprites(mlx, eng, parse);
	sprite = eng->sprite.data;
	while (sprite)
	{
		sprite->dist = hypot(eng->cam.pos.x - sprite->coord.x,
		eng->cam.pos.y - sprite->coord.y);
		sprite = sprite->next;
	}
	ft_sort_sprite(&eng->sprite.data);
	sprite = eng->sprite.data;
	while (sprite)
	{
		ft_set_data_sprite(&eng->sprite, eng->cam, parse->size, sprite);
		ft_draw_sprite(eng, mlx, parse->size, *sprite);
		sprite = sprite->next;
	}
}
