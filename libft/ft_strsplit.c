/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkjornra <bkjornra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:41:54 by bkjornra          #+#    #+#             */
/*   Updated: 2019/03/02 17:27:03 by bkjornra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_word_len(char const *word, char delim)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (word[i] && word[i] == delim)
		i++;
	while (word[i] && word[i] != delim)
	{
		i++;
		count++;
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		index;
	int		k;
	char	**strings;

	if (!s || !(strings = (char **)malloc(sizeof(char *) *
					ft_count_words(s, c) + 1)))
		return (NULL);
	i = 0;
	index = 0;
	while (i < ft_count_words(s, c))
	{
		k = 0;
		if (!(strings[i] = (char *)malloc(sizeof(char) *
						ft_word_len(&s[index], c) + 1)))
			return (NULL);
		while (s[index] == c)
			index++;
		while (s[index] && s[index] != c)
			strings[i][k++] = s[index++];
		strings[i][k] = '\0';
		i++;
	}
	strings[i] = 0;
	return (strings);
}
