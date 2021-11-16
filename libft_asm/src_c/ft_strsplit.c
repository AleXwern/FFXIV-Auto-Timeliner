/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anystrom <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 13:39:25 by anystrom          #+#    #+#             */
/*   Updated: 2019/11/03 14:52:46 by anystrom         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_words(char const *s, char c)
{
	int		word;
	int		bool;

	word = 0;
	bool = 0;
	while (*s)
	{
		if (bool == 1 && *s == c)
			bool = 0;
		if (bool == 0 && *s != c)
		{
			bool = 1;
			word++;
		}
		s++;
	}
	return (word);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**array;
	int			i;
	int			j;
	int			srt;

	if (s == NULL)
		return (NULL);
	j = 0;
	i = ft_words(s, c);
	srt = 0;
	if (!(array = (char**)ft_memalloc(sizeof(char*) * (i + 1))))
		return (NULL);
	while (i > j)
	{
		while (s[srt] == c && s[srt])
			srt++;
		array[j] = ft_strsub(s, srt, ft_wordlen(&s[srt], c));
		while (s[srt] != c && s[srt])
			srt++;
		j++;
	}
	array[j] = NULL;
	return (array);
}
