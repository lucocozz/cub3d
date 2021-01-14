/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_box.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 20:36:12 by lucocozz          #+#    #+#             */
/*   Updated: 2021/01/14 17:11:18 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		ft_init_box(t_mlx *mlx, t_box *box, t_parsing parse)
{
	t_box_data	*floor;
	t_box_data	*celling;

	floor = &box->floor;
	celling = &box->celling;
	floor->img.ptr = mlx_xpm_file_to_image(mlx->ptr, parse.box.floor,
		&floor->size.x, &floor->size.y);
	celling->img.ptr = mlx_xpm_file_to_image(mlx->ptr, parse.box.celling,
		&celling->size.x, &celling->size.y);
	floor->img.data = (int*)mlx_get_data_addr(floor->img.ptr, &floor->img.bpp,
		&floor->img.size, &floor->img.endian);
	celling->img.data = (int*)mlx_get_data_addr(celling->img.ptr,
		&celling->img.bpp, &celling->img.size, &celling->img.endian);
}

static void	ft_display_floor(t_parsing parse, t_box *box, t_mlx *mlx,
t_coord axe)
{
	box->floor.tex.x = (int)(box->floor.size.x * (box->flo.x - box->cell.x))
		& (box->floor.size.x - 1);
	box->floor.tex.y = (int)(box->floor.size.y * (box->flo.y - box->cell.y))
		& (box->floor.size.y - 1);
	box->color = box->floor.img.data[box->floor.size.x * box->floor.tex.y
		+ box->floor.tex.x];
	box->color = (box->color >> 1) & 8355711;
	mlx->img.data[axe.y * parse.size.x + axe.x] = ft_shading(box->color,
		box->row_dis, SHADE);
}

static void	ft_display_celling(t_parsing parse, t_box *box, t_mlx *mlx,
t_coord axe)
{
	box->celling.tex.x = (int)(box->celling.size.x * (box->flo.x - box->cell.x))
		& (box->celling.size.x - 1);
	box->celling.tex.y = (int)(box->celling.size.y * (box->flo.y - box->cell.y))
		& (box->celling.size.y - 1);
	box->color = box->celling.img.data[box->celling.size.x * box->celling.tex.y
		+ box->celling.tex.x];
	box->color = (box->color >> 1) & 8355711;
	mlx->img.data[(parse.size.y - axe.y - 1) * parse.size.x + axe.x] =
		ft_shading(box->color, box->row_dis, SHADE);
}

static void	ft_raycast_box(t_parsing parse, t_box *box, t_camera *cam, int y)
{
	box->r_dir0.x = cam->dir.x - cam->plane.x;
	box->r_dir0.y = cam->dir.y - cam->plane.y;
	box->r_dir1.x = cam->dir.x + cam->plane.x;
	box->r_dir1.y = cam->dir.y + cam->plane.y;
	box->pos_y = y - parse.size.y / 2;
	box->pos_z = 0.5 * parse.size.y;
	box->row_dis = box->pos_z / box->pos_y;
	box->f_step.x = box->row_dis * (box->r_dir1.x - box->r_dir0.x)
		/ parse.size.x;
	box->f_step.y = box->row_dis * (box->r_dir1.y - box->r_dir0.y)
		/ parse.size.x;
	box->flo.x = cam->pos.x + box->row_dis * box->r_dir0.x;
	box->flo.y = cam->pos.y + box->row_dis * box->r_dir0.y;
}

void		ft_box(t_parsing parse, t_box *box, t_camera cam, t_mlx *mlx)
{
	t_coord			axe;
	static int		bool = 0;

	if (!bool++)
		ft_init_box(mlx, box, parse);
	axe.y = 0;
	while (axe.y < parse.size.y)
	{
		ft_raycast_box(parse, box, &cam, axe.y);
		axe.x = 0;
		while (axe.x < parse.size.x)
		{
			axe.x++;
			box->cell.x = (int)box->flo.x;
			box->cell.y = (int)box->flo.y;
			box->flo.x += box->f_step.x;
			box->flo.y += box->f_step.y;
			ft_display_floor(parse, box, mlx, axe);
			ft_display_celling(parse, box, mlx, axe);
		}
		axe.y++;
	}
}
