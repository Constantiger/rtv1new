/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:44:30 by aannara           #+#    #+#             */
/*   Updated: 2019/11/24 17:07:45 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	key_left_right(int key, t_mlx *m)
{
	if (key == 123)
	{
		m->i->lit[0].e[0] += 1.0;
	}
	else if (key == 124)
	{
		m->i->lit[0].e[0] -= 1.0;
	}
}

void	key_up_down(int key, t_mlx *m)
{
	if (key == 126)
	{
		set_cone(m->i->cn.center, m->i->cn.b, m->i->cn.ang, &m->i->cn);
		m->i->lit[0].e[2] += 1.0;
	}
	else if (key == 125)
	{
		set_cone(m->i->cn.center, m->i->cn.b, m->i->cn.ang, &m->i->cn);
		m->i->lit[0].e[2] -= 1.0;
	}
}

void	key_i_k(int key, t_mlx *m)
{
	if (key == 34)
	{
		m->i->lit[0].e[2] += 1.0;
	}
	else if (key == 40)
	{
		m->i->lit[0].e[2] -= 1.0;
	}
}

void	key_j_l(int key, t_mlx *m)
{
	if (key == 38)
	{
		m->i->lit[0].e[0] += 1.0;
	}
	else if (key == 37)
	{
		m->i->lit[0].e[0] -= 1.0;
	}
}

void	num_plus(int key, t_mlx *m)
{
	if (key == 91)
	{
		m->i->ori.e[2] -= 0.5;
	}
	else if (key == 87)
	{
		m->i->ori.e[2] += 0.5;
	}
}

void	num_up_down(int key, t_mlx *m)
{
	if (key == 89)
	{
		m->i->ori.e[1] -= 0.5;
	}
	else if (key == 92)
	{
		m->i->ori.e[1] += 0.5;
	}
}

void	num_left_right(int key, t_mlx *m)
{
	if (key == 86)
	{
		m->i->ori.e[0] -= 0.5;
	}
	else if (key == 88)
	{
		m->i->ori.e[0] += 0.5;
	}
}

int		key_press(int key, void *param)
{
	t_mlx	*m;

	m = (t_mlx*)param;
	if (key == 53)
		close_win(param);
	else if (key == 123 || key == 124)
		key_left_right(key, m);
	else if (key == 126 || key == 125)
		key_up_down(key, m);
	else if (key == 34 || key == 40)
		key_i_k(key, m);
	else if (key == 38 || key == 37)
		key_j_l(key, m);
	else if (key == 91 || key == 87)
		num_plus(key, m);
	else if (key == 86 || key == 88)
		num_left_right(key, m);
	else if (key == 89 || key == 92)
		num_up_down(key, m);
	else if (key == 17 || key == 5 || key == 3 || key == 4)
		rotate_cam(key, m);
	draw(m, m->i, 0, 0);
	return (0);
}

int		close_win(void *param)
{
	t_mlx	*m;

	m = (t_mlx*)param;
	mlx_destroy_window(m->mlx, m->window);
	exit(0);
}
