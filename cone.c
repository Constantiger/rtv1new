/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:42:03 by aannara           #+#    #+#             */
/*   Updated: 2019/11/23 15:01:09 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"

void	set_cone(t_vec p, t_vec b, float a, t_cone *c)
{
	c->center = p;
	c->b = b;
	c->v = sub(b, p);
	c->h = length(c->v);
	make_unit_vector(&c->v);
	c->ang = a;
	c->k = tan(a / 2.0);
	set_plane(b, sub(b, p), &c->cap);
	c->cap.r = c->k * c->h;
}

float	mm_cone(t_ray *ray, t_cone *cn, float t)
{
	return (dot(direction(ray), cn->v) * t +
			dot(sub(origin(ray), cn->center), cn->v));
}

void	con_norm(t_ray *ray, t_cone *cn, float t, t_vec *n)
{
	float	a;
	t_vec	p;
	t_vec	t1;
	t_vec	t2;
	float	m;

	point_at_parameter(ray, t, &p);
	m = mm_cone(ray, cn, t);
	t1 = sub(p, cn->center);
	t2 = mulf(cn->v, m);
	*n = sub(t1, mulf(t2, (1 + cn->k * cn->k)));
	make_unit_vector(n);
}

t_vec	cn_proj(t_cone *cn, t_vec inter)
{
	t_vec	res;
	t_vec	t;

	t = mulf(cn->v, dot(cn->v, sub(inter, cn->center)) / dot(cn->v, cn->v));
	res = add(cn->center, t);
	return (res);
}

void	cone_p_n(t_ray *ray, t_cone *cn, t_res *r)
{
	point_at_parameter(ray, r->t, &r->p);
	con_norm(ray, cn, r->t, &r->n);
}

void	cone_dis(t_cone *cn, t_ray *ray, t_vec *abc)
{
	float	dv;
	t_vec	x;

	x = sub(cn->center, origin(ray));
	dv = dot(direction(ray), cn->v);
	abc->e[0] = dot(direction(ray), direction(ray)) -
		(1 + cn->k * cn->k) * dv * dv;
	abc->e[1] = 2 * (dot(direction(ray), x) - (1 + cn->k * cn->k) *
			dv * dot(x, cn->v));
	abc->e[2] = dot(x, x) - (1 + cn->k * cn->k) * dot(x, cn->v) * dot(x, cn->v);
	abc->e[2] = abc->e[1] * abc->e[1] - 4 * abc->e[0] * abc->e[2];
}

t_res	hit_cone(void *v_cn, t_ray *ray)
{
	t_res	rp;
	t_res	r;
	t_cone	*cn;
	t_vec	abc;
	t_vec	pr;

	cn = (t_cone*)v_cn;
	rp = hit_plane(&cn->cap, ray);
	cone_dis(cn, ray, &abc);
	if (abc.e[2] < 0.0)
		return (rp);
	else
		abc.e[2] = (abc.e[1] - sqrt(abc.e[2])) / (2.0 * abc.e[0]);
	point_at_parameter(ray, abc.e[2], &pr);
	pr = cn_proj(cn, pr);
	if (sq_l(sub(cn->center, pr)) + sq_l(sub(pr, cn->b)) > cn->h * cn->h)
		return (rp);
	else
		r.t = abc.e[2];
	if (r.t > 0.0)
		cone_p_n(ray, cn, &r);
	return (r);
}

int		cone_col(void *v_cn)
{
	t_cone *cn;

	cn = (t_cone*)v_cn;
	return (cn->color);
}
