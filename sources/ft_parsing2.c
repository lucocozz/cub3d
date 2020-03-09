/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:28:07 by lucocozz          #+#    #+#             */
/*   Updated: 2020/03/02 20:31:31 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_get_row(char **data)
{
	int		len;
	char	*row;

	len = ft_matrice_len(data);
	row = ft_strsjoin(len, data, "");
	ft_free_matrice((void**)data, len);
	return (row);
}

static int	ft_top_bottom_map(char *row)
{
	int i;

	i = 0;
	while (row[i])
	{
		if (row[i] != '1')
			return (0);
		i++;
	}
	return (ft_strlen(row));
}

static int	ft_middle_map(char *row)
{
	int	i;

	i = 0;
	if (!ft_strcmp(row, ""))
		return (0);
	if (row[i] != '1')
		return (0);
	while (row[i])
	{
		if (ft_strchr(MAP_DATA, row[i]) == NULL)
			return (0);
		i++;
	}
	if (row[i - 1] != '1')
		return (0);
	return (i);
}

static void	ft_check_map(t_parsing *parse, t_list **alst)
{
	int		len;
	t_list	*lst;

	lst = *alst;
	parse->map.x = ft_top_bottom_map((char*)lst->data);
	if (!parse->map.x)
		ft_exit_parse_map("Map doesn't open proprly.\n", parse, *alst);
	lst = lst->next;
	parse->map.y++;
	while (lst->next)
	{
		len = ft_middle_map((char*)lst->data);
		if (len != parse->map.x)
			ft_exit_parse_map("Map have bad charactere.\n", parse, *alst);
		parse->map.y++;
		lst = lst->next;
	}
	if (ft_top_bottom_map((char*)lst->data) == 0)
		ft_exit_parse_map("Map doesn't close proprely.\n", parse, *alst);
	parse->map.y++;
}

void		ft_parse_map(t_parsing *parse, char **data, int fd)
{
	int			i;
	char		*line;
	t_list		*lst_map;

	i = 0;
	lst_map = NULL;
	(void)parse;
	ft_list_push_back(&lst_map, (void*)ft_get_row(data));
	while (get_next_line(fd, &line))
	{
		ft_list_push_back(&lst_map, (void*)ft_get_row(ft_split(line, ' ')));
		ft_strdel(line);
	}
	ft_check_map(parse, &lst_map);
	parse->map.array = ft_list_to_array(&lst_map);
	ft_strdel(line);
}
