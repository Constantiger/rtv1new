/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:40:53 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 14:27:26 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include "math.h"

typedef struct	s_vec
{
	float		e[3];
}				t_vec;

t_vec			setv(float a, float b, float c);
t_vec			add(t_vec v1, t_vec v2);
t_vec			sub(t_vec v1, t_vec v2);
void			suba(t_vec *v1, t_vec *v2);
t_vec			mulf(t_vec v1, float f);
float			length(t_vec v);
float			sq_l(t_vec v);
void			make_unit_vector(t_vec *v);
float			dot(t_vec v1, t_vec v2);
t_vec			reflect(t_vec d, t_vec n);

#endif
