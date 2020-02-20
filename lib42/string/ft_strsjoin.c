/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 03:23:03 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/14 17:15:40 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

static char	*ft_join(char *strnew, char **strs, char *sep, int size)
{
	int i;
	int j;
	int bl;

	i = 0;
	j = 0;
	bl = 1;
	while (i < size)
	{
		ft_strcpy(&strnew[j], (bl ? strs[i] : sep));
		j += ft_strlen((bl ? strs[i] : sep));
		i += (bl ? 1 : 0);
		bl = (bl ? 0 : 1);
	}
	return (strnew);
}

char		*ft_strsjoin(int size, char **strs, char *sep)
{
	int		i;
	int		len;
	char	*strnew;

	i = 0;
	len = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	len += ft_strlen(sep) * (size - 1);
	if ((strnew = ft_calloc((size > 0 ? len : 0) + 1, sizeof(char))) == NULL)
		return (NULL);
	if (size <= 0)
		return (strnew);
	return (ft_join(strnew, strs, sep, size));
}
