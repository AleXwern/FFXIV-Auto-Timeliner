/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 13:57:56 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/01 15:06:51 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ret;
	unsigned char	*mov;

	if (dst == NULL || src == NULL)
		return (NULL);
	ret = (unsigned char *)dst;
	mov = (unsigned char *)src;
	if (ret > mov)
	{
		while (len > 0)
		{
			ret[len - 1] = mov[len - 1];
			len--;
		}
	}
	else
		ft_memcpy(ret, mov, len);
	return ((void *)ret);
}
