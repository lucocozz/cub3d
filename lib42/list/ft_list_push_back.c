/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 06:31:38 by lucocozz          #+#    #+#             */
/*   Updated: 2019/07/25 19:56:58 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*tmp;

	tmp = *begin_list;
	if (!tmp)
		*begin_list = ft_create_elem(data);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_create_elem(data);
	}
}
