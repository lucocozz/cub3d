/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_cub_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 19:05:20 by lucocozz          #+#    #+#             */
/*   Updated: 2020/06/04 17:03:26 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		ft_exit_cub(t_garbage *garb)
{
	int				i;
	t_texture_data	*tmp;

	i = 0;
	ft_free_parsing(garb->parse);
	while (i < N_TEXTURES)
	{
		tmp = &((t_texture_data *)(&garb->engine->texture))[i++];
		mlx_destroy_image(garb->mlx->ptr, tmp->ptr);
	}
	mlx_destroy_image(garb->mlx->ptr, garb->engine->box.floor.img.ptr);
	mlx_destroy_image(garb->mlx->ptr, garb->engine->box.celling.img.ptr);
	ft_free_sprite(garb);
	if (garb->mlx->img.ptr)
		mlx_destroy_image(garb->mlx->ptr, garb->mlx->img.ptr);
	if (garb->mlx->win)
		mlx_destroy_window(garb->mlx->ptr, garb->mlx->win);
	ft_memdel((void**)&garb->engine->Zbuff);
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_exit_parsing(t_parsing *parse, char *str)
{
	ft_free_parsing(parse);
	ft_exit_error(str);
}

void			ft_exit_parse_map(char *s, t_parsing *parse, t_list *lst)
{
	ft_list_clear(lst, &free);
	ft_free_parsing(parse);
	ft_exit_error(s);
}