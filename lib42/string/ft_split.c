/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 17:54:42 by lucocozz          #+#    #+#             */
/*   Updated: 2019/12/04 20:10:57 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"

static int		ft_nb_word(char *str, char c)
{
	int	i;
	int	nb;
	int	bl;

	i = 0;
	nb = 0;
	while (str[i])
	{
		bl = 0;
		while (str[i] == c && str[i])
			i++;
		while (str[i] != c && str[i])
		{
			nb += (bl ? 0 : 1);
			bl = 1;
			i++;
		}
	}
	return (nb);
}

static char		*ft_cut_word(char *str, char c, int *i)
{
	int		j;
	int		len;
	char	*strnew;

	j = 0;
	len = 0;
	while (str[*i] == c && str[*i])
		*i += 1;
	while (str[*i + len] != c && str[*i + len])
		len++;
	if ((strnew = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (j < len)
	{
		strnew[j] = str[*i];
		j++;
		*i += 1;
	}
	strnew[j] = '\0';
	return (strnew);
}

static void		ft_noleaks(char **tab, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (tab[i])
		{
			free(tab[i]);
			tab[i] = NULL;
		}
		i++;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
}

char			**ft_split(char const *str, char c)
{
	int		i;
	char	**tab;
	int		offset;
	int		tab_size;

	i = 0;
	offset = 0;
	if (!str)
		return (NULL);
	tab_size = ft_nb_word((char *)str, c);
	if ((tab = malloc(sizeof(char *) * (tab_size + 1))) == NULL)
		return (NULL);
	while (i < tab_size)
	{
		if ((tab[i] = ft_cut_word((char *)str, c, &offset)) == NULL)
		{
			ft_noleaks(tab, i);
			return (NULL);
		}
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
