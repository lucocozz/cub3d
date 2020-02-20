/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 05:32:10 by lucocozz          #+#    #+#             */
/*   Updated: 2019/07/25 20:06:39 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list *new;
	t_list *tmp;

	tmp = *begin_list;
	if (!tmp)
		*begin_list = ft_create_elem(data);
	else
	{
		new = ft_create_elem(data);
		new->next = tmp;
		*begin_list = new;
	}
}
