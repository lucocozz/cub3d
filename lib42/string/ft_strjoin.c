/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 10:12:14 by lucocozz          #+#    #+#             */
/*   Updated: 2020/03/10 04:09:43 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strnew;

	if (!s1 || !s2)
		return (NULL);
	if (s1[0] == '\0' && s2[0] == '\0')
		return (ft_strdup(""));
	strnew = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (strnew == NULL)
		return (NULL);
	ft_strcpy(strnew, (char*)s1);
	ft_strcat(strnew, (char*)s2);
	return (strnew);
}
