/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                     :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:16:32 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/27 16:52:53 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_trim(char *str)
{
	int		i;
	char	*extra;

	if (!str || !str[0])
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	extra = (char *)malloc(i + 1);
	if (extra == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		extra[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		extra[i++] = '\n';
	extra[i] = '\0';
	return (extra);
}

char	*ft_newline(char *str)
{
	char	*buf;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	i += (str[i] == '\n');
	buf = (char *) malloc (ft_strlen(str) - i + 1);
	if (buf == NULL)
		return (NULL);
	j = 0;
	while (str[i + j] != '\0')
	{
		buf[j] = str[i + j];
		j++;
	}
	buf[j] = '\0';
	free(str);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*schar;
	char		*buf;
	int			bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes = 1;
	buf = (char *) malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	while (!(ft_strchr(schar, '\n')) && bytes != 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes] = '\0';
		schar = ft_strjoin(schar, buf);
	}
	free(buf);
	buf = ft_trim(schar);
	schar = ft_newline(schar);
	return (buf);
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
	close(fd);
	return (0);
}*/
