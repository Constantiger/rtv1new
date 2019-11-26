/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:43:11 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 18:07:42 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

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

void	iter(t_img *img, int i, int j)
{
	t_ray	ray;
	int		x;
	t_res	r_m;
	int		sh;
	int		clr;

	clr = 0;
	ray = init_ray(img, i, j);
	rotate_v(&ray, img);
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
	if (!img->mult_lit_on)
		img->lit_count = 1;
	else
		img->lit_count = img->lit_save;
	if (img->redraw)
	{
		while (j < img->size_y)
		{
			while (i < img->size_x)
			{
				iter(img, i, j);
				i++;
			}
			i = 0;
			j++;
		}
		img->redraw = 0;
	}
	mlx_put_image_to_window(m->mlx, m->window, img->img, x, y);
	menu(m);
}
