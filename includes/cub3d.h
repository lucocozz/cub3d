/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 22:07:11 by lucocozz          #+#    #+#             */
/*   Updated: 2020/02/26 18:01:55 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include "lib42.h"
# include "cub_key.h"

# define DISPLAY_X 2560
# define DISPLAY_Y 1440

# define MAP_DATA "012NEWS"

# define N_DATA 8
# define N_TEXTURES 5
# define N_COLORS 2
# define N_KEYS	5

typedef struct		s_texture_path
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*sprite;
}					t_texture_path;

typedef	struct		s_color_cub
{
	int				roof;
	int				top;
}					t_color_cub;

typedef struct		s_screen_size
{
	int				x;
	int				y;
}					t_screen_size;

typedef struct		s_map
{
	int				x;
	int				y;
	int				player_x;
	int				player_y;
	char			**array;
}					t_map;

typedef struct		s_parse_cub
{
	t_map			map;
	t_color_cub		color;
	t_screen_size	size;
	t_texture_path	texture;
}					t_parse_cub;

typedef struct		s_hash_table
{
	char			*hash;
}					t_hash_table;

typedef struct		s_data_cub
{
	char			*data;
	void			(*function)();
}					t_data_cub;

typedef struct		s_key_event
{
	int				key;
	int				(*event)();
}					t_key_event;

typedef struct		s_screen_cub
{
	void			*mlx;
	void			*win;
}					t_screen_cub;

typedef struct		s_garbage
{
	t_parse_cub		*cub_data;
	t_screen_cub	*screen;
}					t_garbage;

t_parse_cub			ft_parse_file(char *filename);
t_parse_cub			ft_init_cub_data(void);
t_screen_cub		ft_init_screen(t_parse_cub cub_data);
int					ft_check_cub_data(t_parse_cub cub_data);
void				ft_free_cub_data(t_parse_cub *cub_data);
void				ft_parse_map(t_parse_cub *cub_data, char **data, int fd);
void				ft_parse_color(t_parse_cub *cub_data, char **data);
void				ft_parse_textures(t_parse_cub *cub_data, char **data);
void				ft_parse_resolution(t_parse_cub *cub_data, char **data);
void				ft_exit_parse_map(char *s, t_parse_cub *c_d, t_list *lst);
int					ft_exit_cub(void *param);
int					ft_w_key(void *param);
int					ft_a_key(void *param);
int					ft_s_key(void *param);
int					ft_d_key(void *param);
int					ft_press_event(int key, void *param);
int					ft_release_event(int key, void *param);
int					ft_loop_event(int key, void *param);

#endif
