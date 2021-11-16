/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ditoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:43:13 by anystrom          #+#    #+#             */
/*   Updated: 2020/08/06 21:58:11 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

static int		ft_itoabuilder(char *num, long n, int i)
{
	int		min;

	min = 0;
	if (n < 0)
	{
		num[0] = '-';
		min++;
		n = -1 * n;
	}
	while (i >= min)
	{
		num[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (i);
}

char			*ft_ditoa(double n)
{
	char	*num;

	if (!(num = (char*)malloc(sizeof(char) * (ft_intsize(n) + 1))))
		return (NULL);
	if (n == INT_MIN)
	{
		ft_strcpy(num, "-2147483648");
		return (num);
	}
	ft_itoabuilder(num, (long)n, ft_intsize(n));
	num[ft_intsize(n) + 1] = '\0';
	return (&num[0]);
}
