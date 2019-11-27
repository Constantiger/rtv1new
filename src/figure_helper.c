/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:38:05 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/27 11:48:10 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		sp(char *str, int *i)
{
	if (str[*i] == 's' && str[++(*i)] == 'p' && str[++(*i)] == '\n')
		return (1);
	else
		return (0);
}

int		cn(char *str, int *i)
{
	if (str[*i] == 'c' && str[++(*i)] == 'n' && str[++(*i)] == '\n' &&
	str[++(*i)] == '{' && str[++(*i)] == '\n')
		return (1);
	else
		return (0);
}

int		cy(char *str, int *i)
{
	if (str[*i] == 'C' && str[++(*i)] == 'y' && str[++(*i)] == '\n' &&
	str[++(*i)] == '{' && str[++(*i)] == '\n')
		return (1);
	else
		return (0);
}

int		pl(char *str, int *i)
{
	if (str[*i] == 'p' && str[++(*i)] == 'l' && str[++(*i)] == '\n' &&
	str[++(*i)] == '{' && str[++(*i)] == '\n')
		return (1);
	else
		return (0);
}

int		light(char *str, int *i)
{
	if (str[*i] == 'l' && str[++(*i)] == 'i' && str[++(*i)] == '\n' &&
	str[++(*i)] == '{' && str[++(*i)] == '\n')
		return (1);
	else
		return (0);
}
