/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 10:49:13 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/01/15 11:21:14 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),	void (*del)(void *))
{
	t_list	*list;
	t_list	*node;
	void	*buffer;

	if (!lst || !f || !del)
		return (0);
	list = NULL;
	while (lst != NULL)
	{
		buffer = f(lst->content);
		node = ft_lstnew(buffer);
		if (!node)
		{
			del(buffer);
			ft_lstclear(&list, (*del));
			return (list);
		}
		ft_lstadd_back(&list, node);
		lst = lst ->next;
	}
	return (list);
}
