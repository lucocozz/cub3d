/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_sprite.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 04:40:59 by lucocozz          #+#    #+#             */
/*   Updated: 2020/05/30 21:16:00 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_hash_table	g_sprite[N_SPRITES] = {
	{"S"}
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
		ft_free_parsing(parse);
		ft_exit_error("Can't open texture.\n");
	}
	else
		close(fd);
	ft_strdel(data[0]);
	free(data);
}
