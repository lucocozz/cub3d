/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:28:07 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/20 05:40:16 by lucocozz         ###   ########.fr       */
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

static void	ft_check_map(t_parse_cub *cub_data, t_list **alst)
{
	int		len;
	t_list	*lst;

	lst = *alst;
	cub_data->map.x = ft_top_bottom_map((char*)lst->data);
	if (!cub_data->map.x)
		ft_exit_parse_map("Map doesn't open proprly.\n", cub_data, *alst);
	lst = lst->next;
	cub_data->map.y++;
	while (lst->next)
	{
		len = ft_middle_map((char*)lst->data);
		if (len != cub_data->map.x)
			ft_exit_parse_map("Map have bad charactere.\n", cub_data, *alst);
		cub_data->map.y++;
		lst = lst->next;
	}
	if (ft_top_bottom_map((char*)lst->data) == 0)
		ft_exit_parse_map("Map doesn't close proprely.\n", cub_data, *alst);
	cub_data->map.y++;
}

void		ft_parse_map(t_parse_cub *cub_data, char **data, int fd)
{
	int			i;
	char		*line;
	t_list		*lst_map;

	i = 0;
	lst_map = NULL;
	(void)cub_data;
	ft_list_push_back(&lst_map, (void*)ft_get_row(data));
	while (get_next_line(fd, &line))
	{
		ft_list_push_back(&lst_map, (void*)ft_get_row(ft_split(line, ' ')));
		ft_strdel(line);
	}
	ft_check_map(cub_data, &lst_map);
	cub_data->map.array = ft_list_to_array(&lst_map);
	ft_strdel(line);
}
