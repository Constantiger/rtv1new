/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 11:16:23 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 14:29:58 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"

unsigned int	c(unsigned char r, unsigned char g, unsigned char b)
{
	unsigned int	color;

	color = 0;
	color = color | ((unsigned int)r << 16);
	color = color | ((unsigned int)g << 8);
	color = color | (unsigned int)b;
	return (color);
}

unsigned char	get_rgb(unsigned int color, int rgb)
{
	if (rgb == 1)
		return (color >> 16);
	if (rgb == 2)
	{
		color = color & 65280;
		color = color >> 8;
		return ((unsigned char)color);
	}
	if (rgb == 3)
	{
		color = color & 255;
		return ((unsigned char)color);
	}
	return (0);
}

unsigned int	grad(unsigned int color1, unsigned int color2, float intence)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned int	color;

	r = get_rgb(color1, 1);
	r = (get_rgb(color2, 1) - r) * intence + r;
	g = get_rgb(color1, 2);
	g = (get_rgb(color2, 2) - g) * intence + g;
	b = get_rgb(color1, 3);
	b = (get_rgb(color2, 3) - b) * intence + b;
	color = c(r, g, b);
	return (color);
}

int				cl(int c1, int c2)
{
	int	r;
	int	g;
	int	b;

	r = get_rgb(c1, 1) + get_rgb(c2, 1);
	if (r > 255)
		r = 255;
	g = get_rgb(c1, 2) + get_rgb(c2, 2);
	if (g > 255)
		g = 255;
	b = get_rgb(c1, 3) + get_rgb(c2, 3);
	if (b > 255)
		b = 255;
	return (c(r, g, b));
}
