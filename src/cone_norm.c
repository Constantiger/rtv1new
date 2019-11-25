/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_norm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:35:06 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 13:36:18 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cone.h"

void	con_norm(t_ray *ray, t_cone *cn, float t, t_vec *n)
{
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
