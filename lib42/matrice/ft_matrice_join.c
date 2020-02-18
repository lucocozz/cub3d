/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrice_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:55:52 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/14 18:51:03 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

void	**ft_matrice_join(void **matrice, void *line, int size)
{
	int		i;
	void	**new;

	i = 0;
	if ((new = malloc(sizeof(matrice) * size + 1)) == NULL)
		return (NULL);
	while (i < size)
	{
		new[i] = matrice[i];
		i++;
	}
	new[i++] = line;
	new[i] = NULL;
	free(matrice);
	return (new);
}
