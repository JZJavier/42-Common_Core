/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:31:47 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/13 17:04:01 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *) malloc(sizeof(t_list));
	if (!node)
		return (0);
	node->content = content;
	node->next = NULL;
	return (node);
}

/*#include <stdio.h>
int main(void)
{
    int content = 1;

    t_list *node = ft_lstnew(&content);
	printf("Content: %d\n", *(int *)(node->content));
    printf("Address: %p\n", (void *)(node));
    free(node);

    return (0);
}*/
