/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrice.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:12:54 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/14 18:50:34 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRICE_H
# define FT_MATRICE_H

# include "lib42.h"

void			ft_free_matrice(void **matrice, int size);
int				ft_matrice_len(char **matrice);
void			**ft_matrice_join(void **matrice, void *line, int size);

#endif