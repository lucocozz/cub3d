/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 19:35:00 by lucocozz          #+#    #+#             */
/*   Updated: 2020/04/19 18:08:31 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_sprite_lst	*ft_create_sprite(t_garbage *garb, t_coord axe, int texture)
{
	t_mlx			*mlx;
	t_engine		*eng;
	t_parsing		*parse;
	t_sprite_lst	*sprite;

	mlx = (t_mlx*)garb->mlx;
	eng = (t_engine*)garb->engine;
	parse = (t_parsing*)garb->parse;
	if ((sprite = malloc(sizeof(t_sprite_lst) * 1)) == NULL)
		return (NULL);
	sprite->img.ptr = mlx_xpm_file_to_image(mlx->ptr,
	((char **)(&parse->sprite))[texture], &sprite->size.x, &sprite->size.y);
	sprite->img.data = (int*)mlx_get_data_addr(sprite->img.ptr, &sprite->img.bpp,
	&sprite->img.size, &sprite->img.endian);
	sprite->coord.x = axe.x;
	sprite->coord.y = axe.y;
	sprite->next = NULL;
	return (sprite);
}

void				ft_free_sprite(t_garbage *garb)
{
	t_engine		*eng;
	t_sprite_lst	*prev;
	t_sprite_lst	*sprites;

	eng = (t_engine*)garb->engine;
	sprites = (t_sprite_lst*)eng->sprite.data;
	while (sprites)
	{
		mlx_destroy_image(garb->mlx->ptr, sprites->img.ptr);
		prev = sprites;
		sprites = sprites->next;
		free(prev);
	}
}

void				ft_push_sprite(t_sprite_lst **sprites, t_garbage *garb,
t_coord axe, int texture)
{
	t_sprite_lst	*tmp;

	tmp = *sprites;
	if (!tmp)
		*sprites = ft_create_sprite(garb, axe, texture);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_sprite(garb, axe, texture);
	}
}

static void			ft_swap_sprite(t_sprite_lst *curr, t_sprite_lst *next)
{
	t_sprite_lst	*tmp;

	if ((tmp = malloc(sizeof(t_sprite_lst) * 1)) == NULL)
		return ;
	tmp->coord = curr->coord;
	tmp->dist = curr->dist;
	tmp->img = curr->img;
	tmp->size = curr->size;
	curr->coord = next->coord;
	curr->dist = next->dist;
	curr->img = next->img;
	curr->size = next->size;
	next->coord = tmp->coord;
	next->dist = tmp->dist;
	next->img = tmp->img;
	next->size = tmp->size;
	free(tmp);
}

void				ft_sort_sprite(t_sprite_lst **sprites)
{
	t_sprite_lst	*curr;
	t_sprite_lst	*next;

	curr = *sprites;
	if (curr == NULL || curr->next == NULL)
		return ;
	while (curr->next)
	{
		next = curr->next;
		if (curr->dist > next->dist)
		{
			ft_swap_sprite(curr, next);
			curr = *sprites;
		}
		else
			curr = curr->next;
	}
}