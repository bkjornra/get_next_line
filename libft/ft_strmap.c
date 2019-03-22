/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkjornra <bkjornra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 11:39:01 by bkjornra          #+#    #+#             */
/*   Updated: 2019/02/28 18:45:16 by bkjornra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_s;
	size_t	i;

	if (!s)
		return (NULL);
	new_s = ft_strnew(ft_strlen(s));
	if (new_s == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		new_s[i] = f(s[i]);
		i++;
	}
	return (new_s);
}
