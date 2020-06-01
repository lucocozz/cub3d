/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_two_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:40:59 by lucocozz          #+#    #+#             */
/*   Updated: 2020/05/30 19:11:32 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static t_hash_table	g_sprite[N_SPRITES] = {
	{"SP1"}, {"SP2"}
};

static t_hash_table	g_box[N_BOX] = {
	{"FLO"}, {"CEL"}
};

void	ft_parse_sprites(t_parsing *parse, char **data)
{
	int	i;
	int	fd;

	i = 0;
	if (ft_matrice_len(data) != 2)
	{
		ft_free_matrice((void **)data, 2);
		ft_exit_parsing(parse, "Bad sprite format.\n");
	}
	while (ft_strcmp(data[0], g_sprite[i].hash))
		i++;
	((char **)(&parse->sprite))[i] = data[1];
	if (!ft_endswith(((char **)(&parse->sprite))[i], ".xpm"))
		ft_exit_parsing(parse, "No xpm sprite file.\n");
	if ((fd = open(((char **)(&parse->sprite))[i], O_RDONLY)) < 0)
	{
		ft_strdel(((char **)(&parse->sprite))[i]);
		((char **)(&parse->sprite))[i] = ft_strdup("./sprites/missing.xpm");
		ft_putstr("Warning: Can't open sprite.\n");
	}
	else
		close(fd);
	ft_strdel(data[0]);
	free(data);
}

void		ft_parse_box(t_parsing *parse, char **data)
{
	int	i;
	int	fd;

	i = 0;
	if (ft_matrice_len(data) != 2)
	{
		ft_free_matrice((void **)data, 2);
		ft_exit_parsing(parse, "Bad texture format.\n");
	}
	while (ft_strcmp(data[0], g_box[i].hash))
		i++;
	((char **)(&parse->box))[i] = data[1];
	if (!ft_endswith(((char **)(&parse->box))[i], ".xpm"))
		ft_exit_parsing(parse, "No xpm texture file.\n");
	if ((fd = open(((char **)(&parse->box))[i], O_RDONLY)) < 0)
	{
		ft_strdel(((char **)(&parse->box))[i]);
		((char **)(&parse->box))[i] = ft_strdup("./textures/missing.xpm");
		ft_putstr("Warning: Can't open box texture.\n");
	}
	else
		close(fd);
	ft_strdel(data[0]);
	free(data);
}