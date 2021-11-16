/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeliner.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:56:33 by AleXwern          #+#    #+#             */
/*   Updated: 2021/11/16 16:01:02 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMELINER_H
# define TIMELINER_H
extern "C"
{
	# include "libft.h"
}
# include <fcntl.h>

# define ATK_OPCODE	0x3132

enum	e_tags
{
	TAG_HP_MIN		= 0x5048,
	TAG_TIME_MAX	= 0x4D54,
	TAG_TIME_MIN	= 0x5854,
	TAG_OFFSET		= 0x464F,
	TAG_BLACKLIST	= 0x4C42
};

typedef struct	s_timeoffset
{
	char		day;	//just in case
	char		hour;
	char		min;
	char		sec;
}				t_toffset;

class			Timeliner
{
private:
	int			outfile;
	int			infile;
	t_toffset	time;
	char		**blacklist;
	size_t		blcount;
	t_uint32	minhp;

	void		sort_output(char *line);
	void		error_out(const char *str);
	void		parse_config(void);
	void		add_blacklist(char *name);
	int			check_blacklist(char *line);
public:
	Timeliner(int ac, char **av);
	void		parse_file(void);
};

#endif
