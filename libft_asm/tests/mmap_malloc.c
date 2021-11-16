/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mmap_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexwern <alexwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 18:26:24 by alexwern          #+#    #+#             */
/*   Updated: 2021/04/16 18:35:08 by alexwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_asm.h"

#define PAGE 4096

int		main(void)
{
	void	*null;
	for (int i = 0; i < 5000; i++)
	{
		null = ft_test(PAGE);
		if (null)
			ft_test2(null, PAGE);
		/*null = malloc(PAGE);
		if (null)
			free(null);*/
	}
}