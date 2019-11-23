/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:00:11 by aannara           #+#    #+#             */
/*   Updated: 2019/11/23 14:03:56 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec.h"

typedef struct	s_ray
{
	t_vec		a;
	t_vec		b;
}				t_ray;

t_vec			origin(t_ray *r);
void			originr(t_ray *r, t_vec *res);
t_vec			direction(t_ray *r);
void			directionr(t_ray *r, t_vec *res);
void			point_at_parameter(t_ray *r, float t, t_vec *res);
t_vec			point_at_paramete(t_ray *r, float t);
void			set_ray(t_vec *a, t_vec *b, t_ray *res);

#endif
