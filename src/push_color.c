/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 11:53:38 by aannara           #+#    #+#             */
/*   Updated: 2019/11/27 12:06:00 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	push_cn_color(t_img *img, int color)
{
	img->cn[img->cn_count].color = color;
}

void	push_cy_color(t_img *img, int color)
{
	img->cy[img->cy_count].color = color;
}
