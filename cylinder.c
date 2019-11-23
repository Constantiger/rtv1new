/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:40:01 by aannara           #+#    #+#             */
/*   Updated: 2019/11/23 15:04:10 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

void	set_cylinder(t_vec cent, t_vec b, float r, t_cylinder *c)
{
	c->center = cent;
	c->radius = r;
	c->b = b;
	c->v = sub(b, cent);
	c->h = length(c->v);
	make_unit_vector(&c->v);
	set_plane(cent, sub(cent, b), &c->cap1);
	c->cap1.r = r;
	set_plane(b, sub(b, cent), &c->cap2);
	c->cap2.r = r;
}

t_vec	cyl_proj(t_cylinder *cy, t_vec inter)
{
	t_vec	res;
	t_vec	t;
	float	a;

	a = dot(cy->v, sub(inter, cy->center)) / dot(cy->v, cy->v);
	t = mulf(cy->v, a);
	res = add(cy->center, t);
	return (res);
}

t_vec	cy_proj(t_cylinder *cy, t_vec inter)
{
	t_vec	res;
	t_vec	t;

	t = mulf(cy->v, dot(cy->v, sub(inter, cy->center)) / dot(cy->v, cy->v));
	res = add(cy->center, t);
	return (res);
}

float	mm(t_ray *ray, t_cylinder *cy, float t)
{
	return (dot(direction(ray), cy->v) * t +
			dot(sub(origin(ray), cy->center), cy->v));
}

void	cyl_norm(t_ray *ray, t_cylinder *cy, float t, t_vec *n)
{
	t_vec	p;
	t_vec	pr;

	point_at_parameter(ray, t, &p);
	pr = cyl_proj(cy, p);
	*n = sub(p, pr);
	make_unit_vector(n);
}

void	cylinder_p_n(t_ray *ray, t_cylinder *cy, t_res *r)
{
	point_at_parameter(ray, r->t, &r->p);
	cyl_norm(ray, cy, r->t, &r->n);
}

void	cyl_dis(t_cylinder *cy, t_ray *ray, t_vec *abc)
{
	float	t;
	t_vec	x;

	x = sub(origin(ray), cy->center);
	t = dot(direction(ray), cy->v);
	abc->e[0] = dot(direction(ray), direction(ray)) - t * t;
	abc->e[1] = 2 * (dot(direction(ray), x) -
			t * dot(x, cy->v));
	abc->e[2] = dot(x, x) - dot(x, cy->v) *
		dot(x, cy->v) - cy->radius * cy->radius;
	abc->e[2] = abc->e[1] * abc->e[1] - 4 * abc->e[0] * abc->e[2];
}

t_res	hit_cylinder(void *v_cy, t_ray *ray)
{
	t_cylinder	*cy;
	t_vec		abc;
	t_res		r;
	t_res		r1;
	t_res		r2;
	t_vec		pr;

	cy = (t_cylinder*)v_cy;
	cyl_dis(cy, ray, &abc);
	r1 = hit_plane(&cy->cap1, ray);
	r2 = hit_plane(&cy->cap2, ray);
	if (abc.e[2] < 0.0)
	{
		if (r1.t < 0.0 && r2.t < 0.0)
			r.t = -1.0;
		else
		{
			if ((r1.t > 0.0 && r2.t < 0.0) ||
					(r1.t > 0.0 && r2.t > 0.0 && r1.t < r2.t))
				return (r1);
			else if ((r2.t > 0.0 && r1.t < 0.0) ||
					(r2.t > 0.0 && r1.t > 0.0 && r2.t > r1.t))
				return (r2);
		}
	}
	else
		abc.e[2] = (-abc.e[1] - sqrt(abc.e[2])) / (2.0 * abc.e[0]);
	point_at_parameter(ray, abc.e[2], &pr);
	pr = cy_proj(cy, pr);
	if (sq_l(sub(cy->center, pr)) + sq_l(sub(pr, cy->b)) > cy->h * cy->h)
	{
		if (r1.t < 0.0 && r2.t < 0.0)
			r.t = -1.0;
		else
		{
			if ((r1.t > 0.0 && r2.t < 0.0) ||
					(r1.t > 0.0 && r2.t > 0.0 && r1.t < r2.t))
				return (r1);
			else if ((r2.t > 0.0 && r1.t < 0.0) ||
					(r2.t > 0.0 && r1.t > 0.0 && r2.t > r1.t))
				return (r2);
		}
	}
	else
		r.t = abc.e[2];
	if (r.t > 0.0)
		cylinder_p_n(ray, cy, &r);
	return (r);
}

int		cyl_col(void *v_cy)
{
	t_cylinder *cy;

	cy = (t_cylinder*)v_cy;
	return (cy->color);
}
