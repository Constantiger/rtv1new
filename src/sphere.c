/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:27:57 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 17:15:31 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

void	set_sphere(t_vec pos, float r, t_sphere *s)
{
	s->center = pos;
	s->radius = r;
}

void	sphere_dis(t_sphere *s, t_ray *ray, t_vec *abc)
{
	t_vec	oc;

	oc = sub(origin(ray), s->center);
	abc->e[0] = dot(direction(ray), direction(ray));
	abc->e[1] = 2.0 * dot(oc, direction(ray));
	abc->e[2] = dot(oc, oc) - s->radius * s->radius;
	abc->e[2] = abc->e[1] * abc->e[1] - 4 * abc->e[0] * abc->e[2];
}

t_res	hit_sphere(void *v_s, t_ray *ray)
{
	t_vec		abc;
	t_res		r;
	t_sphere	*s;

	s = (t_sphere*)v_s;
	sphere_dis(s, ray, &abc);
	if (abc.e[2] < 0.0)
	{
		r.t = -1.0;
	}
	else
	{
		r.t = (-abc.e[1] - sqrt(abc.e[2])) / (2.0 * abc.e[0]);
	}
	if (r.t > 0.0)
		sphere_p_n(ray, s, &r);
	return (r);
}

int		sphere_col(void *v_sp)
{
	t_sphere *sp;

	sp = (t_sphere*)v_sp;
	return (sp->color);
}
