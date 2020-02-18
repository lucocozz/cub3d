/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 23:18:22 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/13 21:37:54 by lucocozz         ###   ########.fr       */
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

int			main(int ac, char **av)
{
	int			save;
	t_parse_cub	cub_data;

	save = ft_check_arg(ac, av);
	cub_data = ft_init_cub_data();
	cub_data = ft_parse_file(av[1]);

	return (0);
}