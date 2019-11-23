/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:22:30 by aannara           #+#    #+#             */
/*   Updated: 2019/11/23 15:15:19 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

float	pwr(float f, int p)
{
	int		i;
	float	res;

	res = f;
	i = 1;
	while (i < p)
	{
		res *= res;
		i++;
	}
	return (res);
}

void	new_image(t_mlx *m, t_img *img, int size_x, int size_y)
{
	img->bpp = 32;
	img->stride = 0;
	img->endian = 0;
	img->size_x = size_x;
	img->size_y = size_y;
	img->img = mlx_new_image(m->mlx, size_x, size_y);
	img->ptr = mlx_get_data_addr(img->img, &img->bpp,
			&img->stride, &img->endian);
}

void	img_pixel_put(t_img *img, int x, int y, int color)
{
	if (x < 0 || x > img->size_x || y < 0 || y > img->size_y)
		return ;
	*(int*)(img->ptr + ((x + y * img->size_x) * 4)) = color;
}

void	push_obj_ar(void *obj, t_res (*hit_f)(void *, t_ray *),
		int (*col_f)(void *), t_img *img)
{
	img->ar[img->obj_count].obj = obj;
	img->ar[img->obj_count].hit_f = hit_f;
	img->ar[img->obj_count].col_f = col_f;
	img->obj_count++;
}

void	push_lit(t_vec l, t_img *img)
{
	img->lit[img->lit_count] = l;
	img->lit_count++;
}

void	push_scene(t_img *img)
{
	push_lit(setv(-5.0, 6.0, 10.0), img);
	push_lit(setv(-6.0, 5.0, 9.0), img);
	push_lit(setv(1.0, 15.0, 9.0), img);
	push_obj_ar((void*)(&img->cy), &hit_cylinder, &cyl_col, img);
	push_obj_ar((void*)(&img->sp), &hit_sphere, &sphere_col, img);
	push_obj_ar((void*)(&img->pl), &hit_plane, &plane_col, img);
	push_obj_ar((void*)(&img->cn), &hit_cone, &cone_col, img);
	push_obj_ar((void*)(&img->pl2), &hit_plane, &plane_col, img);
}

void	set_camera(t_img *img)
{
	set_vec(-2.0, -1.0, -1.0, &img->ll_cor);
	set_vec(4.0, 0.0, 0.0, &img->hor);
	set_vec(0.0, 2.0, 0.0, &img->ver);
	set_vec(0.0, 0.0, 2.0, &img->ori);
	set_sphere(setv(0.0, 0.0, -0.5), 0.5, &img->sp);
	img->sp.color = c(255, 50, 50);
	set_sphere(setv(2.0, -100.5, -0.5), 100.5, &img->sp2);
	img->sp2.color = c(50, 50, 255);
	set_plane(setv(0.0, -1.0, 0.0), setv(0.0, 1.0, 0.0), &img->pl);
	set_plane(setv(0.0, 0.0, -5.0), setv(0.0, 0.0, 1.0), &img->pl2);
	set_cone(setv(-1.0, 1.0, -0.5), setv(-1.0, -0.3, -0.5), 1.0, &img->cn);
	set_cylinder(setv(1.0, -0.8, -0.5), setv(0.9, 0.7, -0.5), 0.5, &img->cy);
	img->amb = 0.07;
	img->obj_count = 0;
	img->cn.color = c(255, 0, 0);
	img->pl.color = c(0, 0, 255);
	img->pl2.color = c(0, 128, 128);
	img->cy.color = c(255, 0, 255);
	img->sp.color = c(150, 0, 255);
	push_scene(img);
}

void	fill(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < img->size_y)
	{
		while (j < img->size_x)
		{
			img_pixel_put(img, j, i, color);
			j++;
		}
		i++;
		j = 0;
	}
}

int		vec_col(t_vec *v)
{
	return (c((int)(255.99 * z(v)),
			(int)(255.99 * y(v)),
			(int)(255.99 * z(v))));
}

void	color(t_ray *ray, t_vec *res)
{
	t_vec	unit_direction;
	float	t;
	t_vec	one;
	t_vec	two;

	unit_direction = direction(ray);
	unit_vector(unit_direction);
	t = 0.5 * (y(&unit_direction) + 1.0);
	set_vec(1.0, 1.0, 1.0, &one);
	mulfa(&one, (1.0 - t));
	set_vec(0.5, 0.7, 1.0, &two);
	mulfa(&two, t);
	*res = add(one, two);
}

void	point(t_ray *ray, float t, t_vec *p)
{
	point_at_parameter(ray, t, p);
}

t_ray	init_ray(t_img *img, int i, int j)
{
	float	u;
	float	v;
	t_ray	ray;
	t_vec	ll_cor;

	u = (float)(i) / (float)(img->size_x);
	v = (float)(j) / (float)(img->size_y);
	ll_cor = add(add(img->ll_cor, mulf(img->hor, u)), mulf(img->ver, v));
	set_ray(&img->ori, &ll_cor, &ray);
	return (ray);
}

int		shadowl(t_vec *p, t_img *img, int x, t_vec *l)
{
	int		i;
	t_ray	ray;
	t_res	r;

	i = 0;
	set_ray(p, l, &ray);
	while (i < img->obj_count)
	{
		if (i == x)
			i++;
		if (i >= img->obj_count)
			break ;
		r = (*img->ar[i].hit_f)(img->ar[i].obj, &ray);
		if (r.t > 0.0)
			return (1);
		i++;
	}
	return (0);
}

float	specular(t_res *r, t_img *img, t_vec *l)
{
	t_vec	viewdir;
	t_vec	reflectdir;

	viewdir = sub(img->ori, r->p);
	make_unit_vector(&viewdir);
	reflectdir = reflect(sub(r->p, *l), r->n);
	make_unit_vector(&reflectdir);
	return (dot(viewdir, reflectdir));
}

float	shade_coef(t_res *r, t_vec *l)
{
	t_vec	l_vec;
	float	dot_p;

	l_vec = sub(*l, r->p);
	dot_p = dot(r->n, l_vec);
	return (dot_p / (length(r->n) * length(l_vec)));
}

int		shadel(t_res *r, t_img *img, t_vec *l)
{
	float	coef;
	int		color;
	int		c2;
	float	spec;

	c2 = (*img->ar[r->x].col_f)(img->ar[r->x].obj);
	coef = shade_coef(r, l);
	color = grad(BLACK, c2, img->amb);
	if (!shadowl(&r->p, img, r->x, l))
	{
		if (coef < 0.0)
			return (color);
		if (coef > 1.0)
			coef = 1.0;
		coef = coef / img->lit_count;
		color = grad(color, c2, coef);
		spec = specular(r, img, l);
		if (spec > 0.0)
		{
			spec = pwr(spec, 10);
			color = grad(color, WHITE, spec);
		}
	}
	return (color);
}

int		cl(int c1, int c2)
{
	int	r;
	int	g;
	int	b;

	r = get_rgb(c1, 1) + get_rgb(c2, 1);
	if (r > 255)
		r = 255;
	g = get_rgb(c1, 2) + get_rgb(c2, 2);
	if (g > 255)
		g = 255;
	b = get_rgb(c1, 3) + get_rgb(c2, 3);
	if (b > 255)
		b = 255;
	return (c(r, g, b));
}

t_res	cycle(t_img *img, t_ray *ray)
{
	int		x;
	t_res	r_m;
	t_res	r;

	r_m.t = -2.0;
	x = 0;
	while (x < img->obj_count)
	{
		r = (*img->ar[x].hit_f)(img->ar[x].obj, ray);
		if ((r_m.t < 0.0 && r.t > 0.0) ||
				(r.t > 0.0 && r_m.t > 0.0 && r.t < r_m.t))
		{
			r_m = r;
			r_m.x = x;
		}
		x++;
	}
	return (r_m);
}

void	iter2(t_img *img, int i, int j)
{
	t_ray	ray;
	int		x;
	t_res	r_m;
	int		sh;
	int		clr;

	clr = 0;
	ray = init_ray(img, i, j);
	r_m = cycle(img, &ray);
	x = 0;
	if (r_m.t > 0.0)
	{
		while (x < img->lit_count)
		{
			sh = shadel(&r_m, img, &img->lit[x]);
			clr = cl(clr, sh);
			x++;
		}
		img_pixel_put(img, i, img->size_y - j - 1, clr);
	}
	else
		img_pixel_put(img, i, img->size_y - j - 1, BLACK);
}

void	draw(t_mlx *m, t_img *img, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	fill(img, 0);
	while (j < img->size_y)
	{
		while (i < img->size_x)
		{
			iter2(img, i, j);
			i++;
		}
		i = 0;
		j++;
	}
	mlx_put_image_to_window(m->mlx, m->window, img->img, x, y);
}

int		main(void)
{
	t_mlx	m;
	t_img	img;

	m.mlx = mlx_init();
	m.window = mlx_new_window(m.mlx, WIN_L, WIN_H, "Ray Traycer");
	new_image(&m, &img, WIN_L, WIN_H);
	set_camera(&img);
	m.i = &img;
	draw(&m, &img, 0, 0);
	mlx_hook(m.window, 2, 0, &key_press, (void*)(&m));
	mlx_hook(m.window, 17, 0, &close_win, (void*)(&m));
	mlx_loop(m.mlx);
	return (0);
}
