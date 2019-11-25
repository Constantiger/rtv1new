/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:13:49 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 14:27:52 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

t_vec	setv(float a, float b, float c)
{
	t_vec	t;

	t.e[0] = a;
	t.e[1] = b;
	t.e[2] = c;
	return (t);
}

float	length(t_vec v)
{
	return (sqrt(v.e[0] * v.e[0] + v.e[1] * v.e[1] + v.e[2] * v.e[2]));
}

float	sq_l(t_vec v)
{
	return (v.e[0] * v.e[0] + v.e[1] * v.e[1] + v.e[2] * v.e[2]);
}

float	dot(t_vec v1, t_vec v2)
{
	return (v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2]);
}

t_vec	reflect(t_vec d, t_vec n)
{
	t_vec	res;
	t_vec	t;
	float	tf;

	tf = dot(d, n);
	t = mulf(n, tf);
	t = mulf(t, 2);
	res = sub(d, t);
	return (res);
}
