/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 02:15:43 by lucocozz          #+#    #+#             */
/*   Updated: 2019/12/04 20:05:10 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

static char	*ft_conv(int nbr, char *base_to, char *str, int neg)
{
	int i;
	int size;

	i = 0;
	size = ft_strlen(base_to);
	if (nbr == 0)
		str[i++] = base_to[0];
	while (nbr > 0)
	{
		str[i++] = base_to[nbr % size];
		nbr /= size;
	}
	str[i++] = (neg ? '-' : '\0');
	str[i] = '\0';
	return (ft_strrev(str));
}

char		*ft_itoa_base(int nbr, char *base)
{
	int		neg;
	char	*str;
	int		len;

	neg = 0;
	len = ft_nbrlen(nbr, ft_strlen(base));
	if (nbr < 0)
	{
		neg = 1;
		nbr *= -1;
	}
	if ((str = ft_calloc(len + 1, sizeof(char))) == NULL)
		return (NULL);
	return (ft_conv(nbr, base, str, neg));
}
