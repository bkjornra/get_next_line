/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkjornra <bkjornra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 16:16:03 by bkjornra          #+#    #+#             */
/*   Updated: 2019/03/12 13:57:24 by bkjornra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/*
** find line's length @ the next line break '\n' && the end of string '\0'
*/

static size_t	line_len(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
		len++;
	return (len);
}

/*
** joins n characters from buf into line
*/

static char		*strjoin_n(char **line, const char *buf, size_t n)
{
	char	*new_str;
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	tmp = *line;
	if (!(new_str = ft_strnew(ft_strlen(tmp) + n + 1)))
		return (NULL);
	while (tmp[i])
	{
		new_str[i] = tmp[i];
		i++;
	}
	while (buf[j] && n)
	{
		new_str[i] = buf[j];
		i++;
		j++;
		n--;
	}
	free(tmp);
	return (new_str);
}

/*
** copy string from src to dest and add '\0' for remaining buffer
*/

static void		strcopy_clean(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i <= BUFF_SIZE)
	{
		dest[i] = '\0';
		i++;
	}
}

/*
** verify if there is '\n' in the line, if yes, update address of buf_fd
** if no, clear buffer using strclr, and read the remaining line
*/

static int		end_line(char **line, char *buf_fd, size_t len)
{
	if (buf_fd[len] == '\n' || (buf_fd[0] == '\0' && *line[0]) != '\0')
	{
		strcopy_clean(buf_fd, &(buf_fd[len + 1]));
		return (1);
	}
	return (0);
}

/*
** read from the file up until the end of a line and save the value at address
** pointed to by pointer line. Error -1, finish file 0, finish line 1.
*/

int				get_next_line(int const fd, char **line)
{
	int			ret;
	size_t		dist;
	static char	buf[OPEN_MAX][BUFF_SIZE + 1];

	if (fd < 0 || !line || fd > OPEN_MAX)
		return (-1);
	if (!(*line = ft_strnew(1)))
		return (-1);
	ret = 1;
	while (ret > 0)
	{
		if (buf[fd][0] == '\0')
			if ((ret = read(fd, &buf[fd], BUFF_SIZE)) < 0)
				return (ret);
		dist = line_len(buf[fd]);
		*line = strjoin_n(line, buf[fd], dist);
		if (end_line(line, buf[fd], dist))
			return (1);
		ft_strclr((char *)buf[fd]);
	}
	return (0);
}
