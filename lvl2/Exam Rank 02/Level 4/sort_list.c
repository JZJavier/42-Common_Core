/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:19:51 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/02/07 18:25:48 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*tmp;

	tmp = lst;
	while(lst->next != NULL)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
	return (lst);
}
