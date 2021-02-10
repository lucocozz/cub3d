/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 22:04:29 by lucocozz          #+#    #+#             */
/*   Updated: 2021/02/10 16:50:54 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static t_data_cub	g_data_cub[N_DATA] = {
	{"R", &ft_parse_resolution}, {"TX1", &ft_parse_textures},
	{"TX2", &ft_parse_textures}, {"TX3", &ft_parse_textures},
	{"TX4", &ft_parse_textures}, {"SP1", &ft_parse_sprites},
	{"SP2", &ft_parse_sprites}, {"FLO", &ft_parse_box},
	{"CEL", &ft_parse_box}
};

static t_hash_table	g_texture[N_TEXTURES] = {
	{"TX1"}, {"TX2"}, {"TX3"}, {"TX4"}
};

void		ft_parse_resolution(t_parsing *parse, char **data)
{
	if (ft_matrice_len(data) != 3)
	{
		ft_free_matrice((void **)data, 3);
		ft_exit_parsing(parse, "Bad resolution format.\n");
	}
	parse->size.x = ft_atoui(data[1]);
	parse->size.y = ft_atoui(data[2]);
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
	((char **)(&parse->texture))[i] = data[1];
	if (!ft_endswith(((char **)(&parse->texture))[i], ".xpm"))
		ft_exit_parsing(parse, "No xpm texture file.\n");
	if ((fd = open(((char **)(&parse->texture))[i], O_RDONLY)) < 0)
	{
		ft_strdel(((char **)(&parse->texture))[i]);
		((char **)(&parse->texture))[i] = ft_strdup("./textures/missing.xpm");
		ft_putstr("Warning: Can't open texture.\n");
	}
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
		ft_free_matrice((void **)data, len);
		ft_exit_parsing(parse, "Data can't be parsed.\n");
	}
	while (i < N_DATA && ft_strcmp(g_data_cub[i].data, data[0]))
		i++;
	if (i == N_DATA)
	{
		ft_strdel(line);
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
		if (ft_strcmp(line, "Map:") == 0)
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
