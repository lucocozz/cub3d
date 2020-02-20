/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:54:02 by lucocozz          #+#    #+#             */
/*   Updated: 2019/07/25 17:30:32 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int i;

	i = 0;
	if (!begin_list)
		return (NULL);
	while (i < nbr && begin_list->next != NULL)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}
