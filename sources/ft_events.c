/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 01:05:12 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/26 17:35:06 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_key_event	g_event[N_KEYS] = {
	{ESC_KEY, &ft_exit_cub}, {W_KEY, &ft_w_key}, {A_KEY, &ft_a_key},
	{S_KEY, &ft_s_key}, {D_KEY, &ft_d_key}
};

int	ft_exit_cub(void *param)
{
	t_garbage		*garbage;

	garbage = (t_garbage*)param;
	ft_free_cub_data(garbage->cub_data);
	mlx_destroy_window(garbage->screen->mlx, garbage->screen->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	ft_press_event(int key, void *param)
{
	int	i;

	i = 0;
	while (i < N_KEYS && g_event[i].key != key)
		i++;
	if (i == N_KEYS)
		return (0);
	g_event[i].event(param);
	return (1);
}

int	ft_release_event(int key, void *param)
{
	(void)key;
	(void)param;
	ft_printf("RELEASE\n");
	return (1);
}

int	ft_loop_event(int key, void *param)
{
	(void)key;
	(void)param;
	return (1);
}
