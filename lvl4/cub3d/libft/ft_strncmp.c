/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:31:05 by yugao             #+#    #+#             */
/*   Updated: 2024/01/12 15:41:53 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;

	if (n == 0)
		return (0);
	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	while (--n && *us1 && *us2 && *us1 == *us2)
	{
		if (*us1 != *us2)
			break ;
		us1 ++;
		us2 ++;
	}
	return ((int)(*us1 - *us2));
}

/*
int	main(void)
{
	const char *s1 = "test\200";
	const char *s2 = "test\0";
	int result = ft_strncmp(s1, s2, 0);
	int r2 = strncmp (s1, s2, 0);

	printf ("re : %d\n", result);
	printf ("re2 : %d", r2);
}
*/