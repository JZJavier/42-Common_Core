/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:42:24 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/24 19:06:06 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Falta controlar errores en todoooooooooo

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	int		i;
	int		j;
	char	*a;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	a = (char *) malloc (i + 1);
	if (a == '\0')
		return (0);
	while (j < i)
	{
		a[j] = s1[j];
		j++;
	}
	a[j] = '\0';
	return (a);
}

char	*ft_strtrim(char const *s1)
{
	int		i;
	char	*trimmed;
	int		len;

	i = 0;
	len = 0;
	while (s1[i] != '\n' && s1[i] != '\0')
		i++;
	trimmed = (char *) malloc (i + 1);
	if (trimmed == NULL)
		return (NULL);
	while (len < i)
	{
		trimmed [len] = s1 [len];
		len++;
	}
	trimmed [i] = '\0';
	return (trimmed);
}

char	*ft_read(int fd, char *stati)
{
	char	*line;
	char	*buf;
	int		bytes;

	buf = (char *) malloc (BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	line = (stati != NULL) ? ft_strdup(stati) : ft_strdup("");
	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf [bytes] = '\0';
		line = ft_strjoin(line, buf);
		if ((ft_strchr(buf, '\n')) == 1)
			break ;
	}
	free (buf);
	if (bytes < 0)
	{
		free(buf);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*schar;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_read(fd, schar);
	schar = ft_substr(line);
	line = ft_strtrim(line);
	printf("Returrrrrrrr: %s\n", line); //Borrar
	return (line);
}

/*#include <fcntl.h> //for open
int main(void)
{
	int i = 0;
	int fd = open("chistes.txt", O_RDONLY);
	get_next_line(fd);
	while (i < 60)
	{
		get_next_line(fd);
		i++;
	}
	system("leaks -q a.out");
	close(fd);
	return (0);
}*/
