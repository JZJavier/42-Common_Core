/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:43:57 by yugao             #+#    #+#             */
/*   Updated: 2024/01/12 17:31:49 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_sep(char *s, char c)
{
	int	num;

	num = 0;
	if (c == '\0')
		return (1);
	while (*s == c)
		s ++;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || !*(s + 1)))
			num ++;
		s ++;
	}
	return (num);
}

static char	*crestr(char *start, char c)
{
	int		len;
	char	*fin;

	len = 0;
	while (start[len] != c && start[len])
		len ++;
	fin = (char *) malloc (sizeof (char) * (len + 1));
	if (!fin)
		return (0);
	ft_strlcpy (fin, start, len + 1);
	return (fin);
}

static void	*eli_ary(char **s, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (s[i])
			free (s[i]);
		i ++;
	}
	free(s);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**fin;
	int		len;
	int		i;

	if (!s)
		return (0);
	i = 0;
	len = count_sep ((char *)s, c);
	fin = (char **) malloc (sizeof (char *) * (len + 1));
	if (!fin)
		return (0);
	while (i < len && *s)
	{
		while (*s == c && *s)
			s ++;
		if (*s)
			fin[i++] = crestr ((char *)s, c);
		if (i > 0 && !fin[i - 1])
			return (eli_ary (fin, i - 1));
		while (*s != c && *s)
			s ++;
	}
	fin[i] = 0;
	return (fin);
}

/*
int main() {
	char const *input_string = "^^^1^^2a,^^^^3^^^^--h^^^^";
	char delimiter = '^';
	char t[] = "\0aa\0bbb";
	
	// 使用 ft_split 函数拆分字符串
	char **result = ft_split(input_string, delimiter);

	if (result) {
		// 遍历并打印拆分后的字符串数组
		for (int i = 0; result[i] != NULL; i++) {
			printf("Token %d: %s\n", i, result[i]);
		}

		// 释放分配的内存
		for (int i = 0; result[i] != NULL; i++) {
			free(result[i]);
		}
		free(result);
	} else {
		printf("Memory allocation failed.\n");
	}
	return 0;
}
*/