/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:01:30 by aannara           #+#    #+#             */
/*   Updated: 2019/11/23 14:00:58 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void	set_ray(t_vec *a, t_vec *b, t_ray *res)
{
	res->a.e[0] = a->e[0];
	res->a.e[1] = a->e[1];
	res->a.e[2] = a->e[2];
	res->b.e[0] = b->e[0];
	res->b.e[1] = b->e[1];
	res->b.e[2] = b->e[2];
}

t_vec	origin(t_ray *r)
{
	return (r->a);
}

void	originr(t_ray *r, t_vec *res)
{
	res->e[0] = r->a.e[0];
	res->e[1] = r->a.e[1];
	res->e[2] = r->a.e[2];
}

t_vec	direction(t_ray *r)
{
	return (r->b);
}

void	directionr(t_ray *r, t_vec *res)
{
	res->e[0] = r->b.e[0];
	res->e[1] = r->b.e[1];
	res->e[2] = r->b.e[2];
}

t_vec	point_at_paramete(t_ray *r, float t)
{
	t_vec	v;
	t_vec	m;

	m = mulf(r->b, t);
	v = add(r->a, m);
	return (v);
}

void	point_at_parameter(t_ray *r, float t, t_vec *res)
{
	*res = mulf(r->b, t);
	adda(res, &r->a);
}
