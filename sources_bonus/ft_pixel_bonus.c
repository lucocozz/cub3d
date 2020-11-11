/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 17:36:40 by lucocozz          #+#    #+#             */
/*   Updated: 2020/11/11 21:35:40 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		ft_invert_pixel_color(int pixel)
{
	int	invert_pixel;

	invert_pixel = 0;
	invert_pixel += ((255 - ((RED & pixel) >> 16)) << 16);
	invert_pixel += ((255 - ((GREEN & pixel) >> 8)) << 8);
	invert_pixel += (255 - (BLUE & pixel));
	return (invert_pixel);
}

int		ft_grayscale_pixel(int pixel)
{
	int	gray;
	int grayscale_pixel;

	grayscale_pixel = 0;
	gray = (((RED & pixel) >> 16) + ((GREEN & pixel) >> 8) + (BLUE & pixel))
		/ 3;
	grayscale_pixel += (gray << 16);
	grayscale_pixel += (gray << 8);
	grayscale_pixel += gray;
	return (grayscale_pixel);
}

void	ft_filter_image(t_mlx *mlx, t_parsing parse, int (*ft)(int))
{
	int		color;
	t_coord axe;
	
	axe.y = 0;
	while (axe.y < parse.size.y)
	{
		axe.x = 0;
		while (axe.x < parse.size.x)
		{
			color = mlx->img.data[axe.y * parse.size.x + axe.x];
			mlx->img.data[axe.y * parse.size.x + axe.x] = ft(color);
			axe.x++;
		}
		axe.y++;
	}
}