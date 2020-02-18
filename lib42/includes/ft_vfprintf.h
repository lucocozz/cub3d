/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 17:33:12 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/10 18:55:34 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VFPRINTF_H
# define FT_VFPRINTF_H

# include "lib42.h"
# include <stdarg.h>
# include <stdint.h>

# define TYPES "cspdiuxX%"
# define N_TYPES 9
# define VFPRINTF_BUFFER_SIZE 4096

typedef struct	s_types
{
	char		name;
	void		(*function)();
}				t_types;

typedef struct	s_parse
{
	int			padding;
	int			width;
	int			precision;
	char		fill;
	char		type;
}				t_parse;

typedef struct	s_buffer
{
	int			i;
	int			len;
	int			fd;
	char		data[VFPRINTF_BUFFER_SIZE];
}				t_buffer;

int				ft_vfprintf(int fd, const char *format, va_list ap);
t_parse			ft_init_parse(void);
void			ft_print_buffer(t_buffer *buffer);
void			ft_insert_in_buffer(t_buffer *buffer, char c);
void			ft_insert_str(t_buffer *buffer, t_parse *data, char *str);
void			ft_insert_format(t_buffer *buffer, t_parse *data, char c);
void			ft_c(va_list ap, t_parse data, t_buffer *buffer);
void			ft_s(va_list ap, t_parse data, t_buffer *buffer);
void			ft_p(va_list ap, t_parse data, t_buffer *buffer);
void			ft_d(va_list ap, t_parse data, t_buffer *buffer);
void			ft_i(va_list ap, t_parse data, t_buffer *buffer);
void			ft_u(va_list ap, t_parse data, t_buffer *buffer);
void			ft_x(va_list ap, t_parse data, t_buffer *buffer);
void			ft_xu(va_list ap, t_parse data, t_buffer *buffer);
void			ft_per(va_list ap, t_parse data, t_buffer *buffer);
int				ft_parse_padding(char c, t_parse *data);
int				ft_parse_fill(char c, t_parse *data);
int				ft_parse_width(const char *s, t_parse *data, va_list ap);
int				ft_parse_precision(const char *s, t_parse *data, va_list ap);

#endif
