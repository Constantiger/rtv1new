/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:21:12 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 14:52:16 by aannara          ###   ########.fr       */
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

# define WIN_L 1280
# define WIN_H 640
# define WHITE 16777215
# define BLACK 0
# define PI_R 0.0174532925

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
	t_sphere	sp;
	t_sphere	sp2;
	t_plane		pl;
	t_plane		pl2;
	t_cone		cn;
	t_cylinder	cy;
	t_vec		lit[10];
	int			lit_count;
	int			lit_save;
	float		amb;
	t_obj		ar[100];
	int			obj_count;
	t_vec		cam_a;
	int			shade_on;
	int			shadow_on;
	int			specul_on;
	int			mult_lit_on;
	int			redraw;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
	t_img		*i;
}				t_mlx;

float			pwr(float f, int p);
void			new_image(t_mlx *m, t_img *img, int size_x, int size_y);
void			img_pixel_put(t_img *img, int x, int y, int color);
t_ray			init_ray(t_img *img, int i, int j);
void			iter(t_img *img, int i, int j);
void			draw(t_mlx *m, t_img *img, int x, int y);
int				shadowl(t_vec *p, t_img *img, int x, t_vec *l);
float			specular(t_res *r, t_img *img, t_vec *l);
float			shade_coef(t_res *r, t_vec *l);
int				shadel(t_res *r, t_img *img, t_vec *l);
t_res			cycle(t_img *img, t_ray *ray);
void			push_obj_ar(void *obj, t_res (*hit_f)(void *, t_ray *),
				int (*col_f)(void *), t_img *img);
void			push_lit(t_vec l, t_img *img);
void			push_scene(t_img *img);
void			set_shading(t_img *img);
void			set_camera(t_img *img);
int				expose(void *param);
int				key_press(int key, void *param);
int				close_win(void *param);
void			draw(t_mlx *m, t_img *img, int x, int y);
void			rotate_cam(int key, t_mlx *m);
void			rotate_v(t_ray *ray, t_img *angles);

#endif
