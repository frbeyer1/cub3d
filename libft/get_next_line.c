/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frbeyer <frbeyer@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:56:08 by frbeyer           #+#    #+#             */
/*   Updated: 2023/11/22 16:46:24 by frbeyer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

char	*read_str(int fd, char *str_rest)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (free(str_rest), NULL);
	rd_bytes = 1;
	while (!ft_str_chr(str_rest, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
			return (free(buff), free(str_rest), NULL);
		if (rd_bytes != 0)
		{
			buff[rd_bytes] = '\0';
			str_rest = ft_str_join(str_rest, buff);
		}
	}
	free(buff);
	return (str_rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*str_rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str_rest = read_str(fd, str_rest);
	if (!str_rest)
		return (NULL);
	line = get_linie(str_rest);
	if (!line)
	{
		free(str_rest);
		str_rest = NULL;
		return (NULL);
	}
	str_rest = new_str_rest(str_rest);
	return (line);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	// int		fd2;
// 	// int		fd3;
// 	fd1 = open("../tests/test3 copy.txt", O_RDONLY);
// 	// fd2 = open("tests/test2.txt", O_RDONLY);
// 	// fd3 = open("tests/test3copy.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 4)
// 	{
// 		line = get_next_line(fd1);
// 		printf("fd1 line [%02d]: %s", i, line);
// 		free(line);
// 		// line = get_next_line(fd2);
// 		// printf("fd2 line [%02d]: %s\n", i, line);
// 		// free(line);
// 		// line = get_next_line(fd3);
// 		// printf("fd3 line [%02d]: %s\n", i, line);
// 		// printf("\n");
// 		// free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	// close(fd2);
// 	// close(fd3);
// 	return (0);
// }