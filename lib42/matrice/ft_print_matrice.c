/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrice.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:47:24 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/20 04:54:29 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

void	ft_print_matrice(char **matrice)
{
	int	i;

	i = 0;
	while (matrice[i])
		ft_printf("%s\n", matrice[i++]);
}
