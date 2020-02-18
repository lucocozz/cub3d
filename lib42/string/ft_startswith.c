/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:21:08 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/11 18:22:45 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

int	ft_startswith(char *str, char *startswith)
{
	int	i;

	i = 0;
	while (str[i] == startswith[i] && str[i] && startswith[i])
		i++;
	if (str[i] == startswith[i] && !startswith[i])
		return (1);
	return (0);
}
