/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 15:16:32 by anystrom          #+#    #+#             */
/*   Updated: 2021/04/18 15:16:32 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	atof_fractal(const char *str, double num)
{
	//t_uint64	frac;
	double		frac;

	frac = 0.1;
	str++;
	while (*str && *str <= '9' && *str >= '0')
	{
		num = num + ((*str - '0') * frac);
		str++;
		frac *= 0.1;
	}
	return (num);// / frac);
}

double	ft_atof(const char *str)
{
	double	num;
	int		neg;

	num = 0;
	neg = 1;
	if (!str)
		return (0.0);
	while (ft_isblank(*str))
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str && *str <= '9' && *str >= '0' && *str != '.')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	if (*str == '.')
		num = atof_fractal(str, num);
	return (num * neg);
}
