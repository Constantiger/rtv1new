/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:13:49 by aannara           #+#    #+#             */
/*   Updated: 2019/11/23 14:54:11 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	set_vec(float a, float b, float c, t_vec *v)
{
	*v = setv(a, b, c);
}

t_vec	setv(float a, float b, float c)
{
	t_vec	t;

	t.e[0] = a;
	t.e[1] = b;
	t.e[2] = c;
	return (t);
}

void	setvr(float a, float b, float c, t_vec *v)
{
	v->e[0] = a;
	v->e[1] = b;
	v->e[2] = c;
}

float	x(t_vec *v)
{
	return (v->e[0]);
}

float	y(t_vec *v)
{
	return (v->e[1]);
}

float	z(t_vec *v)
{
	return (v->e[2]);
}

t_vec	add(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.e[0] = v1.e[0] + v2.e[0];
	v.e[1] = v1.e[1] + v2.e[1];
	v.e[2] = v1.e[2] + v2.e[2];
	return (v);
}

void	adda(t_vec *v1, t_vec *v2)
{
	v1->e[0] += v2->e[0];
	v1->e[1] += v2->e[1];
	v1->e[2] += v2->e[2];
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

t_vec	mul(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.e[0] = v1.e[0] * v2.e[0];
	v.e[1] = v1.e[1] * v2.e[1];
	v.e[2] = v1.e[2] * v2.e[2];
	return (v);
}

void	mula(t_vec *v1, t_vec *v2)
{
	v1->e[0] *= v2->e[0];
	v1->e[1] *= v2->e[1];
	v1->e[2] *= v2->e[2];
}

t_vec	divv(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.e[0] = v1.e[0] / v2.e[0];
	v.e[1] = v1.e[1] / v2.e[1];
	v.e[2] = v1.e[2] / v2.e[2];
	return (v);
}

void	diva(t_vec *v1, t_vec *v2)
{
	v1->e[0] /= v2->e[0];
	v1->e[1] /= v2->e[1];
	v1->e[2] /= v2->e[2];
}

t_vec	mulf(t_vec v1, float f)
{
	t_vec	v;

	v.e[0] = v1.e[0] * f;
	v.e[1] = v1.e[1] * f;
	v.e[2] = v1.e[2] * f;
	return (v);
}

void	mulfa(t_vec *v1, float f)
{
	v1->e[0] *= f;
	v1->e[1] *= f;
	v1->e[2] *= f;
}

t_vec	divf(t_vec v1, float f)
{
	t_vec	v;

	v.e[0] = v1.e[0] / f;
	v.e[1] = v1.e[1] / f;
	v.e[2] = v1.e[2] / f;
	return (v);
}

void	divfa(t_vec *v1, float f)
{
	v1->e[0] /= f;
	v1->e[0] /= f;
	v1->e[0] /= f;
}

float	length(t_vec v)
{
	return (sqrt(v.e[0] * v.e[0] + v.e[1] * v.e[1] + v.e[2] * v.e[2]));
}

float	sq_l(t_vec v)
{
	return (v.e[0] * v.e[0] + v.e[1] * v.e[1] + v.e[2] * v.e[2]);
}

void	make_unit_vector(t_vec *v)
{
	float	k;

	k = 1.0 / length(*v);
	mulfa(v, k);
}

float	dot(t_vec v1, t_vec v2)
{
	return (v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2]);
}

t_vec	cross(t_vec v1, t_vec v2)
{
	t_vec	v;

	v.e[0] = v1.e[1] * v2.e[2] + v1.e[2] * v2.e[1];
	v.e[1] = v1.e[0] * v2.e[2] + v1.e[2] * v2.e[0];
	v.e[2] = v1.e[0] * v2.e[1] + v1.e[1] * v2.e[0];
	return (v);
}

void	crossa(t_vec *v1, t_vec *v2)
{
	t_vec	v;

	v.e[0] = v1->e[1] * v2->e[2] + v1->e[2] * v2->e[1];
	v.e[1] = v1->e[0] * v2->e[2] + v1->e[2] * v2->e[0];
	v.e[2] = v1->e[0] * v2->e[1] + v1->e[1] * v2->e[0];
	v1->e[0] = v.e[0];
	v1->e[1] = v.e[1];
	v1->e[2] = v.e[2];
}

t_vec	unit_vector(t_vec v1)
{
	t_vec	v;

	v = divf(v1, length(v1));
	return (v);
}

void	unit_vectora(t_vec *v1)
{
	divfa(v1, length(*v1));
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
