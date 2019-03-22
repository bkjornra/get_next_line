/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkjornra <bkjornra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:38:25 by bkjornra          #+#    #+#             */
/*   Updated: 2019/03/01 20:06:23 by bkjornra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (s1[len] != '\0' && len < n)
		len++;
	i = len;
	while (s2[len - i] != '\0' && len + 1 < n)
	{
		s1[len] = s2[len - i];
		len++;
	}
	if (i < n)
		s1[len] = '\0';
	return (i + ft_strlen(s2));
}
