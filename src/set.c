/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:32:33 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 18:08:14 by aannara          ###   ########.fr       */
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

	push_lit(setv(-5.0, 6.0, 10.0), img);
	push_lit(setv(-6.0, 5.0, 9.0), img);
	push_lit(setv(1.0, 15.0, 9.0), img);
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
/*
void	push_sphere(t_vec c, float r, int color, t_img *img)
{
	if (img->sp_count > 9)
		return ;
	set_sphere(c, r, &img->sp[img->sp_count]);
	img->sp[img->sp_count].color = color;
	img->sp_count++;
}

void	push_pl(t_vec c, t_vec n, int color, t_img *img)
{
	if (img->pl_count > 9)
		return ;
	set_plane(c, n, &img->pl[img->pl_count]);
	img->pl[img->pl_count].color = color;
	img->pl_count++;
}

void	push_cn(t_vec t, t_vec b, float ang, int color, t_img *img)
{
	if (img->cn_count > 9)
		return ;
	set_cone(t, b, ang, &img->cn[img->cn_count]);
	img->cn[img->cn_count].color = color;
	img->cn_count++;
}

void	push_cy(t_vec t, t_vec b, float r, int color, t_img *img)
{
	if (img->cy_count > 9)
		return ;
	set_cylinder(t, b, r, &img->cy[img->cy_count]);
	img->cy[img->cy_count].color = color;
	img->cy_count++;
}
*/
void	set_shading(t_img *img)
{
	img->shade_on = 1;
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
	img->sp_count = 0;
	img->pl_count = 0;
	img->cn_count = 0;
	img->cy_count = 0;
	img->lit_count = 0;
	img->obj_count = 0;
	img->ll_cor = setv(-2.0, -1.0, -1.0);
	img->hor = setv(4.0, 0.0, 0.0);
	img->ver = setv(0.0, 2.0, 0.0);
	img->ori = setv(0.0, 0.0, 2.0);
	img->cam_a = setv(0.0, 0.0, 0.0);
	push_sphere(setv(0.0, 0.0, -0.5), 0.5, c(150, 0, 255), img);
	push_sphere(setv(1.0, 0.0, -0.5), 0.6, c(255, 255, 255), img);
	push_pl(setv(0.0, -1.0, 0.0), setv(0.0, 1.0, 0.0), c(0, 0, 255), img);
	push_pl(setv(0.0, 0.0, -5.0), setv(0.0, 0.0, 1.0), c(0, 128, 128), img);
	push_cn(setv(-1.0, 1.0, -0.5), setv(-1.0, -0.3, -0.5), 1.0, c(255, 0, 0), img);
	push_cn(setv(-3.0, 1.0, -0.5), setv(-3.0, -0.3, -0.5), 1.0, c(100, 100, 100), img);
	push_cy(setv(1.5, -0.4, -0.5), setv(0.9, 0.5, -0.5), 0.5, c(255, 0, 255), img);
	push_cy(setv(2.0, -0.4, -0.5), setv(2.0, 0.5, -0.5), 0.3, c(128, 0, 255), img);
	set_shading(img);
	push_scene(img);
}
