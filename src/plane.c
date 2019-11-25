/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:11:39 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 13:52:37 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "plane.h"

void	set_plane(t_vec pos, t_vec n, t_plane *p)
{
	p->pos = pos;
	p->norm = n;
	make_unit_vector(&p->norm);
	p->r = -1.0;
}

int		hit_cap(t_plane *pl, t_ray *ray, float t)
{
	t_vec	p;

	point_at_parameter(ray, t, &p);
	if (pl->r < 0.0)
		return (1);
	else
	{
		if (length(sub(p, pl->pos)) < pl->r)
			return (1);
		else
			return (0);
	}
}

void	plane_p_n(t_ray *ray, t_plane *pl, t_res *r)
{
	point_at_parameter(ray, r->t, &r->p);
	r->n = pl->norm;
}

t_res	hit_plane(void *v_pl, t_ray *ray)
{
	t_vec	o;
	t_vec	p;
	float	denom;
	t_res	r;
	t_plane *pl;

	pl = (t_plane*)v_pl;
	o = origin(ray);
	denom = dot(direction(ray), pl->norm);
	if (denom > 0.0001 || denom < -0.0001)
	{
		p = sub(pl->pos, o);
		r.t = dot(p, pl->norm) / denom;
	}
	else
		r.t = -1.0;
	if (r.t > 0.0 && !hit_cap(pl, ray, r.t))
		r.t = -1.0;
	if (r.t > 0.0)
		plane_p_n(ray, pl, &r);
	return (r);
}

int		plane_col(void *v_pl)
{
	t_plane *pl;

	pl = (t_plane*)v_pl;
	return (pl->color);
}
