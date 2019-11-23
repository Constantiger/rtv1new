/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 11:16:23 by aannara           #+#    #+#             */
/*   Updated: 2019/11/23 13:51:47 by aannara          ###   ########.fr       */
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
