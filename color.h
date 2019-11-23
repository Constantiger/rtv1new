/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 11:25:47 by aannara           #+#    #+#             */
/*   Updated: 2019/10/31 13:23:39 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "math.h"

unsigned int	c(unsigned char r, unsigned char g, unsigned char b);
unsigned char	get_rgb(unsigned int color, int rgb);
unsigned int	grad(unsigned int color1, unsigned int color2, float intence);
unsigned int	hsv_to_rgb(unsigned int h);

#endif
