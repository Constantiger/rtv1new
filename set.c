/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:32:33 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 14:33:47 by aannara          ###   ########.fr       */
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
	img->lit[img->lit_count] = l;
	img->lit_count++;
	img->lit_save = img->lit_count;
}

void	push_scene(t_img *img)
{
	push_lit(setv(-5.0, 6.0, 10.0), img);
	push_lit(setv(-6.0, 5.0, 9.0), img);
	push_lit(setv(1.0, 15.0, 9.0), img);
	push_obj_ar((void*)(&img->cy), &hit_cylinder, &cyl_col, img);
	push_obj_ar((void*)(&img->sp), &hit_sphere, &sphere_col, img);
	push_obj_ar((void*)(&img->pl), &hit_plane, &plane_col, img);
	push_obj_ar((void*)(&img->cn), &hit_cone, &cone_col, img);
	push_obj_ar((void*)(&img->pl2), &hit_plane, &plane_col, img);
}

void	set_shading(t_img *img)
{
	img->shade_on = 0;
	img->shadow_on = 0;
	img->specul_on = 0;
	img->mult_lit_on = 0;
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
	img->ori = setv(0.0, 0.0, 2.0);
	img->cam_a = setv(0.0, 0.0, 0.0);
	set_sphere(setv(0.0, 0.0, -0.5), 0.5, &img->sp);
	img->sp.color = c(255, 50, 50);
	set_sphere(setv(2.0, -100.5, -0.5), 100.5, &img->sp2);
	img->sp2.color = c(50, 50, 255);
	set_plane(setv(0.0, -1.0, 0.0), setv(0.0, 1.0, 0.0), &img->pl);
	set_plane(setv(0.0, 0.0, -5.0), setv(0.0, 0.0, 1.0), &img->pl2);
	set_cone(setv(-1.0, 1.0, -0.5), setv(-1.0, -0.3, -0.5), 1.0, &img->cn);
	set_cylinder(setv(1.5, -0.4, -0.5), setv(0.9, 0.5, -0.5), 0.5, &img->cy);
	img->lit_count = 0;
	img->obj_count = 0;
	img->cn.color = c(255, 0, 0);
	img->pl.color = c(0, 0, 255);
	img->pl2.color = c(0, 128, 128);
	img->cy.color = c(255, 0, 255);
	img->sp.color = c(150, 0, 255);
	set_shading(img);
	push_scene(img);
}
