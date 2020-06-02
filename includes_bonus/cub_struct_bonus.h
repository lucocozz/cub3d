/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_struct_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:11:46 by lucocozz          #+#    #+#             */
/*   Updated: 2020/06/02 14:13:59 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_STRUCT_BONUS_H
# define CUB_STRUCT_BONUS_H

typedef struct		s_sprite_lst t_sprite_lst;

typedef struct		s_pixel
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
}					t_pixel;

typedef struct		s_bmp
{
	t_pixel			pixel;
	unsigned int	pad_bpr;
	unsigned int	pixel_bpr;
	unsigned int	*sof_entry;
	unsigned int	*width_entry;
	unsigned int	*hight_entry;
}					t_bmp;

typedef struct		s_index
{
	int				i;
	int				j;
}					t_index;

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_fcoord
{
	float			x;
	float			y;
}					t_fcoord;

typedef struct		s_texture_path
{
	char			*tx1;
	char			*tx2;
	char			*tx3;
	char			*tx4;
}					t_texture_path;

typedef struct		s_texture_data
{
	int				num;
	void			*ptr;
	int				*img;
	int				width;
	int				height;
	float			wall_x;
	float			pos;
	float			step;
	t_coord			coord;
}					t_texture_data;

typedef struct		s_img
{
	int				bpp;
	int				size;
	void			*ptr;
	int				*data;
	int				endian;
}					t_img;

typedef struct		s_texture_img
{
	t_texture_data	wall_1;
	t_texture_data	wall_2;
	t_texture_data	wall_3;
	t_texture_data	wall_4;
}					t_texture_img;

typedef struct		s_box_data
{
	t_coord			tex;
	t_coord			size;
	t_img			img;
}					t_box_data;

typedef struct		s_box
{
	int				color;
	int				posY;
	float			posZ;
	float			RowDis;
	t_coord			cell;
	t_fcoord		FStep;
	t_fcoord		flo;
	t_fcoord		Rdir0;
	t_fcoord		Rdir1;	
	t_box_data		floor;
	t_box_data		celling;
}					t_box;

typedef struct		s_box_path
{
	char			*floor;
	char			*celling;
}					t_box_path;

typedef struct		s_sprite_path
{
	char			*sp1;
	char			*sp2;
}					t_sprite_path;

struct				s_sprite_lst
{
	float			dist;
	t_img			img;
	t_coord			size;
	t_fcoord		coord;
	t_sprite_lst	*next;
};

typedef struct		s_sprite
{
	int				d;
	int				nb;
	int				color;
	int				screenX;
	float			invDet;
	t_coord			tex;
	t_coord			start;
	t_coord			end;
	t_coord			size;
	t_fcoord		transf;
	t_fcoord		coord;
	t_sprite_lst	*data;
}					t_sprite;

typedef struct		s_map_parse
{
	int				x;
	int				y;
	char			**array;
}					t_map_parse;

typedef struct		s_parsing
{
	t_coord			size;
	t_map_parse		map;
	t_box_path		box;
	t_sprite_path	sprite;
	t_texture_path	texture;
}					t_parsing;

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

typedef struct		s_key_bit
{
	int				key;
	int				pos;
}					t_key_bit;

typedef struct		s_mlx
{
	int				save;
	void			*ptr;
	void			*win;
	t_img			img;
}					t_mlx;

typedef struct		s_map_eng
{
	int				**array;
}					t_map_eng;

typedef struct		s_raycast
{
	int				hit;
	int				end;
	int				col;
	int				side;
	int				start;
	int				color;
	int				line_h;
	float			PWDist;
	t_coord			map;
	t_coord			step;
	t_fcoord		cam;
	t_fcoord		dir;
	t_fcoord		dDist;
	t_fcoord		sDist;
}					t_raycast;

typedef struct		s_camera
{
	t_fcoord		pos;
	t_fcoord		dir;
	t_fcoord		plane;
}					t_camera;

typedef struct		s_engine
{
	float			rotS;
	float			moveS;
	float			*Zbuff;
	unsigned int	key;
	t_camera		cam;
	t_map_eng		map;
	t_box			box;
	t_sprite		sprite;
	t_texture_img	texture;
}					t_engine;

typedef struct		s_garbage
{
	t_parsing		*parse;
	t_mlx			*mlx;
	t_engine		*engine;
}					t_garbage;

#endif
