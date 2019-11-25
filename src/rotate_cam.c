/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:05:53 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/25 16:50:15 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	rotate_cam(int key, t_mlx *m)
{
	if (key == 13)
	{
		m->i->cam_a.e[0] += 10;
	}
	else if (key == 1)
	{
		m->i->cam_a.e[0] -= 10;
	}
	else if (key == 0)
	{
		m->i->cam_a.e[1] += 10;
	}
	else if (key == 2)
	{
		m->i->cam_a.e[1] -= 10;
	}
}

void	rotate_z(float degree, float *xp, float *yp, float *zp)
{
	float	tempx;
	float	tempy;

	tempx = *xp;
	tempy = *yp;
	*zp = *zp;
	*xp = tempx * cos(degree * PI_R) - tempy * sin(degree * PI_R);
	*yp = tempx * sin(degree * PI_R) + tempy * cos(degree * PI_R);
}

void	rotate_x(float degree, float *xp, float *yp, float *zp)
{
	float	tempy;
	float	tempz;

	tempy = *yp;
	tempz = *zp;
	*xp = *xp;
	*yp = tempy * cos(degree * PI_R) - tempz * sin(degree * PI_R);
	*zp = tempy * sin(degree * PI_R) + tempz * cos(degree * PI_R);
}

void	rotate_y(float degree, float *xp, float *yp, float *zp)
{
	float	tempx;
	float	tempz;

	tempx = *xp;
	tempz = *zp;
	*yp = *yp;
	*zp = tempz * cos(degree * PI_R) - tempx * sin(degree * PI_R);
	*xp = tempz * sin(degree * PI_R) + tempx * cos(degree * PI_R);
}

void	rotate_v(t_ray *ray, t_img *angles)
{
	rotate_x(angles->cam_a.e[0], &ray->b.e[0], &ray->b.e[1], &ray->b.e[2]);
	rotate_y(angles->cam_a.e[1], &ray->b.e[0], &ray->b.e[1], &ray->b.e[2]);
	rotate_z(angles->cam_a.e[2], &ray->b.e[0], &ray->b.e[1], &ray->b.e[2]);
}
