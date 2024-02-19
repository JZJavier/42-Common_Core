/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:31:23 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/13 17:46:13 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	t_list l;
	int *i = (int *)malloc(sizeof(int));
	*i = 9;
	l = *ft_lstnew((void *) i);
	printf("%d", ft_lstsize(&l));
	return (0);
}*/
