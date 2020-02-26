/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 17:20:41 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/26 17:28:28 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_w_key(void *param)
{
	(void)param;
	ft_printf("W\n");
	return (1);
}

int	ft_a_key(void *param)
{
	(void)param;
	ft_printf("A\n");
	return (1);
}

int	ft_s_key(void *param)
{
	(void)param;
	ft_printf("S\n");
	return (1);
}

int	ft_d_key(void *param)
{
	(void)param;
	ft_printf("D\n");
	return (1);
}
