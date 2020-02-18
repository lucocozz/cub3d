/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:37:35 by lucocozz          #+#    #+#             */
/*   Updated: 2019/12/04 20:10:16 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;

	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	if (dest == src)
		return (dest);
	if (tmp_dest > tmp_src)
		while (n-- > 0)
			*(tmp_dest + n) = *(tmp_src + n);
	else
		while (n-- > 0)
			*tmp_dest++ = *tmp_src++;
	return (dest);
}
