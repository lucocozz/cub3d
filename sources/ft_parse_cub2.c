/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:28:07 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/18 04:52:35 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_hash_table	g_color[N_COLORS] = {
	{"F"}, {"C"}
};

void		ft_parse_color(t_parse_cub *cub_data, char **data)
{
	int		i;
	int		j;
	char	**rgb;

	i = 0;
	j = 0;
	while (ft_strcmp(data[0], g_color[i].hash) && i < N_COLORS)
		i++;
	rgb = ft_split(data[1], ',');
	((int *)(&cub_data->color))[i] += ft_atoi(rgb[0]) << 16;
	((int *)(&cub_data->color))[i] += ft_atoi(rgb[1]) << 8;
	((int *)(&cub_data->color))[i] += ft_atoi(rgb[2]);
	ft_free_matrice((void **)data, 2);
	ft_free_matrice((void **)rgb, 3);
}

static void	ft_wall_map(t_parse_cub *cub_data, char *row)
{
	int i;

	i = 0;
	while (row[i])
	{
		if (row[i] != '1')
		{
			ft_strdel(row);
			ft_free_cub_data(cub_data);
			ft_exit_error("Invalide map.\n");
		}
		i++;
	}
}

void		ft_parse_map(t_parse_cub *cub_data, char **data, int fd)
{
	int			i;
	int			len;
	char		*row;

	i = 0;
	row = ft_strsjoin(ft_matrice_len(data), data, "");
	len = ft_strlen(row);
	ft_free_matrice((void**)data, ft_matrice_len(data));
	ft_wall_map(cub_data, row);
	ft_matrice_join(cub_data->map.array, row, cub_data->map.y++);
	ft_strdel(row);
	while (get_next_line(fd, &row))
	{

		ft_strdel(row);
	}
}

// passer la map en list chainee
