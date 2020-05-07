/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:28:07 by lucocozz          #+#    #+#             */
/*   Updated: 2020/05/06 22:41:33 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_set_size(char *line, int size, int i)
{
	line = (void*)ft_srealloc((char*)line, size);
	while (i < size)
		line[i++] = '1';
	return (line);
}

static int	ft_top_bottom_map(char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (ft_strlen(line));
}

static int	ft_middle_map(char *line)
{
	int	i;

	i = 0;
	if (!ft_strcmp(line, ""))
		return (0);
	if (line[i] != '1')
		return (0);
	while (line[i])
	{
		if (ft_strchr(MAP_DATA, line[i]) == NULL)
			return (0);
		i++;
	}
	if (line[i - 1] != '1')
		return (0);
	return (i);
}

static void	ft_check_map(t_parsing *parse, t_list **alst)
{
	int		len;
	t_list	*lst;

	lst = *alst;
	parse->map.y = 0;
	parse->map.x = ft_top_bottom_map((char*)lst->data);
	if (!parse->map.x)
		ft_exit_parse_map("Map doesn't open proprly.\n", parse, *alst);
	lst = lst->next;
	parse->map.y++;
	while (lst->next)
	{
		len = ft_middle_map((char*)lst->data);
		if (len < parse->map.x && len != 0)
			lst->data = (void*)ft_set_size((char*)lst->data, parse->map.x, len);
		else if (len != parse->map.x)
			ft_exit_parse_map("Map have bad charactere.\n", parse, *alst);
		parse->map.y++;
		lst = lst->next;
	}
	if ((len = ft_top_bottom_map((char*)lst->data)) == 0)
		ft_exit_parse_map("Map doesn't close proprely.\n", parse, *alst);
	else if (len < parse->map.x)
		lst->data = (void*)ft_set_size((char*)lst->data, parse->map.x, len);
	parse->map.y++;
}

void		ft_parse_map(t_parsing *parse, char *line, int fd)
{
	t_list		*lst_map;

	lst_map = NULL;
	while (!ft_strcmp(line, ""))
	{
		if (!ft_strcmp(line, ""))
			ft_strdel(line);
		get_next_line(fd, &line);
	}
	if (ft_strcmp(line, ""))
		ft_list_push_back(&lst_map, (void*)ft_replace_in_str(line, ' ', '1'));
	while (get_next_line(fd, &line))
		ft_list_push_back(&lst_map, (void*)ft_replace_in_str(line, ' ', '1'));
	if (ft_strcmp(line, ""))
		ft_list_push_back(&lst_map, (void*)ft_replace_in_str(line, ' ', '1'));
	else
		ft_strdel(line);
	ft_check_map(parse, &lst_map);
	parse->map.array = ft_list_to_array(&lst_map);
}
