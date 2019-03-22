/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkjornra <bkjornra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:42:54 by bkjornra          #+#    #+#             */
/*   Updated: 2019/03/01 16:02:04 by bkjornra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	finish;

	if (!s)
		return (NULL);
	start = 0;
	while (s[start] != '\0' && ft_whitespace(s[start]))
		start++;
	finish = ft_strlen(s);
	while (start < finish && ft_whitespace(s[finish - 1]))
		finish--;
	if (finish == start)
		return (ft_strnew(1));
	return (ft_strsub(s, start, finish - start));
}
