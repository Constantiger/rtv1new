/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:37:22 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/27 11:48:35 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	menu1(t_mlx *m)
{
	void	*mlx;
	void	*wind;

	mlx = m->mlx;
	wind = m->window;
	mlx_string_put(mlx, wind, WIN_L - 195, WIN_H - 25,
			WHITE, "Rotate cam : WASD");
	mlx_string_put(mlx, wind, WIN_L - 195, WIN_H - 45,
			WHITE, "Move cam : NUM 4-9");
	mlx_string_put(mlx, wind, WIN_L - 195, WIN_H - 65,
			WHITE, "Shadow : X");
	mlx_string_put(mlx, wind, WIN_L - 195, WIN_H - 85,
			WHITE, "Spec : C");
	mlx_string_put(mlx, wind, WIN_L - 195, WIN_H - 105,
			WHITE, "Shading : Z");
	mlx_string_put(mlx, wind, WIN_L - 195, WIN_H - 125,
			WHITE, "Multi light : V");
}

void	menu(t_mlx *m)
{
	void	*mlx;
	void	*wind;

	mlx = m->mlx;
	wind = m->window;
	if (m->i->help == 1)
		menu1(m);
	if (m->i->help == 0)
	{
		mlx_string_put(mlx, wind, WIN_L - 135, WIN_H - 25,
				WHITE, "H - Help menu");
	}
}
