/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 04:15:07 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/20 04:55:28 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

char	**ft_list_to_array(t_list **alst)
{
	int		i;
	t_list	*lst;
	t_list	*next;
	char	**array;

	i = 0;
	lst = *alst;
	if ((array = malloc(sizeof(char*) * (ft_list_size(lst) + 1))) == NULL)
		return (NULL);
	while (lst)
	{
		array[i++] = lst->data;
		next = lst->next;
		free(lst);
		lst = next;
	}
	array[i] = NULL;
	*alst = NULL;
	return (array);
}
