/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_matrice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 09:40:55 by lucocozz          #+#    #+#             */
/*   Updated: 2020/03/08 10:02:03 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

void	**ft_malloc_matrice(int x, int y, size_t size_ptr, size_t size_data)
{
	int		i;
	void	**matrice;

	i = 0;
	if ((matrice = malloc(sizeof(size_ptr) * y)) == NULL)
		return (NULL);
	while (i < y)
	{
		if ((matrice[i] = malloc(sizeof(size_data) * x)) == NULL)
		{
			ft_free_matrice(matrice, y);
			return (NULL);
		}
		i++;
	}
	return (matrice);
}
