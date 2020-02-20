/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 08:12:07 by lucocozz          #+#    #+#             */
/*   Updated: 2019/07/18 09:08:17 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *prev;

	while (begin_list)
	{
		(*free_fct)(begin_list->data);
		prev = begin_list;
		begin_list = begin_list->next;
		free(prev);
	}
}
