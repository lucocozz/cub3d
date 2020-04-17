/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_sprites.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 12:26:25 by lucocozz          #+#    #+#             */
/*   Updated: 2020/04/17 18:33:37 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_img_data(t_mlx *mlx, t_engine *eng, t_parsing *parse, t_index n)
{
	eng->sprite.data[n.i].img.ptr = mlx_xpm_file_to_image(mlx->ptr,
	((char **)(&parse->sprite))[n.j], &eng->sprite.data[n.i].size.x,
	&eng->sprite.data[n.i].size.y);
	eng->sprite.data[n.i].img.data = mlx_get_data_addr(
	eng->sprite.data[n.i].img.ptr, &eng->sprite.data[n.i].img.bpp,
	&eng->sprite.data[n.i].img.size, &eng->sprite.data[n.i].img.endian);
}

static void	ft_sprite_data(t_mlx *mlx, t_engine *eng, t_parsing *parse)
{
	t_index n;
	t_coord	a;

	n.i = 0;
	a.y = 0;
	while (a.y < parse->map.y)
	{
		a.x = 0;
		while (a.x < parse->map.x)
		{
			if ((n.j = ft_strchri(SPRITES, parse->map.array[a.y][a.x])) > -1)
			{
				eng->sprite.data[n.i].coord.x = a.x;
				eng->sprite.data[n.i].coord.y = a.y;
				ft_img_data(mlx, eng, parse, n);
				n.i++;
			}
			a.x++;
		}
		a.y++;
	}
}

static void	ft_alloc_sprite(t_mlx *mlx, t_engine *eng, t_parsing *parse)
{
	if (!(eng->sprite.order = malloc(sizeof(int) * eng->sprite.nb)))
		ft_exit_cub(&(t_garbage){&parse, &mlx, &eng});
	if (!(eng->sprite.dist = malloc(sizeof(int) * eng->sprite.nb)))
		ft_exit_cub(&(t_garbage){&parse, &mlx, &eng});
	if (!(eng->sprite.data = malloc(sizeof(t_sprite_data) * eng->sprite.nb)))
		ft_exit_cub(&(t_garbage){&parse, &mlx, &eng});
}

void		ft_init_sprites(t_mlx *mlx, t_engine *eng, t_parsing *parse)
{
	int	i;
	int j;

	i = 0;
	eng->sprite.nb = 0;
	while (i < parse->map.y)
	{
		j = 0;
		while (j < parse->map.x)
		{
			if (!ft_strchr(SPRITES, parse->map.array[i][j]))
				eng->sprite.nb += 1;
			j++;
		}
		i++;
	}
	ft_alloc_sprite(mlx, eng, parse);
	ft_sprite_data(mlx, eng, parse);
}
