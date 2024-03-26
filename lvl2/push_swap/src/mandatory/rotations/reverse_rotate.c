/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjuarez- <jjuarez-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 13:16:22 by jjuarez-          #+#    #+#             */
/*   Updated: 2024/03/26 17:54:00 by jjuarez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	int		len;

	len = ft_listsize(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	last = ft_lstlast(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}
