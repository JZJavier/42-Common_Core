/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 08:43:40 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/07 08:54:18 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_range(int start, int end)
{
	int i;
	int len;
	int *arr;

	i = 0;
	len = abs((end - start)) + 1;
	arr = (int *) malloc (len * sizeof(int));
	if (arr == NULL)
		return (NULL);
	while (i < len)
	{
		if (start < end)
		{
			arr[i] = start;
			start++;
			i++;
		}
		else
		{
			arr[i] = start;
			start--;
			i++;
		}
	}
	return (arr);
}
