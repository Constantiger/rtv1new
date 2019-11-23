/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:40:53 by aannara           #+#    #+#             */
/*   Updated: 2019/11/23 14:54:24 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include "math.h"

typedef struct	s_vec
{
	float		e[3];
}				t_vec;

void			set_vec(float a, float b, float c, t_vec *v);
t_vec			setv(float a, float b, float c);
void			setvr(float a, float b, float c, t_vec *v);
float			x(t_vec *v);
float			y(t_vec *v);
float			z(t_vec *v);
t_vec			add(t_vec v1, t_vec v2);
void			adda(t_vec *v1, t_vec *v2);
t_vec			sub(t_vec v1, t_vec v2);
void			suba(t_vec *v1, t_vec *v2);
t_vec			mul(t_vec v1, t_vec v2);
void			mula(t_vec *v1, t_vec *v2);
t_vec			divv(t_vec v1, t_vec v2);
void			diva(t_vec *v1, t_vec *v2);
t_vec			mulf(t_vec v1, float f);
void			mulfa(t_vec *v1, float f);
t_vec			divf(t_vec v1, float f);
void			divfa(t_vec *v1, float f);
float			length(t_vec v);
float			sq_l(t_vec v);
void			make_unit_vector(t_vec *v);
float			dot(t_vec v1, t_vec v2);
t_vec			cross(t_vec v1, t_vec v2);
void			crossa(t_vec *v1, t_vec *v2);
t_vec			unit_vector(t_vec v1);
void			unit_vectora(t_vec *v1);
t_vec			reflect(t_vec d, t_vec n);

#endif
