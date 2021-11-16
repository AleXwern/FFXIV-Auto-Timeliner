/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 13:08:34 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/02 15:20:12 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	e;

	if (!s)
		return ((char *)s);
	i = 0;
	e = ft_strlen(s);
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i])
		i++;
	while ((s[e - 1] == ' ' || s[e - 1] == '\n' || s[e - 1] == '\t') && i < e)
		e--;
	if (i == e)
		return (ft_strnew(1));
	return (ft_strsub(s, i, (e - i)));
}
