/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeliner.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:14:33 by AleXwern          #+#    #+#             */
/*   Updated: 2022/04/09 23:09:36 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timeliner.hpp"
#include <iostream>

void		Timeliner::error_out(const char *str)
{
	ft_putendl(str);
	exit(-1);
}

Timeliner::Timeliner(int ac, char **av)
{
	infile = open("logs/Network.log", O_RDONLY);
	outfile = open("logs/Timeline.txt", O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (infile & outfile < 0)
		error_out("Couldn't open file(s)!");
	blcount ^= blcount;
	blacklist = NULL;
	minhp = 0;
	time.bits = 0;
	start.bits = 0;
	end.bits = UINT64_MAX;
	//time.offset.hour = 20;
	//time.offset.min = 8;
}
