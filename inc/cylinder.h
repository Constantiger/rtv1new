/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 09:35:09 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 13:45:26 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_H
# define CYLINDER_H

# include "vec.h"
# include "ray.h"
# include "plane.h"

typedef struct	s_cylinder
{
	t_vec		center;
	t_vec		b;
	t_vec		v;
	float		radius;
	float		h;
	t_plane		cap1;
	t_plane		cap2;
	int			color;
}				t_cylinder;

void			cyl_norm(t_ray *ray, t_cylinder *cy, float t, t_vec *n);
void			set_cylinder(t_vec cent, t_vec b, float r, t_cylinder *c);
t_res			hit_cylinder(void *v_cy, t_ray *ray);
int				cyl_col(void *v_cy);
t_vec			cy_proj(t_cylinder *cy, t_vec inter);
void			cylinder_p_n(t_ray *ray, t_cylinder *cy, t_res *r);

#endif
