/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_define_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:05:15 by lucocozz          #+#    #+#             */
/*   Updated: 2020/06/04 21:40:46 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_DEFINE_BONNUS_H
# define CUB_DEFINE_BONNUS_H

# if __APPLE__

#  define DISPLAY_X 2560
#  define DISPLAY_Y 1440

# elif __linux__

#  define DISPLAY_X 1920
#  define DISPLAY_Y 1080

# endif

# define MAP_DATA "01234NEWS#@"
# define PLAYER "NEWS"
# define WALLS "1234"
# define SPRITES "#@"
# define COLLISION "1234@"

# define NORTH 3
# define SOUTH 2
# define EAST 0
# define WEST 1

# define N_DATA 11
# define N_TEXTURES 4
# define N_SPRITES 2
# define N_KEYS	7
# define N_BOX 2

# define SPEED 0.15
# define ROT 0.1
# define SHADE 2

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF

#endif
