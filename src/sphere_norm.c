/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_norm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:47:34 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 13:50:04 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sphere.h"

void	sphere_norm(t_ray *ray, t_sphere *s, float t, t_vec *res)
{
	point_at_parameter(ray, t, res);
	suba(res, &s->center);
	make_unit_vector(res);
}

void	sphere_p_n(t_ray *ray, t_sphere *s, t_res *r)
{
	point_at_parameter(ray, r->t, &r->p);
	sphere_norm(ray, s, r->t, &r->n);
}
