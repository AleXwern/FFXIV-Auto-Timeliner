/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 11:59:41 by anystrom          #+#    #+#             */
/*   Updated: 2021/11/16 13:50:47 by AleXwern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		set_next_line(char **readl, char **line, int fd)
{
	int		i;
	char	*temp;

	i = 0;
	while (readl[fd][i] != '\n' && readl[fd][i] != '\0')
		i++;
	if (readl[fd][i] == '\0')
	{
		*line = ft_strdup(readl[fd]);
		free(readl[fd]);
	}
	else if (readl[fd][i] == '\n')
	{
		*line = ft_strsub(readl[fd], 0, i);
		temp = ft_strdup(readl[fd] + i + 1);
		free(readl[fd]);
		readl[fd] = temp;
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char			buffer[BUFF_SIZE + 1];
	char			*temp;
	static char		*readl[MAX_FD];
	int				bty;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((bty = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[bty] = '\0';
		if (readl[fd] == NULL)
			if (!(readl[fd] = ft_strnew(0)))
				return (-1);
		temp = ft_strjoin(readl[fd], buffer);
		free(readl[fd]);
		readl[fd] = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (bty < 0)
		return (-1);
	else if (bty == 0 && (readl[fd] == NULL || readl[fd][0] == '\0'))
		return (0);
	else
		return (set_next_line(readl, line, fd));
}
