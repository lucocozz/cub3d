/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_engine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:55:13 by lucocozz          #+#    #+#             */
/*   Updated: 2020/03/09 08:06:02 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	**ft_malloc_map(t_parsing *parse)
{
	int	i;
	int	**array;

	i = 0;
	if ((array = malloc(sizeof(int*) * parse->map.y)) == NULL)
	{
		ft_free_parsing(parse);
		ft_exit_error("Engine create map axe y\n");
	}
	while (i < parse->map.y)
	{
		if ((array[i] = malloc(sizeof(int) * parse->map.x)) == NULL)
		{
			ft_free_parsing(parse);
			ft_free_matrice((void**)array, i);
			ft_exit_error("Engine create map axe x\n");
		}
		i++;
	}
	return (array);
}

static void	ft_pos_cam(t_engine *engine, int dy, float px, float py)
{
	engine->cam.dir.y = dy;
	engine->cam.plane.x = px;
	engine->cam.plane.y = py;
}

static void	ft_set_cam(t_parsing *parse, t_engine *engine, int x, int y)
{
	if (parse->map.array[y][x] == 'N')
	{
		engine->cam.dir.x = 0;
		ft_pos_cam(engine, -1, 0.66, 0.0);
	}
	else if (parse->map.array[y][x] == 'E')
	{
		engine->cam.dir.x = 1;
		ft_pos_cam(engine, 0, 0.0, 0.66);
	}
	else if (parse->map.array[y][x] == 'W')
	{
		engine->cam.dir.x = -1;
		ft_pos_cam(engine, 0, 0.0, -0.66);
	}
	else if (parse->map.array[y][x] == 'S')
	{
		engine->cam.dir.x = 0;
		ft_pos_cam(engine, 1, -0.66, 0.0);
	}
	engine->cam.pos.x = x + 0.5;
	engine->cam.pos.y = y + 0.5;
	engine->map.array[y][x] = 0;
}

t_engine	ft_init_engine(t_parsing *parse)
{
	int			x;
	int			y;
	t_engine	engine;

	y = 0;
	engine.map.array = ft_malloc_map(parse);
	while (y < parse->map.y)
	{
		x = 0;
		while (x < parse->map.x)
		{
			if (ft_isalpha(parse->map.array[y][x]))
				ft_set_cam(parse, &engine, x, y);
			else
				engine.map.array[y][x] = parse->map.array[y][x] - '0';
			x++;
		}
		y++;
	}
	engine.sprite.data = NULL;
	engine.sprite.order = NULL;
	engine.sprite.dist = NULL;
	engine.moveS = 0.25;
	engine.rotS = 0.05;
	return (engine);
}
