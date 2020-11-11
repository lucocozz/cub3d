/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_proto_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:00:33 by lucocozz          #+#    #+#             */
/*   Updated: 2020/11/11 21:22:13 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PROTO_BONUS_H
# define CUB_PROTO_BONUS_H

# include "lib42.h"
# include "cub_struct_bonus.h"

t_parsing	ft_init_parsing(void);
t_parsing	ft_parse_file(char *filename);
t_engine	ft_init_engine(t_parsing *parse);
void		ft_raycast(t_parsing *parse, t_engine *eng, t_mlx *mlx);
t_raycast	ft_ray(t_camera cam, t_parsing parse, int x);

void		ft_get_screen(t_engine *eng, t_parsing *parse, t_mlx *mlx);
void		ft_clear_screen(t_mlx *mlx, t_parsing *parse);
void		ft_display_screen(t_engine *eng, t_parsing *parse, t_mlx *mlx);
void		ft_draw(t_engine *e, t_mlx *m, t_parsing p, t_raycast *r);

void		ft_bmp(t_parsing *parse, t_mlx *mlx);

void		ft_get_textures_img(t_engine *e, t_mlx *m, t_parsing p);
void		ft_texturing(t_garbage g, t_texture_data *t, t_raycast *r);
int			ft_shading(int color, float dist, float multiplier);
void		ft_box(t_parsing parse, t_box *box, t_camera cam, t_mlx *mlx);

void		ft_sprite(t_engine *eng, t_mlx *mlx, t_parsing *parse);
void		ft_push_sprite(t_sprite_lst **sprites, t_garbage *garb, t_coord axe,
			int texture);
void		ft_free_sprite(t_garbage *garb);
void		ft_sort_sprite(t_sprite_lst **sprites);

int			ft_check_parsing(t_parsing *parse);
void		ft_free_parsing(t_parsing *parse);
void		ft_exit_parse_map(char *s, t_parsing *c_d, t_list *lst);
void		ft_exit_parsing(t_parsing *parse, char *str);

void		ft_parse_box(t_parsing *parse, char **data);
void		ft_parse_map(t_parsing *parse, char *line, int fd);
void		ft_parse_color(t_parsing *parse, char **data);
void		ft_parse_sprites(t_parsing *parse, char **data);
void		ft_parse_textures(t_parsing *parse, char **data);
void		ft_parse_resolution(t_parsing *parse, char **data);

void		ft_events_hook(t_garbage garbage);
int			ft_exit_cub(t_garbage *garb);
int			ft_press_event(int key, t_garbage *garb);
int			ft_release_event(int key, t_garbage *garb);
int			ft_loop_event(t_garbage *garb);

int			ft_w_key(t_garbage *garb);
int			ft_a_key(t_garbage *garb);
int			ft_s_key(t_garbage *garb);
int			ft_d_key(t_garbage *garb);
int			ft_left_key(t_garbage *garb);
int			ft_right_key(t_garbage *garb);

void		ft_filter_image(t_mlx *mlx, t_parsing parse, int (*ft)(int));
int			ft_invert_pixel_color(int pixel);
int			ft_grayscale_pixel(int pixel);

#endif
