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