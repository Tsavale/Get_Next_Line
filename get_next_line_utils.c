/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsavale <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 10:55:46 by tsavale           #+#    #+#             */
/*   Updated: 2021/02/23 10:55:50 by tsavale          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strchr_eol(const char *str, int eol)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == eol)
			return (i);
		i++;
	}
	if (str && str[i] == eol)
		return (i);
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1 && s1[i] && s1[i] != '\n')
		i++;
	while (s2 && s2[j] && s2[j] != '\n')
		j++;
	if (!(tab = (char*)malloc(sizeof(char) * (i + j + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[j])
		tab[i++] = s1[j++];
	while (s2 && *s2 && *s2 != '\n')
		tab[i++] = *s2++;
	tab[i] = 0;
	free(s1);
	return (tab);
}
