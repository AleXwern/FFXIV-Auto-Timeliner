/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:48:33 by AleXwern          #+#    #+#             */
/*   Updated: 2022/04/09 23:42:34 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timeliner.hpp"
#include <stdio.h>

void			Timeliner::parse_file(void)
{
	char	*line;

	while (get_next_line(infile, &line) == 1)
	{
		if (((short*)line)[0] == OPCODE_ATK || ((short*)line)[0] == OPCODE_AOE)
			sort_output(line);
		free(line);
	}
}

void			Timeliner::print_time(t_toffset *time)
{
	char		out[11];

	ft_memcpy(out, "00:00:00 - ", 11);
	out[0] = (time->hour / 10) + '0';
	out[1] = (time->hour % 10) + '0';
	out[3] = (time->min / 10) + '0';
	out[4] = (time->min % 10) + '0';
	out[6] = (time->sec / 10) + '0';
	out[7] = (time->sec % 10) + '0';
	write(outfile, out, 11);
}

void			Timeliner::sort_output(char *line)
{
	char		**split;
	char		*out;
	u_offset	lineTime;

	split = ft_strsplit(line, '|');
	//printf("Network data of %lu\n", ft_listlen(split));
	if (ft_listlen(split) < 40)
	{
		ft_splitfree(split);
		return ;
	}
	if (check_blacklist(split[PART_NAME]))
	{
		ft_splitfree(split);
		return ;
	}
	parse_time(split[PART_DATETIME], &lineTime.offset);
	//printf("%lu < %lu < %lu\n", start.bits, lineTime.bits, end.bits);
	/*if (lineTime.bits < start.bits)// || lineTime.bits > end.bits)
	{
		ft_splitfree(split);
		return;
	}*/
	if (time.bits)
		offset_time(&lineTime.offset, &time.offset);
	print_time(&lineTime.offset);
	ft_putstr_fd(split[PART_NAME], outfile);
	ft_putstr_fd(" - Attack: ", outfile);
	ft_putstr_fd(split[PART_ATTACKNAME], outfile);
	ft_putstr_fd(" - Target: ", outfile);
	ft_putstr_fd(split[PART_TARGETNAME], outfile);
	ft_putstr_fd(" - Damage: ", outfile);
	ft_putnbr_fd(get_damage(split[PART_DAMAGE]), outfile);
	ft_putchar_fd('\n', outfile);
	ft_splitfree(split);
}

//	I'll hate my life soon with this
//	Effectice string comparisons are not my field
int				Timeliner::check_blacklist(char *line)
{
	for (size_t i = 0; i < blcount; i++)
	{
		if (!ft_strcmp(line, blacklist[i]))
			return (1);
	}
	return (0);
}

u_int32_t		Timeliner::get_damage(char *str)
{
	long		raw;
	u_int32_t	damage = 0;

	raw = strtol(str, NULL, 16);
	if (raw & FLAG_BIGHIT == FLAG_BIGHIT)
	{
		damage = (raw & 0xff) << 16;
		damage += (raw & 0xff000000) >> 8;
		damage += ((raw & 0xff0000) >> 16) - (raw & 0xff);
	}
	else
		damage = (raw & 0xffff0000) >> 16;
	return (damage);
}
