/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:45:30 by anystrom          #+#    #+#             */
/*   Updated: 2021/01/26 14:31:36 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strfjoin(char *s1, char *s2)
{
	char	*array;
	int		i;
	int		a;

	a = 0;
	if (!(array = (char*)malloc(sizeof(char) *
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		array[a] = (char)s1[i];
		a++;
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		array[a] = (char)s2[i];
		a++;
		i++;
	}
	array[a] = '\0';
	free(s1);
	return (array);
}
