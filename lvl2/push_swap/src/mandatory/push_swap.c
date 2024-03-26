/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 10:16:55 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/26 18:57:30 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	last_rotation(t_stack **stack, t_stack *head, char stack_name)
{
	while (*stack != head)
	{
		if (stack_name == 'a')
		{
			if (head->is_above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (head->is_above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

static void	moves(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*b);
	if (cheapest->is_above_median && cheapest->target->is_above_median)
	{
		while (*a != cheapest->target && *b != cheapest)
			rr(a, b, false);
		init_index(*a);
		init_index(*b);
	}
	else if (!(cheapest->is_above_median)
		&& !(cheapest->target->is_above_median))
	{
		while (*a != cheapest->target && *b != cheapest)
			rrr(a, b, false);
		init_index(*a);
		init_index(*b);
	}
	last_rotation(b, cheapest, 'b');
	last_rotation(a, cheapest->target, 'a');
	pa(a, b, false);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		len;

	len = ft_listsize(*a);
	if (len == 5)
		sort_5(a, b);
	else
	{
		while (len-- > 3)
			pb(b, a, false);
	}
	sort_3(a);
	while (*b)
	{
		init_nodes(*a, *b);
		moves(a, b);
	}
	init_index(*a);
	smallest = find_smallest(*a);
	if (smallest->is_above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}
