/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:37:09 by AleXwern          #+#    #+#             */
/*   Updated: 2021/01/21 16:37:09 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_realloc(void *ptr, size_t newlen, size_t oldlen)
{
	char	*oldptr;
	char	*newptr;
	size_t	i;

	oldptr = (char*)ptr;
	if (!(newptr = (char*)ft_memalloc(newlen)))
		return (oldptr);
	if (!oldptr)
		return (newptr);
	i = 0;
	if (newlen < oldlen)
		oldlen = newlen;
	while (i < oldlen)
	{
		newptr[i] = oldptr[i];
		i++;
	}
	if (oldptr)
		free(oldptr);
	return (newptr);
}