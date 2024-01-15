/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:37:14 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/15 09:57:49 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	(del)(lst -> content);
	free(lst);
	lst = NULL;
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
	ft_lstdelone(node2, free);
	//printf("%s\n", (char *) node2->content);

    return 0;
}*/
