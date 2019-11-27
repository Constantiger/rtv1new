/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:38:59 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/25 17:39:00 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	plane(char *str, t_mlx *m, int i)
{
	while (str[i] != '}')
	{
		if (str[i] == 'x' && str[++i] == '=')
			m->a.e[0] = ft_atof(&str[++i]);
		else if (str[i] == 'y' && str[++i] == '=')
			m->a.e[1] = ft_atof(&str[++i]);
		else if (str[i] == 'z' && str[++i] == '=')
			m->a.e[2] = ft_atof(&str[++i]);
		else if (str[i] == 'X' && str[++i] == '=')
			m->b.e[0] = ft_atof(&str[++i]);
		else if (str[i] == 'Y' && str[++i] == '=')
			m->b.e[1] = ft_atof(&str[++i]);
		else if (str[i] == 'Z' && str[++i] == '=')
			m->b.e[2] = ft_atof(&str[++i]);
		else if (str[i] == 'r' && str[++i] == 'e' && str[++i] == '=')
			m->red = ft_atoi(&str[++i]);
		else if (str[i] == 'g' && str[++i] == 'r' && str[++i] == '=')
			m->green = ft_atoi(&str[++i]);
		else if (str[i] == 'b' && str[++i] == 'l' && str[++i] == '=')
			m->blue = ft_atoi(&str[++i]);
		i++;
	}
	m->color = c(m->red, m->green, m->blue);
	push_pl(m->a, m->b, m->color, m->i);
}

void	cylinder(char *str, t_mlx *m, int i)
{
	while (str[i] != '}')
	{
		if (str[i] == 'x' && str[++i] == '=')
			m->a.e[0] = ft_atof(&str[++i]);
		else if (str[i] == 'y' && str[++i] == '=')
			m->a.e[1] = ft_atof(&str[++i]);
		else if (str[i] == 'z' && str[++i] == '=')
			m->a.e[2] = ft_atof(&str[++i]);
		else if (str[i] == 'X' && str[++i] == '=')
			m->b.e[0] = ft_atof(&str[++i]);
		else if (str[i] == 'Y' && str[++i] == '=')
			m->b.e[1] = ft_atof(&str[++i]);
		else if (str[i] == 'Z' && str[++i] == '=')
			m->b.e[2] = ft_atof(&str[++i]);
		else if (str[i] == 'd' && str[++i] == '=')
			m->r = ft_atof(&str[++i]);
		else if (str[i] == 'r' && str[++i] == 'e' && str[++i] == '=')
			m->red = ft_atoi(&str[++i]);
		else if (str[i] == 'g' && str[++i] == 'r' && str[++i] == '=')
			m->green = ft_atoi(&str[++i]);
		else if (str[i] == 'b' && str[++i] == 'l' && str[++i] == '=')
			m->blue = ft_atoi(&str[++i]);
		i++;
	}
	m->color = c(m->red, m->green, m->blue);
}

void	cone(char *str, t_mlx *m, int i)
{
	while (str[i] != '}')
	{
		if (str[i] == 'x' && str[++i] == '=')
			m->a.e[0] = ft_atof(&str[++i]);
		else if (str[i] == 'y' && str[++i] == '=')
			m->a.e[1] = ft_atof(&str[++i]);
		else if (str[i] == 'z' && str[++i] == '=')
			m->a.e[2] = ft_atof(&str[++i]);
		else if (str[i] == 'X' && str[++i] == '=')
			m->b.e[0] = ft_atof(&str[++i]);
		else if (str[i] == 'Y' && str[++i] == '=')
			m->b.e[1] = ft_atof(&str[++i]);
		else if (str[i] == 'Z' && str[++i] == '=')
			m->b.e[2] = ft_atof(&str[++i]);
		else if (str[i] == 'd' && str[++i] == '=')
			m->r = ft_atof(&str[++i]);
		else if (str[i] == 'r' && str[++i] == 'e' && str[++i] == '=')
			m->red = ft_atoi(&str[++i]);
		else if (str[i] == 'g' && str[++i] == 'r' && str[++i] == '=')
			m->green = ft_atoi(&str[++i]);
		else if (str[i] == 'b' && str[++i] == 'l' && str[++i] == '=')
			m->blue = ft_atoi(&str[++i]);
		i++;
	}
	m->color = c(m->red, m->green, m->blue);
}

void	sphere(char *str, t_mlx *m, int i)
{
	if (str[++i] == '{' && str[++i] == '\n')
	{
		while (str[i] != '}')
		{
			if (str[i] == 'x' && str[++i] == '=')
				m->p.e[0] = ft_atof(&str[++i]);
			else if (str[i] == 'y' && str[++i] == '=')
				m->p.e[1] = ft_atof(&str[++i]);
			else if (str[i] == 'z' && str[++i] == '=')
				m->p.e[2] = ft_atof(&str[++i]);
			else if (str[i] == 'd' && str[++i] == '=')
				m->r = ft_atof(&str[++i]);
			else if (str[i] == 'r' && str[++i] == 'e' && str[++i] == '=')
				m->red = ft_atoi(&str[++i]);
			else if (str[i] == 'g' && str[++i] == 'r' && str[++i] == '=')
				m->green = ft_atoi(&str[++i]);
			else if (str[i] == 'b' && str[++i] == 'l' && str[++i] == '=')
				m->blue = ft_atoi(&str[++i]);
			i++;
		}
		m->color = c(m->red, m->green, m->blue);
		push_sphere(m->p, m->r, m->color, m->i);
	}
}

void	li(char *str, t_mlx *m, int i)
{
	while (str[i] != '}')
	{
		if (str[i] == 'x' && str[++i] == '=')
			m->i->lit[m->i->lit_count].e[0] = ft_atof(&str[++i]);
		else if (str[i] == 'y' && str[++i] == '=')
			m->i->lit[m->i->lit_count].e[1] = ft_atof(&str[++i]);
		else if (str[i] == 'z' && str[++i] == '=')
			m->i->lit[m->i->lit_count].e[2] = ft_atof(&str[++i]);
		i++;
	}
	push_lit(m->i->lit[m->i->lit_count], m->i);
}
