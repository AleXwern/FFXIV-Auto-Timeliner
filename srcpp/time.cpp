/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:13:15 by AleXwern          #+#    #+#             */
/*   Updated: 2021/11/17 17:00:33 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timeliner.hpp"

/*
**	Time is *always* fixed length in the data.
**	We receive already splot string so the format is as follows:
**	YY	0-3
**	MM	5-6
**	DD	8-9
**	HH	11-12
**	MM	14-15
**	SS	17-18
*/
void	parse_time(char *str, t_toffset *time)
{
	time->year = ft_atoi(str);
	time->month = ft_atoi(str + 5);
	time->day = ft_atoi(str + 8);
	time->hour = ft_atoi(str + 11);
	time->min = ft_atoi(str + 14);
	time->sec = ft_atoi(str + 17);
}

void	offset_time(t_toffset *time, t_toffset *offset)
{
	
}
