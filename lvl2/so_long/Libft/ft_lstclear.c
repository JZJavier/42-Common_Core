/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:59:58 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/15 10:47:45 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !del ||!(*lst))
		return ;
	ft_lstclear (&(*lst)->next, del);
	(del)((*lst)->content);
	free (*lst);
	*lst = NULL;
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

	//printf("%s\n", (char *) node2->content);
	ft_lstclear(&node2, free);
	//printf("%s\n", (char *) node2->content);

    return 0;
}*/
