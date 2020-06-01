/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 21:38:10 by lucocozz          #+#    #+#             */
/*   Updated: 2020/06/01 15:25:34 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_parsing		ft_init_parsing(void)
{
	int			i;
	t_parsing	parse;

	i = 0;
	while (i < N_TEXTURES)
		((char **)(&parse.texture))[i++] = NULL;
	i = 0;
	while (i < N_SPRITES)
		((char **)(&parse.sprite))[i++] = NULL;
	i = 0;
	while (i < N_BOX)
		((char **)(&parse.box))[i++] = NULL;
	i = 0;
	while (i < 2)
		((int *)(&parse.size))[i++] = 0;
	parse.map.array = NULL;
	parse.map.x = 0;
	parse.map.y = 0;
	return (parse);
}

static char		*ft_missing(int type)
{
	char	*str;

	str = NULL;
	if (type == 2)
	{
		ft_putstr("Warning: missing box texture in .cub file.\n");
		str = ft_strdup("./textures/missing.xpm");
	}
	else if (type == 1)
	{
		ft_putstr("Warning: missing texture in .cub file.\n");
		str = ft_strdup("./textures/missing.xpm");
	}
	else if (type == 0)
	{
		ft_putstr("Warning: missing sprite in .cub file.\n");
		str = ft_strdup("./sprites/missing.xpm");
	}
	return (str);
}

int				ft_check_parsing(t_parsing *parse)
{
	int	i;
	
	i = -1;
	while (++i < N_BOX)
		if (((char **)(&parse->box))[i] == NULL)
			((char **)(&parse->box))[i] = ft_missing(2);
	i = -1;
	while (++i < N_TEXTURES)
		if (((char **)(&parse->texture))[i] == NULL)
			((char **)(&parse->texture))[i] = ft_missing(1);
	i = -1;
	while (++i < N_SPRITES)
		if (((char **)(&parse->sprite))[i] == NULL)
			((char **)(&parse->sprite))[i] = ft_missing(0);
	i = 0;
	while (i < 2)
		if (((int *)(&parse->size))[i++] == 0)
			return (-1);
	if (parse->map.array == NULL)
		return (-1);
	if (parse->map.x < 3 || parse->map.y < 3)
		return (-1);
	return (1);
}

void			ft_free_parsing(t_parsing *parse)
{
	int	i;

	i = 0;
	while (i < N_TEXTURES)
		ft_strdel(((char **)(&parse->texture))[i++]);
	i = 0;
	while (i < N_SPRITES)
		ft_strdel(((char **)(&parse->sprite))[i++]);
	i = 0;
	while (i < N_BOX)
		ft_strdel(((char **)(&parse->box))[i++]);
	ft_free_matrice((void**)parse->map.array, parse->map.y);
}
