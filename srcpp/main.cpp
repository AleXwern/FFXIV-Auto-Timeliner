/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:56:14 by AleXwern          #+#    #+#             */
/*   Updated: 2022/04/09 23:35:16 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timeliner.hpp"
#include <stdio.h>

int				main(int argc, char **argv)
{
	Timeliner	tl(argc, argv);
	tl.parse_config();
	tl.parse_file();
	return (0);
}
