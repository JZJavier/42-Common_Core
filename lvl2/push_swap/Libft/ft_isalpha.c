/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 15:45:45 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/10 17:13:50 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int i)
{
	if ((i >= 65 && i <= 90) || (i >= 97 && i <= 122))
		return (1);
	else
		return (0);
}

/*#include <stdio.h>

int main (void)
{
	printf("%d",ft_isalpha(100));
}*/
