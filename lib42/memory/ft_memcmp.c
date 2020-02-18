/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:12:46 by lucocozz          #+#    #+#             */
/*   Updated: 2019/12/04 20:10:08 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pt1;
	unsigned char	*pt2;
	size_t			i;

	pt1 = (unsigned char*)s1;
	pt2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (pt1[i] != pt2[i])
			return ((int)(pt1[i] - pt2[i]));
		i++;
	}
	return (0);
}
