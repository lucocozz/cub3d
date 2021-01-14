/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_cub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:05:20 by lucocozz          #+#    #+#             */
/*   Updated: 2021/01/14 17:05:11 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	ft_memdel((void**)&garb->engine->z_buff);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_exit_parsing(t_parsing *parse, char *str)
{
	ft_free_parsing(parse);
	ft_exit_error(str);
}
