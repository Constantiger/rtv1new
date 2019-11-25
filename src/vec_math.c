/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:19:19 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 14:22:48 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vec	add(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.e[0] = v1.e[0] + v2.e[0];
	v.e[1] = v1.e[1] + v2.e[1];
	v.e[2] = v1.e[2] + v2.e[2];
	return (v);
}

t_vec	sub(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.e[0] = v1.e[0] - v2.e[0];
	v.e[1] = v1.e[1] - v2.e[1];
	v.e[2] = v1.e[2] - v2.e[2];
	return (v);
}

void	suba(t_vec *v1, t_vec *v2)
{
	v1->e[0] -= v2->e[0];
	v1->e[1] -= v2->e[1];
	v1->e[2] -= v2->e[2];
}

t_vec	mulf(t_vec v1, float f)
{
	t_vec	v;

	v.e[0] = v1.e[0] * f;
	v.e[1] = v1.e[1] * f;
	v.e[2] = v1.e[2] * f;
	return (v);
}

void	make_unit_vector(t_vec *v)
{
	float	k;

	k = 1.0 / length(*v);
	*v = mulf(*v, k);
}
