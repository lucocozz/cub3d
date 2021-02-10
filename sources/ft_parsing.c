/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:04:29 by lucocozz          #+#    #+#             */
/*   Updated: 2021/02/10 15:46:12 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_data_cub	g_data_cub[N_DATA] = {
	{"R", &ft_parse_resolution}, {"NO", &ft_parse_textures},
	{"SO", &ft_parse_textures}, {"WE", &ft_parse_textures},
	{"EA", &ft_parse_textures}, {"S", &ft_parse_sprites},
	{"F", &ft_parse_color}, {"C", &ft_parse_color}
};

static t_hash_table	g_texture[N_TEXTURES] = {
	{"NO"}, {"SO"}, {"WE"}, {"EA"}
};

static t_hash_table	g_color[N_COLORS] = {
	{"F"}, {"C"}
};

void		ft_parse_color(t_parsing *parse, char **data)
{
	int		i;
	char	**rgb;

	i = 0;
	if (ft_matrice_len(data) != 2)
	{
		ft_free_matrice((void **)data, 2);
		ft_exit_parsing(parse, "Bad color format.\n");
	}
	while (ft_strcmp(data[0], g_color[i].hash) && i < N_COLORS)
		i++;
	rgb = ft_split(data[1], ',');
	if (ft_matrice_len(rgb) != 3)
	{
		ft_free_matrice((void **)data, 2);
		ft_free_matrice((void **)rgb, 3);
		ft_exit_parsing(parse, "Bad rgb format.\n");
	}
	if (((int *)(&parse->color))[i] != -1)
		ft_exit_parsing(parse, "Color already set.\n");
	((int *)(&parse->color))[i] += ft_atoi(rgb[0]) << 16;
	((int *)(&parse->color))[i] += ft_atoi(rgb[1]) << 8;
	((int *)(&parse->color))[i] += ft_atoi(rgb[2]);
	ft_free_matrice((void **)data, 2);
	ft_free_matrice((void **)rgb, 3);
}

void		ft_parse_resolution(t_parsing *parse, char **data)
{
	if (ft_matrice_len(data) != 3)
	{
		ft_free_matrice((void **)data, 3);
		ft_exit_parsing(parse, "Bad resolution format.\n");
	}
	if (parse->size.x != 0 && parse->size.y != 0)
		ft_exit_parsing(parse, "Resolution already set.\n");
	parse->size.x = ft_atoi(data[1]);
	parse->size.y = ft_atoi(data[2]);
	ft_free_matrice((void**)data, 3);
	if (parse->size.x <= 0 || parse->size.y <= 0)
		ft_exit_parsing(parse, "Null or negative resolution value.\n");
	if (parse->size.x > DISPLAY_X)
		parse->size.x = DISPLAY_X;
	if (parse->size.y > DISPLAY_Y)
		parse->size.y = DISPLAY_Y;
}

void		ft_parse_textures(t_parsing *parse, char **data)
{
	int	i;
	int	fd;

	i = 0;
	if (ft_matrice_len(data) != 2)
	{
		ft_free_matrice((void **)data, 2);
		ft_exit_parsing(parse, "Bad texture format.\n");
	}
	while (ft_strcmp(data[0], g_texture[i].hash))
		i++;
	if (((char **)(&parse->texture))[i] == NULL)
		((char **)(&parse->texture))[i] = data[1];
	else
		ft_exit_parsing(parse, "Texture already set.\n");
	if (!ft_endswith(((char **)(&parse->texture))[i], ".xpm"))
		ft_exit_parsing(parse, "No xpm file.\n");
	if ((fd = open(((char **)(&parse->texture))[i], O_RDONLY)) < 0)
		ft_exit_parsing(parse, "Can't open texture.\n");
	else
		close(fd);
	ft_strdel(data[0]);
	free(data);
}

void		ft_parse_data(t_parsing *parse, char *line)
{
	int		i;
	int		len;
	char	**data;

	i = 0;
	data = ft_split(line, ' ');
	if ((len = ft_matrice_len(data)) == 1)
	{
		ft_strdel(line);
		ft_print_matrice(data);
		ft_free_matrice((void **)data, len);
		ft_exit_parsing(parse, "Data can't be parsed.\n");
	}
	while (i < N_DATA && ft_strcmp(g_data_cub[i].data, data[0]))
		i++;
	if (i == N_DATA)
	{
		ft_strdel(line);
		ft_print_matrice(data);
		ft_free_matrice((void **)data, len);
		ft_exit_parsing(parse, "Unreconized data.\n");
	}
	g_data_cub[i].function(parse, data);
}

t_parsing	ft_parse_file(char *filename)
{
	int			fd;
	char		*line;
	t_parsing	parse;

	if ((fd = open(filename, O_RDONLY)) < 0)
		ft_exit_error("Can't open file.\n");
	parse = ft_init_parsing();
	while (get_next_line(fd, &line))
	{
		if (ft_check_parsing(parse) == 0)
		{
			ft_parse_map(&parse, line, fd);
			break ;
		}
		else if (ft_strcmp(line, ""))
			ft_parse_data(&parse, line);
		ft_strdel(line);
	}
	close(fd);
	return (parse);
}
