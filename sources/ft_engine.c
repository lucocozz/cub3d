/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:13:42 by lucocozz          #+#    #+#             */
/*   Updated: 2021/02/09 16:34:00 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



// void		ft_display_img(t_engine *eng, t_parsing *parse, t_mlx *mlx)
// {
// 	t_coord		axe;
// 	void		*ptr;
// 	int			*img;

// 	axe.y = 0;
// 	ptr = mlx_new_image(mlx->ptr, parse->size.x, parse->size.y);
// 	img = (int*)mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp,
// 	&mlx->img.size, &mlx->img.endian);
// 	while (axe.y < parse->size.y)
// 	{
// 		axe.x = 0;
// 		while (axe.x < parse->size.x)
// 		{
// 			img[axe.y * parse->size.x + axe.x] = 0;
// 			axe.x++;
// 		}
// 		axe.y++;
// 	}
// 	mlx_put_image_to_window(mlx->ptr, mlx->win, ptr, 0, 0);
// 	mlx_destroy_image(mlx->ptr, ptr);
// 	ft_raycast(parse, eng, mlx);
// 	ft_sprite(eng, mlx, parse);
// 	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
// }
