/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:38:10 by lucocozz          #+#    #+#             */
/*   Updated: 2021/02/08 16:38:50 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_parsing		ft_init_parsing(void)
{
	int			i;
	t_parsing	parse;

	i = 0;
	while (i < N_TEXTURES)
		((char **)(&parse.texture))[i++] = NULL;
	i = 0;
	while (i < N_SPRITES)
		((char **)(&parse.sprite))[i++] = NULL;
	i = 0;
	while (i < N_COLORS)
		((int *)(&parse.color))[i++] = -1;
	parse.size.x = 0;
	parse.size.y = 0;
	parse.map.array = NULL;
	parse.map.x = 0;
	parse.map.y = 0;
	return (parse);
}

int				ft_check_parsing(t_parsing parse)
{
	int	i;

	i = 0;
	while (i < N_TEXTURES)
		if (((char **)(&parse.texture))[i++] == NULL)
			return (-1);
	i = 0;
	while (i < N_SPRITES)
		if (((char **)(&parse.sprite))[i++] == NULL)
			return (-1);
	i = 0;
	while (i < 2)
		if (((int *)(&parse.size))[i++] == 0)
			return (-1);
	if (parse.color.roof == -1)
		return (-1);
	if (parse.color.top == -1)
		return (-1);
	if (parse.map.array == NULL)
		return (0);
	if (parse.map.x < 3 || parse.map.y < 3)
		return (-1);
	return (1);
}

void			ft_free_parsing(t_parsing *parse)
{
	int	i;

	i = 0;
	while (i < N_TEXTURES)
		ft_strdel(((char **)(&parse->texture))[i++]);
	i = 0;
	while (i < N_SPRITES)
		ft_strdel(((char **)(&parse->sprite))[i++]);
	i = 0;
	ft_free_matrice((void**)parse->map.array, parse->map.y);
}

void			ft_exit_parse_map(char *s, t_parsing *parse, t_list *lst)
{
	ft_list_clear(lst, &free);
	ft_free_parsing(parse);
	ft_exit_error(s);
}

t_mlx			ft_init_mlx(t_parsing parse)
{
	t_mlx	mlx;

	mlx.img.bpp = 32;
	mlx.ptr = mlx_init();
	mlx.img.size = parse.size.x * 4;
	mlx.img.ptr = mlx_new_image(mlx.ptr, parse.size.x, parse.size.y);
	mlx.img.data = (int*)mlx_get_data_addr(mlx.img.ptr, &mlx.img.bpp,
	&mlx.img.size, &mlx.img.endian);
	return (mlx);
}
