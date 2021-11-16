/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:18:46 by anystrom          #+#    #+#             */
/*   Updated: 2019/10/30 16:55:05 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = (char *)str;
	while (str2[i] != '\0')
	{
		if (str2[i] == (char)c)
			return (&str2[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&str2[i]);
	return (NULL);
}
