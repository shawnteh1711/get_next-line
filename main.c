/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:34:52 by steh              #+#    #+#             */
/*   Updated: 2022/03/04 10:11:46 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_line(int fd)
{
	char	*line;
	int		i;
	int		r;
	char	*buf;
	int		bytes_read;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
	free(buf);
	// i = 1;
	// line = (char *)1;
	// while (line != NULL)
	// {
	// 	line = get_next_line(fd);
	// 	printf("line [%02d]: %s\n", i, line);
	// 	free(line);
	// 	i++;
	// }
}

int	main(int argc, char *argv[])
{
	char		*line;
	int			fd1;
	int			test_count;
	int			fds[3];
	int			i;
	char const	*tests[5] = {
		"tests/test.txt",
		"tests/test2.txt",
		"tests/test3.txt"
	};

	test_count = 3;
	if (argc > 1)
	{
		fd1 = open(argv[1], O_RDONLY);
		read_line(fd1);
		if (argc > 2)
		{
			printf("Sorry, only accept one file to open");
			return (-1);
		}
		close(fd1);
	}
	else
	{
		i = 0;
		while (i < test_count)
		{
			fds[i] = open(tests[i], O_RDONLY);
			i++;
		}
		i = 0;
		while (i < test_count)
		{
			read_line(fds[i]);
			i++;
		}
		i = 0;
		while (i < test_count)
			close(fds[i++]);
	}
	return (0);
}