/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sevyesil <sevyesil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 22:33:22 by sevyesil          #+#    #+#             */
/*   Updated: 2025/11/26 23:07:27 by sevyesil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

char	*buf_control(char *buf, ssize_t bytes_read)
{
	if (bytes_read < 0)
	{
		free(buf);
		return (NULL);
	}
	if (!buf)
	{
		buf = (char *)malloc(1);
		if (!buf)
			return (NULL);
		buf[0] = '\0';
	}
	return (buf);
}

char	*read_fd_to_buffer(int fd)
{
	char	tmp[BUFFER_SIZE];
	char	*buf;
	size_t	buf_len;
	ssize_t	bytes_read;

	buf = NULL;
	buf_len = 0;
	bytes_read = read(fd, tmp, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf = append_buf(buf, buf_len, tmp, bytes_read);
		if (!buf)
			return (NULL);
		buf_len += bytes_read;
		bytes_read = read(fd, tmp, BUFFER_SIZE);
	}
	buf = buf_control(buf, bytes_read);
	return (buf);
}

char	*read_stdin(void)
{
	return (read_fd_to_buffer(STDIN_FILENO));
}

char	*read_file(char *filename)
{
	int		fd;
	char	*buf;

	if (filename == NULL)
	{
		return (NULL);
	}
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buf = read_fd_to_buffer(fd);
	close(fd);
	return (buf);
}
