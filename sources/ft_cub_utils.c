/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:38:10 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/14 04:54:08 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_parse_cub	ft_init_cub_data(void)
{
	int			i;
	t_parse_cub	cub_data;

	i = 0;
	while (i < N_TEXTURES)
		((char **)(&cub_data.texture))[i++] = NULL;
	i = 0;
	while (i < N_COLORS)
		((int *)(&cub_data.color))[i++] = 0;
	i = 0;
	while (i < 2)
		((int *)(&cub_data.size))[i++] = 0;
	cub_data.map.array = NULL;
	cub_data.map.x = 0;
	cub_data.map.y = 0;
	return (cub_data);
}
