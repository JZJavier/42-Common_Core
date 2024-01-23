/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:42:24 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/23 21:01:47 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Falta controlar errores en todoooooooooo

#include "get_next_line.h"
#include <stdio.h>

int	modi_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (1);
		else
			i++;
	}
	return (0);
}

char	*print_extra(char *s1)
{
	int		i;
	int		len;
	char	*trimmed;

	len = ft_strlen(s1);
	trimmed = (char *) malloc (len + 1);
	if (trimmed == '\0')
		return (0);
	i = 0;
	while (s1[i] != '\n')
	{
		write(1, &s1[i], 1);
		i++;
	}
	write (1, "\n", 1);
	i++;
	len = 0;
	while (s1[i] != '\0')
	{
		trimmed [len] = s1 [i];
		len++;
		i++;
	}
	trimmed [i] = '\0';
	return (trimmed);
}

char	*save_extra(char *extra)
{
	while (modi_strchr (extra, '\n'))
	{
		extra = print_extra(extra);
		if (extra == NULL)
			return (NULL);
	}
	return (extra);
}

char	*ft_read(int fd, char *stati)
{
	char	*line;
	char	*buf;
	int		bytes;

	buf = (char *) malloc (BUFFER_SIZE + 1);
	line = (char *) malloc (BUFFER_SIZE + 1);
	if (stati != NULL)
		line = ft_strjoin(line, stati);
	if (line == NULL || buf == NULL)
		return (NULL);
	while ((ft_strchr(buf, '\n')) != 1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
		{
			free (buf);
			return (NULL);
		}
		line = ft_strjoin(line, buf);
	}
	free (buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*schar;
	char		*line;
	char		*returned;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	line = ft_read(fd, schar);
	ft_putstr(line);
	i = ft_strlen(line);
	returned = (char *) malloc (i);
	if (returned == NULL)
		return (NULL);
	i = 0;
	while (line[i] != '\n')
	{
		returned [i] = line[i];
		i++;
	}
	schar = ft_substr(line);
	schar = save_extra(schar);
	free (line);
	return (line);
}

/*#include <fcntl.h> //for open
int main(void)
{
	int i = 0;
	int fd = open("chistes.txt", O_RDONLY);
	get_next_line(fd);
	while (i < 5)
	{
		get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}*/
