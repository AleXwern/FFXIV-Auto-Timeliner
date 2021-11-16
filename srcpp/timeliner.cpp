/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeliner.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:14:33 by AleXwern          #+#    #+#             */
/*   Updated: 2021/11/16 16:04:29 by AleXwern         ###   ########.fr       */
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
	time = {0, 0, 0, 0};
	parse_config();
}

void		Timeliner::sort_output(char *line)
{
	char	**split;
	char	*out;

	split = ft_strsplit(line, '|');
	if (ft_listlen(split) < 40)
	{
		ft_splitfree(split);
		return ;
	}
	if (check_blacklist(split[3]))
	{
		ft_splitfree(split);
		return ;
	}
	ft_putstr_fd(split[3], outfile);
	ft_putstr_fd(" - Attack: ", outfile);
	ft_putstr_fd(split[5], outfile);
	ft_putstr_fd(" - MAX HP: ", outfile);
	ft_putendl_fd(split[35], outfile);
	ft_splitfree(split);
}

//	I'll hate my life soon with this
//	Effectice string comparisons are not my field
int			Timeliner::check_blacklist(char *line)
{
	for (size_t i = 0; i < blcount; i++)
	{
		if (!ft_strcmp(line, blacklist[i]))
			return (1);
	}
	return (0);
}

void		Timeliner::parse_file(void)
{
	char	*line;

	while (get_next_line(infile, &line) == 1)
	{
		if (((short*)line)[0] == ATK_OPCODE)
			sort_output(line);
		free(line);
	}
}
