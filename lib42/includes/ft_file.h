/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 22:55:42 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/10 18:54:21 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILE_H
# define FT_FILE_H

# include "lib42.h"

void	ft_putchar(char c);
int		ft_putstr(char const *s);
void	ft_putnbr(int n);
int		get_next_line(int fd, char **line);
int		ft_fprintf(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);

#endif