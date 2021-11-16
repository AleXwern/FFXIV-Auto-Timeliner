/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:29:16 by anystrom          #+#    #+#             */
/*   Updated: 2021/04/23 16:58:11 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_wordlen(char const *str, char del)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0' && str[len] != del)
		len++;
	return (len--);
}
