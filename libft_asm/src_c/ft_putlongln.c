/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlongln.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 16:19:53 by AleXwern          #+#    #+#             */
/*   Updated: 2021/10/27 15:59:54 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putlongln(long n)
{
	unsigned char	arr[21];
	unsigned char	i;
	char			sign;

	if (n == -9223372036854775807 - 1)
	{
		ft_putstr_fd("-9223372036854775807", 1);
		return ;
	}
	arr[20] = 0xa;
	sign = 0;
	if (n < 0)
		sign = 1;
	i = 19;
	while (n)
	{
		arr[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	if (sign)
	{
		arr[i] = '-';
		i--;
	}
	write(1, arr + (i + 1), 21 - (i + 1));
}

void				ft_putulongln(unsigned long n)
{
	unsigned char	arr[21];
	unsigned char	i;

	arr[20] = 0xa;
	i = 19;
	while (n)
	{
		arr[i] = n % 10 + 48;
		n /= 10;
		i--;
	}
	write(1, arr + (i + 1), 21 - (i + 1));
}
