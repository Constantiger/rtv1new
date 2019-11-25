/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:00:11 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 14:07:28 by aannara          ###   ########.fr       */
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
t_vec			direction(t_ray *r);
void			point_at_parameter(t_ray *r, float t, t_vec *res);
void			set_ray(t_vec *a, t_vec *b, t_ray *res);

#endif
