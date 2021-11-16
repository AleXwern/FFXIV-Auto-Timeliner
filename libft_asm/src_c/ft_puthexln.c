/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexln.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 14:10:45 by anystrom          #+#    #+#             */
/*   Updated: 2021/05/06 14:14:12 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_puthexln(unsigned long num)
{
	char	c[21];
	char	*hex;
	size_t	index;

	index = 19;
	hex = "0123456789abcdef";
	while (num > 15)
	{
		c[index] = hex[num % 16];
		num >>= 4;
		index--;
	}
	c[index] = hex[num % 16];
	num >>= 4;
	c[20] = '\n';
	write(1, c + index, 21 - index);
}
