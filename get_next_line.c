/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:25:09 by gita              #+#    #+#             */
/*   Updated: 2025/05/31 20:28:52 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *leftover(char *finding_nl, int i)
{
	char	*after_nl;
	size_t	leftover_len;
	
	if (finding_nl == NULL)
		return (NULL);
	leftover_len = ft_strlen(finding_nl + i);
	after_nl = ft_substr(finding_nl, i, leftover_len);
	if (after_nl == NULL)
		return (NULL);
	free (finding_nl);
	if (after_nl[0] == '\0')
		return (free (after_nl), NULL);
	return (after_nl);
}

static char	*save_read_here(int	fd, char *finding_nl)
{
	char	*extraction;
	ssize_t	alr_read;

	extraction = malloc(BUFFER_SIZE + 1);
	if (extraction == NULL)
		return (free(finding_nl), NULL);
	while (!ft_strchr(finding_nl, '\n'))
	{
		alr_read = read(fd, extraction, BUFFER_SIZE);
		if (alr_read < 0)
			return (free(extraction), free(finding_nl), NULL);
		if (alr_read == 0)
			break ;
		extraction[alr_read] = '\0';
		finding_nl = ft_strjoin(finding_nl, extraction);
		if (finding_nl == NULL)
			return (free(extraction), NULL);
		if (ft_strchr(finding_nl, '\n'))
			break ;
	}
	free(extraction);
	return (finding_nl);
}

char	*get_next_line(int fd)
{
	static char	*finding_nl;
	int			i;
	char		*result;
	char		*standby;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	finding_nl = save_read_here(fd, finding_nl);
	if (finding_nl == NULL || finding_nl[0] == '\0')
		return (free(finding_nl), finding_nl = NULL, NULL);
	i = 0;
	while (finding_nl[i] && finding_nl[i] != '\n')
		i++;
	if (finding_nl[i] == '\n')
		i++;
	result = ft_substr(finding_nl, 0, i);
	if (result == NULL)
		return (free(finding_nl), finding_nl = NULL, NULL);
	standby = leftover(finding_nl, i);
	finding_nl = standby;
	return (result);
}
