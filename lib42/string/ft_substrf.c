/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substrf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:33:44 by lucocozz          #+#    #+#             */
/*   Updated: 2020/04/17 19:53:08 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_substrf(char *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((substr = ft_calloc(len + 1, sizeof(char))) == NULL)
		return (NULL);
	if (start < ft_strlen(s))
		while (i < len && s[start + i])
		{
			substr[i] = s[start + i];
			i++;
		}
	substr[i] = '\0';
	ft_strdel(s);
	return (substr);
}
