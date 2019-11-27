/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:49:49 by aannara           #+#    #+#             */
/*   Updated: 2019/11/27 12:05:19 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	push_sphere(t_vec c, float r, int color, t_img *img)
{
	if (img->sp_count > 9)
		return ;
	set_sphere(c, r, &img->sp[img->sp_count]);
	img->sp[img->sp_count].color = color;
	img->sp_count++;
}

void	push_pl(t_vec c, t_vec n, int color, t_img *img)
{
	if (img->pl_count > 9)
		return ;
	set_plane(c, n, &img->pl[img->pl_count]);
	img->pl[img->pl_count].color = color;
	img->pl_count++;
}

void	push_cn(t_vec t, t_vec b, float ang, t_img *img)
{
	if (img->cn_count > 9)
		return ;
	set_cone(t, b, ang, &img->cn[img->cn_count]);
	img->cn_count++;
}

void	push_cy(t_vec t, t_vec b, float r, t_img *img)
{
	if (img->cy_count > 9)
		return ;
	set_cylinder(t, b, r, &img->cy[img->cy_count]);
	img->cy_count++;
}
