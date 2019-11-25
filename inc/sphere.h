/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:25:18 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 17:15:49 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "vec.h"
# include "ray.h"
# include "result.h"

typedef struct	s_sphere
{
	t_vec		center;
	float		radius;
	int			color;
}				t_sphere;

void			set_sphere(t_vec pos, float r, t_sphere *s);
t_res			hit_sphere(void *v_s, t_ray *ray);
int				sphere_col(void *v_sp);
void			sphere_norm(t_ray *ray, t_sphere *s, float t, t_vec *res);
void			sphere_p_n(t_ray *ray, t_sphere *s, t_res *r);

#endif
