/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:21:12 by aannara           #+#    #+#             */
/*   Updated: 2019/11/27 11:59:37 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
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
	t_sphere	sp[10];
	int			sp_count;
	t_plane		pl[10];
	int			pl_count;
	t_cone		cn[10];
	int			cn_count;
	t_cylinder	cy[10];
	int			cy_count;
	t_vec		lit[10];
	int			lit_count;
	int			lit_save;
	float		amb;
	float		powl;
	int			pows;
	t_obj		ar[100];
	int			obj_count;
	t_vec		cam_a;
	int			shade_on;
	int			shadow_on;
	int			specul_on;
	int			mult_lit_on;
	int			redraw;
	int			help;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
	t_img		*i;
	int			red;
	int			green;
	int			blue;
	t_vec		p;
	t_vec		a;
	t_vec		b;
	float		r;
	int			color;
	double		integer;
	double		fraction;
	int			infraction;
	int			size;
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
void			push_sphere(t_vec c, float r, int color, t_img *img);
void			push_pl(t_vec c, t_vec n, int color, t_img *img);
void			push_cn(t_vec t, t_vec b, float ang, t_img *img);
void			push_cy(t_vec t, t_vec b, float r, t_img *img);
void			read_file(int fd, t_mlx *m);
int				ft_atoi(const char *str);
double			ft_atof(char *num);
t_mlx			init_atof(t_mlx *m);
void			print_err(char *s);
int				sp(char *str, int *i);
int				cn(char *str, int *i);
int				cy(char *str, int *i);
int				pl(char *str, int *i);
int				pl2(char *str, int *i);
int				light(char *str, int *i);
void			push_lit(t_vec l, t_img *img);
void			plane(char *str, t_mlx *m, int i);
void			cylinder(char *str, t_mlx *m, int i);
void			cone(char *str, t_mlx *m, int i);
void			sphere(char *str, t_mlx *m, int i);
void			li(char *str, t_mlx *m, int i);
void			set_figure(t_mlx *m);
void			menu(t_mlx *m);
void			push_cn_color(t_img *img, int color);
void			push_cy_color(t_img *img, int color);

#endif
