/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_engine_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:55:13 by lucocozz          #+#    #+#             */
/*   Updated: 2020/05/07 17:42:58 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

static void	ft_data(t_parsing *parse, t_engine *engine)
{
	engine->sprite.data = NULL;
	engine->moveS = SPEED;
	engine->rotS = ROT;
	engine->key = 0;
	if ((engine->Zbuff = malloc(sizeof(float) * parse->size.x)) == NULL)
	{
		ft_free_parsing(parse);
		ft_free_matrice((void**)engine->map.array, parse->size.y);
		ft_exit_error("Init engine error\n");
	}
}

t_engine	ft_init_engine(t_parsing *parse)
{
	int			x;
	int			y;
	t_engine	engine;

	y = 0;
	ft_data(parse, &engine);
	engine.map.array = ft_malloc_map(parse);
	while (y < parse->map.y)
	{
		x = 0;
		while (x < parse->map.x)
		{
			if (ft_strchr(PLAYER, parse->map.array[y][x]))
				ft_set_cam(parse, &engine, x, y);
			else if (ft_isdigit(parse->map.array[y][x]))
				engine.map.array[y][x] = parse->map.array[y][x] - '0';
			else
				engine.map.array[y][x] = (int)parse->map.array[y][x];
			x++;
		}
		y++;
	}
	return (engine);
}
