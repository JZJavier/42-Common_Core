/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 12:56:15 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/26 17:55:12 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*node;

	if (*src == NULL)
		return ;
	node = *src;
	*src = (*src)->next;
	if (*src != NULL)
		(*src)->prev = NULL;
	node->prev = NULL;
	if (*dest == NULL)
	{
		*dest = node;
		node->next = NULL;
	}
	else
	{
		node->next = *dest;
		node->next->prev = node;
		*dest = node;
	}
}
