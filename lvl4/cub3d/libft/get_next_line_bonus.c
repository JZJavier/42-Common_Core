/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:38:58 by yugao             #+#    #+#             */
/*   Updated: 2024/02/20 00:18:22 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_free(char	**str)
{
	free (*str);
	*str = NULL;
	return (NULL);
}

static char	*read_file(int fd, char *old_buf)
{
	char	*tem_buf;
	int		stat_fd;

	stat_fd = 1;
	tem_buf = ft_call (BUFFER_SIZE + 1);
	if (!tem_buf)
		return (ft_free(&old_buf));
	while (!find_char (old_buf, '\n') && stat_fd != 0)
	{
		stat_fd = read (fd, tem_buf, BUFFER_SIZE);
		if (stat_fd == -1)
		{
			free (tem_buf);
			free (old_buf);
			return (NULL);
		}
		tem_buf[stat_fd] = 0;
		old_buf = merge (old_buf, tem_buf);
	}
	free (tem_buf);
	return (old_buf);
}

static char	*get_line(char *str)
{
	char	*tem;
	size_t	len;

	len = 0;
	if (!*str)
		return (NULL);
	if (!find_char (str, '\n'))
	{
		tem = str_cp (str, str_len(str));
		if (!tem)
			return (NULL);
		return (tem);
	}
	while (str[len] != '\n' && str[len])
		len ++;
	tem = str_cp (str, len + 1);
	if (!tem)
		return (NULL);
	return (tem);
}

static char	*refresh_buf(char	*buf)
{
	char	*old;
	char	*new;

	old = buf;
	if (!buf)
		return (ft_free (&buf));
	if (!find_char (buf, '\n'))
		return (ft_free (&buf));
	while (*buf && *buf != '\n')
		buf ++;
	if (*buf == '\n')
	{
		buf ++;
		new = str_cp (buf, str_len (buf));
		if (!new)
			return (ft_free(&old));
		free (old);
		return (new);
	}
	free (old);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buff[FD_COUNT];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buff[fd] = read_file (fd, buff[fd]);
	if (buff[fd] == NULL)
		return (ft_free (&buff[fd]));
	line = get_line (buff[fd]);
	if (line == NULL)
		return (ft_free (&buff[fd]));
	buff[fd] = refresh_buf (buff[fd]);
	return (line);
}

/*
int main(void)
{
	int	*test;
	int	i = 0;
	int	fd;
	char	*fin;

	//test = (int *)ft_call(10);
	//printf ("**%s**", merge ("this", ""));
	//printf ("== %zu ==", str_len (merge ("", "")));
	//fd = open ("./multiple_nl.txt", O_RDONLY);
	fd = open ("./test.txt", O_RDONLY);
	//printf ("output: %s  \n", read_file(fd, fin));
	//printf ("test : --%s--\n", get_line(read_file(fd, fin)));
	//printf ("test : --%s--\n", get_line(read_file(fd, fin)));
	printf ("                      1: %s \n", get_next_line(fd));
	printf ("                      2: %s \n", get_next_line(fd));
	printf ("                      3: %s \n", get_next_line(fd));
	printf ("                      4: %s \n", get_next_line(fd));
	printf ("                      5: %s \n", get_next_line(fd));
	close (fd);
	return 0;
}
*/