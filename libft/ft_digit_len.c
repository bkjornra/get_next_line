/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkjornra <bkjornra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 18:47:45 by bkjornra          #+#    #+#             */
/*   Updated: 2019/03/01 01:15:43 by bkjornra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digit_len(int num)
{
	int	length;

	if (num == -2147483648)
		return (10);
	length = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		num = -num;
		length++;
	}
	while (num)
	{
		num /= 10;
		length++;
	}
	return (length);
}
