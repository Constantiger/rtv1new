/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:38:59 by aannara           #+#    #+#             */
/*   Updated: 2019/11/23 14:56:46 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_H
# define CONE_H

# include "vec.h"
# include "ray.h"
# include "math.h"
# include "plane.h"

typedef struct	s_cone
{
	t_vec		center;
	float		ang;
	float		k;
	float		h;
	t_vec		v;
	t_vec		b;
	int			color;
	t_plane		cap;
}				t_cone;

void			con_norm(t_ray *ray, t_cone *cn, float t, t_vec *n);
void			set_cone(t_vec p, t_vec v, float a, t_cone *c);
t_res			hit_cone(void *v_cn, t_ray *ray);
int				cone_col(void *v_cn);

#endif
