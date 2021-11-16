/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:44:52 by exam              #+#    #+#             */
/*   Updated: 2021/05/06 14:31:29 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_puthex(unsigned long num)
{
	char	c[20];
	char	*hex;
	size_t	index;

	index = 19;
	hex = "0123456789abcdef";
	while (num > 15)
	{
		c[index] = hex[num & 0xf];
		num >>= 4;
		index--;
	}
	c[index] = hex[num & 0xf];
	num >>= 4;
	write(1, c + index, 20 - index);
}
