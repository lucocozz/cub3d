/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:11:28 by lucocozz          #+#    #+#             */
/*   Updated: 2020/04/18 01:08:34 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib42.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("map.cub", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		ft_printf("%s\n", line);
		ft_strdel(line);
	}
	ft_strdel(line);
	return (0);
}