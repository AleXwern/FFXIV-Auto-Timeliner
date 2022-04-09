/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:45:39 by AleXwern          #+#    #+#             */
/*   Updated: 2022/04/09 23:16:11 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timeliner.hpp"
#include "stdio.h"

void			Timeliner::parse_config(void)
{
	int			fd;
	char		*line;
	char		**split;
	t_uint16	tag;

	fd = open("global.conf", O_RDONLY);
	if (fd == -1)
		return ;
	while (get_next_line(fd, &line) == 1)
	{
		tag = ((short*)line)[0];
		split = ft_strsplit(line, ':');
		free(line);
		if (ft_listlen(split) < 2)
		{
			ft_splitfree(split);
			continue;
		}
		switch (tag)
		{
		case TAG_BLACKLIST:
			add_blacklist(split[1]);
			break;
		case TAG_TIME_MAX:
			parse_time(split[1], &end.offset);
			break;
		case TAG_TIME_MIN:
			parse_time(split[1], &start.offset);
			break;
		case TAG_HP_MIN:
			minhp = atoi(split[1]);
			break;
		case TAG_OFFSET:
			parse_time(split[1], &time.offset);
			break;
		default:
			break;
		}
		ft_splitfree(split);
	}
	printf("Configs loaded with:\nBLcount %ld\nMINHP: %u\n", blcount, minhp);
	close(fd);
}

void			Timeliner::add_blacklist(char *name)
{
	if (blcount % 8 == 0)
		blacklist = (char**)realloc(blacklist, sizeof(char*) * (blcount + 8));
	blacklist[blcount] = ft_strdup(name);
	blcount++;
}
