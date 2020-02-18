/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tabs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 04:07:33 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/14 04:24:10 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

void	ft_free_tabs(void **tabs, int size)
{
	int	i;

	i = 0;
	if (tabs)
	{
		while (i < size)
			ft_memdel((void**)&tabs[i++]);
		free(tabs);
	}
}
