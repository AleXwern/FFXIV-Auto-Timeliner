/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeliner.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:56:33 by AleXwern          #+#    #+#             */
/*   Updated: 2021/11/17 16:59:27 by AleXwern         ###   ########.fr       */
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

enum				e_tags
{
	TAG_HP_MIN		= 0x5048,
	TAG_TIME_MAX	= 0x4D54,
	TAG_TIME_MIN	= 0x5854,
	TAG_OFFSET		= 0x464F,
	TAG_BLACKLIST	= 0x4C42
};

typedef struct		s_timeoffset
{
	//YYMMDD just in case. Raids tend to be late
	short			year;
	char			month;
	char			day;
	char			hour;
	char			min;
	char			sec;
	char			unused;
}					t_toffset;

class				Timeliner
{
private:
	int				outfile;
	int				infile;
	union			u_offset
	{
		t_toffset	offset;
		t_uint64	bits;
	}				time;
	char			**blacklist;
	size_t			blcount;
	t_uint32		minhp;

	void			sort_output(char *line);
	void			error_out(const char *str);
	void			add_blacklist(char *name);
	void			print_time(t_toffset *time);
	int				check_blacklist(char *line);
public:
	Timeliner(int ac, char **av);
	void			parse_config(void);
	void			parse_file(void);
};

void	parse_time(char *str, t_toffset *time);

#endif
