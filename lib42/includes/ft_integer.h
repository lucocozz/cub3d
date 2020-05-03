/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 22:44:26 by lucocozz          #+#    #+#             */
/*   Updated: 2020/05/03 00:40:05 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INTEGER_H
# define FT_INTEGER_H

# include "lib42.h"

int					ft_nbrlen(long n, int base);
int					ft_atoi(const char *str);
int					ft_atoui(const char *str);
char				*ft_itoa_base(int value, char *base);
char				*ft_uitoa_base(unsigned int n, char const *base);
int					ft_atoi_base(char *str, char *base);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
char				*ft_itoa(int n);
char				*ft_uitoa(unsigned int n);
char				*ft_ltoa_base(long n, char const *base);

#endif
