/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:13:42 by lucocozz          #+#    #+#             */
/*   Updated: 2021/01/14 16:56:01 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		ft_raycast(t_parsing *parse, t_engine *eng, t_mlx *mlx)
{
	int			x;
	static int	bool = 0;
	t_raycast	ray;

	x = 0;
	if (!bool++)
		ft_get_textures_img(eng, mlx, *parse);
	while (x < parse->size.x)
	{
		ray = ft_ray(eng->cam, *parse, x);
		ft_draw(eng, mlx, *parse, &ray);
		eng->z_buff[x++] = ray.pw_dist;
	}
}

void		ft_draw(t_engine *eng, t_mlx *mlx, t_parsing parse, t_raycast *ray)
{
	int				i;
	t_texture_data	*texture;

	texture = NULL;
	if ((i = ft_strchri(WALLS, parse.map.array[ray->map.y][ray->map.x])) > -1)
		texture = &((t_texture_data *)(&eng->texture))[i];
	ft_texturing((t_garbage){&parse, mlx, eng}, texture, ray);
}

void		ft_clear_screen(t_mlx *mlx, t_parsing *parse)
{
	t_coord		axe;
	void		*ptr;
	int			*img;

	axe.y = 0;
	ptr = mlx_new_image(mlx->ptr, parse->size.x, parse->size.y);
	img = (int*)mlx_get_data_addr(mlx->img.ptr, &mlx->img.bpp,
	&mlx->img.size, &mlx->img.endian);
	while (axe.y < parse->size.y)
	{
		axe.x = 0;
		while (axe.x < parse->size.x)
		{
			img[axe.y * parse->size.x + axe.x] = 0;
			axe.x++;
		}
		axe.y++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, ptr, 0, 0);
	mlx_destroy_image(mlx->ptr, ptr);
}

void		ft_get_screen(t_engine *eng, t_parsing *parse, t_mlx *mlx)
{
	ft_box(*parse, &eng->box, eng->cam, mlx);
	ft_raycast(parse, eng, mlx);
	ft_sprite(eng, mlx, parse);
}

void		ft_display_screen(t_engine *eng, t_parsing *parse, t_mlx *mlx)
{
	ft_get_screen(eng, parse, mlx);
	ft_draw_reticle(mlx, *parse);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
}
