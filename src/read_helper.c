/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiego <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:06:47 by sdiego            #+#    #+#             */
/*   Updated: 2019/11/25 13:06:49 by sdiego           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_mlx	init_atof(t_mlx *m)
{
	m->integer = 0;
	m->fraction = 0;
	m->infraction = 0;
	return (*m);
}

int		ft_atoi(const char *str)
{
	int	i;
	int	nbr;
	int	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\r' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == ' ' || str[i] == '\n')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		nbr = (nbr * 10) + (str[i++] - '0');
	return (nbr * sign);
}

double	ft_atof_n(char *num, int sign, t_mlx m, int divisorforfraction)
{
	while (*num != '\n')
	{
		if (*num >= '0' && *num <= '9')
		{
			if (m.infraction)
			{
				m.fraction = m.fraction * 10 + (*num - '0');
				divisorforfraction *= 10;
			}
			else
				m.integer = m.integer * 10 + (*num - '0');
		}
		else if (*num == '.')
		{
			if (m.infraction)
				return (sign * (m.integer + m.fraction / divisorforfraction));
			else
				m.infraction = 1;
		}
		else
			return (sign * (m.integer + m.fraction / divisorforfraction));
		++num;
	}
	return (sign * (m.integer + m.fraction / divisorforfraction));
}

double	ft_atof(char *num)
{
	int		divisorforfraction;
	int		sign;
	t_mlx	m;

	divisorforfraction = 1;
	sign = 1;
	m = init_atof(&m);
	if (!num || !*num)
		return (0);
	if (*num == '-')
	{
		++num;
		sign = -1;
	}
	else if (*num == '+')
		++num;
	return (ft_atof_n(num, sign, m, divisorforfraction));
}
