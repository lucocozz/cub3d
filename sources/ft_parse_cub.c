/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_cub.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:04:29 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/20 03:04:42 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_data_cub		g_data_cub[N_DATA] = {
	{"R", &ft_parse_resolution}, {"NO", &ft_parse_textures},
	{"SO", &ft_parse_textures}, {"WE", &ft_parse_textures},
	{"EA", &ft_parse_textures}, {"S", &ft_parse_textures},
	{"F", &ft_parse_color}, {"C", &ft_parse_color}
};

static t_hash_table	g_texture[N_TEXTURES] = {
	{"NO"}, {"SO"}, {"WE"}, {"EA"}, {"S"}
};

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

void		ft_parse_resolution(t_parse_cub *cub_data, char **data)
{
	int i;

	i = 0;
	cub_data->size.x = ft_atoi(data[1]);
	cub_data->size.y = ft_atoi(data[2]);
	ft_free_matrice((void**)data, 3);
}

void		ft_parse_textures(t_parse_cub *cub_data, char **data)
{
	int	i;
	int	fd;

	i = 0;
	while (ft_strcmp(data[0], g_texture[i].hash))
		i++;
	((char **)(&cub_data->texture))[i] = data[1];
	if (!ft_endswith(((char **)(&cub_data->texture))[i], ".xpm"))
	{
		ft_free_cub_data(cub_data);
		ft_exit_error("No xpm file.\n");
	}
	if ((fd = open(((char **)(&cub_data->texture))[i], O_RDONLY)) < 0)
	{
		ft_free_cub_data(cub_data);
		ft_exit_error("Can't open texture.\n");
	}
	else
		close(fd);
	ft_strdel(data[0]);
	free(data);
}

void		ft_parse_data(t_parse_cub *cub_data, char *line)
{
	int		i;
	char	**data;

	i = 0;
	data = ft_split(line, ' ');
	while (ft_strcmp(g_data_cub[i].data, data[0]) && i < N_DATA)
		i++;
	if (i == N_DATA)
		return ;
	g_data_cub[i].function(cub_data, data);
}

t_parse_cub	ft_parse_file(char *filename)
{
	int			fd;
	char		*line;
	t_parse_cub cub_data;

	if ((fd = open(filename, O_RDONLY)) < 0)
		ft_exit_error("Can't open file.\n");
	while (get_next_line(fd, &line))
	{
		if (ft_startswith(line, "1"))
			ft_parse_map(&cub_data, ft_split(line, ' '), fd);
		else if (ft_strcmp(line, ""))
			ft_parse_data(&cub_data, line);
		ft_strdel(line);
	}
	ft_strdel(line);
	close(fd);
	return (cub_data);
}
