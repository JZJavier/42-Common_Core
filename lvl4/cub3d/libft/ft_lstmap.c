/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:39:11 by yugao             #+#    #+#             */
/*   Updated: 2024/01/12 06:36:44 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_nudo;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_nudo = ft_lstnew (f (lst->content));
		if (!new_nudo)
		{
			ft_lstclear (&new_list, del);
			return (NULL);
		}
		ft_lstadd_back (&new_list, new_nudo);
		lst = lst->next;
	}
	return (new_list);
}
