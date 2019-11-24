/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:05:53 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/24 11:47:49 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	rotate_cam(int key, t_mlx *m)
{
	if (key == 17)
	{
		m->i->cam_a.e[0] += 10;
	}
	else if (key == 5)
	{
		m->i->cam_a.e[0] -= 10;
	}
	else if (key == 3)
	{
		m->i->cam_a.e[1] += 10;
	}
	else if (key == 4)
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
	*xp = tempx * cos(degree * PI_R) - tempy * sin(degree * PI_R);
	*yp = tempx * sin(degree * PI_R) + tempy * cos(degree * PI_R);
}

void	rotate_x(float degree, float *xp, float *yp, float *zp)
{
	float	tempy;
	float	tempz;

	tempy = *yp;
	tempz = *zp;
	*yp = tempy * cos(degree * PI_R) - tempz * sin(degree * PI_R);
	*zp = tempy * sin(degree * PI_R) + tempz * cos(degree * PI_R);
}

void	rotate_y(float degree, float *xp, float *yp, float *zp)
{
	float	tempx;
	float	tempz;

	tempx = *xp;
	tempz = *zp;
	*zp = tempz * cos(degree * PI_R) - tempx * sin(degree * PI_R);
	*xp = tempz * sin(degree * PI_R) + tempx * cos(degree * PI_R);
}

void	rotate_v(t_ray *ray, t_img *angles)
{
	rotate_x(angles->cam_a.e[0], &ray->B.e[0], &ray->B.e[1], &ray->B.e[2]);
	rotate_y(angles->cam_a.e[1], &ray->B.e[0], &ray->B.e[1], &ray->B.e[2]);
	rotate_z(angles->cam_a.e[2], &ray->B.e[0], &ray->B.e[1], &ray->B.e[2]);
}
