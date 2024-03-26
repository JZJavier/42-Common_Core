/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:16:00 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/26 17:22:35 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	is_sorted(t_stack *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (FALSE);
		stack = stack->next;
	}
	return (TRUE);
}

void	add_back(t_stack **stack, int number)
{
	t_stack	*node;

	node = ft_lstnew(number);
	if (!node)
	{
		ft_lstclear(stack);
		exit(EXIT_FAILURE);
	}
	ft_lstadd_back(stack, node);
}

void	init_nodes(t_stack *a, t_stack *b)
{
	init_index(a);
	init_index(b);
	init_target(a, b);
	init_price(a, b);
	init_cheapest(b);
}
