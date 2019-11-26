/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 12:25:54 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/24 12:25:55 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include <stdio.h>

void	set_figure(t_img *img)
{
	img->sp_count = 0;
	img->pl_count = 0;
	img->cn_count = 0;
	img->cy_count = 0;
	img->lit_count = 0;
	img->obj_count = 0;
}

void	read_file_next(char *str, t_mlx *m, int i)
{
	while (str[i] != '\0')
	{
		if (sp(str, &i))
			sphere(str, m, i);
		if (cn(str, &i))
		{
			cone(str, m, i);
			push_cn(m->a, m->b, m->r, m->color, m->i);
		}
		if (cy(str, &i))
		{
			cylinder(str, m, i);
			push_cy(m->a, m->b, m->r, m->color, m->i);
		}
		if (pl(str, &i))
			plane(str, m, i);
		if (light(str, &i))
			li(str, m, i);
		i++;
	}
	free(str);
}

void	read_file(int fd, t_mlx *m)
{
	int		bytes;
	int		i;
	char	c;
	char	*str;

	i = 0;
	str = NULL;
	bytes = read(fd, &c, 1);
	if (bytes <= 0)
		print_err("Error read file");
	if (bytes == 1)
	{
		if (!(str = (char *)malloc(sizeof(char) * 1200)))
			return ;
		while (bytes != '\0')
		{
			str[i++] = c;
			bytes = read(fd, &c, 1);
		}
		str[i] = '\0';
	}
	i = 0;
	read_file_next(str, m, i);
}