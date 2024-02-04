/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 13:31:14 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/04 13:43:26 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	checkset(char c, const char *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}
char *ft_strpbrk(const char *s1, const char *s2)
{
	int i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i])
	{
		if (checkset(s1[i], s2) > 0)
			return ((char *) &s1[i]);
		else
			i++;
	}
	return (0);
}
