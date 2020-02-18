/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srealloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:48:14 by lucocozz          #+#    #+#             */
/*   Updated: 2019/12/04 20:11:06 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_srealloc(char *str, size_t size)
{
	char	*strnew;

	if (!size)
	{
		if (str)
			free(str);
		return (NULL);
	}
	if (size <= ft_strlen(str))
	{
		strnew = str;
		free(str);
	}
	else
	{
		if ((strnew = ft_calloc(size, sizeof(char))) == NULL)
			return (NULL);
		if (str != NULL)
		{
			ft_strcpy(strnew, str);
			free(str);
		}
	}
	return (strnew);
}
