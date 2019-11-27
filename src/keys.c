/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:24:47 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 16:48:49 by aannara          ###   ########.fr       */
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
		m->i->lit[0].e[2] += 1.0;
	}
	else if (key == 125)
	{
		m->i->lit[0].e[2] -= 1.0;
	}
}

void	key_i_k_j_l(int key, t_mlx *m)
{
	if (key == 34)
		m->i->lit[0].e[1] += 1.0;
	else if (key == 40)
		m->i->lit[0].e[1] -= 1.0;
	else if (key == 38)
	{
		m->i->powl -= 0.1;
		if (m->i->powl < 0.0)
			m->i->powl = 0.0;
	}
	else if (key == 37)
	{
		m->i->powl += 0.1;
		if (m->i->powl > 1.0)
			m->i->powl = 1.0;
	}
	else if (key == 11)
	{
		m->i->pows++;
		m->i->pows %= 12;
	}
}

void	key_z_x_c_v(int key, t_mlx *m)
{
	if (key == 6)
	{
		m->i->shade_on = !m->i->shade_on;
		if (!m->i->shade_on)
			m->i->amb = 1.0;
		else
			m->i->amb = 0.09;
	}
	else if (key == 7)
	{
		m->i->shadow_on = !m->i->shadow_on;
	}
	else if (key == 8)
	{
		m->i->specul_on = !m->i->specul_on;
	}
	else if (key == 9)
	{
		m->i->mult_lit_on = !m->i->mult_lit_on;
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
	else if (key == 4)
	{
		m->i->help = !m->i->help;
	}
}
