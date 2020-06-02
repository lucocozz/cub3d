/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 01:05:12 by lucocozz          #+#    #+#             */
/*   Updated: 2020/06/02 16:39:50 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static t_key_event	g_event[N_KEYS] = {
	{ESC_KEY, &ft_exit_cub}, {W_KEY, &ft_w_key}, {A_KEY, &ft_a_key},
	{S_KEY, &ft_s_key}, {D_KEY, &ft_d_key}, {RIGHT_KEY, &ft_right_key},
	{LEFT_KEY, &ft_left_key}
};

void		ft_events_hook(t_garbage garbage)
{
	t_mlx	*mlx;

	mlx = garbage.mlx;
	mlx_hook(mlx->win, DESTROYNOTIFY, 0, &ft_exit_cub, (void*)&garbage);
	mlx_hook(mlx->win, KEYPRESS, 1, &ft_press_event, (void*)&garbage);
	mlx_hook(mlx->win, KEYRELEASE, 2, &ft_release_event, (void*)&garbage);
	mlx_loop_hook(mlx->ptr, &ft_loop_event, (void*)&garbage);
	mlx_loop(mlx->ptr);
}

int			ft_press_event(int key, t_garbage *garb)
{
	int	i;

	i = 0;
	while (i < N_KEYS && g_event[i].key != key)
		i++;
	if (i == N_KEYS)
		return (0);
	garb->engine->key |= 1 << i;
	return (1);
}

int			ft_release_event(int key, t_garbage *garb)
{
	int	i;

	i = 0;
	(void)garb;
	while (i < N_KEYS && g_event[i].key != key)
		i++;
	if (i == N_KEYS)
		return (0);
	garb->engine->key &= ~(1 << i);
	return (1);
}

int			ft_loop_event(t_garbage *garb)
{
	int				i;
	t_mlx			*mlx;

	i = 0;
	mlx = garb->mlx;
	if (garb->engine->key)
	{
		ft_clear_img(mlx, garb->parse);
		while (i < N_KEYS)
		{
			if ((garb->engine->key >> i) & 1)
				g_event[i].event(garb);
			i++;
		}
		ft_display_img(garb->engine, garb->parse, mlx);
	}
	return (1);
}
