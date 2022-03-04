/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:34:52 by steh              #+#    #+#             */
/*   Updated: 2022/03/04 21:38:58 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_line(int fd)
{
	char		*line;
	int			i;
	char		*buf;
	ssize_t		bytes_read;

	i = 1;
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line != NULL)
			printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char		*line;
	int			fd;
	int			j;
	const char	*tests[] = {
		"tests/test.txt",
		"tests/test2.txt",
		"tests/test3.txt"
	};
	const int	files = sizeof(tests) / sizeof(tests[0]);

	if (argc > 1)
	{
		if (argc > 2)
		{
			printf("Sorry, only accept one file to open");
			return (-1);
		}
		fd = open(argv[1], O_RDONLY);
		read_line(fd);
		close(fd);
	}
	else
	{
		for (int i = 0; i < files; i++)
		{
			printf("Now testing file %s:\n", tests[i]);
			fd = open(tests[i], O_RDONLY);
			line = get_next_line(fd);
			while (line != NULL)
			{
				printf("%s", line);
				free(line);
				line = get_next_line(fd);
			}
			printf("\n\n");
			close(fd);
		}
	}
	return (0);
}