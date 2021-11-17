/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:56:14 by AleXwern          #+#    #+#             */
/*   Updated: 2021/11/17 16:11:25 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timeliner.hpp"

int				main(int argc, char **argv)
{
	Timeliner	tl(argc, argv);
	tl.parse_config();
	tl.parse_file();
	return (0);
}
