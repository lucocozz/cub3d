/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrice_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:42:04 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/14 17:51:59 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

int		ft_matrice_len(char **matrice)
{
	int	i;

	i = 0;
	while (matrice[i])
		i++;
	return (i);
}
