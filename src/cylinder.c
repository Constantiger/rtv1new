/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:40:01 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 13:47:14 by aannara          ###   ########.fr       */
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

float	mm(t_ray *ray, t_cylinder *cy, float t)
{
	return (dot(direction(ray), cy->v) * t +
			dot(sub(origin(ray), cy->center), cy->v));
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
	t_vec		pr;

	cy = (t_cylinder*)v_cy;
	cyl_dis(cy, ray, &abc);
	r = hit_plane(&cy->cap1, ray);
	r1 = hit_plane(&cy->cap2, ray);
	if ((r.t > 0.0 && r1.t > 0.0 && r.t < r1.t) || (r1.t < 0.0 && r.t > 0.0))
		r1 = r;
	if (abc.e[2] < 0.0)
		return (r1);
	else
		abc.e[2] = (-abc.e[1] - sqrt(abc.e[2])) / (2.0 * abc.e[0]);
	point_at_parameter(ray, abc.e[2], &pr);
	pr = cy_proj(cy, pr);
	if (sq_l(sub(cy->center, pr)) + sq_l(sub(pr, cy->b)) > cy->h * cy->h)
		return (r1);
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
