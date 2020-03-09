/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 01:05:12 by lucocozz          #+#    #+#             */
/*   Updated: 2020/03/08 10:32:45 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_key_event	g_event[N_KEYS] = {
	{ESC_KEY, &ft_exit_cub}, {W_KEY, &ft_w_key}, {A_KEY, &ft_a_key},
	{S_KEY, &ft_s_key}, {D_KEY, &ft_d_key}, {RIGHT_KEY, &ft_right_key},
	{LEFT_KEY, &ft_left_key}
};

void	ft_events_hook(t_garbage garbage)
{
	t_mlx	*mlx;

	mlx = garbage.mlx;
	mlx_do_key_autorepeaton(mlx->ptr);
	mlx_hook(mlx->win, DESTROYNOTIFY, 0, &ft_exit_cub, (void*)&garbage);
	mlx_hook(mlx->win, KEYPRESS, 0, &ft_press_event, (void*)&garbage);
	mlx_hook(mlx->win, KEYRELEASE, 0, &ft_release_event, (void*)&garbage);
	mlx_loop_hook(mlx->ptr, &ft_loop_event, (void*)&garbage);
	mlx_loop(mlx->ptr);
}

int		ft_exit_cub(t_garbage *garb)
{
	int				i;
	t_texture_data	*tmp;

	i = 0;
	ft_free_parsing(garb->parse);
	mlx_destroy_image(garb->mlx->ptr, garb->mlx->img.ptr);
	if (garb->mlx->win)
		mlx_destroy_window(garb->mlx->ptr, garb->mlx->win);
	ft_free_matrice((void**)garb->engine->map.array, garb->parse->map.y);
	while (i < N_TEXTURES)
	{
		tmp = &((t_texture_data *)(&garb->engine->texture))[i];
		mlx_destroy_image(garb->mlx->ptr, tmp->ptr);
		i++;
	}
	exit(EXIT_SUCCESS);
	return (0);
}

int		ft_press_event(int key, t_garbage *garb)
{
	int	i;

	i = 0;
	while (i < N_KEYS && g_event[i].key != key)
		i++;
	if (i == N_KEYS)
		return (0);
	g_event[i].event(garb);
	return (1);
}

int		ft_release_event(int key, t_garbage *garb)
{
	int	i;

	i = 0;
	(void)garb;
	while (i < N_KEYS && g_event[i].key != key)
		i++;
	if (i == N_KEYS)
		return (0);
	return (1);
}

int		ft_loop_event(int key, t_garbage *garb)
{
	(void)key;
	(void)garb;
	return (1);
}
