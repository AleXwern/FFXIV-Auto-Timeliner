/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 12:52:03 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/02 11:08:45 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*array;
	size_t	i;

	if (!(array = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		array[i] = (char)s[start];
		i++;
		start++;
	}
	while (i < len)
	{
		array[i] = '\0';
		i++;
	}
	array[i] = '\0';
	return (array);
}
