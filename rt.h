/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:21:12 by aannara           #+#    #+#             */
/*   Updated: 2019/11/23 15:06:58 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include "vec.h"
# include "ray.h"
# include "color.h"
# include "sphere.h"
# include "cone.h"
# include "cylinder.h"
# include "plane.h"
# include "result.h"

# define WIN_L	1280
# define WIN_H	640
# define WHITE	16777215
# define BLACK	0
# define PI_R	3.14159265/180

typedef	struct	s_obj
{
	void		*obj;
	t_res		(*hit_f)(void *obj, t_ray *ray);
	t_res		(*sdw_f)(void *obj, t_ray *ray);
	int			(*col_f)(void *obj);
}				t_obj;

typedef struct	s_img
{
	void		*img;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
	int			size_x;
	int			size_y;
	t_vec		ll_cor;
	t_vec		hor;
	t_vec		ver;
	t_vec		ori;
	t_vec		cam_a;
	t_sphere	sp;
	t_sphere	sp2;
	t_plane		pl;
	t_plane		pl2;
	t_cone		cn;
	t_cylinder	cy;
	t_vec		lit[10];
	int			lit_count;
	float		amb;
	t_obj		ar[100];
	int			obj_count;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
	t_img		*i;
}				t_mlx;

int				key_press(int key, void *param);
int				close_win(void *param);
void			draw(t_mlx *m, t_img *img, int x, int y);
void			rotate_v(t_ray *ray, t_img *angles);
void			rotate_cam(int key, t_mlx *m);

#endif
