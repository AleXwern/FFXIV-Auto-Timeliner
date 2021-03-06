/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitfree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 16:25:48 by AleXwern          #+#    #+#             */
/*   Updated: 2021/01/21 16:25:48 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_splitfree(char **c)
{
	int	i;

	i = 0;
	if (c == NULL)
		return ;
	while (c[i] != NULL)
	{
		free(c[i]);
		i++;
	}
	free(c);
}
