/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_norm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:40:59 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 13:44:08 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cylinder.h"

t_vec	cy_proj(t_cylinder *cy, t_vec inter)
{
	t_vec	res;
	t_vec	t;

	t = mulf(cy->v, dot(cy->v, sub(inter, cy->center)) / dot(cy->v, cy->v));
	res = add(cy->center, t);
	return (res);
}

void	cyl_norm(t_ray *ray, t_cylinder *cy, float t, t_vec *n)
{
	t_vec	p;
	t_vec	pr;

	point_at_parameter(ray, t, &p);
	pr = cy_proj(cy, p);
	*n = sub(p, pr);
	make_unit_vector(n);
}

void	cylinder_p_n(t_ray *ray, t_cylinder *cy, t_res *r)
{
	point_at_parameter(ray, r->t, &r->p);
	cyl_norm(ray, cy, r->t, &r->n);
}
