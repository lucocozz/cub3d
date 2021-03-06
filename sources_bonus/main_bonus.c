/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 23:18:22 by lucocozz          #+#    #+#             */
/*   Updated: 2021/02/09 16:35:20 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void		ft_win(t_garbage garb, int save)
{
	t_mlx		*mlx;
	t_parsing	*parse;

	mlx = garb.mlx;
	parse = garb.parse;
	if (save)
	{
		mlx->win = NULL;
		ft_bmp(parse, mlx);
		ft_exit_cub((void*)&garb);
	}
	else
	{
		mlx->win = mlx_new_window(mlx->ptr, parse->size.x, parse->size.y,
		"Cub3D");
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img.ptr, 0, 0);
	}
}

static t_mlx	ft_init_mlx(t_parsing parse)
{
	t_mlx	mlx;

	mlx.ptr = mlx_init();
	mlx.img.ptr = mlx_new_image(mlx.ptr, parse.size.x, parse.size.y);
	mlx.img.data = (int*)mlx_get_data_addr(mlx.img.ptr, &mlx.img.bpp,
	&mlx.img.size, &mlx.img.endian);
	return (mlx);
}

static int		ft_check_arg(int ac, char **av)
{
	if (ac < 2)
		ft_exit_error("Too few aguments.\n");
	if (ac > 3)
		ft_exit_error("Too many arguments.\n");
	if (!ft_endswith(av[1], ".cub"))
		ft_exit_error("Bad extension filename.\n");
	if (ac == 3 && !ft_strcmp(av[2], "--save"))
		return (1);
	else if (ac == 3)
		ft_exit_error("Invalide argument.\n");
	return (0);
}

int				main(int ac, char **av)
{
	int				save;
	t_mlx			mlx;
	t_engine		engine;
	t_parsing		parse;

	save = ft_check_arg(ac, av);
	parse = ft_parse_file(av[1]);
	if (ft_check_parsing(&parse) == -1)
	{
		ft_free_parsing(&parse);
		ft_exit_error("Missing or bad obligtoire parameter in .cub file.\n");
	}
	engine = ft_init_engine(&parse);
	mlx = ft_init_mlx(parse);
	ft_get_screen(&engine, &parse, &mlx);
	ft_win((t_garbage){&parse, &mlx, &engine}, save);
	ft_events_hook((t_garbage){&parse, &mlx, &engine});
	return (0);
}
