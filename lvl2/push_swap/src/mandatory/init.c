/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:08:31 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/26 17:57:27 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	init_node(t_stack **a, char **argv)
{
	int	nbr;
	int	i;

	i = 0;
	while (argv[i])
	{
		nbr = ft_atol(argv[i]);
		add_back(a, nbr);
		++i;
	}
}

void	init_index(t_stack *stack)
{
	int	i;
	int	len;
	int	center;

	i = 0;
	len = ft_listsize(stack);
	if (stack == NULL)
		return ;
	center = ft_listsize(stack) / 2;
	while (stack != NULL)
	{
		stack->index = i;
		stack->is_above_median = (i < center) || (len % 2 == 0 && i == center);
		stack = stack->next;
		++i;
	}
}

void	init_target(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target;
	long	index;

	while (b)
	{
		index = LONG_MAX;
		current_a = a;
		target = NULL;
		while (current_a)
		{
			if (current_a->number > b->number && current_a->number < index)
			{
				index = current_a->number;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (index == LONG_MAX)
			b->target = find_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	init_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;
	int	push_price;

	len_a = ft_listsize(a);
	len_b = ft_listsize(b);
	while (b)
	{
		push_price = b->index;
		if (!(b->is_above_median))
			push_price = len_b - (b->index);
		if (b->target->is_above_median)
			push_price += b->target->index;
		else
			push_price += len_a - (b->target->index);
		b->push_price = push_price;
		b = b->next;
	}
}

void	init_cheapest(t_stack *b)
{
	long	best_price;
	t_stack	*best_node;
	t_stack	*current;

	if (b == NULL)
		return ;
	best_price = LONG_MAX;
	best_node = NULL;
	current = b;
	while (current != NULL)
	{
		if (current->push_price < best_price)
		{
			best_price = current->push_price;
			best_node = current;
		}
		current = current->next;
	}
	if (best_node != NULL)
		best_node->cheapest = true;
}
