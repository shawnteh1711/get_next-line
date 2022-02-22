/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: steh <steh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 10:18:34 by steh              #+#    #+#             */
/*   Updated: 2022/02/22 21:25:34 by steh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef 	GET_NEXT_LINE_H
# define 	GET_NEXT_LINE_H
#ifndef 	BUFFER_SIZE
# define 	BUFFER_SIZE 	1
# endif
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
size_t	ft_strlcat(char *dest, const char *src, size_t len);
size_t	ft_strlcpy(char *dest, const char *src, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

# endif