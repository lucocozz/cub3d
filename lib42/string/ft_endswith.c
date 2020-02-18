/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_endswith.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:12:45 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/11 18:13:29 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

int	ft_endswith(char *str, char *endswith)
{
	int	i;
	int j;

	i = ft_strlen(str);
	j = ft_strlen(endswith);
	while (str[i] == endswith[j] && i && j)
	{
		i--;
		j--;
	}
	if (str[i] == endswith[j] && !j)
		return (1);
	return (0);
}
