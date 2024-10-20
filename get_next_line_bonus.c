/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migugar2 <migugar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 16:41:29 by migugar2          #+#    #+#             */
/*   Updated: 2024/10/20 19:48:22 by migugar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>
#include <unistd.h>

char	*get_new_saved(char **saved, char *new_line, size_t line_len)
{
	char	*new_saved;
	char	*line;
	size_t	i;

	line = (char *)malloc(sizeof(char) * (line_len + 1));
	if (line == NULL)
		return (free_str(saved));
	i = 0;
	while (i < line_len)
	{
		line[i] = (*saved)[i];
		i++;
	}
	line[i] = '\0';
	if (*(new_line + 1) != '\0')
	{
		new_saved = str_dup(new_line + 1);
		if (new_saved == NULL)
			return (free_str(&line), free_str(saved));
	}
	else
		new_saved = NULL;
	free_str(saved);
	*saved = new_saved;
	return (line);
}

char	*extract_line(char **saved)
{
	char	*new_line;
	char	*line;

	new_line = str_chr(*saved, '\n');
	if (new_line != NULL)
		return (get_new_saved(saved, new_line, new_line - *saved + 1));
	if ((*saved)[0] == '\0')
		return (free_str(saved));
	line = *saved;
	*saved = NULL;
	return (line);
}

char	*read_until_eol_eof(int fd, char **saved, char **buffer)
{
	char		*temp;
	ssize_t		bytes_read;
	char		*compared;

	bytes_read = 1;
	compared = *saved;
	while (bytes_read > 0 && str_chr(compared, '\n') == NULL)
	{
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_str(saved), free_str(buffer));
		if (bytes_read > 0)
		{
			(*buffer)[bytes_read] = '\0';
			compared = *buffer;
			temp = str_join(*saved, *buffer);
			if (temp == NULL)
				return (free_str(saved), free_str(buffer));
			free_str(saved);
			*saved = temp;
		}
	}
	return (*saved);
}

char	*get_next_line(int fd)
{
	static char	*saved[MAX_FD];
	char		*buffer;
	char		*line;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	if (saved[fd] == NULL)
		saved[fd] = str_dup("");
	if (saved[fd] == NULL)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (free_str(&saved[fd]));
	saved[fd] = read_until_eol_eof(fd, &saved[fd], &buffer);
	if (saved[fd] == NULL)
		return (free_str(&buffer), NULL);
	line = extract_line(&saved[fd]);
	free_str(&buffer);
	return (line);
}
