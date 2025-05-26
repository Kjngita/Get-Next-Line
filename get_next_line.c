/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gita <gita@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:25:09 by gita              #+#    #+#             */
/*   Updated: 2025/05/26 21:12:01 by gita             ###   ########.fr       */
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
	while (finding_nl == NULL || !ft_strchr(finding_nl, '\n') && alr_read > 0)
	{
		alr_read = read(fd, extraction, BUFFER_SIZE);
		if (alr_read < 0)
			return (free (extraction), free(finding_nl), NULL);
		if (alr_read == 0)
			break ;
		extraction[alr_read] = '\0';
			
	}
	xtrabuf = ft_strjoin(finding_nl, extraction);
	finding_nl = NULL;
	finding_nl = xtrabuf;
	
	
		
	
	
}

char	*get_next_line(int fd)
{
	static char	*finding_nl;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	finding_nl = save_read_here(fd, finding_nl);
	
}




