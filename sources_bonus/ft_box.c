/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_box.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 20:36:12 by lucocozz          #+#    #+#             */
/*   Updated: 2020/06/02 00:34:20 by lucocozz         ###   ########.fr       */
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
		box->RowDis, SHADE);
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
	mlx->img.data[(parse.size.y - axe.y - 1) * parse.size.x + axe.x]
		= ft_shading(box->color, box->RowDis, SHADE);
}


static void	ft_raycast_box(t_parsing parse, t_box *box, t_camera *cam, int y)
{
	box->Rdir0.x = cam->dir.x - cam->plane.x;
	box->Rdir0.y = cam->dir.y - cam->plane.y;
	box->Rdir1.x = cam->dir.x + cam->plane.x;
	box->Rdir1.y = cam->dir.y + cam->plane.y;
	box->posY = y - parse.size.y / 2;
	box->posZ = 0.5 * parse.size.y;
	box->RowDis = box->posZ / box->posY;
	box->FStep.x = box->RowDis * (box->Rdir1.x - box->Rdir0.x) / parse.size.x;
	box->FStep.y = box->RowDis * (box->Rdir1.y - box->Rdir0.y) / parse.size.x;
	box->flo.x = cam->pos.x + box->RowDis * box->Rdir0.x;
	box->flo.y = cam->pos.y + box->RowDis * box->Rdir0.y;
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
			box->flo.x += box->FStep.x;
			box->flo.y += box->FStep.y;
			ft_display_floor(parse, box, mlx, axe);
			ft_display_celling(parse, box, mlx, axe);
		}
		axe.y++;
	}
}
