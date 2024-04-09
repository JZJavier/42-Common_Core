/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:46:33 by yugao             #+#    #+#             */
/*   Updated: 2024/01/12 00:13:54 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen ((char *)s))
		return (ft_strdup (""));
	if (len > ft_strlen((char *)(s + start)))
		len = ft_strlen((char *)(s + start));
	result = ft_calloc (len + 1, sizeof (char));
	if (!result)
		return (0);
	while (i < len)
	{
		result[i] = s[i + start];
		i ++;
	}
	result[i] = '\0';
	return (result);
}

/*
int main() {
	const char *original = "Hello, World!";
	unsigned int start = 1;
	size_t length = 5;

	char *substring = ft_substr(original, start, length);

	if (substring) {
		printf("Substring: %s\n", substring);
		free(substring); // 释放动态分配的内存
	} else {
		printf("Memory allocation failed.\n");
	}

	return 0;
}
*/