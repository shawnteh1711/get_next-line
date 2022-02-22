/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:17:30 by steh              #+#    #+#             */
/*   Updated: 2022/02/22 21:27:30 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// read the text file pointed by fd, one line at a time
// return NULL if there is nothing to read or an error occured
// 
char	*get_next_line(int fd)
{
	char	*line;
	char	*save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	save = ft_read_and_save(fd, save);
	return (line);
}

char	*ft_read_and_save(int fd, char *save)
{
	
}