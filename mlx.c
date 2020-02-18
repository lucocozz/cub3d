/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 23:32:23 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/10 19:47:31 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <string.h>
#include <stdio.h>

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	str[] = "test";
	int		x = 500;
	int		y = 500;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, x, y, str);
	while (x > 0 && y > 0)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 255);
		x--;
		if (x == 0)
		{
			y--;
			x = 500 - y;
		}
	}
	mlx_loop(mlx_ptr);

	mlx_destroy_window(mlx_ptr, win_ptr);
	return (0);
}