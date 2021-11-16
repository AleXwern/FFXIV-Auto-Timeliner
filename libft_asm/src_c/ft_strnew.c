/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 16:10:00 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/01 14:16:15 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*array;

	if (!(array = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_bzero((void*)array, size + 1);
	return (array);
}
