/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:38:10 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/26 17:49:05 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_parse_cub		ft_init_cub_data(void)
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

int				ft_check_cub_data(t_parse_cub cub_data)
{
	int	i;

	i = 0;
	while (i < N_TEXTURES)
		if (((char **)(&cub_data.texture))[i++] == NULL)
			return (0);
	i = 0;
	while (i < 2)
		if (((int *)(&cub_data.size))[i++] == 0)
			return (0);
	if (cub_data.map.array == NULL)
		return (0);
	if (cub_data.map.x < 3 || cub_data.map.y < 3)
		return (0);
	return (1);
}

void			ft_free_cub_data(t_parse_cub *cub_data)
{
	int	i;

	i = 0;
	while (i < N_TEXTURES)
		ft_strdel(((char **)(&cub_data->texture))[i++]);
	i = 0;
	ft_free_matrice((void**)cub_data->map.array, cub_data->map.y);
}

void			ft_exit_parse_map(char *s, t_parse_cub *cub_data, t_list *lst)
{
	ft_list_clear(lst, &free);
	ft_free_cub_data(cub_data);
	ft_exit_error(s);
}

t_screen_cub	ft_init_screen(t_parse_cub cub_data)
{
	t_screen_cub	s;

	s.mlx = mlx_init();
	mlx_do_key_autorepeaton(s.mlx);
	s.win = mlx_new_window(s.mlx, cub_data.size.x, cub_data.size.y, "Cub3D");
	return (s);
}
