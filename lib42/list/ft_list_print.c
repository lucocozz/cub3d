/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 00:03:47 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/19 00:04:15 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

void	ft_list_print(t_list *lst)
{
	while (lst)
	{
		ft_printf("%s -> ", (char *)lst->data);
		lst = lst->next;
	}
	ft_printf("NULL\n");
}
