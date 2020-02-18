/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strscat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:54:27 by lucocozz          #+#    #+#             */
/*   Updated: 2019/12/04 20:12:03 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_strscat(size_t size, ...)
{
	size_t	i;
	char	*strn;
	char	*str;
	va_list	ap;

	i = 0;
	if (size == 0)
		return (NULL);
	va_start(ap, size);
	while (i < size)
	{
		str = va_arg(ap, char *);
		if (!i)
			strn = ft_strdup(str);
		else
		{
			strn = ft_srealloc(strn, ft_strlen(str) + ft_strlen(strn) + 1);
			ft_strcat(strn, str);
		}
		i++;
	}
	va_end(ap);
	return (strn);
}
