/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:27:24 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/10 17:14:41 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int i)
{
	if (i >= 48 && i <= 57)
		return (1);
	else
		return (0);
}

/*#include <stdio.h>

int main (void)
{
	printf("%d",ft_isdigit(48));
}*/
