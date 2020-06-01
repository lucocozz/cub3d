/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 19:57:06 by lucocozz          #+#    #+#             */
/*   Updated: 2020/05/29 16:04:17 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include "lib42.h"

size_t				ft_strlen(const char *s);
size_t				ft_strclen(const char *s, char c);
char				*ft_strdup(const char *s);
char				*ft_strchr(const char *s, int c);
int					ft_strchri(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *str);
void				ft_strdel(char *s);
char				*ft_strstr(const char *big, const char *little);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcat(char *dest, char *src);
char				*ft_strncat(char *dest, char *src, size_t n);
char				*ft_strscat(size_t size, ...);
char				*ft_strcpy(char *dest, char *src);
char				*ft_strncpy(char *dest, char *src, size_t n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strsjoin(int size, char **strs, char *sep);
char				*ft_strjoin_free(char *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_srealloc(char *str, size_t size);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_substrf(char *s, unsigned int start, size_t len);
char				*ft_substr_free(char *s, unsigned int start, size_t len);
int					ft_count_word(const char *str);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isspace(int c);
int					ft_endswith(char *str, char *endswith);
int					ft_startswith(char *str, char *startswith);
char				*ft_rep_in_str(char *str, char to_replace, char new);

#endif
