/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:42:30 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/01 14:23:37 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*array;
	int		i;
	int		a;

	a = 0;
	if (!(array = (char *)malloc(sizeof(char) *
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
	return (array);
}
