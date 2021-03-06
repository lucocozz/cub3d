/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 18:21:08 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/20 00:50:47 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

int	ft_startswith(char *str, char *startswith)
{
	int	lstr;
	int	lstart;

	lstr = ft_strlen(str);
	lstart = ft_strlen(startswith);
	return (lstr < lstart ? 0 : ft_memcmp(startswith, str, lstart) == 0);
}
