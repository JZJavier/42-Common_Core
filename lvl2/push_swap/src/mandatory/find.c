/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:22:10 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/26 17:55:57 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest;

	smallest = stack;
	while (stack)
	{
		if (stack->number < smallest->number)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

t_stack	*find_cheapest(t_stack *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_stack	*find_highest(t_stack *stack)
{
	int		highest_number;
	t_stack	*highest_node;

	if (NULL == stack)
		return (NULL);
	highest_number = INT_MIN;
	while (stack)
	{
		if (stack->number > highest_number)
		{
			highest_number = stack->number;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}
