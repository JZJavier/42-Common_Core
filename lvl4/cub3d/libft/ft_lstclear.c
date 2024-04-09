/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yugao <yugao@student.42madrid.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 18:36:31 by yugao             #+#    #+#             */
/*   Updated: 2024/01/11 18:36:54 by yugao            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*pre;

	if (!lst)
		return ;
	while (*lst)
	{
		pre = *lst;
		*lst = (*lst)->next;
		del(pre->content);
		free(pre);
	}
	*lst = NULL;
}
