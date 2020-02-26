/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 23:18:22 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/26 18:15:41 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_arg(int ac, char **av)
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

static void	ft_events_hook(t_garbage garbage)
{
	t_screen_cub	*screen;

	screen = garbage.screen;
	mlx_hook(screen->win, DESTROYNOTIFY, 0, &ft_exit_cub, (void*)&garbage);
	mlx_hook(screen->win, KEYPRESS, 0, &ft_press_event, (void*)&garbage);
	mlx_hook(screen->win, KEYRELEASE, 0, &ft_release_event, (void*)&garbage);
	mlx_loop_hook(screen->mlx, &ft_loop_event, (void*)&garbage);
	mlx_loop(screen->mlx);
}

int			main(int ac, char **av)
{
	int				save;
	t_screen_cub	screen;
	t_parse_cub		cub_data;

	save = ft_check_arg(ac, av);
	cub_data = ft_init_cub_data();
	cub_data = ft_parse_file(av[1]);
	if (!ft_check_cub_data(cub_data))
	{
		ft_free_cub_data(&cub_data);
		ft_exit_error("Missing or bad obligtoire parameter in .cub file.\n");
	}
	screen = ft_init_screen(cub_data);
	ft_events_hook((t_garbage){&cub_data, &screen});
	return (0);
}
