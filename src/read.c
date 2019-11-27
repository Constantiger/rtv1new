/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 12:25:54 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/27 11:57:48 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		camera(char *str, int *i)
{
	if (str[*i] == 'e' && str[++(*i)] == 'y' && str[++(*i)] == 'e' &&
	str[++(*i)] == '\n' && str[++(*i)] == '{' && str[++(*i)] == '\n')
		return (1);
	else
		return (0);
}

void	cam(char *str, t_mlx *m, int i)
{
	while (str[i] != '}')
	{
		if (str[i] == 'x' && str[++i] == '=')
			m->i->ori.e[0] = ft_atof(&str[++i]);
		if (str[i] == 'y' && str[++i] == '=')
			m->i->ori.e[1] = ft_atof(&str[++i]);
		if (str[i] == 'z' && str[++i] == '=')
			m->i->ori.e[2] = ft_atof(&str[++i]);
		if (str[i] == 'X' && str[++i] == '=')
			m->i->cam_a.e[0] = ft_atof(&str[++i]);
		if (str[i] == 'Y' && str[++i] == '=')
			m->i->cam_a.e[1] = ft_atof(&str[++i]);
		if (str[i] == 'Z' && str[++i] == '=')
			m->i->cam_a.e[2] = ft_atof(&str[++i]);
		i++;
	}
}

void	set_figure(t_mlx *m)
{
	m->i->sp_count = 0;
	m->i->pl_count = 0;
	m->i->cn_count = 0;
	m->i->cy_count = 0;
	m->i->lit_count = 0;
	m->i->obj_count = 0;
	m->i->help = 0;
	m->red = 255;
	m->green = 255;
	m->blue = 255;
	m->i->ori = setv(0.0, 0.0, 2.0);
	m->i->cam_a = setv(0.0, 0.0, 0.0);
	m->color = c(255, 255, 255);
	m->size = 1500;
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
			push_cn_color(m->i, m->color);
			push_cn(m->a, m->b, m->r, m->i);
		}
		if (cy(str, &i))
		{
			cylinder(str, m, i);
			push_cy_color(m->i, m->color);
			push_cy(m->a, m->b, m->r, m->i);
		}
		if (pl(str, &i))
			plane(str, m, i);
		if (light(str, &i))
			li(str, m, i);
		if (camera(str, &i))
			cam(str, m, i);
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
		if (!(str = (char *)malloc(sizeof(char) * m->size)))
			print_err("Malloc error");
		while (bytes != '\0')
		{
			if (i >= m->size)
				print_err("Out of memory");
			str[i++] = c;
			bytes = read(fd, &c, 1);
		}
		str[i] = '\0';
	}
	i = 0;
	read_file_next(str, m, i);
}
