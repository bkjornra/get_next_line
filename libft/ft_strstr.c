/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkjornra <bkjornra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 23:40:11 by bkjornra          #+#    #+#             */
/*   Updated: 2019/02/28 17:54:35 by bkjornra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *mainstr, const char *substr)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(mainstr);
	if (ft_strlen(substr) == 0)
		return ((char *)mainstr);
	while (i < len)
	{
		if (ft_memcmp((mainstr + i), substr, ft_strlen(substr)) == 0)
			return ((char *)(mainstr + i));
		i++;
	}
	return (NULL);
}
