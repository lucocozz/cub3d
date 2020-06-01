/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_in_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 19:57:11 by lucocozz          #+#    #+#             */
/*   Updated: 2020/05/29 16:03:43 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	*ft_rep_in_str(char *str, char to_replace, char new)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_replace)
			str[i] = new;
		i++;
	}
	return (str);
}
