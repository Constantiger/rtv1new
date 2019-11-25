/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 14:21:15 by aannara           #+#    #+#             */
/*   Updated: 2019/11/23 13:24:38 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_H
# define PLANE_H

# include "vec.h"
# include "ray.h"
# include "result.h"

typedef struct	s_plane
{
	t_vec		pos;
	t_vec		norm;
	float		r;
	int			color;
}				t_plane;

void			set_plane(t_vec pos, t_vec n, t_plane *p);
t_res			hit_plane(void *v_pl, t_ray *ray);
int				plane_col(void *v_pl);

#endif
