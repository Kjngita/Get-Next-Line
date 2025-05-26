/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:25:09 by gita              #+#    #+#             */
/*   Updated: 2025/05/27 00:39:25 by gita             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*save_read_here(int	fd, char *finding_nl)
{
	char	*extraction;
	ssize_t	alr_read;
	char	*xtrabuf;

	extraction = malloc(BUFFER_SIZE + 1);
	if (extraction == NULL)
		return (NULL);
	alr_read = 68;
	while (!ft_strchr(finding_nl, '\n') && alr_read > 0)
	{
		alr_read = read(fd, extraction, BUFFER_SIZE);
		if (alr_read < 0)
			return (free(extraction), free(finding_nl), NULL);
		if (alr_read == 0)
			break ;
		extraction[alr_read] = '\0';
		xtrabuf = ft_strjoin(finding_nl, extraction);
		if (xtrabuf == NULL)
			return (free(extraction), free(finding_nl), NULL);
		free(finding_nl);
		finding_nl = xtrabuf;	
	}
	free(extraction);
	return (finding_nl);
}

char	*get_next_line(int fd)
{
	static char	*finding_nl;
	int			i;
	char		*result;
	char		*leftover;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	finding_nl = save_read_here(fd, finding_nl);
	if (finding_nl == NULL)
		return (free(finding_nl), NULL);
	i = 0;
	while (finding_nl[i] && finding_nl[i] != '\n')
		i++;
	if (finding_nl[i] == '\n')
		i++;
	result = ft_substr(finding_nl, 0, i);
	if (result == NULL)
		return (free(finding_nl), finding_nl = NULL, NULL);
	leftover = ft_substr(finding_nl, i, ft_strlen(finding_nl) - i);
	if (leftover == NULL)
		return (free(finding_nl), finding_nl = NULL, NULL);
	free(finding_nl);
	finding_nl = leftover;
	free(leftover);
	return (result);
}




