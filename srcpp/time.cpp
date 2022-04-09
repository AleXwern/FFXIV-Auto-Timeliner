/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:13:15 by AleXwern          #+#    #+#             */
/*   Updated: 2022/04/09 16:44:58 by AleXwern         ###   ########.fr       */
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
	time->year = atoi(str);
	time->month = atoi(str + 5);
	time->day = atoi(str + 8);
	time->hour = atoi(str + 11);
	time->min = atoi(str + 14);
	time->sec = atoi(str + 17);
}

void	offset_time(t_toffset *time, t_toffset *offset)
{
	t_toffset	shift;

	shift = *offset;
	if (time->sec < shift.sec)
	{
		time->sec += 60;
		shift.min++;
	}
	time->sec -= shift.sec;
	if (time->min < shift.min)
	{
		time->min += 60;
		shift.hour++;
	}
	time->min -= shift.min;
	if (time->hour < shift.hour)
	{
		time->hour += 24;
		shift.day++;
	}
	time->hour -= shift.hour;
}
