/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:25:36 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/26 17:53:47 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*last_node;
	int		len;

	len = ft_listsize(*stack);
	if (NULL == stack || NULL == *stack || 1 == len)
		return ;
	last_node = ft_lstlast(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}
