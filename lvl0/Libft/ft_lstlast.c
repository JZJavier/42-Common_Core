/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 17:59:55 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/13 18:18:31 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*curr;

	curr = lst;
	while (curr != NULL && curr->next != NULL)
		curr = curr -> next;
	return (curr);
}

/*#include <stdio.h>
int main(void)
{
    t_list *node1 = ft_lstnew("Node 1");
    t_list *node2 = ft_lstnew("Node 2");
    t_list *node3 = ft_lstnew("Node 3");

    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

	t_list *last = ft_lstlast(node1);
	printf("%s\n", (char *)last->content);

    return 0;
}*/
