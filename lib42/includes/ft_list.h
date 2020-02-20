/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 04:53:46 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/20 04:38:04 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
# define FT_LIST_H

# include "lib42.h"

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

t_list				*ft_create_elem(void *data);
t_list				*ft_list_at(t_list *begin_list, unsigned int nbr);
void				ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
t_list				*ft_list_last(t_list *begin_list);
void				ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void				ft_list_push_back(t_list **begin_list, void *data);
void				ft_list_push_front(t_list **begin_list, void *data);
void				ft_list_reverse(t_list **begin_list);
int					ft_list_size(t_list *begin_list);
void				ft_list_print(t_list *lst);
char				**ft_list_to_array(t_list **alst);

#endif
