/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkjornra <bkjornra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:41:12 by bkjornra          #+#    #+#             */
/*   Updated: 2019/02/28 17:56:51 by bkjornra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *main, const char *sub, size_t len)
{
	size_t	i;
	size_t	j;

	if (*sub == '\0')
		return ((char*)main);
	i = 0;
	while (main[i] && i < len)
	{
		j = 0;
		while (main[i + j] && i + j < len && sub[j] && main[i + j] == sub[j])
			j++;
		if (sub[j] == '\0')
			return ((char *)(main + i));
		i++;
	}
	return (NULL);
}
