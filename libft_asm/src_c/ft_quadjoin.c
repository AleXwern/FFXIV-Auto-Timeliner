/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quadjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 16:03:33 by anystrom          #+#    #+#             */
/*   Updated: 2021/05/07 12:47:11 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void inline quadhelper(char *arr, int a, char *s3, char *s4)
{
	int		i;

	i = 0;
	while (s3[i] != '\0')
	{
		arr[a] = (char)s3[i];
		a++;
		i++;
	}
	i = 0;
	while (s4[i] != '\0')
	{
		arr[a] = (char)s4[i];
		a++;
		i++;
	}
	arr[a] = '\0';
}

char		*ft_quadjoin(char *s1, char *s2, char *s3, char *s4)
{
	char	*array;
	int		i;
	int		a;

	a = 0;
	if (!(array = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)
			+ ft_strlen(s3) + ft_strlen(s4) + 1))))
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
	quadhelper(array, a, s3, s4);
	return (array);
}
