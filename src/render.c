/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:42:44 by aannara           #+#    #+#             */
/*   Updated: 2019/11/27 11:50:06 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		shadowl(t_vec *p, t_img *img, int x, t_vec *l)
{
	int		i;
	t_ray	ray;
	t_res	r;
	t_vec	d;

	i = 0;
	d = sub(*l, *p);
	set_ray(p, &d, &ray);
	if (!img->shadow_on)
		return (0);
	while (i < img->obj_count)
	{
		if (i == x)
			i++;
		if (i >= img->obj_count)
			break ;
		r = (*img->ar[i].hit_f)(img->ar[i].obj, &ray);
		if (r.t > 0.0 && r.t < 1.0)
			return (1);
		i++;
	}
	return (0);
}

float	specular(t_res *r, t_img *img, t_vec *l)
{
	t_vec	viewdir;
	t_vec	reflectdir;

	if (!img->specul_on)
		return (0.0);
	viewdir = sub(img->ori, r->p);
	make_unit_vector(&viewdir);
	reflectdir = reflect(sub(r->p, *l), r->n);
	make_unit_vector(&reflectdir);
	return (dot(viewdir, reflectdir));
}

float	shade_coef(t_res *r, t_vec *l)
{
	t_vec	l_vec;
	float	dot_p;

	l_vec = sub(*l, r->p);
	dot_p = dot(r->n, l_vec);
	return (dot_p / (length(r->n) * length(l_vec)));
}

int		shadel(t_res *r, t_img *img, t_vec *l)
{
	float	coef;
	int		color;
	int		c2;
	float	spec;

	c2 = (*img->ar[r->x].col_f)(img->ar[r->x].obj);
	coef = shade_coef(r, l);
	color = grad(BLACK, c2, img->amb);
	if (!shadowl(&r->p, img, r->x, l) && img->shade_on)
	{
		if (coef < 0.0)
			return (color);
		if (coef > 1.0)
			coef = 1.0;
		coef = coef / img->lit_count;
		coef *= img->powl;
		color = grad(color, c2, coef);
		spec = specular(r, img, l);
		if (spec > 0.0)
		{
			spec = pwr(spec, img->pows) * img->powl;
			color = grad(color, WHITE, spec);
		}
	}
	return (color);
}

t_res	cycle(t_img *img, t_ray *ray)
{
	int		x;
	t_res	r_m;
	t_res	r;

	r_m.t = -2.0;
	x = 0;
	while (x < img->obj_count)
	{
		r = (*img->ar[x].hit_f)(img->ar[x].obj, ray);
		if ((r_m.t < 0.0 && r.t > 0.0) ||
				(r.t > 0.0 && r_m.t > 0.0 && r.t < r_m.t))
		{
			r_m = r;
			r_m.x = x;
		}
		x++;
	}
	return (r_m);
}
