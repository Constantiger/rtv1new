/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:32:33 by aannara           #+#    #+#             */
/*   Updated: 2019/11/27 11:45:54 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	push_obj_ar(void *obj, t_res (*hit_f)(void *, t_ray *),
		int (*col_f)(void *), t_img *img)
{
	img->ar[img->obj_count].obj = obj;
	img->ar[img->obj_count].hit_f = hit_f;
	img->ar[img->obj_count].col_f = col_f;
	img->obj_count++;
}

void	push_lit(t_vec l, t_img *img)
{
	if (img->lit_count > 9)
		return ;
	img->lit[img->lit_count] = l;
	img->lit_count++;
	img->lit_save = img->lit_count;
}

void	push_scene(t_img *img)
{
	int	i;

	i = 0;
	while (i < img->sp_count)
		push_obj_ar((void*)(&img->sp[i++]), &hit_sphere, &sphere_col, img);
	i = 0;
	while (i < img->pl_count)
		push_obj_ar((void*)(&img->pl[i++]), &hit_plane, &plane_col, img);
	i = 0;
	while (i < img->cn_count)
		push_obj_ar((void*)(&img->cn[i++]), &hit_cone, &cone_col, img);
	i = 0;
	while (i < img->cy_count)
		push_obj_ar((void*)(&img->cy[i++]), &hit_cylinder, &cyl_col, img);
}

void	set_shading(t_img *img)
{
	img->shade_on = 1;
	img->powl = 1.0;
	img->pows = 10;
	img->shadow_on = 1;
	img->specul_on = 1;
	img->mult_lit_on = 1;
	if (!img->shade_on)
		img->amb = 1.0;
	else
		img->amb = 0.09;
}

void	set_camera(t_img *img)
{
	img->ll_cor = setv(-2.0, -1.0, -1.0);
	img->hor = setv(4.0, 0.0, 0.0);
	img->ver = setv(0.0, 2.0, 0.0);
	set_shading(img);
	push_scene(img);
}
