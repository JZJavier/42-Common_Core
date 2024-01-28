/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 06:08:08 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/28 06:17:14 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char    *ft_strcpy(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] =  '\0';
	return (s1);
}

/*#include <stdio.h>
int main(void)
{
	char	*s1;
	char	*s2;

	s2 = "Hola Pacoo";
	printf("%s", ft_strcpy(s1, s2));
	return (0);
}*/
