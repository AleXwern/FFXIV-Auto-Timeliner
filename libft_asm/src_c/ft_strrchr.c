/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:37:06 by anystrom          #+#    #+#             */
/*   Updated: 2019/10/30 16:57:45 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = (char *)str;
	while (str2[i] != '\0')
		i++;
	while (i >= 0)
	{
		if ((char)c == str2[i])
			return (&str2[i]);
		i--;
	}
	return (NULL);
}
