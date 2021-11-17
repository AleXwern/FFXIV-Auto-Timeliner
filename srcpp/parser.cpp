/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:48:33 by AleXwern          #+#    #+#             */
/*   Updated: 2021/11/17 17:01:45 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timeliner.hpp"

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

void		Timeliner::print_time(t_toffset *time)
{
	char	out[11];

	ft_memcpy(out, "00:00:00 - ", 11);
	out[0] = (time->hour / 10) + '0';
	out[1] = (time->hour % 10) + '0';
	out[3] = (time->min / 10) + '0';
	out[4] = (time->min % 10) + '0';
	out[6] = (time->sec / 10) + '0';
	out[7] = (time->sec % 10) + '0';
	write(outfile, out, 11);
}

void		Timeliner::sort_output(char *line)
{
	char	**split;
	char	*out;
	t_toffset	time;

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
	parse_time(split[1], &time);
	print_time(&time);
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
