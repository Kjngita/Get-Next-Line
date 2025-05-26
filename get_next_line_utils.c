/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 19:36:11 by gita              #+#    #+#             */
/*   Updated: 2025/05/26 21:05:14 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strchr(char *string, int c)
{
	unsigned int	i;
	
	i = 0;
	if (string == NULL)
		return (NULL);
	while (string[i] || (unsigned char)c == '\0')
	{
		if (string[i] == (unsigned char)c)
			return (string + i);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*team;
	int		i;
	int		len1;
	int		len2;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	team = malloc(len1 + len2 + 1);
	if (team == NULL)
		return (NULL);
	i = 0;
	while (i < len1)
	{
		team[i] = s1[i];
		i++;
	}
	while (i < len1 + len2)
	{
		team[i] = s2[i - len1];
		i++;
	}
	team[i] = '\0';
	return (team);
}
