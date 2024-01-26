/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:42:24 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/26 08:37:26 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Falta controlar errores en todoooooooooo

#include "get_next_line.h"

#include <unistd.h> //Borrarrrrrrrrrrrrr funcion
void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (1, &s[i], 1);
		i++;
	}
}

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
	len = ft_strlen(s1);
	trimmed = (char *) malloc (len + 1);
	if (trimmed == NULL)
		return (NULL);
	while (s1[i] != '\n' && s1[i] != '\0')
	{
		trimmed [i] = s1 [i];
		i++;
	}
	trimmed [i] = '\n'; // Se puede poner en otro lado??
	trimmed [i + 1] = '\0';  //Esto es necesario?????????????? NO
	return (trimmed);
}

char	*ft_read(int fd, char *buf,char *stati)
{
	char	*line;
	int		bytes;

	if (stati == NULL)
		line = ft_strdup("");
	else
		line = ft_strdup(stati);
	while ((bytes = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		line = ft_strjoin(line, buf);
		if ((ft_strchr(buf, '\n')) == 1)
			break ;
	}
	if (bytes < 0)
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*schar;
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *) malloc (BUFFER_SIZE + 1);
	line = ft_read(fd, buf, schar);
	if (line == NULL)
		return (NULL);
	schar = ft_substr(line);
	line = ft_strtrim(line);
	free (buf);
	//ft_putstr(line); //Borrarrrrrrrrrrrrrrrrrr
	return (line);
}

/*#include <fcntl.h> //for open
int main(void)
{
	int i = 0;
	int fd = open("chistes.txt", O_RDONLY);
	get_next_line(fd);
	while (i < 80)
	{
		get_next_line(fd);
		i++;
	}
	system("leaks -q a.out");
	close(fd);
	return (0);
}*/
