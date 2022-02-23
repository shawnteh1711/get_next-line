/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:17:30 by steh              #+#    #+#             */
/*   Updated: 2022/02/23 21:17:53 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// read the text file pointed by fd, one line at a time
// return NULL if there is nothing to read or an error occured
char	*get_next_line(int fd)
{
	char	*line;
	char	*save_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	save_line = ft_read_and_save(fd, save_line);
	if (!save_line)
		return (NULL);
	return (line);
}

// ssize_t read(int fd, void *buf, size_t count);
// if read count is zero(BUFFER SIZE), read may return error
// keep reading while the char *save not find '\n' using strchr
char	*ft_read_and_save(int fd, char *save_line)
{
	char	*buffer;
	int		read_bytes;

	read_bytes = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(save_line, '\n') && read_bytes != 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes] = '\0';
		save_line = ft_strjoin(save_line, buffer);
	}
	free(buffer);
	return (save_line);
}