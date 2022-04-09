/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeliner.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:56:33 by AleXwern          #+#    #+#             */
/*   Updated: 2022/04/09 23:40:21 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMELINER_H
# define TIMELINER_H
extern "C"
{
	# include "libft.h"
}
# include <fcntl.h>

enum				e_opcodes
{
	OPCODE_CAST		= 0x3032,
	OPCODE_ATK		= 0x3132,
	OPCODE_AOE		= 0x3232
};

enum				e_parts
{
	PART_OPCODE		= 0,
	PART_DATETIME	= 1,
	PART_SOURCEID	= 2,
	PART_NAME		= 3,
	PART_ACTIONID	= 4,
	PART_ATTACKNAME	= 5,
	PART_TARGETID	= 6,
	PART_TARGETNAME	= 7,
	PART_FLAGS		= 8,
	PART_DAMAGE		= 9,
	PART_TARGETHP	= 24,
	PART_TARGETMAXHP= 25,
	PART_TARGETMP	= 26,
	PART_TARGETMAXMP= 27,
	PART_TARGETX	= 28,
	PART_TARGETY	= 29,
	PART_TARGETZ	= 30,
	PART_TARGETDIR	= 31,
	PART_OWNHP		= 32,
	PART_OWNMAXHP	= 33,
	PART_OWNMP		= 34,
	PART_OWNMAXMP	= 35
};

enum				e_abilityflags
{
	FLAG_DODGE		= 0x01,
	FLAG_DAMAGE		= 0x03,
	FLAG_BLOCKED	= 0x05,
	FLAG_PARRIED	= 0x06,
	FLAG_INSTAKO	= 0x33,
	FLAG_CRIT		= 0x100,
	FLAG_DIRECTHIT	= 0x200,
	FLAG_DIRECTCRIT	= 0x300,
	FLAG_HEAL		= 0x00004,
	FLAG_CRITHEAL	= 0x10004,
	FLAG_BIGHIT		= 0x00004000
};

enum				e_tags
{
	TAG_HP_MIN		= 0x5048,
	TAG_TIME_MIN	= 0x4D54,
	TAG_TIME_MAX	= 0x5854,
	TAG_OFFSET		= 0x464F,
	TAG_BLACKLIST	= 0x4C42
};

typedef struct		s_timeoffset
{
	//YYMMDD just in case. Raids tend to be late
	char			unused;
	char			sec;
	char			min;
	char			hour;
	char			day;
	char			month;
	short			year;
}					t_toffset;

union				u_offset
{
	t_toffset		offset;
	t_uint64		bits;
};

class				Timeliner
{
private:
	int				outfile;
	int				infile;
	/*union			u_offset
	{
		t_toffset	offset;
		t_uint64	bits;
	}				time;*/
	u_offset		time;
	u_offset		start;
	u_offset		end;
	char			**blacklist;
	size_t			blcount;
	t_uint32		minhp;

	void			parse_timestamp(t_toffset *time, char *str);
	void			sort_output(char *line);
	void			error_out(const char *str);
	void			add_blacklist(char *name);
	void			print_time(t_toffset *time);
	int				check_blacklist(char *line);
	u_int32_t		get_damage(char *str);
public:
	Timeliner(int ac, char **av);
	void			parse_config(void);
	void			parse_file(void);
};

void	parse_time(const char *str, t_toffset *time);
void	offset_time(t_toffset *time, t_toffset *offset);

#endif
