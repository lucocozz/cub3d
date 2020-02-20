/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 05:16:54 by lucocozz          #+#    #+#             */
/*   Updated: 2019/07/18 05:27:50 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *elem;

	if ((elem = malloc(sizeof(t_list) * 1)) == NULL)
		return (NULL);
	elem->data = data;
	elem->next = NULL;
	return (elem);
}
