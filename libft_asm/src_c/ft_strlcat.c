/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:00:05 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/01 12:05:13 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		d;
	size_t		s;
	size_t		ret;

	d = 0;
	s = 0;
	ret = 0;
	while (src[ret] != '\0')
		ret++;
	while (dst[d] != '\0')
		d++;
	if (d >= dstsize)
		ret += dstsize;
	else
		ret += d;
	while (src[s] != '\0' && (d + 1) < dstsize)
	{
		dst[d] = src[s];
		d++;
		s++;
	}
	dst[d] = '\0';
	return (ret);
}
