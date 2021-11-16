/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lcm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <anystrom@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 14:29:04 by exam              #+#    #+#             */
/*   Updated: 2020/01/21 15:19:20 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	lcm;

	lcm = 2;
	if (a == 0 || b == 0)
		return (0);
	if (a == 1 || b == 1)
		return (1);
	while (lcm <= a && lcm <= b)
	{
		if (a % lcm == 0 && b % lcm == 0)
			return (lcm);
		lcm++;
	}
	return (1);
}
