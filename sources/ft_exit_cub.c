/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:05:20 by lucocozz          #+#    #+#             */
/*   Updated: 2020/04/17 18:56:01 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_free_sprite(t_garbage *garb)
{
	int	i;

	i = 0;
	if (garb->engine->sprite.data)
	{
		while (i < garb->engine->sprite.nb)
			mlx_destroy_image(garb->mlx->ptr, garb->engine->sprite.data[i].img.ptr);
		ft_memdel((void**)&garb->engine->sprite.data);
	}
	ft_memdel((void**)&garb->engine->sprite.dist);
	ft_memdel((void**)&garb->engine->sprite.order);
}

int		ft_exit_cub(t_garbage *garb)
{
	int				i;
	t_texture_data	*tmp;

	i = 0;
	ft_free_parsing(garb->parse);
	ft_free_matrice((void**)garb->engine->map.array, garb->parse->map.y);
	while (i < N_TEXTURES)
	{
		tmp = &((t_texture_data *)(&garb->engine->texture))[i++];
		mlx_destroy_image(garb->mlx->ptr, tmp->ptr);
	}
	ft_free_sprite(garb);
	if (garb->mlx->img.ptr)
		mlx_destroy_image(garb->mlx->ptr, garb->mlx->img.ptr);
	if (garb->mlx->win)
		mlx_destroy_window(garb->mlx->ptr, garb->mlx->win);
	ft_memdel((void**)&garb->engine->Zbuff);
	exit(EXIT_SUCCESS);
	return (0);
}