/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:22:30 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 14:55:02 by aannara          ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	t_mlx	m;
	t_img	img;
	int		fd;

	if (argc != 2)
		print_err("./RTv1 <scene>");
	m.mlx = mlx_init();
	m.window = mlx_new_window(m.mlx, WIN_L, WIN_H, "Ray Traycer");
	new_image(&m, &img, WIN_L, WIN_H);
	m.i = &img;
	if (argc == 2)
	{
		set_figure(&m);
		fd = open(argv[1], O_RDONLY);
		read_file(fd, &m);
	}
	set_camera(&img);
	img.redraw = 1;
	draw(&m, &img, 0, 0);
	mlx_expose_hook(m.window, &expose, (void*)(&m));
	mlx_hook(m.window, 2, 0, &key_press, (void*)(&m));
	mlx_hook(m.window, 17, 0, &close_win, (void*)(&m));
	mlx_loop(m.mlx);
	return (0);
}
