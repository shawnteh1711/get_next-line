/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:34:52 by steh              #+#    #+#             */
/*   Updated: 2022/03/03 19:03:51 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	read_line(int fd)
{
	char	*line;
	int		i;

	i = 1;
	line = (char *)1;
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("line [%02d]: %s\n", i, line);
		free(line);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		r;
	int		fd1;
	int		fd2;

	if (argc > 1)
	{
		fd1 = open(argv[1], O_RDONLY);
		read_line(fd1);
	}
	else
	{
		fd1 = open("tests/test.txt", O_RDONLY);
		fd2 = open("tests/test2.txt", O_RDONLY);
		read_line(fd1);
		read_line(fd2);
	}
	close(fd1);
	close(fd2);
	return (0);
}

// void	ft_readi(int fd)
// {
// 	char	*line;
// 	int		r;

// 	while ((r = get_next_line(fd)) > 0)
// 	{
// 		line = get_next_line(fd);
// 		printf("r = %d line : |%s|\n", r, line);
// 		free(line);
// 	}
// 	printf("r = %d line : |%s|\n", r, line);
// }

// int		main(int ac, char **av)
// {
// 	int fd;

// 	if (ac == 2)
// 	{
// 		fd = open(av[1], O_RDONLY);
// 		ft_readi(fd);
// 	}
// 	else
// 		ft_readi(0);
// 	return (0);
// }