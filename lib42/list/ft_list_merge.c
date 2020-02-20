/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 11:00:49 by lucocozz          #+#    #+#             */
/*   Updated: 2019/07/25 17:21:02 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list *tmp;

	if (*begin_list1 == NULL)
		*begin_list1 = begin_list2;
	else
	{
		tmp = *begin_list1;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = begin_list2;
	}
}
