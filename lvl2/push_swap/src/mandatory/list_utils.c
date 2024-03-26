/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 18:15:05 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/26 17:59:04 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*curr;

	curr = lst;
	while (curr != NULL && curr->next != NULL)
		curr = curr -> next;
	return (curr);
}

void	ft_lstclear(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

int	ft_listsize(t_stack *stack)
{
	int	len;

	if (stack == NULL)
		return (0);
	len = 0;
	while (stack)
	{
		stack = stack->next;
		len++;
	}
	return (len);
}

void	ft_lstadd_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last_node;

	if (!stack || !new_node)
		return ;
	last_node = *stack;
	if (!last_node)
		*stack = new_node;
	else
	{
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

t_stack	*ft_lstnew(int number)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->number = number;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}
