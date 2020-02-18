/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tabs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 04:07:33 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/14 17:37:44 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

void	ft_free_matrice(void **matrice, int size)
{
	int	i;

	i = 0;
	if (matrice)
	{
		while (i < size)
			ft_memdel((void**)&matrice[i++]);
		free(matrice);
	}
}
