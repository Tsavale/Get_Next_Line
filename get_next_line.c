/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsavale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:55:04 by tsavale           #+#    #+#             */
/*   Updated: 2021/02/23 10:55:24 by tsavale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char		buf[FOPEN_MAX][BUFFER_SIZE + 1];
	int				i;
	int				r;

	if (fd < 0 || !line || fd >= FOPEN_MAX ||
	BUFFER_SIZE < 1 || !(*line = ft_strjoin(NULL, buf[fd])))
		return (-1);
	r = 1;
	while (ft_strchr_eol(buf[fd], '\n') == -1 && r)
	{
		r = read(fd, buf[fd], BUFFER_SIZE);
		if (r == -1)
			return (-1);
		buf[fd][r] = '\0';
		if (!(*line = ft_strjoin(*line, buf[fd])))
			return (-1);
	}
	i = 0;
	r = ft_strchr_eol(buf[fd], '\n') + 1;
	if (buf[fd][0] == 0)
		return (0);
	while (buf[fd][r] != '\0' && r)
		buf[fd][i++] = buf[fd][r++];
	buf[fd][i] = '\0';
	return (1);
}
