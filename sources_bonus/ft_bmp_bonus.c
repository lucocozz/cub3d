/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 17:26:57 by lucocozz          #+#    #+#             */
/*   Updated: 2020/06/04 20:07:12 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static t_pixel	**ft_rotate_flip_bmp(t_pixel **pixels, t_parsing *parse)
{
	t_coord	axe;
	t_pixel	**pixels_rot;

	axe.y = 0;
	pixels_rot = (t_pixel**)ft_malloc_matrice(parse->size.x, parse->size.y,
	sizeof(t_pixel*), sizeof(t_pixel));
	while (axe.y < parse->size.y)
	{
		axe.x = 0;
		while (axe.x < parse->size.x)
		{
			pixels_rot[axe.y][axe.x] = pixels[(parse->size.y - 1) - axe.y]
			[axe.x];
			axe.x++;
		}
		axe.y++;
	}
	return (pixels_rot);
}

static t_pixel	**ft_get_pixels(t_parsing *parse, t_mlx *mlx, t_bmp bmp)
{
	t_coord					axe;
	t_pixel					**pixels;

	pixels = (t_pixel**)ft_malloc_matrice(parse->size.x, parse->size.y,
	sizeof(t_pixel*), sizeof(t_pixel));
	while (axe.y < parse->size.y)
	{
		axe.x = 0;
		while (axe.x < parse->size.x)
		{
			bmp.pixel.r = (mlx->img.data[axe.y * parse->size.x + axe.x]
			& RED) >> 16;
			bmp.pixel.g = (mlx->img.data[axe.y * parse->size.x + axe.x]
			& GREEN) >> 8;
			bmp.pixel.b = (mlx->img.data[axe.y * parse->size.x + axe.x]
			& BLUE);
			pixels[axe.y][axe.x] = bmp.pixel;
			axe.x++;
		}
		axe.y++;
	}
	return (pixels);
}

static void		ft_put_pixels(int fd, t_parsing *parse, t_mlx *mlx, t_bmp bmp)
{
	int						y;
	t_pixel					**pixels;
	t_pixel					**pixels_rot;
	static unsigned char	zeroes[3] = {0, 0, 0};

	y = 0;
	pixels = ft_get_pixels(parse, mlx, bmp);
	pixels_rot = ft_rotate_flip_bmp(pixels, parse);
	while (y < parse->size.y)
	{
		write(fd, pixels_rot[y], bmp.pixel_bpr);
		write(fd, zeroes, bmp.pad_bpr);
		y++;
	}
	ft_free_matrice((void**)pixels, parse->size.y);
	ft_free_matrice((void**)pixels_rot, parse->size.y);
}

void		ft_bmp(t_parsing *parse, t_mlx *mlx)
{
	int						fd;
	t_bmp					bmp;
	static unsigned char	header[54] = {66, 77, 0, 0, 0, 0, 0, 0, 0, 0, 54, 0,
	0, 0, 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24};

	fd = open("save.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR
	| S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	bmp.pixel_bpr = parse->size.x * sizeof(t_pixel);
	bmp.pad_bpr = (4 - (bmp.pixel_bpr % 4)) % 4;
	bmp.sof_entry = (unsigned int*)&header[2];
	*bmp.sof_entry = 54 + (bmp.pixel_bpr + bmp.pad_bpr) * parse->size.y;
	bmp.width_entry = (unsigned int*)&header[18];
	*bmp.width_entry = parse->size.x;
	bmp.hight_entry = (unsigned int*)&header[22];
	*bmp.hight_entry = parse->size.y;
	write(fd, header, 54);
	ft_put_pixels(fd, parse, mlx, bmp);
	close(fd);
}
