/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:04:32 by lucocozz          #+#    #+#             */
/*   Updated: 2019/12/04 20:09:54 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *tmp;

	if ((tmp = malloc(size * count)) == NULL)
		return (NULL);
	ft_bzero(tmp, count * size);
	return (tmp);
}
