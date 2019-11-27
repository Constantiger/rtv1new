/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:44:30 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 16:52:18 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "keys.h"

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
	else if (key == 34 || key == 40 || key == 38 || key == 37 || key == 11)
		key_i_k_j_l(key, m);
	else if (key == 6 || key == 7 || key == 8 || key == 9)
		key_z_x_c_v(key, m);
	else if (key == 91 || key == 87 || key == 4)
		num_plus(key, m);
	else if (key == 86 || key == 88)
		num_left_right(key, m);
	else if (key == 89 || key == 92)
		num_up_down(key, m);
	else if (key == 13 || key == 1 || key == 0 || key == 2)
		rotate_cam(key, m);
	m->i->redraw = 1;
	draw(m, m->i, 0, 0);
	return (0);
}

int		expose(void *param)
{
	t_mlx	*m;

	m = (t_mlx*)param;
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
